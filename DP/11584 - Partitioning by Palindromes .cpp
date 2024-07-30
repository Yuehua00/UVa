// 求字串當中最少能切成幾段迴文
// 參考來源 : Fish (同學)

#include <iostream>
#include <string.h>
#define MAXN 1000+5

using namespace std;

int n = 0;
string s;
int dp[MAXN], pal[MAXN][MAXN];

int main()
{
    scanf("%d", &n);
    while(n--){
        cin >> s;
        memset(dp, 0, sizeof(dp));
        memset(pal, 0, sizeof(pal));
        int len = s.length();

        for(int i = 0; i < len; i++){ // 初始化
            pal[i][i] = 1;
            pal[i+1][i] = 1;
        }

        int a = 0, b = 1, cnt = 1;
        while(cnt < len){
            for(b = a+cnt; b < len; b++){    // 找出字串當中屬於迴文的部分
                if(pal[a+1][b-1] && s[a] == s[b]){  // 如果之間是迴文 && 前後字母相同
                    pal[a][b] = 1;
                }
                a++;
            }
            cnt++;
            a = 0;
        }
        dp[0] = 1;
        for(int i = 1; i < len; i++){
            dp[i] = dp[i-1] + 1;
            if(pal[0][i]){
                dp[i] = 1;
                continue;
            }
            for(int j = 1; j < i; j++){
                if(pal[j][i]){
                    dp[i] = min(dp[i], dp[j-1]+1);   // ans[j-1] 表示從索引 0 到 j-1 的最少分割次數，加上 1 表示將 j 到 i 的部分作為一個新的回文子字符串分割出來
                }
            }
        }
        printf("%d\n", dp[len-1]);

    }

    return 0;
}
