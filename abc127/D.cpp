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
    priority_queue<pair<int,int>> q;
    priority_queue<ll> fin;
    int n; cin>>n;
    int m; cin>>m;
    for(int i = 0 ; i < n; i++){
        ll k; cin>>k;
        fin.push(k);
    }
    for(int i =0 ; i < m; i++){
        int qty; cin>>qty;
        ll val; cin>>val;
        q.push({val,qty});
    }
    int take = 0;
    while(!q.empty() && take < n){
        for(int i = take ; i <min(n,take+q.top().ss); i++){
            fin.push(q.top().ff);
        }
        take+=q.top().ss;
        q.pop();
    }
    ll ans = 0;
    for(int i = 0 ; i < n; i++){
        ans+=fin.top();
        fin.pop();
    }
    cout<<ans<<endl;
    return 0;
}