// UVa : https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=54
// 中文題目 : https://zerojudge.tw/ShowProblem?problemid=c082

#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    int nowx = 0, nowy = 0;
    char dir;
    string s;
    int x = 0, y = 0;
    bool lost = false;
    scanf("%d%d", &x, &y);
    int arr[x+5][y+5];
    memset(arr, 0, sizeof(arr));
    while(cin >> nowx >> nowy >> dir){
        lost = false;
        cin >> s;
        for(int i = 0; i < s.length(); i++){
            if(dir == 'E'){
                if(s[i] == 'R'){
                    dir = 'S';
                }else if(s[i] == 'L'){
                    dir = 'N';
                }else{
                    int tmp = nowx + 1;
                    if(tmp <= x){
                        nowx++;
                    }else if(tmp > x && arr[nowx][nowy] == 0){
                        lost = true;
                        break;
                    }
                }
            }else if(dir == 'W'){
                if(s[i] == 'R'){
                    dir = 'N';
                }else if(s[i] == 'L'){
                    dir = 'S';
                }else{
                    int tmp = nowx - 1;
                    if(tmp >= 0){
                        nowx--;
                    }else if(tmp < 0 && arr[nowx][nowy] == 0){
                        lost = true;
                        break;
                    }

                }
            }else if(dir == 'N'){
                if(s[i] == 'R'){
                    dir = 'E';
                }else if(s[i] == 'L'){
                    dir = 'W';
                }else{
                    int tmp = nowy + 1;
                    if(tmp <= y){
                        nowy++;
                    }else if(tmp > y && arr[nowx][nowy] == 0){
                        lost = true;
                        break;
                    }
                }
            }else if(dir == 'S'){
                if(s[i] == 'R'){
                    dir = 'W';
                }else if(s[i] == 'L'){
                    dir = 'E';
                }else{

                    int tmp = nowy - 1;
                    if(tmp >= 0){
                        nowy--;
                    }else if(tmp < 0 && arr[nowx][nowy] == 0){
                        lost = true;
                        break;
                    }
                }
            }
            if(lost){
                break;
            }

        }
        if(lost){
            arr[nowx][nowy] = 1;
            printf("%d %d %c LOST\n", nowx, nowy, dir);
        }else{
            printf("%d %d %c\n", nowx, nowy, dir);
        }
    }

    return 0;
}
