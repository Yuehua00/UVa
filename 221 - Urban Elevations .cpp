// 用到 algorithm 的 unique

#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

const int maxn = 100+5;
int n = 0;

struct bulid{
    int id;
    int x, y, w, d, h;

    bool operator<(const bulid a) const{
        return a.x > x || (a.x == x && a.y > y);
    }
}b[maxn];

double x[maxn*2];   // 儲存建築物的左右兩個 x

bool cover_mx(int i, double mx){  // 建築物的 x 若包含 mx 則有機會被看到
    return b[i].x <= mx && mx <= b[i].x+b[i].w;
}

bool visible(int i, double mx){
    if(!cover_mx(i, mx)) return false;  // 不涵蓋 mx -> 沒機會看到
    for(int j = 0; j < n; j++){
        if(cover_mx(j, mx) && b[j].y < b[i].y && b[j].h >= b[i].h) return false;  
        // 有其他建築物在前面，且他也涵蓋 mx ，且高度比較高 -> 會擋住現在要驗證是否能看到的建築物
    }
    return true;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int casee = 0;
    while(scanf("%d", &n) != EOF && n){
        for(int i = 0; i < n; i++){
            scanf("%d%d%d%d%d", &b[i].x, &b[i].y, &b[i].w, &b[i].d, &b[i].h);
            b[i].id = i+1;
            x[i*2] = b[i].x;
            x[i*2+1] = b[i].x + b[i].w;
        }

        sort(b, b+n);
        sort(x, x+2*n);
        int m = unique(x, x+n*2)-x;  // x座標排序後去掉重複的，得到m個不同的x座標

        if(casee++) printf("\n");
        printf("For map #%d, the visible buildings are numbered as follows:\n%d", casee, b[0].id);

        for(int i = 1; i < n; i++){
            bool vis = false;
            for(int j = 0; j < m-1; j++){
                // m個不同的x座標存於陣列x,檢驗m-1個相鄰2個x值中點處, 看看建築物b[i]是否看的見
                if(visible(i, (x[j] + x[j+1])/2)){
                    vis = true;
                    break;
                }
            }
            if(vis) printf(" %d", b[i].id);
        }
        printf("\n");
    }

    return 0;
}
