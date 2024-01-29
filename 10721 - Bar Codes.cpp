// DP
#include <iostream>

using namespace std;

typedef unsigned long long int ull;

int main()
{
    int n = 0, k = 0, m = 0, tmp = 0;
    while(scanf("%d%d%d", &n, &k, &m) != EOF){
        ull arr[2][n+5];
        tmp = 0;

        arr[0][0] = 1;
        for(int i = 1; i <= n; i++){
            arr[0][i] = 0;
        }

        for(int i = 1; i <= k; i++){
            for(int j = 0; j <= n; j++){
                if(j < i) arr[tmp^1][j] = 0;
                else if(j == i) arr[tmp^1][j] = 1;
                else {
                    arr[tmp^1][j] = 0;
                    for(int l = 1; l <= m; l++){
                        if(j-l >= 0) arr[tmp^1][j] += arr[tmp][j-l];
                        else break;
                    }
                }
            }
            tmp ^= 1;
            //cout << arr[tmp][n] << endl;
            /*for(int a = 0; a < 2; a++){
                for(int b = 0; b <= n; b++){
                    cout << arr[a][b] << " ";
                }
                cout << endl;
            }
            cout << endl;*/
        }

        printf("%lld\n", arr[tmp][n]);
    }


    return 0;
}
