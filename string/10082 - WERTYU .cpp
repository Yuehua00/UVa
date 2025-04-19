#include <iostream>

using namespace std;

int main()
{
    string s = "1234567890-=QWERTYUIOP[]\ASDFGHJKL;'ZXCVBNM,./";
    string in;
    int j = 0;

    while(getline(cin, in)){
        for(int i = 0; i < in.length(); i++){
            for(j = 1; j < s.length() && in[i] != s[j]; j++);
            if(s[j]) cout << s[j-1];
            else cout << in[i];
        }
        cout << endl;
    }

    return 0;
}

/*
鍵盤上字元往左一格輸出
*/
