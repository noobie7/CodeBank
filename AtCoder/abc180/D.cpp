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
    ll x, y, a, b;
    cin >> x >> y >> a >> b;

    
    auto bs = [&](long long val){
        ll c = 0;
        for(ll i = 1 ; i < 100 ; i++){ 
            if(val * (ll)(pow(a,i) + 0.5) >= y ) break;
            if(val * (ll)(pow(a,i) + 0.5) < val + b * i){
                //cout << val * (ll)(pow(a,i) + 0.5) << " " <<  val + b * i << endl;
                c = i;
                continue;
            }
            break;
        }
        return c;
    };
    ll ans = 0;
    ll poc = bs(x);
    //cout << poc << endl;
    if(x * (ll)(pow(a,poc) + 0.5) >= y ){
        while(x * a < y){
            x *= a;
            ans++;
        } 
    }
    else{
        ans = poc;
        x *= (ll)(pow(a,poc) + 0.5);
        ans += (y - x)/b - ((y - x)%b==0);
       
    }
    cout << ans << endl;
    return 0;
}