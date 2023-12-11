// UVa : https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2456
// 中文題目 : https://zerojudge.tw/ShowProblem?problemid=d186

#include <iostream>
#include <string.h>
#include <cmath>

using namespace std;

int main()
{
    int n = 0, m = 0;
    int nc = 0, mc = 0;
    
    while(cin >> n >> m && n != 0){
        nc = 0; mc = 0;
            for(int i = 1; i <= sqrt(n); i++){
                if(i*i < n){
                    nc++;
                }
            }
            for(int i = 1; i <= sqrt(m); i++){
                if(i*i <= m){
                    mc++;
                }
            }

        
        cout << mc - nc << endl;

    }

	return 0;
}
