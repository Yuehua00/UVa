// 01背包，無權重
#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

int dp[1000+5];

int main()
{
    //freopen("12455.in", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int kase = 0, target = 0, m = 0, a = 0;
    vector<int> stick;
    scanf("%d", &kase);
    while(kase--){
        stick.clear();
        memset(dp, 0, sizeof(dp));
        scanf("%d%d", &target, &m);
        dp[0] = 1;
        for(int i = 0; i < m; i++){
            scanf("%d", &a);
            stick.emplace_back(a);
            //dp[a] = 1;                // 加上這句會造成 RE，可能輸入 > 1004 (但題目明明就在範圍內)
        }

        sort(stick.begin(), stick.end());

        for(int i = 0; i < m; i++){
            for(int j = target; j >= 0; j--){
                if(dp[j] && j+stick[i] <= target){
                    dp[j+stick[i]] = 1;
                }
            }
        }
        if(dp[target]){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }

    return 0;
}
