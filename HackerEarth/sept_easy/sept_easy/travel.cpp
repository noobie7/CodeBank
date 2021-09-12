#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		int k; cin >> k;
		vector<ll> a(n); 
		for(ll &i : a){
			cin >> i;
			i--;
		}
		vector<pair<ll, ll>> range(k, {1e9, -1});
		for(ll i = 0; i < n; i++){
			range[a[i]].first = min(range[a[i]].first, i);
			range[a[i]].second = max(range[a[i]].second, i);
		}
		vector<vector<ll>> dp(k, vector<ll> (2));
		// dp[i][0] => choosing the left most choice for the ith city
		// dp[i][1] => choosing the right most choice for the ith city
		for(int i = 1; i < k; i++){
			dp[i][0] = max(dp[i - 1][0] + abs(range[i - 1].first - range[i].first), dp[i - 1][1] + abs(range[i - 1].second - range[i].first));
            dp[i][1] = max(dp[i - 1][0] + abs(range[i - 1].first - range[i].second), dp[i - 1][1] + abs(range[i - 1].second - range[i].second));
        }
        cout << *max_element(dp[k - 1].begin(), dp[k - 1].end()) << endl;
	}
}
