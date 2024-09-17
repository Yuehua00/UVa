#include <iostream>
#include <string.h>
#include <vector>
#define MAXN 1500+5

using namespace std;

vector<int> G[MAXN];
int dp[MAXN][2];
int n, u, d, v;

void dfs(int u, int fa) {
    dp[u][0] = dp[u][1] = 0;

    for (auto v : G[u]) {
        if (v == fa) {
            continue;
        }
        dfs(v, u);
        dp[u][0] += dp[v][1];
        dp[u][1] += min(dp[v][0], dp[v][1]);
    }
    dp[u][1]++;
}

int main() {


    while (scanf("%d", &n) != EOF && n) {
        for(int i = 0; i < MAXN; i++) G[i].clear();
        memset(dp, 0, sizeof(dp));

        for (int i = 0; i < n; i++) {
            scanf("%d:(%d)", &u, &d);
            int v;
            for (int j = 0; j < d; j++) {
                scanf("%d", &v);
                G[u].emplace_back(v);
                G[v].emplace_back(u);
            }
        }
        dfs(1, -1);
        printf("%d\n", min(dp[1][0], dp[1][1]));
    }
    return 0;
}
