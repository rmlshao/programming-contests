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
vector<vector<int>> vec;
vector<bool> visited(27, false);
vector<bool> recStack(27, false);
stack<int> mystack;
bool isCyclicUtil(int v)	
{ 
    if(visited[v] == false) 
    { 
        visited[v] = true; 
        recStack[v] = true;
        for(int i: vec[v])
        {
            if ( !visited[i] && isCyclicUtil(i) ) 
                return true; 
            else if (recStack[i]) 
                return true; 
        } 
  
    } 
    recStack[v] = false;
    return false; 
} 

void topSortUtil(int v){
	visited[v] = true; 
    for (int i: vec[v]){ 
        if (!visited[i]) 
            topSortUtil(i);
	}
    mystack.push(v); 
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int tc;
	cin >> tc;
	REP(i, tc){
		bool possible = true;
		string ans = "";
		lli n, k;
		cin >> n >> k;
		string str;
		unordered_set<char> myset;
		char arr[n][k];
		for(int j = 0; j < n; j++){
			cin >> str;
			for(int m = 0; m < k; m++){
				arr[j][m] = str[m];
				myset.insert(str[m]);
			}
		}
		vec.clear();
		vec.resize(27);
		for(int j = 0; j < k; j++){
			for(int m = n - 1; m > 0; m--){
				if(arr[m][j] != arr[m-1][j]){
					bool inside = false;
					for(int i = 0; i < vec[arr[m][j] - 64].size(); i++){
						if(arr[m-1][j] - 64 == vec[arr[m][j] - 64][i])
							inside = true;
					}
					if(!inside) {
						vec[arr[m][j] - 64].PB(arr[m-1][j] - 64);
					}
				}
			}
		}
		for(int i = 1; i <= 26; i++){
			visited[i] = false;
			recStack[i] = false;
		}
		for(int i = 1; i <= 26; i++) {
			if (isCyclicUtil(i))
				possible = false;
		}
		if(possible){
			for(int i = 1; i <= 26; i++)
				visited[i] = false;
			for(int i = 1; i <= 26; i++){
				if(!visited[i]){
					topSortUtil(i);
				}
			}
			while(mystack.size() != 0){
				if(myset.find((char) (mystack.top() + 64)) != myset.end()){
					ans += (char) (mystack.top() + 64);
				}
				mystack.pop();
			}
		}
		else ans = "-1";
		cout << "Case #" << i + 1 << ": " << ans << '\n';
	}
}