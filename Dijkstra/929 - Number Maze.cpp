#include <bits/stdc++.h>
#define MAXN 1000+10
#define INF 0x3f3f3f3f

using namespace std;

int dir[4][2] = {1, 0, 0, 1, 0, -1, -1, 0};
int G[MAXN][MAXN];
int dis[MAXN][MAXN];
int n = 0, m = 0;

struct node{
    int x, y, now;
    bool operator<(const node &a)const{
        return a.now < now;
    }
};

void dijkstra(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            dis[i][j] = INF;
        }
    }
    priority_queue<node> pq;
    dis[0][0] = G[0][0];
    pq.push((node){0, 0, dis[0][0]});
    node tmp;
    int X, Y;

    while(!pq.empty()){
        tmp = pq.top(); pq.pop();
        if(tmp.now > dis[tmp.x][tmp.y]) continue;
        for(int i = 0; i < 4; i++){
            X = tmp.x + dir[i][0];
            Y = tmp.y + dir[i][1];
            if(X >= 0 && X < n && Y >= 0 && Y < m && dis[X][Y] > tmp.now+G[X][Y]){
                dis[X][Y] = tmp.now + G[X][Y];
                pq.push((node){X, Y, dis[X][Y]});
            }
        }
    }
    printf("%d\n", dis[n-1][m-1]);

}

int main(){
    int kase = 0;
    scanf("%d", &kase);
    while(kase--){
        scanf("%d%d", &n, &m);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                scanf("%d", &G[i][j]);
            }
        }
        dijkstra();
    }


    return 0;
}
