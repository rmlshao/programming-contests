#include <bits/stdc++.h>
using namespace std;
string complement(string s){
    for(int k = 0; k < s.length(); k++){
        if(s[k] == '0')
            s[k] = '1';
        else
            s[k] = '0';
    }
    return s;
}
string reverse(string s){
    string s1 = string(s.length(), '0');
    for(int i = s.length() - 1; i >= 0; i--){
        s1[s.length() - 1 - i] = s[i];
    }
    return s1;
}
int main(){
    int tc;
    int b;
    cin >> tc >> b;
    for(int i = 0; i < tc; i++){
		string ans = string(b, '0');
        bool spfound = false;
        bool dpfound = false;
        int sp1, dp1;
        int ctr = 0;
		int l = 0;
        while(l < b / 2){
			for(int j = 1; j <= 5; j++){
				l++;
				cout << l << endl;
				cin >> ans[l - 1];
				cout << b + 1 - l << endl;
				cin >> ans[b - l];
				if(!spfound && ans[l-1] == ans[b-l]){
					spfound = true;
					sp1 = l;
				}
				if(!dpfound && ans[l-1] != ans[b-l]){
					dpfound = true;
					dp1 = l;
				}
				ctr += 2;
				if(ctr % 10 == 0) break;
				if(l == b / 2) break;
			}
			if(l == b / 2) break;
			if(!dpfound || !spfound){
				char x;
				cout << 1 << endl;
				cin >> x;
				if(ans[0] != x)
					ans = complement(ans);
				cout << 1 << endl;
				cin >> x;
				ctr += 2;
			}
			else{
				char x, y;
				cout << sp1 << endl;
				cin >> x;
				cout << dp1 << endl;
				cin >> y;
				if(x != ans[sp1 - 1] && y != ans[dp1 - 1])
					ans = complement(ans);
				else if(x == ans[sp1 - 1] && y != ans[dp1 - 1])
					ans = reverse(ans);
				else if(x != ans[sp1 - 1] && y == ans[dp1 - 1]){
					ans = complement(ans);
					ans = reverse(ans);
				}
				ctr += 2;
			}
		}
		cout << ans << endl;
		char response;
		cin >> response;
		if(response == 'N') return 0;
    }
    return 0;
}