#include <iostream>
#include <string.h>
#include <vector>
#define MAXN 100+10
#define INF 0x3f3f3f3f

using namespace std;

int kase = 0;
int n = 0, r = 0;
int D[MAXN][MAXN];

void floyd(){
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
            }
        }
    }
}

int main()
{
    scanf("%d", &kase);
    for(int k = 1; k <= kase; k++){
        memset(D, INF, sizeof(D));
        for(int i = 0; i < MAXN; i++){
            D[i][i] = 0;
        }

        int u = 0, v = 0;
        scanf("%d%d", &n, &r);
        for(int i = 0; i < r; i++){
            scanf("%d%d", &u, &v);
            D[u][v] = D[v][u] = 1;
        }

        floyd();

        int s = 0, d = 0, ans = 0;
        scanf("%d%d", &s, &d);
        for(int i = 0; i < n; i++){
            ans = max(ans, D[s][i] + D[i][d]);
        }
        printf("Case %d: %d\n", k, ans);
    }

    return 0;
}
