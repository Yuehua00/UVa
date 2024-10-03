// tree DP
#include <iostream>
#include <vector>
#include <string.h>
#define MAXN 1000+10
#define INF 0x3f3f3f3f

using namespace std;

struct node{
    int to, w;
};

vector<node> G[MAXN];
int dp[MAXN][MAXN][2];
int tc[MAXN];

void dfs(int n){
    tc[n] = 1;
    for(auto i : G[n]){
        dfs(i.to);
        tc[n] += tc[i.to];
    }
    dp[n][1][0] = dp[n][1][1] = 0;
    for(int i = 2; i <= tc[n]; i++) dp[n][i][0] = dp[n][i][1] = INF;

    for(auto i : G[n]){
        for(int j = tc[n]; j >= 2; j--){
            for(int k = 0; k <= j && k <= tc[i.to]; k++){
                dp[n][j][1] = min(dp[n][j][1], dp[n][j-k][1]+dp[i.to][k][1]+2*i.w);
                dp[n][j][0] = min(dp[n][j][0], dp[n][j-k][0]+dp[i.to][k][1]+2*i.w);
                dp[n][j][0] = min(dp[n][j][0], dp[n][j-k][1]+dp[i.to][k][0]+i.w);
            }
        }
    }

}

int main()
{
    int n = 0, u = 0, v = 0, w = 0, q = 0, a = 0, ans = 0, cnt = 0;
    while(scanf("%d", &n) != EOF && n){
        printf("Case %d:\n", ++cnt);
        for(int i = 0; i < MAXN; i++) G[i].clear();
        memset(tc, 0, sizeof(tc));
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= n-1; i++){
            scanf("%d%d%d", &v, &u, &w);
            G[u].emplace_back((node){v, w});
        }
        dfs(0);
        scanf("%d", &q);
        while(q--){
            scanf("%d", &a);
            for(int i = n; i >= 1; i--){
                if(a >= dp[0][i][0]){
                    ans = i;
                    break;
                }
            }
            printf("%d\n", ans);
        }
    }

    return 0;
}
