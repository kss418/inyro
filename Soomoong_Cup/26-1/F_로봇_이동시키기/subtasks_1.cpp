#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int MINF = -2e9;

int a[55][55], dp[55][55][55][55];
int solve(int x1, int y1, int x2, int y2){
    if(x1 <= 0 || y1 <= 0 || x2 <= 0 || y2 <= 0) return MINF;

    int& ret = dp[x1][y1][x2][y2];
    if(ret != -1) return ret; ret = MINF;
    if(x1 == 1 && y1 == 1 && x2 == 1 && y2 == 1) return ret = 0;

    ret = max(ret, solve(x1 - 1, y1, x2 - 1, y2));
    ret = max(ret, solve(x1, y1 - 1, x2 - 1, y2));
    ret = max(ret, solve(x1 - 1, y1, x2, y2 - 1));
    ret = max(ret, solve(x1, y1 - 1, x2, y2 - 1));

    return ret += abs(a[x1][y1] - a[x2][y2]);
}

void solve(){
    int n; cin >> n;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            for(int k = 1;k <= n;k++){
                for(int l = 1;l <= n;l++) dp[i][j][k][l] = -1;
            }
        }
    }


    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++) cin >> a[i][j];
    }

    cout << solve(n, n, n, n) << "\n";
}

int main(){
    int t; cin >> t;
    for(int i = 1;i <= t;i++) solve();

    return 0;
}
