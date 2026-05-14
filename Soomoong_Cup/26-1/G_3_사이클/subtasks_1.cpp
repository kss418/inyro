#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

vector <int> adj[202];
bool flag;
int ind[202], n;

void clear(){
    for(int i = 1;i <= n;i++) adj[i].clear();
    memset(ind, 0, sizeof(ind));
}

vector <int> arr;
void dfs(int cur, int pre, int e){
    if(cur == e){ flag = 1; return; }
    arr.push_back(cur);

    for(auto& nxt : adj[cur]){
        if(pre == nxt) continue;
        if(flag) return;
        dfs(nxt, cur, e);
    }

    if(flag) return;
    arr.pop_back();
}

int chk(int s, int e){
    arr.clear(); flag = 0;
    arr.push_back(s);
    dfs(e, s, s);

    if(!flag) return 0;
    for(auto& i : arr){
        if(i == s || i == e){
            if(ind[i] != 2) return 0;
        }
        else if(ind[i] != 3) return 0;
    }

    return 1;
}

void solve(){
    cin >> n; clear();

    int result = 0; 
    for(int i = 1;i < n;i++){
        int s, e; cin >> s >> e;
        adj[s].push_back(e);
        adj[e].push_back(s);
        ind[s]++; ind[e]++;
    }

    for(int i = 1;i <= n;i++){
        for(int j = i + 1;j <= n;j++) result += chk(i, j);
    }

    cout << result << "\n";
}

int main(){
    int t; cin >> t;
    for(int i = 1;i <= t;i++) solve();

    return 0;
}