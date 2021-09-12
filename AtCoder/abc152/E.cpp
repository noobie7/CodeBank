/*
"Do I really belong in this game I ponder, I just wanna play my part."
- Guts over fear, Eminem
 */
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define ff first
#define Shazam ios_base::sync_with_stdio(false);   cin.tie(NULL); cout.tie(NULL);
#define ss second
#define all(c) c.begin(),c.end()
#define endl "\n"
#define test() int t; cin>>t; while(t--)
#define fl(i,a,b) for(int i = a ; i <b ;i++)
#define get(a) fl(i,0,a.size())  cin>>a[i];
#define pra(a) fl(i,0,a.size()) cout<<a[i]<<" ";	cout<<endl;
#define pr(a,n) fl(i,0,n) cout<<a[i]<<" ";	cout<<endl;
const ll INF = 2e18;
const int inf = 2e9;
const int mod1 = 1e9 + 7;



int main(){
    Shazam;
    int n; cin>>n;
    map<ll,int> f;
    vector<ll> vc(n);
    for(int i = 0; i < n; i++){
        ll a; cin>>a;
        vc[i] = a;
        for(int j = 2; j*j <= a; j++){
            if(a%j==0){
                int cnt = 0;
                while(a%j==0){
                    a/=j;
                    cnt++;
                }
                if(f.count(j)) f[j] = max(f[j],cnt);
                else           f[j] = cnt;
            }
        }
        if(a>=2){
            if(!f.count(a)) f[a] = 1;
        }
    }
    ll ans = 0;
    auto add = [&](ll &a, ll b){
        a = (a + b)%mod1;
    };

    for(ll &i : vc){
        ll res = 1;
        for(auto pp : f){
            ll pr = pp.ff;
            int mx = pp.ss;
            int cnt = 0;
            while(i % pr == 0){
                i/=pr;
                cnt++;
            }
            while(mx-cnt>0){
                res*=pr;
                res%=mod1;
                cnt++;
            }
        }
        add(ans, res);
    }
    cout<<ans<<endl;
    return 0;
}