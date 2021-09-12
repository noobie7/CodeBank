#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<ll> a(n);
        for(ll &i : a)
            cin>>i;
        vector<ll> dp(n+1);
        for(int i = 0 ; i < n; i++){
            if(a[i]>=0){
                dp[i+1] = a[i] + dp[i];
            }
            else{
                dp[i] -= min(dp[i],abs(a[i]));
                dp[i+1] = dp[i];
            }
        }
        cout<<dp.back()<<endl;
    }
    return 0;
}