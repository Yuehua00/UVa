// BFS + 拓樸排序
#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

typedef unsigned long long int ull;
typedef long long int ll;
int degree[10000 + 5], marbles[10000+5], parent[10000+5];

int main()
{
    int n = 0, a = 0, b = 0, c = 0, d = 0;
    while(scanf("%d", &n) != EOF && n != 0){
        int Ans = 0, tmp = 0;
        memset(degree, 0, sizeof(degree));
        memset(marbles, 0, sizeof(marbles));
        memset(parent, 0, sizeof(parent));

        for(int i = 0; i < n; i++){
            scanf("%d%d%d", &a, &b, &c);
            degree[a] = c;
            marbles[a] = b;
            for(int j = 0; j < c; j++){
                scanf("%d", &d);
                parent[d] = a;
            }
        }

        queue<int> q;
        for(int i = 1; i <= n; i++){
            if(degree[i] == 0) q.push(i);
        }
        while(!q.empty()){
            int top = q.front();
            q.pop();
            int Parent = parent[top];
            if(Parent == 0) break;
            if(marbles[top] != 1){
                marbles[Parent] += marbles[top] -1;
                Ans += abs(marbles[top] - 1);
                marbles[top] = 1;
            }

            if(--degree[Parent] == 0) q.push(Parent);
        }

        printf("%d\n", Ans);
    }

    return 0;
}
