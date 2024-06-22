#include <iostream>
#include <string.h>
#define MAXN 10000+5
#define INF 0x3f3f3f

using namespace std;

int dpi[MAXN], dpd[MAXN];
int h[MAXN], w[MAXN];

int main()
{
    int kase = 0, n = 0, a = 0;
    scanf("%d", &kase);
    for(int k = 1; k <= kase; k++){
        printf("Case %d. ", k);
        memset(dpi, 0, sizeof(dpi));
        memset(dpd, 0, sizeof(dpd));

        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            scanf("%d", &h[i]);
        }
        for(int i = 0; i < n; i++){
            scanf("%d", &a);
            w[i] = a;
            dpi[i] = a;
            dpd[i] = a;
        }

        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(h[i] < h[j]){
                    dpi[j] = max(dpi[j], w[j] + dpi[i]);
                }else if(h[i] > h[j]){
                    dpd[j] = max(dpd[j], w[j] + dpd[i]);
                }
            }
        }

        int ma = 0, mi = 0;

        for(int i = 0; i < n; i++){
            ma = max(ma, dpi[i]);
            mi = max(mi, dpd[i]);
        }

        if(ma > mi){
            printf("Increasing (%d). Decreasing(%d).\n", ma, mi);
        }else{
            printf("Decreasing(%d). Increasing (%d).\n", mi, ma);
        }

    }

    return 0;
}
