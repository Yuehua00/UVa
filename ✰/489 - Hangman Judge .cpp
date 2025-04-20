#include <iostream>
#include <string.h>
#include <algorithm>
#define MAXN 10000

using namespace std;

string ans, s;
int round, cnt_end = 0, cnt_ansc = 0;
int cnt_ans[30];

int main()
{
    while(scanf("%d", &round) != EOF && round != -1){
        cin >> ans >> s;
        printf("Round %d\n", round);

        memset(cnt_ans, -1, sizeof(cnt_ans));
        cnt_end = 0;
        cnt_ansc = 0;

        for(int i = 0; i < ans.length(); i++){
            if(cnt_ans[ans[i]-'a'] == -1){
                cnt_ansc++;
                cnt_ans[ans[i]-'a'] = 1;
            } else cnt_ans[ans[i]-'a']++;
        }

        for(int i = 0; i < s.length(); i++){
            if(cnt_ans[s[i]-'a'] > 0){
                cnt_ansc--;
                if(cnt_ansc == 0) break;
            }else if(cnt_ans[s[i]-'a'] != 0){
                cnt_end++;
            }
            cnt_ans[s[i]-'a'] = 0;
        }

        if(cnt_end < 7){
            if(cnt_ansc == 0) printf("You win.\n");
            else printf("You chickened out.\n");
        }else printf("You lose.\n");
    }

    return 0;
}
/*
猜單字
只能錯七次
猜過的再猜忽略
*/
