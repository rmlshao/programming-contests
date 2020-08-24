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
		int n, q, val, curr, needed;
		cin >> n >> q;
		vector<int> vec;
		vector<int> ans;
		vec.PB(0);
		REP(j, n - 1){
			cin >> val;
			vec.PB(val);
		}
		REP(j, q){
			cin >> curr >> needed;
			needed--;
			int left = curr - 1; // room to the left
			int right = curr; //room currently in 
			int moveleft, moveright;
			while(needed > 0){
				if(left <= 0){ // you can't go left
					curr = needed + right;
					break;
				}
				else 
					moveleft = vec[left];
				if(right > n - 1){
					curr = left - needed + 1;
					break;
				}
				else
					moveright = vec[right];
				if(moveleft < moveright){
					left--;
					curr = left + 1;
				}
				else{
					right++;
					curr = right;
				}
				needed--;
			}
			ans.PB(curr);
		}
		cout << "Case #" << i + 1 << ": ";
		REP(j, ans.size())
			cout<< ans[j] << " ";
		cout << '\n';
	}
}
