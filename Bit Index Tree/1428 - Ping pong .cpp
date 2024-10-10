#include <iostream>
#include <string.h>
#define MAXN 20000+10
#define lowbit(x) ((x) & (-x))

using namespace std;

int people[MAXN], left_big[MAXN], right_big[MAXN], bit[100001];

int sum(int x){
    int ret = 0;
    while(x > 0){
        ret += bit[x];
        x -= lowbit(x);
    }
    return ret;
}

void add(int x, int b){
    while(x < 100001){
        bit[x] += b;
        x += lowbit(x);
    }
}

int main()
{
    int kase = 0, n = 0;
    scanf("%d", &kase);
    while(kase--){
        scanf("%d", &n);
        for(int i = 1; i <= n; i++){
            scanf("%d", &people[i]);
        }
        memset(bit, 0, sizeof(bit));
        for(int i = 1; i <= n; i++){
            add(people[i], 1);
            left_big[i] = sum(people[i]-1);
        }
        memset(bit, 0, sizeof(bit));
        for(int i = n; i > 0; i--){
            add(people[i], 1);
            right_big[i] = sum(people[i]-1);
        }
        long long int ans = 0;
        for(int i = 1; i <= n; i++){
            ans += left_big[i] * (n-i-right_big[i]) + (i-1-left_big[i])*right_big[i];
        }
        printf("%lld\n", ans);

    }

    return 0;
}
