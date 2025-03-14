#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <sstream>
#define MAXN 50+10

using namespace std;

int m = 0;
vector<int> G[MAXN];
vector<int> ans;
int cnt[MAXN], visit[MAXN];
string s;

void dfs(int n){
    if(n == m){
        for(auto i : ans){
            printf("%c", i+'a');
        }
        puts("");
        return;
    }

    for(int i = 0; i < 26; i++){
        if(!visit[i] && !cnt[i]){
            ans.emplace_back(i);
            visit[i] = 1;
            for(auto j : G[i]){
                cnt[j]--;
            }
            dfs(n+1);
            for(auto j : G[i]){
                cnt[j]++;
            }
            visit[i] = 0;
            ans.pop_back();
        }
    }

}

int main()
{
    bool first = true;
    while(getline(cin, s)){
        for(int i = 0; i < MAXN; i++) G[i].clear();
        memset(cnt, -1, sizeof(cnt));
        memset(visit, 0, sizeof(visit));
        ans.clear();
        m = 0;

        if(!first) puts("");
        first = false;

        char tmp; int a = 0;
        stringstream ss(s);
        while(ss >> tmp){
            a = tmp - 'a';
            cnt[a] = 0;
            m++;
        }

        getline(cin, s);
        stringstream ss2(s);
        char _u, _v;
        int u = 0, v = 0;
        while(ss2 >> _u >> _v){
            u = _u - 'a';
            v = _v - 'a';
            G[u].emplace_back(v);
            cnt[v]++;
        }

        dfs(0);
    }

    return 0;
}
