#include <iostream>
#include <string>
using namespace std;

const int maxn = 101;
const int INF  = 9999999;
int dis[maxn];
bool flag[maxn];

int n, m, cnt;

int head[maxn];
struct E{
    int to, w, next;
}e[maxn];

void add(int u, int v, int w){
    e[++cnt].next = head[u];
    e[cnt].to = v;e[cnt].w = w;
    head[u] = cnt;
}

void Init(){
    cnt = 0;
    memset(dis, INF, sizeof(dis));
    memset(flag, false, sizeof(flag));
    memset(head,-1, sizeof(head));
    cin >> n >> m;
    int u,v,w;
    for(int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        add(u, v, w);
    }


}

void Dijstra(int u){
    for(int i = head[u]; i!=-1; i=e[i].next)
        dis[e[i].to] = e[i].w;

    dis[u] = 0;
    flag[u] = true;
    for(int i = 0; i < n; i++){
        int temp = INF, t = u;
        for(int v = 0; v < n; v++)
            if(!flag[v]&&temp>dis[v])
            {
                temp=dis[v];t=v;
            }

        if(t==u)return;
        flag[t] = true;
        for(int v = head[t]; v!=-1; v=e[v].next)
            dis[e[v].to] = min(dis[e[v].to],dis[t]+e[v].w);

    }

}




int main(){
    Init();
    Dijstra(0);
    for(int i = 0; i < n; i++)
       cout << dis[i] << " ";
    cout << endl;

    return 0;
}
/*
5 8
0 1 2
0 2 5
1 2 2
1 3 6
2 3 7
3 2 2
3 4 4
2 4 1
 */