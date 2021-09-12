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



int main(){
    Shazam;
    int n,m; cin>>n>>m;
    // multiset<ll,greater<ll>> s;
    // for(int i = 0 ; i < n; i++){
    //     ll k; cin>>k; s.insert(k);
    // }
    // for(int i = 0 ; i < m; i++){
    //     ll operate = *s.begin();
    //     s.erase(s.begin());
    //     s.insert(operate>>=1);
    // }
    // ll ans = 0;
    // for(auto p : s)
    //     ans+= p;
    ll ans = 0;
    priority_queue<ll> q;
    for(int i = 0 ; i < n ;i++){
        ll k; cin>>k;
        q.push(k);
    }
    for(int i = 0; i < m; i++){
        ll operate = q.top();
        q.pop();
        q.push(operate>>=1);
    }
    while(!q.empty()){
        ans+=q.top();
        q.pop();
    }
    cout<<ans<<endl;
    return 0;
}