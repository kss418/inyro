#include <iostream>
#include <algorithm>
using namespace std;

int a[201010], n;
void solve(){
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];
    sort(a + 1, a + n + 1);

    int mn = 0, mx = 0;
    for(int i = 1;i <= n;i += 2) mn += a[i + 1] - a[i];
    for(int i = 1;i <= n / 2;i++) mx += a[i + n / 2] - a[i];
    cout << mn << " " << mx << "\n";
}

int main(){
    int t; cin >> t;
    for(int i = 1;i <= t;i++) solve();

    return 0;
}
