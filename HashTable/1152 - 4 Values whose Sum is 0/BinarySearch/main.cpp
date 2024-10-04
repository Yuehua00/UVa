#include <bits/stdc++.h>
#define MAXN 5000

using namespace std;

int arr[4][MAXN];
int ab[MAXN*MAXN];

int main()
{
    int kase = 0, m = 0;
    bool line = false;
    scanf("%d", &kase);
    while(kase--){
        if(line) printf("\n");
        line = true;
        scanf("%d", &m);
        for(int j = 0; j < m; j++){
            for(int i = 0; i < 4; i++){
                scanf("%d", &arr[i][j]);
            }
        }
        int cnt = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < m; j++){
                ab[cnt++] = arr[0][i] + arr[1][j];
            }
        }
        sort(ab, ab+cnt);
        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < m; j++){
                ans += upper_bound(ab, ab+cnt, -(arr[2][i]+arr[3][j])) - lower_bound(ab, ab+cnt, -(arr[2][i]+arr[3][j]));
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}
