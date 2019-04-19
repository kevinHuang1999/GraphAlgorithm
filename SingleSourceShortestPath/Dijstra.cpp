#include <iostream>
using namespace std;
const int maxn  = 1005;
const int INF = 1<<7;
int cost[maxn][maxn];
int dist[maxn],flag[maxn];
int p[maxn];
int n, m;

void Dijkstra(int u){
    for(int i = 0; i < n; i++){
        dist[i] = cost[u][i];
        flag[i] = false;
        if(dist[i] == INF)
            p[i] = -1;
        else
            p[i] = u;
    }

    dist[u] = 0;
    flag[u] = true;
    for(int i = 0; i < n; i++){
        int temp = INF, t = u;
        for(int j = 0; j < n; j++)
            if(!flag[j] && dist[j] < temp)
            {
                t = j;
                temp = dist[j];
            }
        if( t == u ) return;
        flag[t] = true;
        for(int j = 0; j < n; j++)
            if(!flag[j] && cost[t][j] < INF)
                if(dist[j] > dist[t] + cost[t][j])
                {
                    dist[j] = dist[t] + cost[t][j];
                    p[j] = t;
                }
    }

}


int main() {
    cin >> n >> m;
    memset(p, -1, sizeof(p));
    memset(dist, INF, sizeof(dist));
    memset(cost, INF, sizeof(cost));
    int u, v, c;
    for(int i = 0; i < m; i++){
        cin >> u >> v >> c;
        cost[u][v] = c;
    }

    Dijkstra(0);

    for(int i = 0; i < n; i++)
        cout << dist[i] << " ";

    return 0;
}