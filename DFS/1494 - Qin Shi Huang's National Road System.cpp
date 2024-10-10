// DFS + MST(kruscal)
#include <bits/stdc++.h>
#define MAXN 1005

using namespace std;

struct node{
    int u, v;
    double w;
    bool operator<(const node &a) const{
        return a.w > w;
    }
};

vector<node> V;
vector<node> tree[MAXN];
int x[MAXN], y[MAXN], weight[MAXN];
int pa[MAXN], rak[MAXN];
bool visited[MAXN];
double max_edge[MAXN][MAXN];
int n = 0;

int find_pa(int x){
    if(x == pa[x]) return x;
    else return pa[x] = find_pa(pa[x]);
}

bool joint(int x, int y){
    int a = find_pa(x);
    int b = find_pa(y);
    if(a == b){
        return false;
    }else{
        if(rak[a] > rak[b]){
            rak[a] += rak[b];
            pa[b] = a;
        }else{
            rak[b] += rak[a];
            pa[a] = b;
        }
        return true;
    }
}

double kruscal(int m){
    for(int i = 0; i < n; i++){
        pa[i] = i;
        rak[i] = 1;
        tree[i].clear();
    }
    sort(V.begin(), V.end());
    double sum = 0;

    for(int i = 0; i < m; i++){
        if(joint(V[i].u, V[i].v)){
            sum += sqrt(V[i].w);
            tree[V[i].u].emplace_back((node){V[i].u, V[i].v, V[i].w});
            tree[V[i].v].emplace_back((node){V[i].v, V[i].u, V[i].w});
        }
    }
    return sum;
}

void dfs(int u){
    visited[u] = true;
    for(auto i : tree[u]){
        if(visited[i.v]) continue;
        double cost = sqrt(i.w);
        max_edge[u][i.v] = max_edge[i.v][u] = cost;
        for(int j = 0; j < n; j++){
            if(visited[j]) max_edge[j][i.v] = max_edge[i.v][j] = max(max_edge[j][u], cost);
        }
        dfs(i.v);
    }
}

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    int kase = 0;
    scanf("%d", &kase);
    while(kase--){
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            scanf("%d%d%d", &x[i], &y[i], &weight[i]);
        }
        V.clear();
        memset(max_edge, 0, sizeof(max_edge));
        memset(visited, false, sizeof(visited));
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                V.emplace_back((node){i, j, (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])});
            }
        }
        double maxcost = kruscal(V.size());

        dfs(0);
        double ret = 0;

        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                ret = max(ret, (weight[i]+weight[j])/(maxcost-max_edge[i][j]));
            }
        }
        printf("%.2lf\n", ret);

    }

    return 0;
}
