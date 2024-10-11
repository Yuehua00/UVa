#include <bits/stdc++.h>
#define MAXN 100+10

using namespace std;

int prime[MAXN];
bool notPrime[MAXN];
int cnt_p[MAXN];
int cnt = 0;

void build_prime(){
    memset(notPrime, 0, sizeof(notPrime));
    prime[cnt++] = 2;
    for(int i = 3; i < MAXN; i++){
        if(!notPrime[i]){
            prime[cnt++] = i;
            for(int j = i*2; j < MAXN; j += i){
                notPrime[j] = 1;
            }
        }
    }
}

void solve(int n){
    memset(cnt_p, 0, sizeof(cnt_p));
    int tmp = 0, pt = 0;

    for(int i = 2; i <= n; i++){
        tmp = i;
        for(int j = 0; j < cnt; j++){
            while(tmp % prime[j] == 0){
                cnt_p[j]++;
                tmp /= prime[j];
                pt = max(pt, j);
            }
        }
    }
    printf("%3d! =", n);

    int countn = 0;
    for(int i = 0; i <= pt; i++){
        if(countn >= 15){
            countn = 0;
            printf("\n      ");
        }
        if(cnt_p[i]){
            printf("%3d", cnt_p[i]);
            countn++;
        }
    }
    printf("\n");

}

int main()
{
    build_prime();
    int n = 0;
    while(scanf("%d", &n) != EOF && n){
        solve(n);
    }

    return 0;
}
