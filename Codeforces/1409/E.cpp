#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    int t; cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        vector<ll> x(n), y(n);
        for(ll &i : x) cin>>i;
        for(ll &i : y) cin>>i;
        sort(x.begin(),x.end());
        vector<int> pref(n), suf(n);
        int j = n-1;
        for(int i = n-1; i >=0 ; i--){
            while(x[j]-x[i]>k) j--;
            suf[i] = j-i+1;
            if(i!=n-1)
                suf[i] = max(suf[i],suf[i+1]);
        }
        j = 0;
        for(int i = 0; i < n; i++){
            while(x[i]-x[j]>k) j++;
            pref[i] = i-j+1;
            if(i)
                pref[i] = max(pref[i], pref[i-1]);
        }
        int ans = 1;
        for(int i = 0 ; i < n-1; i++){
            ans = max(ans, pref[i]+suf[i+1]);
        }
        cout<<ans<<endl;
    }
}