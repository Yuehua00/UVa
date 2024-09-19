#include <iostream>
#include <string.h>
#define MAXN 100000+10

using namespace std;

int n = 0, m = 0, cnt = 0, tmp = 0;
int ans[MAXN];

int main()
{
    while(scanf("%d%d", &n, &m) != EOF && (n && m)){
        memset(ans, 0, sizeof(ans));
        getchar();
        cnt = 1;

        if(n == m){
            printf("0\n");
            continue;
        }
        for(int i = 0; i < n; i++){
            tmp = getchar() - '0';
            while(cnt && n-i+cnt > (n-m) && tmp > ans[cnt-1]) cnt--;
            if(cnt < (n-m)) ans[cnt++] = tmp;
        }

        for(int i = 0; i < (n-m); i++){
            printf("%d", ans[i]);
        }
        printf("\n");
    }

    return 0;
}
