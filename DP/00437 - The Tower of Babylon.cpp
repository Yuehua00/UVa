#include <bits/stdc++.h>
#define MAXN 30*6+10

using namespace std;

struct Block{
    int x, y, z;
    bool operator<(const Block& a)const{
        return x > a.x || (x == a.x && y > a.y) || (x == a.x && y == a.y && z > a.z);
    }
};

vector<Block> block;
int dp[MAXN];

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n = 0, ans = 0, kase = 1;
    int a[3];
    while(scanf("%d", &n) != EOF && n){
        memset(dp, 0, sizeof(dp));
        block.clear(); ans = 0;
        for(int i = 0; i < n; i++){
            scanf("%d%d%d", &a[0], &a[1], &a[2]);
            sort(a, a+3);
            do{
                block.emplace_back((Block){a[0], a[1], a[2]});
            }while(next_permutation(a, a+3));
        }
        sort(block.begin(), block.end());
        for(int i = 0; i < block.size(); i++){
            dp[i] = block[i].z;
            for(int j = 0; j < i; j++){
                if(block[j].x > block[i].x && block[j].y > block[i].y){
                    dp[i] = max(dp[i], dp[j] + block[i].z);
                }
                ans = max(ans, dp[i]);
            }
        }
        printf("Case %d: maximum height = %d\n", kase++, ans);
    }

    return 0;
}

/*
題目 : 給出 n 種積木，求疊在一起最高高度。積木不限數量，但 x 和 y 都需大於下方積木才能疊。
解法 : 將積木不同面放入 block ，排序由 x -> y -> z(高度有沒有排不影響)
       dp[i] 代表 第 i 個積木放在最上面的最大高度 
*/
