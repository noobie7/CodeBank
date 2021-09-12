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
    test(){
        ll p, q;
        ll ans;
        cin >> p >> q;
        ans = p;
        map<ll,ll> pcount, qcount;
        for(ll i = 2; i*i <= q; i++){
            if(q%i == 0){
                int cnt = 0;
                while(q%i == 0){
                    q /= i;
                    cnt++;
                }
                qcount[i] = cnt;
            }
        }
        if(q >= 2){
            if(qcount.count(q))
                qcount[q] += 1;
            else{
                qcount[q] = 1;
            }
        }

        bool lessalready = false;
        
        ll mn = 2e18;
        
        for(auto pp : qcount){
            ll req = pp.ss;
            ll num = p;
            ll cnt = 0;
            while(num % pp.ff == 0){
                num /= pp.ff;
                cnt++;
            }
            if( cnt < req ){
                lessalready = true;
                break;
            }
            else{
                mn = min(mn, (ll)(pow(pp.ff, cnt - (req - 1)) + 0.5));
            }
        }
        
        if(mn == 2e18){
            mn = 1;
        }
        if(!lessalready){
             ans /= mn;
        }
        cout << ans << endl;
    }

    return 0;
}