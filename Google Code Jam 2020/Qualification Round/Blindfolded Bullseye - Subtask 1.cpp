#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main(){
    string response;
    int tc;
    lli a, b;
    cin >> tc >> a >> b;
    for(int i = 0; i < tc; i++){
        bool found = false;
        for(int j = -5; j <= 5; j++){
            for(int k = -5; k <= 5; k++){
                cout << j << " " << k << endl;
                cin >> response;
                if(response == "CENTER"){
                    found = true;
                    break;
                }
            }
            if(found) break;
        }
    }
    return 0;
}