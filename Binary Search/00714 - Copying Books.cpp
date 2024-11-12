/* reference : https://programming-study-notes.blogspot.com/2014/01/uva-714-copying-books.html */
#include <bits/stdc++.h>
#define MAXN 500+10

using namespace std;

long long Min = 0, Max = 0, mid = 0;
int n = 0, m = 0, k = 0;
int book[MAXN];
vector<int> ans[MAXN];

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    scanf("%d", &n);
    while(n--){
        for(int i = 0; i < MAXN; i++) ans[i].clear();
        Min = 0; Max = 0;
        scanf("%d%d", &m, &k);
        for(int i = 0; i < m; i++){
            scanf("%d", &book[i]);
            if(book[i] > Min) Min = book[i];  // 紀錄書本中最大，可負荷量介於 書本最大 與 書本總和之間
            Max += book[i];
        }
        // 二分搜，找最大每人可負荷量
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
            if(sum + book[i] > Max || j > i){     // 超過可讀頁數 || 都給他有人會沒拿到
                j--;
                sum = 0;
            }
            sum += book[i];
            ans[j].emplace_back(book[i]);
        }
        for(int i = 0; i < k; i++){
            for(int j = ans[i].size()-1; j >= 0; j--){
                if(i || j < ans[i].size()-1) printf(" ");
                printf("%d", ans[i][j]);
            }
            if(i != k-1) printf(" /");
        }
        puts("");

    }

    return 0;
}
