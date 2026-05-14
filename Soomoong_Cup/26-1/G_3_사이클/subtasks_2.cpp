#include <iostream>
#include <vector>
using namespace std;

vector <int> adj[201010];
bool v[201010]; int n;

void clear(){
    for(int i = 1;i <= n;i++){
        adj[i].clear();
        v[i] = 0;
    }
}

int dfs(int cur, int pre){
    int ret = 0;
    if(adj[cur].size() == 2) return ret = 1;
    else if(adj[cur].size() != 3) return ret = 0;
    v[cur] = 1;

    for(auto& nxt : adj[cur]){
        if(nxt == pre) continue;
        ret += dfs(nxt, cur);
    }

    return ret;
}

void solve(){
    cin >> n; clear();

    long long result = 0; 
    for(int i = 1;i < n;i++){
        int s, e; cin >> s >> e;
        adj[s].push_back(e);
        adj[e].push_back(s);
    }

    for(int i = 1;i <= n;i++) {
        if(v[i]) continue;
        if(adj[i].size() != 3) continue;
        long long cnt = dfs(i, 0);
        result += (cnt * (cnt - 1)) / 2;
    }

    cout << result << "\n";
}

int main(){
    int t; cin >> t;
    for(int i = 1;i <= t;i++) solve();

    return 0;
}