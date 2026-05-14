#include <iostream>
#include <vector>
using namespace std;

void solve(){
    int n; cin >> n;

    vector <int> arr;
    for(int i = 1;i <= n;i++){
        int x, v; cin >> x >> v;
        arr.push_back(x);

        while(1){
            int cnt = 0;
            for(int j = arr.size() - 1;j >= 0;j--){
                if(arr[j] == x) cnt++;
                else break;
            }

            if(cnt < x) break;
            for(int j = 1;j <= x;j++) arr.pop_back();
        }

        cout << arr.size() << "\n";
    }
    
}

int main(){
    int t; cin >> t;
    for(int i = 1;i <= t;i++) solve();

    return 0;
}
