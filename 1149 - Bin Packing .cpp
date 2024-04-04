// greedy

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int n = 0, len = 0, m = 0, a = 0;
    vector<int> item;
    scanf("%d", &n);
    while(n--){
        item.clear();
        scanf("%d%d", &m, &len);

        for(int i = 0; i < m; i++){
            scanf("%d", &a);
            item.emplace_back(a);
        }
        sort(item.begin(), item.end());
        int l = 0, r = item.size()-1;
        int ans = 0;

        while(l < r){
            if(item[r-1] + item[r] <= len){
                r -= 2;
            }else if(item[l] + item[r] <= len){
                l++;
                r--;
            }else {
                r--;
            }
            ans++;
        }
        if(l == r){
            ans++;
        }

        printf("%d\n", ans);
        if(n) printf("\n");
    }


    return 0;
}
/*
1
10
80
70
15
30
35
10
80
20
35
10
30
*/
