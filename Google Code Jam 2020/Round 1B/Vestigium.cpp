#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lli tc, n, num;
    cin >> tc;
    vector<vector<lli>> vec;
    unordered_set<lli> myset;
    for(int i = 0; i < tc; i++){
        lli rows = 0, cols = 0, sum = 0;
        cin >> n;
        vec.clear();
        vec.resize(n);
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                cin >> num;
                vec[j].push_back(num);
            }
        }
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++)
                myset.insert(vec[j][k]);
            if(myset.size() != n)
                rows++;
            myset.clear();
        }
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++)
                myset.insert(vec[k][j]);
            if(myset.size() != n)
                cols++;
            myset.clear();
        }
        for(int j = 0; j < n; j++)
            sum += vec[j][j];
        cout << "Case #" << i+1 << ": " << sum << " " 
        << rows << " " << cols << '\n';
    }
}