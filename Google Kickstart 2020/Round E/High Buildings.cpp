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

bool sortbysec(const pair<int,int> &a, const pair<int,int> &b) { 
    return (a.second < b.second); 
} 

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int tc;
	cin >> tc;
	REP(i, tc){
		cout << "Case #" << i + 1 << ": ";
		lli n, m, k, val, a, b, c;
		string ans;
		vector<lli> vec;
		cin >> n >> a >> b >> c;
		int buffer = n - (a + b - c);
		if(a + b - c > n)
			cout << "IMPOSSIBLE\n";
		else if(n == 1){
			if(!(a == b && b == c && c == 1))
				cout << "IMPOSSIBLE\n";
			else{
				cout << "1\n";
			}
		}
		else if(n == 2){
			if(a == b && b == c && c == 2)
				cout << "2 2\n";
			else if(a == 2 && b == 1 && c == 1)
				cout << "1 2\n";
			else if(a == 1 && b == 2 && c == 1)
				cout << "2 1\n";
			else
				cout << "IMPOSSIBLE\n";
		}
		else if(a == b && b == c){
			if(c == 1) cout << "IMPOSSIBLE\n";
			else{
			cout << n << " ";
			REP(j, n - a)
				cout << 1 << " ";
			REP(j, a - 1)
				cout << n << " ";
			cout << '\n';
			}
		}
		else{
			for(int j = 1; j <= a - c; j++)
				vec.PB(n-1);
			if(a != c){
				for(int j = 1; j <= buffer; j++)
					vec.PB(1);
			}
			for(int j = 1; j <= c; j++)
				vec.PB(n);
			if(a == c && b != c){
				for(int j = 1; j <= buffer; j++)
					vec.PB(1);
			}
			for(int j = 1; j <= b - c; j++)
				vec.PB(n-1);
			REP(j, n)
				cout << vec[j] << " ";
			cout << '\n';
		}
			
	}
}
