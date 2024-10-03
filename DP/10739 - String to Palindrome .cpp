#include <iostream>
#include <vector>
#include <string.h>
#define MAXN 1000+10
#define INF 0x3f3f3f3f

using namespace std;

int dp[MAXN][MAXN];

int main()
{
    int n = 0;
    string s;
    scanf("%d", &n);
    for(int k = 1; k <= n; k++){
        cin >> s;
        int len = s.length();
        memset(dp, 0, sizeof(dp));
        for(int i = len-1; i >= 0; i--){
            for(int j = i+1; j < len; j++){
                if(s[i] == s[j]) dp[i][j] = dp[i+1][j-1];
                else dp[i][j] = min(dp[i+1][j-1], min(dp[i][j-1], dp[i+1][j]))+1;
            }
        }

        printf("Case %d: %d\n", k, dp[0][len-1]);
    }

    return 0;
}
