// 求字串當中最少能切成幾段迴文
#include <bits/stdc++.h>
#define MAXN 1000+10

using namespace std;

string s;
int is_pal[MAXN][MAXN];
int dp[MAXN];      // 從 0 開始至 idx 切成迴文的數量

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n = 0;
    scanf("%d", &n);
    while(n--){
        cin >> s;
        memset(is_pal, 0, sizeof(is_pal));
        for(int i = 0; i < s.size(); i++){        // 處理一個字與兩個相鄰字是否為迴文
            is_pal[i][i] = 1;
            if(s[i] == s[i+1]) is_pal[i][i+1] = 1;
        }
        for(int i = 2; i < s.size(); i++){       // 處理 3 至 n 個字是否為迴文
            for(int j = 0; j+i < s.size(); j++){
                if(is_pal[j+1][i+j-1] && s[i+j] == s[j]) is_pal[j][i+j] = 1;
            }
        }
        for(int i = 0; i < s.size(); i++){
            dp[i] = i+1;                        // 初始化，都先設為最大可能
            for(int j = 0; j <= i; j++){
                if(is_pal[j][i]) dp[i] = min(dp[i], dp[j-1]+1); 
            }
        }
        printf("%d\n", dp[s.size()-1]);
    }

    return 0;
}
