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
bool contains(pair<int, int> x, int y){
    if(x.first <= y && y <= x.second) return true;
    return false;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int tc;
	cin >> tc;
	REP(i, tc){
		cout << "Case #" << i + 1 << ": \n";
		int n;
		cin >> n;
		vector<string> vec;
		REP(j, 2){
			string x;
			cin >> x;
			vec.PB(x);
		}
		vector<string> vec2;
		REP(j, n){
			int moveleft = j;
			int moveright = j;
			string output = "";
			while(moveleft != 0){
				if(vec[1][moveleft] == 'Y' && vec[0][moveleft - 1] == 'Y')
					moveleft--;
				else
					break;
			}
			while(moveright != n - 1){
				if(vec[1][moveright] == 'Y' && vec[0][moveright + 1] == 'Y')
					moveright++;
				else
					break;
			}
			REP(k, moveleft)
				output += "N";
			for(int k = moveleft; k <= moveright; k++)
				output += "Y";
			for(int k = moveright + 1; k < n; k++)
				output += "N";
			cout << output << '\n';
		}
	}
			
}