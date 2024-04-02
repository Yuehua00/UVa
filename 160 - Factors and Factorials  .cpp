#include <iostream>
#include <string.h>

using namespace std;

bool Is_Prime[100];
int prime[100];
int c = 0;

void find_prime(){

    memset(Is_Prime, true, sizeof(Is_Prime));
    Is_Prime[0] = false; Is_Prime[1] = false;

    for(int i = 2; i <= 100; i++){
        if(Is_Prime[i]){
            for(int j = i+i; j <= 100; j+=i){
                Is_Prime[j] = false;
            }
        }

    }
}

void set_PrimeArray(){
    for(int i = 0; i <= 100; i++){
        if(Is_Prime[i]){
            prime[c] = i;
            c++;
        }
    }
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n = 0;
    find_prime();
    set_PrimeArray();
    /*for(int i = 0; i <= c; i++){
        cout << prime[i] << endl;

    }*/
    while(scanf("%d", &n) != EOF && n){
        printf("%3d! =", n);
        if(n == 0) break;
        int ans = 0;
        int cnt = 0, tmp = n;
        for(int i = 0; i < c; i++){
            ans = 0;
            if(prime[i] > n){
                break;
            }
            while(tmp > 1){
                tmp /= prime[i];
                ans += tmp;
            }
            cnt++;
            if(cnt == 16){
                cnt = 0;
                printf("\n%9d", ans);
            } else printf("%3d", ans);
            tmp = n;
        }
        printf("\n");
    }

    return 0;
}
