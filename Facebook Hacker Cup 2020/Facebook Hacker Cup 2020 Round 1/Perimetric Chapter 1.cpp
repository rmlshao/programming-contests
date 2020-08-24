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

vector<lli> lengths;
vector<lli> heights;
lli n, k, w, al, bl, cl, dl, ah, bh, ch, dh;

lli get_next_length(lli first, lli second){
	lli ans = al * first + bl * second + cl;
	return ans % dl + 1;
}

lli get_next_height(lli first, lli second){
	lli ans = ah * first + bh * second + ch;
	return ans % dh + 1;
}
	
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	lli tc, val;
	cin >> tc;
	REP(i, tc){
		lengths.clear();
		heights.clear();
		cin >> n >> k >> w;
		
		REP(j, k){
			cin >> val;
			lengths.PB(val);
		}
		cin >> al >> bl >> cl >> dl;
		
		REP(j, k){
			cin >> val;
			heights.PB(val);
		}
		cin >> ah >> bh >> ch >> dh;
		
		for(int j = k; j < n; j++){
			lengths.PB(get_next_length(lengths[j-2], lengths[j-1]));
			heights.PB(get_next_height(heights[j-2], heights[j-1]));
		}
		
		lli ans = 1;
		lli perim_so_far = 0;
		REP(j, n){
			lli baselength = lengths[j];
			lli currlength;
			lli maxheight = heights[j];
			lli drops_saved = 0;
			lli currperim;
			lli vis_height = -1, vis_length = -1;
			lli total_drops_saved = 0;
			while(j < n){
				currlength = lengths[j];
				maxheight = max(maxheight, heights[j]);
				currperim = 2 * (maxheight + (currlength + w) - baselength);
				currperim += perim_so_far;
				if(heights[j] >= vis_height){
					if(drops_saved > 0){
						if(heights[j] - vis_height > drops_saved){
							total_drops_saved += 2 * drops_saved;
							drops_saved = 0;
						}
						else{
							total_drops_saved += 2 * (heights[j] - vis_height);
							drops_saved -= (heights[j] - vis_height);
						}
					}
					vis_height = heights[j];
					vis_length = lengths[j];
				}
				else{
					bool there_is_no_greater_height_in_range = true;
					int idx = j + 1;
					while(idx < n && lengths[idx] - vis_length <= w){
						if(heights[idx] > heights[j]){
							there_is_no_greater_height_in_range = false;
							break;
						}
						else idx++;
					}
					if(there_is_no_greater_height_in_range){
						drops_saved += (vis_height - heights[j]);
						vis_height = heights[j];
						vis_length = lengths[j];
					}
				}
				total_drops_saved %= MOD;
				currperim %= MOD;
				ans *= (currperim + total_drops_saved);
				ans %= MOD;
				if((j + 1 < n) && (currlength + w >= lengths[j+1]))
					j++;
				else
					break;
			}
			perim_so_far = currperim + total_drops_saved;
		}
		cout << "Case #" << i + 1 << ": " << ans << '\n';
	}	
}