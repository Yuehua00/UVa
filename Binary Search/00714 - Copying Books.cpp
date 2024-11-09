/* reference : https://programming-study-notes.blogspot.com/2014/01/uva-714-copying-books.html */
#include <bits/stdc++.h>
#define MAXN 500+10

using namespace std;

long long Min = 0, Max = 0, mid = 0;
int n = 0, m = 0, k = 0;
int book[MAXN], tmp[MAXN];
int ans[MAXN][MAXN];

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    scanf("%d", &n);
    while(n--){
        Min = 0; Max = 0;
        scanf("%d%d", &m, &k);
        for(int i = 0; i < m; i++){
            scanf("%d", &book[i]);
            if(book[i] > Min) Min = book[i];
            Max += book[i];
        }
        while(Min < Max){
            int cnt = 1;
            long long sum = 0;
            mid = (Min + Max) / 2;
            for(int i = 0; i < m; i++){
                if(sum + book[i] > mid){
                    cnt++;
                    sum = 0;
                }
                sum += book[i];
            }
            if(cnt > k) Min = mid + 1;
            else Max = mid;
        }
        memset(tmp, 0, sizeof(tmp));
        long long sum = 0;
        for(int i = m-1, j = k-1; i >= 0; i--){
            if(sum + book[i] > Max || j > i){
                j--;
                sum = 0;
            }
            sum += book[i];
            ans[j][tmp[j]++] = book[i];
        }
        for (int i = 0; i < k; i++){
            for (int j=tmp[i]-1; j>=0; j--){
                if (i!=0 || j!=tmp[0]-1) printf(" ");
                printf("%d",ans[i][j]);
            }
            if (i != k-1) printf(" /");
        }
        printf("\n");

    }

    return 0;
}
