#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

const int maxn = 1000+5;
typedef unsigned long long int ull;
int Fib[maxn][maxn*6], period[maxn];

ull pow_mod(ull a, ull b, int c){
    if(!b) return 1;
    ull k = pow_mod(a, b/2, c);
    k = k * k % c;
    if(b % 2) k = k * a % c;  // b is odd
    return k;
}

int solve(ull a, ull b, int c){
    if(a == 0 || c == 1) return 0;
    int p = pow_mod(a%period[c], b, period[c]);  // [(a%p)^b]%p
    return Fib[c][p];
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n = 0, c = 0;
    ull a = 0, b = 0;
    for(int i = 2; i <= 1000; i++){
        Fib[i][0] = 0; Fib[i][1] = 1;
        for(int j = 2;; j++){
            Fib[i][j] = (Fib[i][j-1] + Fib[i][j-2]) % i;
            if(Fib[i][j-1] == 0 && Fib[i][j] == 1){
                period[i] = j-1;
                break;
            }
        }
    }

    scanf("%d", &n);
    while(n--){
        //scanf("%lld%lld%d", &a, &b, &c);
        cin >> a >> b >> c;                 // 我不知道為何用 scanf 輸入會答案錯誤
        printf("%d\n", solve(a, b, c));
    }

    return 0;
}
