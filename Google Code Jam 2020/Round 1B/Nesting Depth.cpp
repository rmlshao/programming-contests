#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    string S;
    cin >> tc;
    for(int i = 1; i <= tc; i++){
        cin >> S;
        string T;
        T += string(S[0] - '0', '(');
        T += S[0];
        for(int k = 0; k < S.length() - 1; k++){
            int diff = S[k+1] - S[k];
            if(diff > 0)
                T += string(diff, '(');
            else if(diff < 0)
                T += string(-diff, ')');
            T += S[k+1];
        }
        T += string(S[S.length() - 1] - '0', ')');
        cout << "Case #" << i << ": " << T << '\n';
    }
}