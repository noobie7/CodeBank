/*
"An anomaly, I'm Muhammad Ali
  Cause I know one day I'm gonna be the"
                - Greatest, Eminem
*/
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
const ll INF = 2e18;
const int inf = 2e9;
const int mod1 = 1e9 + 7;



int main(){
    Shazam;
    ll n, x, m; cin >> n >> x >> m;
    ll ans = 0;
    vector<ll> a;
    set<ll> s;
    while(s.find(x) == s.end() && n){
        a.push_back(x);
        s.insert(x);
        ans += x;
        n--;
        x = x * x % m;
    }
    if(n){
        int cyclesize = 1;
        ll cyclesum = x;
        vector<ll> cycle(1,x);
        while(a.back() != x){
            cyclesize++;
            cyclesum += a.back();
            cycle.push_back(a.back());
            a.pop_back();
        }
        cycle.push_back(x);
        reverse(all(cycle));
        cycle.pop_back();
        reverse(all(cycle));
        ans += (cyclesum) * (n / cyclesize);
        n %= cyclesize;
        while(n--){
            ans += cycle.back();
            cycle.pop_back();
        }
        
    }
    cout << ans << endl;
    return 0;
}