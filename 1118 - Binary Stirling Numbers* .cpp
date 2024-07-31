// 判斷斯特林數的奇偶  https://www.wikiwand.com/en/Stirling_numbers_of_the_second_kind#Parity
// 參考 : | [arpingmail](https://vjudge.net/user/arpingmail) |
#include <iostream>
typedef long long int LL;

using namespace std;

LL n = 0, m = 0, t = 0;

LL solve(LL a, LL b){
    if(a == b || b == 1) return 1;
    if(a < 3) return (b * (solve(a-1, b)) + solve(a-1, b-1)) % 2;
    LL p = 1;
    while(p < b) p <<= 1;
    p >>= 1;
    LL h = p >> 1;
    if(h == 0) return 1;
    if((a-b) % p / h) return 0;
    a = b + (a - b) % h;
    b -= p; a-= p;
    return solve(a, b);
}


int main()
{
    scanf("%lld", &t);
    while(t--){
        scanf("%lld%lld", &n, &m);
        printf("%lld\n", solve(n, m));
    }

    return 0;
}

------------------------------------------------------------------------------------------
// 數論 (?)
// 來源 : | [JianShan](https://vjudge.net/user/JianShan) |

#include <iostream>

using namespace std;

int main() {
int T;
cin >> T:

    while (T -- ) {
        int n. m;
        cin >> n >> m;
        cout <<! ((n- m) & ((m - 1) / 2)) << endl;

        return 0;

    }

}
