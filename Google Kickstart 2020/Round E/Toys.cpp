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
		vector<lli> enjoyments;
		vector<lli> remembrances;
		lli n, enjoyment, remembrance, totalhindance = 0, minallowance = INF, count_hindrance = 0;
		cout << "Case #" << i + 1 << ": ";
		cin >> n;
		REP(j, n){
			cin >> enjoyment >> remembrance;
			enjoyments.PB(enjoyment);
			remembrances.PB(remembrance);
		}
		//bitmasking
		lli longest_time = -1;
		lli least_removed_corresponding_to_longest_time = 1e9;
		
		for(int j = 1; j < (1 << n); j++){
			vector<lli> workingset_enjoyments;
			vector<lli> workingset_remembrances;
			vector<lli> time_firstseen;
			for(int k = 0; k < n; k++){
				if((j & (1 << k)) != 0){
					workingset_enjoyments.PB(enjoyments[k]);
					workingset_remembrances.PB(remembrances[k]);
				}
			}
			lli currtime = 0;
			REP(m, workingset_enjoyments.size()){
				currtime += workingset_enjoyments[m];
				time_firstseen.PB(currtime);
			}
			bool notfull = false;
			REP(m, workingset_enjoyments.size()){
				if(currtime - time_firstseen[m] < workingset_remembrances[m]){
					notfull = true;
					break;
				}
				currtime += workingset_enjoyments[m];
			}
			if(!notfull) currtime = 1e12;
			if(currtime > longest_time){
				longest_time = currtime;
				least_removed_corresponding_to_longest_time = n - workingset_enjoyments.size();
			}
			else if(currtime == longest_time){
				if(n - workingset_enjoyments.size() < least_removed_corresponding_to_longest_time)
					least_removed_corresponding_to_longest_time = n - workingset_enjoyments.size();
			}
		}
		if(longest_time == 1e12)
			cout << least_removed_corresponding_to_longest_time << " INDEFINITELY\n";
		else
			cout << least_removed_corresponding_to_longest_time << " " << longest_time << '\n';
	}
}
