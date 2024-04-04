// dijkstra
#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <queue>

using namespace std;

const int MAXN = 100+5;
int d[MAXN][MAXN][2];
int G[MAXN][MAXN];
int n, r;

struct pq_node{
    int u, cost;
    bool operator<(const pq_node& a) const{
        return cost > a.cost;
    }
};

void dijkstra(int s){
    priority_queue<pq_node> pq;

    for(int i = 0; i < n; i++){
        if(G[s][i]){
            pq.push((pq_node){i, G[s][i]});
        }
    }
    pq_node tmp;

    while(!pq.empty()){
        tmp = pq.top();
        pq.pop();

        int u = tmp.u, cost = tmp.cost;
        if(d[s][u][0] == 0){
            d[s][u][0] = cost;
        }else{
            if(d[s][u][0] > cost){
                d[s][u][1] = d[s][u][0];
                d[s][u][0] = cost;
            }else if(d[s][u][0] == cost){
                continue;
            }else if(d[s][u][1] == 0 ||d[s][u][1] > cost){
                d[s][u][1] = cost;
            }else{
                continue;
            }
        }
        for(int i = 0; i < n; i++){
            if(G[u][i]){
                pq.push(pq_node{i, G[u][i]+cost});
            }
        }
    }
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int T = 1;
    while(scanf("%d%d", &n, &r) != EOF){
        int u, v, w;
        memset(G, 0, sizeof(G));

        for(int i = 0; i < r; i++){
            scanf("%d%d%d", &u, &v, &w);
            G[u][v] = w;
            G[v][u] = w;
        }
        printf("Set #%d\n", T++);
        memset(d, 0, sizeof(d));

        for(int i = 0; i < n; i++){
            dijkstra(i);
        }

        int a, b, Cas;
        scanf("%d", &Cas);
        for(int i = 0; i < Cas; i++){
            scanf("%d%d", &a, &b);
            if(d[a][b][1]){
                printf("%d\n", d[a][b][1]);
            }else{
                printf("?\n");
            }
        }
    }


    return 0;
}
