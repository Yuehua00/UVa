#include <iostream>
#include <string.h>
#include <algorithm>
#define MAXN 30

using namespace std;

int cnt1[MAXN], cnt2[MAXN];

int main()
{
    string s1, s2;
    while(getline(cin, s1)){
        getline(cin, s2);

        memset(cnt1, 0, sizeof(cnt1));
        memset(cnt2, 0, sizeof(cnt2));

        for(int i = 0; i < s1.length(); i++){
            cnt1[s1[i]-'A']++;
            cnt2[s2[i]-'A']++;
        }

        sort(cnt1, cnt1+30, greater<int>());
        sort(cnt2, cnt2+30, greater<int>());

        bool same = true;
        for(int i = 0; i < 26; i++){
            if(cnt1[i] != cnt2[i]){
                same = false;
                break;
            }
        }
        if(same) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}
/*
問第一串字是否能轉換成第二串字，在相同字母轉換方式下
*/
