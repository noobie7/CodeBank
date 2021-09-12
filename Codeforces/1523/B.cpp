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

set<pair<ll,ll>> st;
map<pair<ll,ll>, pair<ll, ll>> par;
int ans = -1;
void rec(pair<ll, ll> a, int c){
    if(a.ff < -2e18 || a.ss > 1e18) return ;
    if(a == make_pair(-1LL, (ll)-1e9)) {
        ans = c;
        return ;
    }
    st.insert(a);
    if(st.size() > 10000){
        return;
    }
    
    if(st.find({a.ff - a.ss, a.ss}) == st.end()){
        par[{a.ff - a.ss, a.ss}] = a;
        rec({a.ff - a.ss, a.ss}, c + 1 );
    }
    if(st.find({a.ff, a.ss + a.ff}) == st.end()){
        par[{a.ff, a.ss + a.ff}] = a;
        rec({a.ff, a.ss + a.ff}, c + 1);
    }
    
}

int main(){
    Shazam;
    pair<ll, ll> a = {1LL, (ll)1e9};
    rec(a, 0);
    cout << ans << endl;
    
    pair<ll,ll> curr = {-1LL, (ll)-1e9};
    while(0){
        cout << curr.ff << " " << curr.ss << endl;
        if(curr == a){
            break;
        }
        curr = par[curr];
    }
    
    return 0;
}