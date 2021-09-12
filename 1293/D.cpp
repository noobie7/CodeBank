/*
"Won't stop until I'm phenomenal."
- Phenomenal, Eminem
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
    if(!x) return 0;
    ll res = 1;
    while(y){
        if(y&1){
            res = res*x;
        }
        y/=2;
        x = x*x;
    }
    return res;
}

int main(){
    Shazam;
    ll x,y,a,b,c,d;
    cin>>x>>y>>a>>c>>b>>d;
    ll sx, sy, t; 
    cin>>sx>>sy>>t;

    vector<ll> X(1,x), Y(1,y);
    ll upto = (1LL<<62)-1;
    while( (upto-b)/a >= X.back() && (upto - d)/c >= Y.back() ){
        X.push_back(X.back()*a + b);
        Y.push_back(Y.back()*c + d);
    }
    int rightlim = X.size();
 
    auto man = [&](ll a, ll b, ll x, ll y){
        return abs(a-x) + abs(b-y);
    };

    int cnt = 0;
    for(int left = 0 ; left < rightlim ; left++){
        for(int right = left; right < rightlim; right ++){
            ll seg = man(X[left],Y[left],X[right],Y[right]);
            ll rig = man(sx     ,sy     ,X[right],Y[right]);
            ll lef = man(sx     ,sy     ,X[left] ,Y[left] );
            if(seg <= t - rig || seg <= t - lef)
                cnt = max(cnt, right - left + 1);
        }
    }
    cout<<cnt<<endl;
    return 0;
}