// 數論
// 參考 : https://www.cnblogs.com/scau20110726/archive/2012/12/21/2828420.html
#include <iostream>

using namespace std;

typedef unsigned long long int ull;
typedef long long int ll;
int arr[10000000];

int main()
{
    int n = 0, c = 1, time = 0;
    scanf("%d", &time);
    while(time--){
        scanf("%d", &n);
        printf("Case #%d: ", c);
        c++;

        if(n == 0){
            printf("0\n");
            continue;
        }

        int cnt = 0;
        while(n){
            //cout<< n % (-2) << endl;
            arr[cnt] = n % (-2);
            n /= (-2);
            if(arr[cnt] == -1){
                n++;
                arr[cnt] = 1;
            }
            cnt++;
        }

        for(int i = cnt-1; i >= 0; i--){
            printf("%d", arr[i]);
        }
        printf("\n");

    }

    return 0;

}
