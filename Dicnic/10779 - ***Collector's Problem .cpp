// dinic

#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
#define MAXN 50+10
#define INF 0x3f3f3f3f
#define eb emplace_back

using namespace std;

struct Edge{
    int from, to, cap, flow;
};

vector<Edge> edges;
vector<int> G[MAXN];
int d[MAXN];
int cur[MAXN];
int own[MAXN][MAXN];
bool visited[MAXN];
int m, n, t, s;

void AddEdge(int from, int to, int cap){
    edges.eb((Edge){from, to, cap, 0});
    edges.eb((Edge){to, from, 0, 0});
    m = edges.size();
    G[to].eb(m-1);
    G[from].eb(m-2);
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
    int kase = 0, p = 0, c = 0, have = 0, a = 0;
    scanf("%d", &kase);
    for(int k = 1; k <= kase; k++){
        memset(own, 0, sizeof(own));
        memset(d, 0, sizeof(d));
        edges.clear();
        for(int i = 0; i < MAXN; i++) G[i].clear();

        scanf("%d%d", &p, &c);
        s = 0; t = p+c;
        for(int i = 0; i < p; i++){
            scanf("%d", &have);
            for(int j = 0; j < have; j++){
                scanf("%d", &a);
                own[i][a]++;
            }
        }
        for(int i = 1; i <= c; i++){
            if(own[0][i]) AddEdge(0, i+p-1, own[0][i]);
            AddEdge(i+p-1, t, 1);
        }
        for(int i = 1; i < p; i++){
            for(int j = 1; j <= c; j++){
                if(own[i][j] > 1) AddEdge(i, j+p-1, own[i][j]-1);
                else if(!own[i][j]) AddEdge(j+p-1, i, 1);
            }
        }
        printf("Case #%d: %d\n", k, dicnic_MaxFlow(s, t));
    }

    return 0;
}
