#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define all(cont) cont.begin(), cont.end()
#define INF (int)1e9
#define EPS 1e-6
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define MP make_pair
#define PB push_back
#define MEM(a, b) memset(a, (b), sizeof(a))
typedef long long int lli;
typedef pair<lli, lli> pll;
typedef pair<int, int> pii;
typedef unordered_map<char, lli> mcl;
typedef unordered_map<lli, lli> mll;
typedef unordered_set<lli> usl;
typedef unordered_set<char> usc;
typedef unordered_set<pll> uspll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<pll> vpll;
typedef map<int,int> mpii;
typedef set<int> si;
typedef multiset<int> msi;
typedef pair<double, double> pdd;
const double pi = 3.14159265358979323;
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	lli arr[200002];
	lli evenStart[200002];
	lli oddStart[200002];
	lli arr3[200002];
	arr3[0] = 0;
	arr[0] = 0;
	evenStart[0] = 0;
	oddStart[0] = 0;
	int tc;
	cin >> tc;
	REP(i, tc){
		lli n, q, ans = 0, mymax = -1, mymin = 10000000, val, left, right;
		string type;
		cin >> n >> q;
		for(int i = 1; i <= n; i++){
			cin >> arr[i];
			if(i % 2 == 0){
				evenStart[i] = (i-1) * arr[i];
				oddStart[i] = -i * arr[i];
			}
			else{
				evenStart[i] = (1 - i) * arr[i];
				oddStart[i] = i * arr[i];
			}
			arr3[i] = arr[i];
		}
		for(int i = 2; i <= n; i++){
			arr3[i] += arr3[i-2];
			evenStart[i] += evenStart[i-2];
			oddStart[i] += oddStart[i-2];
		}
		for(int i = 0; i < q; i++){
			cin >> type >> left >> right;
		if(type == "U"){
			arr[left] = right;
			for(int i = 1; i <= n; i++){
				if(i % 2 == 0){
					evenStart[i] = (i-1) * arr[i];
					oddStart[i] = -i * arr[i];
				}
				else{
					evenStart[i] = (1 - i) * arr[i];
					oddStart[i] = i * arr[i];
				}
				arr3[i] = arr[i];
			}
			for(int i = 1; i <= n; i++){
				arr3[i] += arr3[i-2];
				evenStart[i] += evenStart[i-2];
				oddStart[i] += oddStart[i-2];
			}
		}
		else{
			if(left % 2 == 0){
				lli currsum = evenStart[right] + evenStart[right - 1] - evenStart[left - 1] - evenStart[left - 2];
				if(right % 2 == 0){
					currsum -= (left - 2) * (arr3[right] - arr3[left - 2]);
					currsum += (left - 2) * (arr3[right - 1] - arr3[left - 1]);
				}
				else{
					currsum -= (left - 2) * (arr3[right - 1] - arr3[left - 2]);
					currsum += (left - 2) * (arr3[right] - arr3[left - 1]);
				}
				ans += currsum;
			}
			else{
				if(left == 1)
					ans += oddStart[right] + oddStart[right - 1];
				else{
					lli currsum = oddStart[right] + oddStart[right - 1] - oddStart[left - 1] - oddStart[left - 2];
					if(right % 2 == 0){
						currsum += (left - 1) * (arr3[right] - arr3[left - 1]);
						currsum -= (left - 1) * (arr3[right - 1] - arr3[left - 2]);
					}
					else{
						currsum -= (left - 1) * (arr3[right] - arr3[left - 2]);
						currsum += (left - 1) * (arr3[right - 1] - arr3[left - 1]);
					}
					ans += currsum;
				}
			}
		}
		}
		cout << "Case #" << i + 1 << ": " << ans << '\n';
	}
}