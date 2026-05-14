#include <iostream>
#include <string>
using namespace std;

void solve(){
    int n; cin >> n;

    int result = 0;
    for(int i = 1;i <= n;i++){
        int num = i, sum = 0;
        while(num){
            sum += num % 10;
            num /= 10;
        }

        if(sum % 7 == 0) result++;
    }

    cout << result << "\n";
}

int main(){
    int t; cin >> t;
    for(int i = 1;i <= t;i++) solve();

    return 0;
}
