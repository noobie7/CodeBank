/*
"Won't stop until I'm phenomenal."
- Phenomenal, Eminem
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

ll solve(){
    int n,k; cin>>n>>k;
    vector<ll> a(n);
    get(a);
    ll ans = LLONG_MAX;
    for(int i = 1; i <= k; i++){
        ll curr = 0;
        for(ll j : a){
            curr += min(k-abs(i-j), abs(i-j));
        }
        ans = min(ans, curr);
    }
    return ans;    
}

int main(){
    Shazam;
    int c = 1;

    test(){
        cout<<"Case #"<<c<<": "<<solve()<<endl;
        c++;
    }
    return 0;
}