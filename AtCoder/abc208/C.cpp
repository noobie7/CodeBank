#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    int n; cin >> n;
    ll k; cin >> k;
    vector<pair<ll, int>> a(n);
    for(int i = 0; i < n; i++){
        ll k; cin >> k;
        a[i] = {k, i};
    }
    vector<ll> ans(n, k / n);
    k %= n;
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    while(k){
        ans[a.back().second]++;
        a.pop_back();
        k--;
    }
    for(ll i : ans) cout << i << endl;
    return 0;

}