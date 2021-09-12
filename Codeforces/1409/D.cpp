#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int sum(ll n){
    int res = 0;
    while(n){
        res+= n%10;
        n/=10;
    }
    return res;
}
int main(){
    int t; cin>>t;
    while(t--){
        ll n; cin>>n;
        int s; cin>>s;
        if(sum(n)<=s){
            cout<<0<<endl;
            continue;
        }
        ll ans = 0;
        ll pw = 1;
        for(int i = 0 ; i < 18; i++){
            int dig = (n/pw)%10;
            ll add = pw*((10 - dig)%10);
            n+=add;
            ans+=add;
            if(sum(n)<=s){
                break;
            }
            pw*=10;
        }
        cout<<ans<<endl;
    }
    return 0;
}