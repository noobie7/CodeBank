#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int mod = 998244353;

int main(){
    int n; cin>>n;
    vector<int> dp(n), pow10(n,1);
    for(int i =1; i < n; i++){
        pow10[i] = pow10[i-1]*10%mod;
    }
    dp[n-1] = 9;
    for(int i = n-1; i >0; i--){
        dp[i-1] = 2*dp[i]*pow10[i]%mod;
    }
    dp[n-1]+=1;
    for(int i : dp)
        cout<<i<<" ";
    cout<<endl;
}