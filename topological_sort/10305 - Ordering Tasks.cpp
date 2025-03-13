#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#define MAXN 100+10

using namespace std;

int n = 0, m = 0;
vector<int> G[MAXN];
int cnt[MAXN];

void topological(){
    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(!cnt[i]){
            q.push(i);
            cnt[i] = -1;
        }
    }

    bool first = true;
    while(!q.empty()){
        int now = q.front(); q.pop();
        if(!first) printf(" ");
        first = false;
        printf("%d", now);
        for(auto i : G[now]){
            if(--cnt[i] == 0){
                q.push(i);
                cnt[i] = -1;
            }
        }
    }
    printf("\n");
}

int main()
{
    while(scanf("%d%d", &n, &m) != EOF && n){
        for(int i = 0; i < MAXN; i++) G[i].clear();
        memset(cnt, 0, sizeof(cnt));

        int u = 0, v = 0;
        for(int i = 0; i < m; i++){
            scanf("%d%d", &u, &v);
            G[u].emplace_back(v);
            cnt[v]++;
        }

        topological();
    }

    return 0;
}
