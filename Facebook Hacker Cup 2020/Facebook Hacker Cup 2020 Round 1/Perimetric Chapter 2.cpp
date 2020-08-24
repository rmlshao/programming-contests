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
vector<lli> widths;
set<pll> segments;

lli n, k, w, al, bl, cl, dl, ah, bh, ch, dh, aw, bw, cw, dw, perimeter;

lli get_next_length(lli first, lli second){
	lli ans = al * first + bl * second + cl;
	return ans % dl + 1;
}

lli get_next_height(lli first, lli second){
	lli ans = ah * first + bh * second + ch;
	return ans % dh + 1;
}

lli get_next_width(lli first, lli second){
	lli ans = aw * first + bw * second + cw;
	return ans % dw + 1;
}
void merge(pll segment, lli new_height){
	auto it = segments.lower_bound(segment);
	if(it != segments.begin())
		--it;
	lli merged = 0;
	lli newsegment_left = segment.first;
	lli newsegment_right = segment.second;
	lli lengthdeducted = 0;
	while(segments.size() != 0 && it != segments.end()){
		pll x = *it;
		lli left = x.first;
		lli right = x.second;
		if(x.first > segment.second)
			break;
		if(!(left > segment.second || (right < segment.first))){
			lengthdeducted += (right - left);
			it = segments.erase(it);
			merged++;
			newsegment_left = min(left, newsegment_left);
			newsegment_right = max(right, newsegment_right);
		}
		else
			++it;
	}
	if(merged == 0)
		perimeter += (new_height + segment.second - segment.first) * 2;
	else
		perimeter += 2 * (newsegment_right - newsegment_left - lengthdeducted - (merged - 1) * new_height);
	while(perimeter < 0)
		perimeter += MOD;
	perimeter %= MOD;
	segments.insert({newsegment_left, newsegment_right});
}
	
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	lli tc, val;
	cin >> tc;
	REP(i, tc){
		lli ans = 1;
		lengths.clear();
		heights.clear();
		widths.clear();
		segments.clear();
		cin >> n >> k;
		REP(j, k){
			cin >> val;
			lengths.PB(val);
		}
		cin >> al >> bl >> cl >> dl;
		REP(j, k){
			cin >> val;
			widths.PB(val);
		}
		cin >> aw >> bw >> cw >> dw;
		REP(j, k){
			cin >> val;
			heights.PB(val);
		}
		cin >> ah >> bh >> ch >> dh;
		
		for(int j = k; j < n; j++){
			lengths.PB(get_next_length(lengths[j-2], lengths[j-1]));
			widths.PB(get_next_width(widths[j-2], widths[j-1]));
			heights.PB(get_next_height(heights[j-2], heights[j-1]));
		}
		
		perimeter = 0;
		REP(j, n){
			pll new_segment = {lengths[j], lengths[j] + widths[j]};
			merge(new_segment, heights[j]);
			ans *= perimeter;
			ans %= MOD;
		}
		cout << "Case #" << i + 1 << ": " << ans << '\n';
	}	
}