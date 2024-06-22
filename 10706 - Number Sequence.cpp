#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <cmath>
#define MAXN 1000000+5
#define INF 0x3f3f3f

using namespace std;

unsigned long long int num[MAXN];
unsigned long long int countn[MAXN];
unsigned long long int sum[MAXN];

void setnum(){
    int a = 1;
    for(int i = 1; i < MAXN; i++){
        if(i == pow(10, a)){
            a++;
        }
        num[i] = a;
    }
}

void setcountn(){
    countn[0] = 0;
    for(int i = 1; i < MAXN; i++){
        countn[i] = countn[i-1] + num[i];
    }
}

void setsum(){
    sum[0] = 0;
    for(int i = 1; i < MAXN; i++){
        sum[i] = sum[i-1] + countn[i];
    }
}

int main()
{
    setnum();
    setcountn();
    setsum();

    unsigned long long int n = 0, kase = 0;
    scanf("%lld", &kase);
    while(kase--){
        scanf("%lld", &n);

        int l = 0, r = MAXN, mid = 0;
        while(l <= r){    // 二分搜
            mid = (l+r) / 2;
            if(sum[mid-1] < n && sum[mid] >= n) break;
            else if(n > sum[mid]) l = mid + 1;
            else if (n < sum[mid]) r = mid - 1;
        }

        unsigned long long int cnt = sum[mid], ans = mid;
        while(cnt > n && cnt - num[ans] >= n){   
            // 表示 n  != 一組數字最尾數，需要找到明確在哪組內(哪個數字範圍中)
            cnt -= num[ans];
            ans--;
        }
        char number[1000000];
        int cntt = 0;
        while(ans > 9){              // 將數字轉成陣列
            number[cntt] = ans % 10;
            ans /= 10;
            cntt++;
        }
        if(ans > 0) number[cntt] = ans;
        else cntt--;

        printf("%c\n", number[(cnt-n)]+'0');

    }

    return 0;
}
