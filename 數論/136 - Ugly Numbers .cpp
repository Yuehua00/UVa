#include <iostream>
#include <vector>
#include <algorithm>
typedef unsigned long long int ull;

using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    vector<ull> ans;
    ans.emplace_back(1);
    int a = 0, b = 0, c = 0;
    for(int i = 1; i < 1500+1; i++){
        while(ans[a] * 2 <= ans[i-1]) a++;
        while(ans[b] * 3 <= ans[i-1]) b++;
        while(ans[c] * 5 <= ans[i-1]) c++;

        ans.emplace_back(min(min(ans[a]*2, ans[b]*3), ans[c]*5));
    }

    printf("The 1500'th ugly number is %llu.\n",ans[1499]);

    return 0;
}
