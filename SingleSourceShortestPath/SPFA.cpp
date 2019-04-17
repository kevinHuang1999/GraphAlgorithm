#include <iostream>
#include <queue>
using namespace std;
const int maxn = 20005;
const int INF = 1000000;
struct edge{
    int x, y, cost, next;
}e[200005];
int head[maxn], dis[maxn];
int inq[maxn];
bool vis[maxn];
int n,m;
void add(int u,int v, int w, int cnt){
    e[cnt].x = u;e[cnt].y = v;e[cnt].cost=w;
    e[cnt].next=head[u];head[u]=cnt;
}

void SPFA(int s){

    dis[s] = 0;
    vis[s] = 1;
    queue<int>q;
    q.push(s);
    inq[s]++;
    while(!q.empty()){
        int u = q.front(); q.pop();
        vis[u] = 0;
        for(int i = head[u]; i!=-1; i=e[i].next){
            int v = e[i].y;
            if(dis[v] > dis[u] + e[i].cost && !vis[v])
            {
                dis[v] = dis[u] + e[i].cost;
                q.push(v);
                vis[v] = 1;

            }
        }
    }

}


int main(){

    scanf("%d%d",&n,&m);
    int u,v,w;

    for(int i = 1; i <= n; i++)
    {
        dis[i] = INF;
        vis[i] = 0;
        head[i]=-1;
        inq[i]  = 0;
    }
    for(int i = 0; i < m; i++)
    {
        scanf("%d%d%d",&u,&v,&w);
        add(u,v,w,i);
    }
    SPFA(1);

    for(int i = 2; i <= n; i++)
            printf("%d\n",dis[i]);
    return 0;
}
/*
3 3
1 2 -1
2 3 -1
3 1 2
 */