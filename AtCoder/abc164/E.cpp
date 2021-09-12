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

struct E{
    ll to;
    ll co;
    ll ti;
};

struct P{
    ll ti;
    ll id;
    ll re;
};
bool operator <(const P &a,const P &b){return a.ti>b.ti;}
ll dp[55][5001];
ll ans[55];
vector<E> edge[55];

int main(){
    Shazam;
    int n; cin>>n;
    int m; cin>>m;
    ll s; cin>>s;
    for(int i = 0 ; i < m; i++){
        ll a,b,c,d; 
        cin>>a>>b>>c>>d;
        edge[a].push_back({b,c,d});
        edge[b].push_back({a,c,d});
    }
    vector<ll> c(n+1),d(n+1);
    for(int i = 1; i < n+1; i++){
        cin>>c[i]>>d[i];
    }
    priority_queue<P> q;
    q.push({0,1,min(5000LL,s)});
    while(!q.empty()){
        P p = q.top();
        q.pop();
        if(dp[p.id][p.re]) continue;
        dp[p.id][p.re] = p.ti;
        if(!ans[p.id]) ans[p.id] = p.ti;
        for(E e : edge[p.id]){
            if(p.re>=e.co && ! dp[e.to][p.re-e.co])
                q.push({ p.ti + e.ti, e.to , p.re- e.co});
        }
        if(p.re + c[p.id] <= 5000){
            q.push({p.ti + d[p.id], p.id, p.re + c[p.id]});
        }

    }
    for(int i = 2; i < n+1; i++) 
        cout<<ans[i]<<endl;
    return 0;

}