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
        int n; cin >> n;
        vector<ll> c(n), a(n), b(n);
        get(c);
        get(a);
        get(b);
        for(int i = 0; i < n; i++){
            if(a[i] > b[i]){
                swap(a[i], b[i]);
            }
        }
        auto calc = [&](vector<ll> & v){
            int x = v.size();
            ll res = 0;
            
        };
        ll ans = 0;
        for(int i = n-1; i >=0 ;i--){
            ll curr = c[i];
            vector<ll> trex; 
            int j = i - 1;
            ll tp = 1;
            ll bt = c[i];
            trex.push_back(c[i]);
            for( ; j >= 0; j--){
                if(a[j + 1] == b[j + 1]){
                    curr++;    
                    break;
                }
                tp = a[j + 1];
                bt = b[j + 1];
                trex.push_back(bt - tp + 1);
            }
            i = j;
        }
        
        cout << ans << endl;
    }
    return 0;
}