#include <iostream>
#include <algorithm>

using namespace std;

int arr[1000+5];
int pos[1000+5];
int copyb[1000+5];
int b[1000+5];

void printarr(int a[], int n){
    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

int change(int a[], int n){
    int tmp_ans = 0, return_ans = n;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        cnt = 0;
        tmp_ans = 0;
        for(int j = i; j < i+n; j++){
            copyb[cnt] = a[j];
            b[a[j]] = cnt;
            cnt++;
        }
        //printarr(copyb, n);
        //printarr(b, n);
        for(int j = 0; j < n; j++){
            if(j != copyb[j]){
                int tmp = copyb[j], tmp_pos = b[j];
                swap(copyb[j], copyb[b[j]]);
                b[j] = j;
                b[tmp] = tmp_pos;
                tmp_ans++;
            }
            //printarr(copyb, n);
            //printarr(b, n);
        }
        //printf("\n");
        return_ans = min(return_ans, tmp_ans);
    }
    return return_ans;
}

int main()
{
    //freopen("10570.in", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int n = 0;
    while(scanf("%d", &n) != EOF && n){
        for(int i = 0; i < n; i++){
            scanf("%d", &arr[i]);
            arr[i]--;
            arr[n+i] = arr[i];
        }
        //printarr(arr, 2*n);
        //printarr(pos, n);

        int ans = change(arr, n);
        reverse(arr, arr+2*n);
        ans = min(ans, change(arr, n));

        printf("%d\n", ans);
    }

    return 0;
}
