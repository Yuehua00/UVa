#include <iostream>
#include <vector>
#include <string.h>
#define MAXN 100000+10

using namespace std;

int kase = 0, n = 0, a = 0, s = 0, maxn = 0, now = 0;
int arr[MAXN], arr2[MAXN];

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    scanf("%d", &kase);
    for(int i = 1; i <= kase; i++){
        memset(arr, 0, sizeof(arr));
        memset(arr2, 0, sizeof(arr2));
        maxn = 0; s = 0;
        scanf("%d", &n);
        for(int j = 1; j <= n; j++){
            scanf("%d", &arr[j]);
            if(j) arr2[++s] = arr[j] - arr[j-1];
            maxn = max(maxn, arr2[s]);
        }
        now = maxn;
        for(int j = 1; j <= s; j++){
            if(arr2[j] == now) now--;
            else if(arr2[j] > now){
                maxn++;
                break;
            }
        }

        printf("Case %d: %d\n", i, maxn);
    }

    return 0;
}
