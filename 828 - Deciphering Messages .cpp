#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int place[26+5];

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    string code, encode;
    vector<char> ans;
    int shift = 0, casee = 0, n = 0;
    bool line = false;
    scanf("%d", &n);
    while(n--){
        if(line) printf("\n");
        line = true;
        memset(place, -1, sizeof(place));
        cin >> code;
        for(int i = 0; i < (int)code.length(); i++){
            place[code[i]-'A'] = 1;
        }
        scanf("%d%d", &shift, &casee);
        while(casee--){
            ans.clear();
            bool solve = true;
            int m = 0;
            cin >> ws;
            getline(cin, encode);
            for(int i = 0; i < (int)encode.length() && solve; i++){
                if(encode[i] == ' '){
                    ans.emplace_back(' ');
                    continue;
                }
                if(((code[m] == encode[i] && code[m+1] == encode[i+2]) || (code[code.length()-1] == encode[i] && code[0] == encode[i+2] && m == code.length()-1)) && i+2 < (int)encode.length()){
                    ans.emplace_back((((encode[i+1]-'A')-shift+26)%26)+'A');
                    i += 2;
                    m++;
                    if(m == code.length()) m = 0;

                }else{
                    if(place[(((encode[i]-'A')-shift)+26)%26] != -1){
                        solve = false;
                    }else{
                        ans.emplace_back((((encode[i]-'A')-shift+26)%26)+'A');
                    }
                }
            }
            if(!solve){
                printf("error in encryption\n");
            }else{
                for(auto i : ans){
                    printf("%c", i);
                }
                printf("\n");
            }

        }

    }

    return 0;
}
