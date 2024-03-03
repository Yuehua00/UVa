// 參考 : https://theriseofdavid.github.io/2020/10/09/UVa/UVa11362/
#include <iostream>
#define MAX_SIZE 1000005

using namespace std;

int cnt = 0;
struct TrieNode{
    int children[15];
    bool isLeaf = false;

    void reset(){
        for(int i = 0; i < 15; i++){
            children[i] = -1;
        }
        isLeaf = false;
    }
}trie[MAX_SIZE];

bool insert(string s){
    int cur = 0;
    for(int i = 0; i < (int)s.length(); i++){
        int c = s[i] - '0';
        if(trie[cur].children[c] == -1 ){ //代表節點沒有被新增
            trie[cnt].reset();            //先重新設定節點，以免舊資料也加入
            trie[cur].children[c] = cnt ; //連接到下一層的 node
            cur = cnt++ ;                 //增加陣列長度
        }else{
            cur = trie[cur].children[c];
            if(trie[cur].isLeaf || i == (int)s.length()-1) return false;
        }
    }
    trie[cur].isLeaf = true;
    return true;
}

int main()
{
    int n = 0, m = 0;
    bool ans = true;
    string input;
    scanf("%d", &n);
    while(n--){
        cnt = 1;
        trie[0].reset();
        scanf("%d", &m);
        for(int i = 0; i < m; i++){
            cin >> input;
            if(!ans) continue;
            ans = insert(input);
            if(!ans){
                printf("NO\n");
            }
        }
        if(ans){
            printf("YES\n");
        }
        ans = true;

    }


    return 0;
}
