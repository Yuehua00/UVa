#include <bits/stdc++.h>
#define MAXN 1010
#define INF 0x3f3f3f3f

using namespace std;

vector<int> G[MAXN];
int dis[MAXN][MAXN];
int flag[MAXN];

int main() {
    int n = 0;
    string s;
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i <= n; i++) G[i].clear();
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == j) dis[i][j] = 0;
                else dis[i][j] = INF;
            }
        }
        for (int i = 1; i <= n; i++) {
            cin >> ws;
            getline(cin, s);
            stringstream ss(s);
            int neighbor;
            while (ss >> neighbor) {
                G[i].emplace_back(neighbor);
                dis[i][neighbor] = 1;
                dis[neighbor][i] = 1;
            }
        }

        // Floyd-Warshall algorithm
        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
        }

        int q = 0, f = 0, cnt = 0;
        scanf("%d", &q);
        while (q--) {
            f = 0;
            cnt = 0;
            memset(flag, 0, sizeof(flag));
            cin >> ws;
            getline(cin, s);
            stringstream ss(s);
            int x;
            while (ss >> x) {
                flag[x] = 1;
                cnt++;
            }

            for (int i = 1; i <= n; i++) {
                if (flag[i]) continue;
                f = 0;
                for (int j = 1; j <= n; j++) {
                    if (!flag[j]) continue;
                    for (int k = 1; k <= n; k++) {
                        if (!flag[k]) continue;
                        if (dis[j][k] == dis[j][i] + dis[i][k]) {
                            f = 1;
                            break;
                        }
                    }
                    if (f) break;
                }
                if (!f) break;
            }
            if (!f && cnt != n) printf("no\n");
            else printf("yes\n");
        }
    }

    return 0;
}
