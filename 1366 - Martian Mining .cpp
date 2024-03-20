// dp
#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

const int maxn = 500+10;
int dp[maxn][maxn], a[maxn][maxn], b[maxn][maxn];

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n = 0, m = 0, tmp = 0;
    while(scanf("%d%d", &n, &m) != EOF && n){
        memset(dp, 0, sizeof(dp));
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                scanf("%d", &tmp);
                a[i][j] = tmp + a[i][j-1];
            }
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                scanf("%d", &tmp);
                b[i][j] = tmp + b[i-1][j];
            }
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                dp[i][j] = max(dp[i-1][j]+a[i][j], dp[i][j-1]+b[i][j]);
            }
        }
        printf("%d\n", dp[n][m]);

    }

    return 0;
}
