#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n = 0, a = 0, b = 0;
    string s, ans;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        cin >> a >> b;
        for(int k = 0; k < b; k++)
        {
            cin >> s;
            if(k == 0){
                ans = s;
                continue;
            }
            for(int j = s.size(); j >= 0; j--)
            {
                if(s.substr(0, j) == ans.substr(ans.size()-j))
                {
                    ans += s.substr(j);
                    break;
                }
            }
        }

        cout << ans.size() << endl;
    }

    return 0;
}
