#include <iostream>
#include <stack>
using namespace std;

void solve(){
    int n; cin >> n;

    int result = 0;
    stack <pair<int, int>> stk;
    for(int i = 1;i <= n;i++){
        int x, v; cin >> x >> v;
        result += v;
        if(!stk.empty() && stk.top().first == x){
            stk.top().second += v;
        } 
        else stk.push({x, v});

        while(!stk.empty() && stk.top().first <= stk.top().second){
            stk.top().second -= stk.top().first;
            result -= stk.top().first;
            if(!stk.top().second) stk.pop();
        }

        cout << result << "\n";
    }
}

int main(){
    int t; cin >> t;
    for(int i = 1;i <= t;i++) solve();

    return 0;
}
