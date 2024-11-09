#include <bits/stdc++.h>
#define MAXN 100000+10

using namespace std;

int next_arr[MAXN];
string str;
string reverse_str;
int n = 0;

void build(){
    int j = 0;
    next_arr[0] = -1;
    for(int i = 1; i < n; i++){
        j = next_arr[i-1];
        while((reverse_str[i] != reverse_str[j+1]) && j >= 0) j = next_arr[j];
        if(reverse_str[i] == reverse_str[j+1]) next_arr[i] = j+1;
        else next_arr[i] = -1;
    }
}

int KMP(){
    int i = 0, j = i+1;
    while(i < n){
        if(reverse_str[j] == str[i]){
            i++;
            j++;
        }else if(j <= 0){
            i++;
        }else{
            j = next_arr[j-1]+1;
        }
    }
    return j;
}

int main()
{
    while(cin >> str){
        reverse_str = str;
        reverse(reverse_str.begin(), reverse_str.end());
        n = str.length();
        build();
        int len = KMP();
        cout << str << reverse_str.substr(len) << endl;
    }

    return 0;
}

/*
題目 : 在結尾增加自，使字串變成迴文
解法 : 
  1. KMP 找尾端開始字串最長迴文 -> KMP 加速
      用 原字串 與 reverse 的字串比對
  2. 輸出 原字串 與 剩餘的 reverse 字元
*/
