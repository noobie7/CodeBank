/*
"Won't stop until I'm Phenomenal."
- Phenomenal, EMINEM
*/
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

ll binmodulo(ll x, ll y){
    x%=mod1;
    if(!x) return 0;
    ll res = 1;
    while(y){
        if(y&1){
            res = res*x%mod1;
        }
        y/=2;
        x = x*x%mod1;
    }
    return res;
}

ll ncrr(ll n, ll r){
    if(n - r < r)
        r = n-r;
    ll x = 1, y =1;
    for(int i = 1; i <= r; i++){
        x*=(n+1-i);
        x%=mod1;
        y*=i;
        y%=mod1;

    }
    return x*binmodulo(y,mod1-2)%mod1;
}

int main(){
    Shazam;
    ll n,a,b; cin>>n>>a>>b;
    ll tot = binmodulo(2LL,n);
    tot = (tot - ncrr(n,a) + mod1)%mod1;
    tot = (tot - ncrr(n,b) + mod1)%mod1;
    cout<<tot-1<<endl;
    return 0;
}