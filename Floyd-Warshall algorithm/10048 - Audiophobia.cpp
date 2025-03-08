#include <iostream>
#include <string.h>
#include <vector>
#define MAXN 100+10
#define INF 0x3f3f3f3f

using namespace std;

int kase = 0;
bool line = false;
int c = 0, s = 0, q = 0;
int D[MAXN][MAXN];
int P[MAXN][MAXN];

void floyd(){

    for(int k = 1; k <= c; k++){
        for(int i = 1; i <= c; i++){
            for(int j = 1; j <= c; j++){
                if(D[i][j] > D[i][k] && D[i][j] > D[k][j]){   // 改成記錄此路當中會遇到的最大值
                    D[i][j] = max(D[i][k], D[k][j]);
                }
            }
        }
    }
}

int main()
{
    while(scanf("%d%d%d", &c, &s, &q) != EOF && c){
        if(line) puts("");
        line = true;
        printf("Case #%d\n", ++kase);
        memset(D, INF, sizeof(D));
        memset(P, INF, sizeof(P));
        for(int i = 0; i < MAXN; i++){
            D[i][i] = 0;
        }

        int u = 0, v = 0, w = 0;
        for(int i = 0; i < s; i++){
            scanf("%d%d%d", &u, &v, &w);
            D[u][v] = D[v][u] = w;
        }

        floyd();

        while(q--){
            scanf("%d%d", &u, &v);
            if(D[u][v] == INF) printf("no path\n");
            else printf("%d\n", D[u][v]);
        }
    }

    return 0;
}
