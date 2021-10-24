#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    vector<ll> a(11, 1);
    for(int i = 1; i < 11; i++){
        a[i] = i * a[i - 1];
    }
    ll n; cin >> n;
    int ans = 0;
    while(n){
        while(n >= a.back()){
            ans++;
             n -= a.back();
        }
        a.pop_back();
    }
    cout << ans << endl;
    return 0;
}