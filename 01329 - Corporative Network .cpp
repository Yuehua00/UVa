// 邊查詢父節點，邊計算
#include <iostream>
#include <string.h>
#define MAXN 200000+10

using namespace std;

int kase = 0, n = 0, a = 0, b = 0, ans = 0;
char c;
int pa[MAXN];

void init(){
    for(int i = 0; i < MAXN; i++){
        pa[i] = i;
    }
}

int find_pa(int x){
    int cnt = 0;
    if(x == pa[x]) return 0;
    while(x != pa[x]){
        cnt += abs(pa[x] - x) % 1000;
        x = pa[x];
    }
    return cnt;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    scanf("%d", &kase);
    while(kase--){
        init();
        scanf("%d", &n);
        while(scanf("%c", &c) && c != 'O'){
            if(c == 'E'){
                scanf("%d", &a);
                ans = find_pa(a);
                printf("%d\n", ans);
            }else if(c == 'I'){
                scanf("%d%d", &a, &b);
                pa[a] = b;
            }
        }
    }

    return 0;
}
