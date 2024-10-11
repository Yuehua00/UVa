#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s1, s2;
    int n = 0;
    while(scanf("%d", &n) != EOF){
        stack<string> s;
        while(n--){
            cin >> s1;
            if(s1 == "Sleep"){
                cin >> s2;
                s.push(s2);
            }else if(s1 == "Kick" && !s.empty()){
                s.pop();
            }else if(s1 == "Test"){
                if(s.empty()) cout << "Not in a dream\n";
                else cout << s.top() << endl;
            }
        }
    }

    return 0;
}
/*
20
Sleep Dom
Sleep Sakin
Test
Sleep Asif
Sleep Mushfiq
Test
Kick
Test
Sleep Shafi
Test
Kick
Test
Kick
Test
Kick
Test
Kick
Test
Kick
Test
*/
