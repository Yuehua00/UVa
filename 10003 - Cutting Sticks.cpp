// DP
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define maxn 1000+10
#define INF 0x3f3f3f3f

int cut[maxn], dp[maxn][maxn];
int length, n;

int d(int l, int r)
{
    if((r-l)==1)
        return 0;

    if(dp[l][r]>0)
        return dp[l][r];

    dp[l][r]=INF;

    for(int i=l; i<=r; i++)
    {
        dp[l][r]=min(dp[l][r], d(l, i)+d(i, r) + (cut[r]-cut[l]));
    }
    return dp[l][r];
}

int main()
{
    //freopen("d:\\10003_in.txt", "r", stdin);
    //freopen("d:\\10003_tout.txt", "w", stdout);

    while(scanf("%d", &length) && length)
    {
        scanf("%d",&n);
        for(int i=1; i<=n; i++)
            scanf("%d", &cut[i]);

        cut[0]=0; cut[n+1]=length;

        memset(dp, 0, sizeof(dp));
        int ans=d(0, n+1);

        printf("The minimum cutting is %d.\n", ans);
    }
    return 0;
}
