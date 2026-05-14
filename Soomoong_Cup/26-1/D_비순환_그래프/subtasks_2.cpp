#include <iostream>
#include <vector>
using namespace std;

vector <int> adj[201010];
bool visit[201010];
void clear(int n){
    for(int i = 1;i <= n;i++){
        visit[i] = 0;
        adj[i].clear();
    }
}

void dfs(int cur){
    if(visit[cur]) return;
    visit[cur] = 1;

    for(auto& nxt : adj[cur]) dfs(nxt);
}

void solve(){
    int n, m; cin >> n >> m;
    clear(n);

    for(int i = 1;i <= m;i++){
        int s, e; cin >> s >> e;
        adj[s].push_back(e);
        adj[e].push_back(s);
    }

    int component = 0;
    for(int i = 1;i <= n;i++){
        if(visit[i]) continue;
        dfs(i); component++;
    }

    cout << max(m - n + component, 0) << "\n";
}

int main(){
    int t; cin >> t;
    for(int i = 1;i <= t;i++) solve();

    return 0;
}