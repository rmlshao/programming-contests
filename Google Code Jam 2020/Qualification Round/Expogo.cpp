#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
string printer(int i, string str){
    return "CASE #" + to_string(i) + ": " + str;
}
int main(){
    lli tc;
	cin >> tc;
	lli num1, num2;
    for(int i = 0; i < tc; i++){
		bool possible = true;
		vector<int> num1bits;
		vector<int> num2bits;
        bool neg1 = false, neg2 = false;
        cin >> num1 >> num2;
        if(num1 < 0){
            neg1 = true;
            num1 = -num1;
        }
        if(num2 < 0){
            neg2 = true;
            num2 = -num2;
        }
		while(num1 > 0){
			num1bits.push_back(num1 % 2);
			num1 /= 2;
		}
		while(num2 > 0){
		    num2bits.push_back(num2 % 2);
			num2 /= 2;
		}
		if(num1bits.size() > num2bits.size()) {
		    int k = num1bits.size() - num2bits.size();
		    for(int j = 0; j < k; j++)
		        num2bits.push_back(0);
		}
		else if(num1bits.size() < num2bits.size()){
		    int k = num2bits.size() - num1bits.size();
		    for(int j = 0; j < k; j++)
		        num1bits.push_back(0);
		}
		else{
		    num1bits.push_back(0);
		    num2bits.push_back(0);
		}
		for(int j = 0; j < num1bits.size() - 1; j++){
			if(abs(num1bits[j]) == abs(num2bits[j])) {
				cout << printer(i + 1, "IMPOSSIBLE") << endl;
				possible = false;
				break;
			}
			else if(abs(num1bits[j + 1]) == abs(num2bits[j + 1])){
				if(num1bits[j] == 1){
					num1bits[j] = -1;
					int itr = j + 1;
					while(num1bits[itr] == 1){
						num1bits[itr] = 0;
						itr++;
					}
					if(itr >= num1bits.size()){
					    num1bits.push_back(1);
					    num2bits.push_back(0);
					}
					else num1bits[itr] = 1;
				}
				else if(num2bits[j] == 1){
					num2bits[j] = -1;
					int itr = j + 1;
					while(num2bits[itr] == 1){
						num2bits[itr] = 0;
						itr++;
					}
					if(itr >= num2bits.size()){
					    num2bits.push_back(1);
					    num1bits.push_back(0);
					}
					else num2bits[itr] = 1;
				}
			}
			else continue;	
		}
		if(!possible) continue; 
		else{
			string ans = "";
			for(int j = 0; j < num1bits.size(); j++){
				if(num1bits[j] != 0){
					if((num1bits[j] == 1) ^ neg1) ans += "E";
						else ans += "W";
				}
				else{
					if((num2bits[j] == 1) ^ neg2) ans += "N";
						else ans += "S";
				}
			}
			cout << printer(i + 1, ans) << endl;
		}
    }
}