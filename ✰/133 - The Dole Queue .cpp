#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#define MAXN 10000

using namespace std;

int total = 0, n = 0, m = 0;
int number[MAXN];
int visited[MAXN];
int check = 0;

int main()
{
    while(scanf("%d%d%d", &total, &n, &m) != EOF && total){
        memset(visited, 0, sizeof(visited));
        for(int i = 1; i <= total; i++){
            number[i] = i;
        }
        check = 0;

        int now_n = 0, now_m = total+1;
        bool first = true;
        while(check != total){
            if(!first){
                printf(",");
            }
            first = false;
            int cnt = 0;
            while (cnt < n) {
                now_n++;
                if (now_n > total) now_n = 1;
                if (!visited[now_n]) cnt++;
            }

            cnt = 0;
            while (cnt < m) {
                now_m--;
                if (now_m < 1) now_m = total;
                if (!visited[now_m]) cnt++;
            }

            if(now_n != now_m){
                printf("%3d%3d", number[now_n], number[now_m]);
                visited[now_n] = visited[now_m] = 1;
                check += 2;
            } else{
                printf("%3d", number[now_n]);
                visited[now_n] = 1;
                check++;
            }

        }
        puts("");
    }

    return 0;
}
/*
一個順時針，一個逆時針，用各自的規律走，走過的就消除，直到 total 數字都走過
*/
