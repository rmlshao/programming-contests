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
 
 bool isSquare(long double x) 
{   
  long double sr = sqrt(x); 
  
  return ((sr - floor(sr)) == 0); 
} 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int arr[100002];
	int tc;
	cin >> tc;
	REP(i, tc){
		lli n, k, ctr = 0, mymax = -1, mymin = 10000000, val;
		cin >> n;
		for(int i = 1; i <= n; i++){
			cin >> arr[i];
		}
		arr[0] = 0;
		for(int i = 1; i <= n; i++){
			arr[i] += arr[i-1];
		}
		for(int j = 0; j < n; j++){
			for(int k = j + 1; k <= n; k++){
				if(arr[k] >= arr[j] && isSquare(arr[k] - arr[j]))
					ctr++;
			}
		}
		cout << "Case #" << i + 1 << ": " << ctr << '\n';
	}
}