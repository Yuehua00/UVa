#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#define MAXN 1000

using namespace std;

struct eng{
    char c;
    int num;

    bool operator<(const eng& a) const{
        return (a.num < num) || (a.num == num && a.c > c);
    }
};

int dir[4][2] = {0, 1, 0,  -1, 1, 0, -1, 0};
bool vis[MAXN][MAXN];
char G[MAXN][MAXN];
int ans[26+5];
vector<eng> fin_ans;
int t = 0, h = 0, w = 0, a = 0, b = 0;

bool inside(int x, int y){
    return (x >= 0) && (x < h) && (y >= 0) && (y < w);
}

void dfs(int x, int y){
    vis[x][y] = true;
    for(int i = 0; i < 4; i++){
        a = x + dir[i][0];
        b = y + dir[i][1];
        if(inside(a, b) && !vis[a][b] && G[a][b] == G[x][y]){
            dfs(a, b);
        }
    }
}

int main()
{
    scanf("%d", &t);
    for(int z = 1; z <= t; z++){
        for(int i = 0; i < MAXN; i++){
            for(int j = 0; j < MAXN; j++){
                vis[i][j] = false;
            }
        }
        fin_ans.clear();
        memset(ans, 0, sizeof(ans));
        printf("World #%d\n", z);
        scanf("%d%d", &h, &w);

        for(int i = 0; i < h; i++){
            scanf("%s", &G[i]);
        }
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                if(!vis[i][j]){
                    dfs(i, j);
                    ans[G[i][j]-'a']++;
                }
            }
        }
        eng tmp;
        for(int i = 0; i < 26; i++){
            if(ans[i]){
                tmp.c = i+'a';
                tmp.num = ans[i];
                fin_ans.emplace_back(tmp);
            }
        }
        sort(fin_ans.begin(), fin_ans.end());
        for(auto i : fin_ans){
            printf("%c: %d\n", i.c, i.num);
        }
    }

    return 0;
}
