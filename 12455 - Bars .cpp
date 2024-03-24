#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#define maxn 1000+10

using namespace std;

int dp[maxn];

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n = 0, now_max = 0;
    int tar = 0, m = 0, tmp = 0;
    vector<int> len;
    scanf("%d", &n);
    while(n--){
        memset(dp, 0, sizeof(dp));
        len.clear();

        scanf("%d%d", &tar, &m);
        while(m--){
            scanf("%d", &tmp);
            len.emplace_back(tmp);
        }
        sort(len.begin(), len.end());

        dp[0] = 1;
        for(int i = 0; i < len.size(); i++){
            now_max += len[i];
            for(int j = tar; j >= 0; j--){     // 從後面，才不會重複計算。例如len[i] = 5，在 dp[5]=1，但在 j = 10 時，也會 true，此為重複計算
                if(dp[j] && j+len[i]<=tar){
                    dp[j+len[i]] = 1;
                }
            }
        }
        /*for(int i = 0; i <= tar; i++){
            if(dp[i]) cout << i << " ";
            else cout << "0 ";
        }
        cout << endl;*/
        if(dp[tar]){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }


    return 0;
}
