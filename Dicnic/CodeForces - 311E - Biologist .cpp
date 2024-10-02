// 這題不是 UVa
// 最大權閉合子圖
#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
#define MAXN 100000+10
#define INF 0x3f3f3f3f
#define eb emplace_back

using namespace std;

struct Edge{
    int from, to, cap, flow;
};

vector<Edge> edges;
vector<int> G[MAXN];
int dog_sex[MAXN];
int dog_money[MAXN];
int d[MAXN];
int cur[MAXN];
bool visited[MAXN];
int m, n, t, s, g, total = 0;

void init(){
    for(int i = 0; i < MAXN; i++) G[i].clear();
    edges.clear();
    memset(dog_money, 0, sizeof(dog_money));
    memset(dog_sex, 0, sizeof(dog_sex));
    memset(d, 0, sizeof(d));
    memset(cur, 0, sizeof(cur));
}

void AddEdge(int from, int to, int cap){
    edges.eb((Edge){from, to, cap, 0});
    edges.eb((Edge){to, from, 0, 0});
    int m_c = edges.size();
    G[to].eb(m_c-1);
    G[from].eb(m_c-2);
}

bool BFS(){
    int tmp;
    memset(visited, false, sizeof(visited));
    queue<int> Q;
    Q.push(s); visited[s] = true; d[s] = 0;

    while(!Q.empty()){
        tmp = Q.front(); Q.pop();
        for(int i = 0; i < G[tmp].size(); i++){
            Edge e = edges[G[tmp][i]];
            if(!visited[e.to] && e.cap > e.flow){
                Q.push(e.to);
                visited[e.to] = true;
                d[e.to] = d[tmp] + 1;
            }
        }
    }

    return visited[t];
}

int DFS(int u, int a){

    if(u == t || a == 0) return a;

    int f = 0, flow = 0;
    for(int& i = cur[u]; i < G[u].size(); i++){
        Edge& e = edges[G[u][i]];
        if(d[e.to] == d[u]+1 && (f = DFS(e.to, min(a, e.cap-e.flow)))> 0){
            flow += f;
            a -= f;
            e.flow += f;
            edges[G[u][i]^1].flow -= f;
            if(!a) break;
        }
    }
    return flow;
}

int dicnic_MaxFlow(int s, int t){
    int max_flow = 0;
    while(BFS()){
        memset(cur, 0, sizeof(cur));
        max_flow += DFS(s, INF);
    }

    return max_flow;
}

int main()
{

    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w",stdout);
    while(scanf("%d%d%d", &n, &m, &g) != EOF){
        total = 0;
        s = 0; t = n+m+1;
        init();
        for(int i = 1; i <= n; i++){
            scanf("%d", &dog_sex[i]);
        }
        for(int i = 1; i <= n; i++){
            scanf("%d", &dog_money[i]);
            if(dog_sex[i]){
                AddEdge(s, i, dog_money[i]);
            }else{
                AddEdge(i, t, dog_money[i]);
            }
        }
        int want = 0, mon = 0, guess = 0, tar = 0, friends = 0;
        for(int i = 1; i <= m; i++){
            scanf("%d%d%d", &want, &mon, &guess);
            total += mon;
            if(want){
                for(int j = 0; j < guess; j++){
                    scanf("%d", &tar);
                    AddEdge(i+n, tar, INF);
                }
            }else{
                for(int j = 0; j < guess; j++){
                    scanf("%d", &tar);
                    AddEdge(tar, i+n, INF);
                }
            }
            scanf("%d", &friends);
            int pay = mon;
            if(friends) pay += g;
            if(!want) AddEdge(n+i, t, pay);
            else AddEdge(s, n+i, pay);

        }
        printf("%d\n", total-dicnic_MaxFlow(s, t));

    }

    return 0;
}
