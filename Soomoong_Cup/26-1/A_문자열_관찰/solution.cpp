#include <iostream>
#include <string>
using namespace std;

void solve(){
    string s; cin >> s;

    int low = 0, up = 0, num = 0;
    for(auto& i : s){   
        if(i >= 'A' && i <= 'Z') up++;
        else if(i >= 'a' && i <= 'z') low++;
        else num++;
    }

    cout << up << " " << low << " " << num << "\n";
}

int main(){
    int t; cin >> t;
    for(int i = 1;i <= t;i++) solve();

    return 0;
}
