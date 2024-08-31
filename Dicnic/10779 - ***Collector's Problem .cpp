// dinic

#include <iostream>
#include <queue>
#include <CString>
#include <vector>

using namespace std;

#define maxn 50+5
#define INF  0x3f3f3f3f

struct Edge
{
    int from, to, cap, flow;
};

int n, m, s, t;
vector<Edge> edges;
vector<int> G[maxn];
bool visited[maxn];
int d[maxn];
int cur[maxn];
int own[maxn][maxn];

void AddEdge(int from, int to, int cap)
{
    edges.push_back((Edge) {from, to, cap, 0});
    m=edges.size();
    G[from].push_back(m-1);
}

bool BFS()
{
    memset(visited, false, sizeof(visited));
    queue<int> Q;
    Q.push(s);
    d[s]=0;
    visited[s]=true;

    while(!Q.empty())
    {
        int x=Q.front();
        Q.pop();

        for(int i=0; i<G[x].size(); i++)
        {
            Edge e=edges[G[x][i]];
            if ( !visited[e.to] && (e.cap>e.flow) )
            {
                visited[e.to]=true;
                d[e.to]=d[x]+1;
                Q.push(e.to);
            }
        }
    }
    return(visited[t]);
}

int DFS(int x, int a)
{
    if(x==t || a==0)
        return a;

    int flow=0, f;

    for (int& i=cur[x]; i<G[x].size(); i++)
    {
        Edge& e=edges[G[x][i]];
        if(d[e.to]==(d[x]+1))
        {
            if ((f=DFS(e.to, min(a, e.cap-e.flow)))>0)
            {
                e.flow+=f;
                flow+=f;
                a-=f;
                if(a==0) break;
            }
        }
    }
    return flow;
}

int dinic_Maxflow(int s, int t)
{
    int max_flow=0;

    while(BFS())
    {
        memset(cur, 0, sizeof(cur));
        max_flow+=DFS(s, INF);
    }
    return max_flow;
}

int main()
{
    freopen("d:\\10779_in.txt", "r", stdin);
    freopen("d:\\10779_out_t.txt", "w", stdout);

    int T;
    scanf("%d", &T);
    int Cas=1;

    while (T-->0)
    {
        int n, m;
        scanf("%d %d", &n, &m);

        s=0, t=n+m;

        for (int i=0; i<maxn; i++)
            G[i].clear();

        memset(own, 0, sizeof(own));

        for(int i=0; i<n; i++)
        {
            int num;
            scanf("%d", &num);
            while(num--)
            {
                int j;
                scanf("%d", &j);
                own[i][j]++;
            }
        }

        for(int j=1; j<=m; j++)
            if (own[0][j]!=0)
                AddEdge(0, n+j-1, own[0][j]);

        for(int i=1; i<n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(own[i][j]>1)
                    AddEdge(i, n+j-1, own[i][j]-1);
                else if(!own[i][j])
                    AddEdge(n+j-1, i, 1);
            }
        }

        for(int i=n; i<n+m; i++)
            AddEdge(i, t, 1);

        printf("Case #%d: %d\n",Cas++ ,dinic_Maxflow(s, t));
    }

    return 0;
}
