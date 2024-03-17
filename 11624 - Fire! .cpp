#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};

struct state{
    state(int x, int y, int id, int step) : x(x), y(y), id(id), step(step){}

    int x, y;
    int id;
    int step;
};

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n = 0, a = 0, b = 0, px = 0, py = 0, fx = 0, fy = 0;
    scanf("%d", &n);
    while(n--){
        scanf("%d%d", &a, &b);
        char arr[a+5][b+5];
        int visit[a+5][b+5];
        memset(visit, 0, sizeof(visit));
        queue<state> q;
        for(int i = 0; i < a; i++){
            for(int j = 0; j < b; j++){
                cin >> arr[i][j];
                if(arr[i][j] == 'J'){
                    px = i;
                    py = j;
                }else if(arr[i][j] == 'F'){
                    fx = i;
                    fy = j;
                    q.push(state(fx, fy, 1, 0));
                    visit[fx][fy] = 1;
                }
            }
        }
        q.push(state(px, py, 0, 0));
        visit[px][py] = 1;

        bool success = false;
        int ans = 0;
        while(!q.empty() && !success){
            state s(0, 0, 0, 0);
            s = q.front();
            q.pop();
            for(int i = 0; i < 4; i++){
                int tmpx = s.x + dir[i][0];
                int tmpy = s.y + dir[i][1];


                if(!s.id && (tmpx < 0 || tmpx >= a || tmpy < 0 || tmpy >= b)){
                    ans = s.step + 1;
                    success = true;
                    break;
                }
                if(visit[tmpx][tmpy]){
                    continue;
                }
                if(arr[tmpx][tmpy] == '.'){
                    q.push(state(tmpx, tmpy, s.id, s.step+1));
                    visit[tmpx][tmpy] = 1;
                }
            }

        }
        if(success){
            printf("%d\n", ans);
        }else{
            printf("IMPOSSIBLE\n");
        }


    }

    return 0;
}
