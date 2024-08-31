// lef[i]、rig[i] 紀錄至左右大於 num[i] 的值
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#define MAXN 100000+5

using namespace std;

int lef[MAXN], rig[MAXN], num[MAXN];
long long int prefix[MAXN];

void reset(){
    memset(lef, 0, sizeof(lef));
    memset(rig, 0, sizeof(rig));
    memset(num, -1, sizeof(num));
    memset(prefix, 0, sizeof(prefix));
}

int main()
{
    int n = 0;
    bool line = false;
    while(scanf("%d", &n) != EOF){
        reset();
        if(line) printf("\n");
        line = true;

        for(int i = 1; i <= n; i++){
            scanf("%d", &num[i]);
            if(i == 1) prefix[i] = num[i];
            else prefix[i] = prefix[i-1] + num[i];
            lef[i] = rig[i] = i;
        }

        for(int i = n; i > 0; i--){
            while(rig[i] < n && num[rig[i]+1] >= num[i]){      // 沒有加 rig[i] < n -> WA
                rig[i] = rig[rig[i]+1];
            }
        }

        for(int i = 1; i <= n; i++){
            while(lef[i] > 1 && num[lef[i]-1] >= num[i]){     // 沒有加 lef[i] > 1 -> WA
                lef[i] = lef[lef[i]-1];
            }
        }

        long long int ans = 0, cmp = 0;
        int l = 1, r = 1;

        for(int i = 1; i <= n; i++){
            cmp = num[i] * (prefix[rig[i]] - prefix[lef[i]-1]);
            if(cmp > ans || (cmp == ans && ((r-l) > (rig[i]-lef[i])))) {
                ans = cmp;
                l = lef[i];
                r = rig[i];
            }
        }
        printf("%lld\n%d %d\n", ans, l, r);
    }

    return 0;
}
