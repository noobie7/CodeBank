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
    int n; cin >> n;
    vector<ll> a(n);
    get(a);
    sort(all(a));
    auto ok = [&](long long x){

        map<ll,int> f;
        int bal = 0;
        for(long long  i : a){
            if(i % x == 0) {
                bal++;
                continue;
            } 
            f[i % x]++;
        }

        if(bal & 1) return 0;
        for(auto pp : f){
            if(f.find(x - pp.ff) == f.end()) return 0;
            if(f[x  - pp.ff] != pp.ss) return 0;
        }
        return 1;
    };
    
    ll ans = 0;

    for(int i = 1; i < n; i++){
        ll sum = a[0] + a[i];
        for(ll div = 1; div * div <= sum; div++){
            ll trywith = div;
            if(sum % trywith == 0){
                if(ok(trywith)){
                    ans = max(ans, trywith);
                }
                if(div != sum / div){
                    trywith = sum / div;
                    if(ok(trywith)){
                        ans = max(ans, trywith);
                    }
                }
            }
        }
    }


    cout << ans << endl;
    return 0;
}