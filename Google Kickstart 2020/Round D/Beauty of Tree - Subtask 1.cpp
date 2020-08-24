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
	int tc;
	cin >> tc;
	REP(i, tc){
		vector<vector<int>> adj;
		int nodes, par, child;
		int a, b;
		cin >> nodes >> a >> b;
		adj.resize(nodes + 1);
		for(int j = 2; j <= nodes; j++){
			cin >> par;
			adj[par].PB(j);
		}
		// do bfs on each graph and collect distances
		double ans = 0;
		for(int j = 1; j <= nodes; j++){
			double gets_a = 0;
			double gets_b = 0;
			queue<pair<int, double>> q;
			q.push({j, 0});
			while(!q.empty()){
				int node = q.front().first;
				int dist = q.front().second;
				if(dist % a == 0) gets_a++;
				if(dist % b == 0) gets_b++;
				q.pop();
				for(int m = 0; m < adj[node].size(); m++)
					q.push({adj[node][m], dist + 1});
				
			}
			ans += gets_a / (double) nodes + gets_b / (double) nodes - gets_a * gets_b / (double) (nodes * nodes);
		}
		cout << "Case #" << i + 1 << ": " << fixed << setprecision(7) << ans << '\n';
	}
}