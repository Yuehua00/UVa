#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    int c = 0, m = 0, d = 0, a = 0, b = 0, casee = 1;
    scanf("%d", &c);
    while(c--){
        scanf("%d%d", &m, &d);
        int arr[m][m];
        memset(arr, 0, sizeof(arr));
        for(int i = 0; i < d; i++){
            scanf("%d%d", &a, &b);
            arr[a][b] = 1;
        }

        bool result = true;
        for(int i = 0; i < m && result; i++){
            for(int j = 0; j < m && result; j++){
                bool ch1 = false, ch2 = false;
                for(int k = 0; k < m && result; k++){
                    if(arr[i][k] && arr[j][k]) ch1 = true;
                    if(arr[i][k] ^  arr[j][k]) ch2 = true; // XOR 只存在其中一條，不符合要求
                    if(ch1 && ch2) result = false;  // 讓迴圈 break
                }
            }
        }
        if(result){
            printf("Case #%d: Yes\n", casee);
        }else{
            printf("Case #%d: No\n", casee);
        }
        casee++;

    }

    return 0;
}
