// Greedy
// 參考 : https://mypaper.pchome.com.tw/zerojudge/post/1324807908
#include <iostream>

using namespace std;

typedef unsigned long long int ull;
typedef long long int ll;

int main()
{
    int time = 0;
    scanf("%d", &time);
    while(time--){
        int v = 0, n = 0;
        scanf("%d%d", &n, &v);

        if(n > v){
            printf("%d\n", v);
        }else{
            for(ll i = 1; i <= n; i++){
                ll rest = n-i;
                if(i*(i-1)/2 >= v-rest){
                    printf("%d\n", rest);
                    break;
                }
            }
        }
    }

    return 0;

}
