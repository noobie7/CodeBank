#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    int t; cin>>t;
    while(t--){
        ll p,f; cin>>p>>f;
        ll cw, cs; cin>>cs>>cw;
        ll s,w; cin>>s>>w;
        ll ans = 0;
        if(s > w){
            swap(s,w);
            swap(cw,cs);
            swap(p,f);
        }        
        for(ll i = 0 ; i <= min(p/s,cs); i++){
            ll pw = min((p-i*s)/w, cw);
            ll fs = min(cs-i, f/s);
            ll fw = min((f-fs*s)/w, cw-pw);
            ans = max(ans, i + pw + fs + fw);
        }
        cout<<ans<<endl;
    }
}