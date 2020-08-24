#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc, n, start, end;
    cin >> tc;
    for(int i = 0; i < tc; i++){
		priority_queue<pi, vector<pi>, greater<pi>> pq;
		map<pi, vector<int>> idx;
		int maxEndcam = -1;
		int maxEndjam = -1;
		bool possible = true;
        cin >> n;
        string s = string(n, '0');
        for(int j = 0; j < n; j++){
            cin >> start >> end;
			pq.push({start, end});
			idx[{start,end}].push_back(j);
		}
		while(pq.size() != 0){
			pi x = pq.top();
			pq.pop();
			bool cam2 = true;
            bool jam2 = true;
            if(x.first < maxEndcam){
				if(x.first < maxEndjam){
					possible = false;
					break;
				}
				else{
					maxEndjam = max(maxEndjam, x.second);
					s[idx[x][0]] = 'J';
					idx[x].erase(idx[x].begin(), idx[x].begin() + 1);
					continue;
				}
			}
			else{
				maxEndcam = max(maxEndcam, x.second);
				s[idx[x][0]] = 'C';
				idx[x].erase(idx[x].begin(), idx[x].begin() + 1);;
				continue;
			}
		}
		cout << "CASE #" << i + 1 << ": ";
		if(!possible) cout << "IMPOSSIBLE" << '\n';
		else cout << s << '\n';
    }
}