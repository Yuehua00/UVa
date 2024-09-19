#include <iostream>
#include <vector>

using namespace std;

int n = 0, m = 0, a = 0;
vector<int> people;
int maxn = 0, ans = 0;

int main()
{
    scanf("%d", &n);
    while(n--){
        people.clear();

        scanf("%d", &m);
        for(int i = 0; i < m; i++){
            scanf("%d", &a);
            people.emplace_back(a);
        }
        
        maxn = people[0];
        ans = people[0] - people[1];
        for(int i = 1; i < people.size(); i++){
            ans = max(ans, maxn - people[i]);
            maxn = max(maxn, people[i]);
        
        }

        printf("%d\n", ans);

    }

    return 0;
}
