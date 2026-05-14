#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int MINF = -2e9;

int a[255][255], dp[505][255][255];
int solve(int ti, int x1, int x2){
    if(x1 <= 0 || x2 <= 0) return MINF;

    int& ret = dp[ti][x1][x2];
    if(ret != -1) return ret; ret = MINF;
    if(ti == 2) return ret = (x1 == 1 && x2 == 1) ? 0 : MINF;

    ret = max(ret, solve(ti - 1, x1, x2));
    ret = max(ret, solve(ti - 1, x1 - 1, x2));
    ret = max(ret, solve(ti - 1, x1, x2 - 1));
    ret = max(ret, solve(ti - 1, x1 - 1, x2 - 1));

    return ret += abs(a[x1][ti - x1] - a[x2][ti - x2]);
}

void solve(){
    int n; cin >> n;
    for(int i = 1;i <= 2 * n;i++){
        for(int j = 1;j <= n;j++){
            for(int k = 1;k <= n;k++) dp[i][j][k] = -1;
        }
    }

    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++) cin >> a[i][j];
    }

    cout << solve(2 * n, n, n) << "\n";
}

int main(){
    int t; cin >> t;
    for(int i = 1;i <= t;i++) solve();

    return 0;
}
