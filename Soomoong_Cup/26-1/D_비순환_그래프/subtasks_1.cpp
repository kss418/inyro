#include <iostream>
using namespace std;

bool adj[1005][1005];
bool visit[1005];
int n, m, result;
void clear(){
    result = 0;
    for(int i = 1;i <= n;i++){
        visit[i] = 0;
        for(int j = 1;j <= n;j++) adj[i][j] = 0;
    }
}

void dfs(int cur){
    if(visit[cur]) return;
    visit[cur] = 1;

    for(int nxt = 1;nxt <= n;nxt++){
        if(adj[cur][nxt] == 0) continue;
        adj[cur][nxt] = adj[nxt][cur] = 0;
        if(visit[nxt]) result++;
        else dfs(nxt);
    }
}

void solve(){
    cin >> n >> m;
    clear();

    for(int i = 1;i <= m;i++){
        int s, e; cin >> s >> e;
        adj[s][e] = adj[e][s] = 1;
    }

    for(int i = 1;i <= n;i++){
        if(visit[i]) continue;
        dfs(i);
    }

    cout << result << "\n";
}

int main(){
    int t; cin >> t;
    for(int i = 1;i <= t;i++) solve();

    return 0;
}
