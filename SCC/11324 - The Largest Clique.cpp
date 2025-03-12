#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string.h>
#define MAXN 1000+10

using namespace std;

int n = 0, m = 0, kase = 0, ans = 0, total = 0;
vector<int> G[MAXN], dag[MAXN];
stack<int> s;
int dfn[MAXN], low[MAXN], cnt = 0;
int in_stk[MAXN], scc_id[MAXN], scc_sz[MAXN];
int in[MAXN];
int dp[MAXN];

void tarjan(int p){
    dfn[p] = low[p] = ++cnt;
    s.push(p);
    in_stk[p] = 1;

    for(auto i : G[p]){
        if(!in_stk[i] && dfn[i]) continue;  // 如果被走過且不在stack裡代表已經是其他SCC
      
        // 剩下的只有可能是還沒被走過或還在stack裡，代表待合成SCC
        if(!dfn[i]) tarjan(i);  // 如果還沒被走過就先遍歷
        low[p] = min(low[p], low[i]);  // 更新我能回到最上祖先節點的編號(dfn)
    }

    if(dfn[p] == low[p]){  // 如果遍歷完全部的子樹，我能回到最上的祖先編號為自己的話，代表我的子樹是一個SCC且我是root
        total++;  // 建立一個新的SCC
        int x;
        do{
            x = s.top();
            s.pop();
            in_stk[x] = 0;
            scc_id[x] = total;
            scc_sz[total]++;
        }while(x != p);  // 更新所有子節點直到Root
    }
}

void build_dag() {  // 建立 DAG
    for (int u = 1; u <= n; u++) {
        for (auto v : G[u]) {
            if (scc_id[u] != scc_id[v]) {  // 身處不同 SCC
                dag[scc_id[u]].emplace_back(scc_id[v]);
                in[scc_id[v]]++;
            }
        }
    }
}

void topo(){
    queue<int> q;
    for(int i = 1; i <= total; i++){
        if(!in[i]) q.push(i);
        dp[i] = scc_sz[i];
    }

    while(!q.empty()){
        int u = q.front(); q.pop();
        for(auto i : dag[u]){
            dp[i] = max(dp[i], dp[u]+scc_sz[i]);
            if(!--in[i]) q.push(i);
        }
    }
}

void init(){
    for(int i = 0; i < MAXN; i++) {
        G[i].clear();
        dag[i].clear();
    }
    while(!s.empty()) s.pop();
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    memset(in_stk, 0, sizeof(in_stk));
    memset(scc_id, 0, sizeof(scc_id));
    memset(scc_sz, 0, sizeof(scc_sz));
    memset(in, 0, sizeof(in));
    memset(dp, 0, sizeof(dp));
    cnt = 0; ans = 0; total = 0;
}

int main()
{
    scanf("%d", &kase);
    while(kase--){
        init();
        scanf("%d%d", &n, &m);
        int u = 0, v = 0;
        for(int i = 0; i < m; i++){
            scanf("%d%d", &u, &v);
            G[u].emplace_back(v);
        }
        for(int i = 1; i <= n; i++){
            if(!dfn[i]) tarjan(i);
        }
        build_dag();
        topo();
        for(int i = 1; i <= total; i++){
            ans = max(ans, dp[i]);
        }
        printf("%d\n", ans);
    }

    return 0;
}

/*
1
5 5
1 2
2 3
3 1
4 1
5 2
*/
