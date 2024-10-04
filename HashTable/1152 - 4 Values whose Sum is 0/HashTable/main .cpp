#include <bits/stdc++.h>
#define MAXN 5000
#define hashsize 10000007

using namespace std;

int arr[4][MAXN];
int ab[MAXN*MAXN];
int head[hashsize];
int next_o[MAXN*MAXN];

void init(){
    memset(ab, 0, sizeof(ab));
    memset(head, -1, sizeof(head));
    memset(next_o, -1, sizeof(next_o));
}

void insert_(int x){
    int idx = abs(ab[x]) % hashsize;
    next_o[x] = head[idx];
    head[idx] = x;
}

int to_find(int x){
    int idx = abs(x) % hashsize;
    int u = head[idx];
    int num = 0;
    while(u != -1){
        if(ab[u] == x) num++;
        u = next_o[u];
    }
    return num;
}

int main()
{
    int kase = 0, m = 0;
    bool line = false;
    scanf("%d", &kase);
    while(kase--){
        init();
        if(line) printf("\n");
        line = true;
        scanf("%d", &m);
        for(int j = 0; j < m; j++){
            for(int i = 0; i < 4; i++){
                scanf("%d", &arr[i][j]);
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < m; j++){
                ab[i*m+j] = arr[0][i] + arr[1][j];   // i*m+j : 將陣列攤平，變成一維
                insert_(i*m+j);
            }
        }
        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < m; j++){
                ans += to_find(-(arr[2][i]+arr[3][j]));  // 中途相遇法 -> a+b+c+d = 0 -> a+b = -(c+d)
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}
