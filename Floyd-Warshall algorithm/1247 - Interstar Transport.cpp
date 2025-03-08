#include <iostream>
#include <string.h>
#include <vector>
#define MAXN 200+10
#define INF 0x3f3f3f3f

using namespace std;

int kase = 0;
int s = 0, p = 0;
int D[MAXN][MAXN];
int P[MAXN][MAXN];

void floyd(){

    for(int i = 0; i < p; i++){
        for(int j = 0; j < p; j++){
            P[i][j] = i;
        }
    }

    for(int k = 0; k < p; k++){
        for(int i = 0; i < p; i++){
            for(int j = 0; j < p; j++){
                if(D[i][k] + D[k][j] < D[i][j]){
                    D[i][j] = D[i][k] + D[k][j];
                    P[i][j] = P[k][j];
                }
            }
        }
    }
}

void output(int a, int b){
    if(a == b){
        printf("%c", a + 'A');
        return;
    }
    output(a, P[a][b]);
    printf(" %c", b + 'A');
}

int main()
{
    while(scanf("%d%d", &s, &p) != EOF){
        memset(D, INF, sizeof(D));
        memset(P, -1, sizeof(P));
        for(int i = 0; i < MAXN; i++){
            D[i][i] = 0;
        }

        char u = 0, v = 0;
        int a = 0, b = 0;
        int w = 0;
        for(int i = 0; i < p; i++){
            scanf(" %c %c%d", &u, &v, &w);
            a = u - 'A', b = v - 'A';
            D[a][b] = D[b][a] = w;
        }

        floyd();

        int t = 0;
        scanf("%d", &t);
        while(t--){
            scanf(" %c %c", &u, &v);
            a = u - 'A'; b = v - 'A';
            output(a, b);
            puts("");
        }
    }

    return 0;
}
