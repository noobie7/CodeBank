/*
"An anomaly, I'm Muhammad Ali
  Cause I know one day I'm gonna be the"
                - Greatest, Eminem
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
const int mod = 1e9 + 7;

ll binmodulo(ll x, ll y){
    x%=mod;
    ll res = 1;
    while(y){
        if(y&1){
            res = res*x%mod;
        }
        y/=2;
        x = x*x%mod;
    }
    return res;
}

int main(){
    Shazam;
    int n; cin >> n;
    int m; cin >> m;
    vector<multiset<ll>> dis(n);
    for(int i = 0; i < m; i++){
        int l, r, x; cin >> l >> r >> x;
        l--;
        if(x == 0) continue;
        dis[l].insert(x);
        if(r < n){
            dis[r].insert(-x);
        } 
    }
    multiset<ll> bag = dis.front();
    ll ans = 1 + bag.size();

    for(int i = 1; i < n; i++){
        for(auto ele : dis[i]){
            if(ele < 0){
                if(bag.find(abs(ele)) != bag.end()){
                    bag.erase(bag.find(abs(ele)));
                }
            }
            else{
                bag.insert(ele);
            }
        }
        ans = ans * binmodulo(2, (int)bag.size()) % mod;
    }
    cout << ans << endl;
    return 0;
}