#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <sstream>
#define MAXN 26+10

using namespace std;

int kase = 0, n = 0;
vector<int> G[MAXN];
int cnt[MAXN], times[MAXN], total[MAXN];
string s;

void topological(){
    queue<int> q;
    for(int i = 0; i < n; i++){
        if(!cnt[i]){
            q.push(i);
            total[i] = times[i];
        }
    }

    int ans = 0;
    while(!q.empty()){
        int now = q.front(); q.pop();
        for(auto i : G[now]){
            total[i] = max(total[i], total[now] + times[i]);
            if(--cnt[i] == 0){
                q.push(i);
            }
        }
        ans = max(ans, total[now]);
    }
    printf("%d\n", ans);
}

int main()
{
    bool first = true;
    scanf("%d", &kase);
    while(kase--){
        cin >> ws;
        if(!first) puts("");
        first = false;
        for(int i = 0; i < MAXN; i++) G[i].clear();
        memset(cnt, 0, sizeof(cnt));
        memset(times, 0, sizeof(times));
        memset(total, 0, sizeof(total));
        n = 0;

        char c;
        int a = 0, b = 0, d = 0;
        while(getline(cin, s) && s[0] >= 'A' && s[0] <= 'Z'){
            n++;
            stringstream ss(s);

            ss >> c;
            a = c - 'A';
            ss >> b;
            times[a] = b;
            while(ss >> c){
                d = c - 'A';
                G[d].emplace_back(a);
                cnt[a]++;
            }
        }
        topological();

    }

    return 0;
}
