#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <map>

using namespace std;

string haab[20] = { " " , "pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen",
                        "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu", "uayet"};
string tzolkin[20] = { "imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok",
                            "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};

int main()
{
    //freopen("10570.in", "r", stdin);
    //freopen("out.txt", "w", stdout);

    unsigned long long int n = 0, year = 0, day = 0;
    string month, sday;

    scanf("%lld", &n);
    printf("%lld\n", n);
    while(n--){
        cin >> sday >> month;
        sday.erase(sday.end()-1);
        day = stoi(sday);

        scanf("%lld", &year);

        unsigned long long int total = day + year * 365;
        for(int i = 1; i < 20; i++){
            if(month == haab[i]){
                while(--i){
                    total += 20;
                }
                break;
            }
        }
        cout << total%13+1 << " " << tzolkin[total%20] << " " << total/260 << endl;


    }

    return 0;
}
