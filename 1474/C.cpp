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
        vector<ll> a(n * 2);
        get(a);
        sort(all(a));
        multiset<ll> thems;
        for(auto i : a){
            thems.insert(i);
        }
        bool got = 0;
        auto calc = [&](ll x){
            multiset<ll> ms = thems;
            vector<pair<ll,ll>> res;
            for(int i = 0; i < n; i++){
                auto it1 = ms.end();
                it1--;
                ll val = *it1;
                ms.erase(it1);
                if(ms.find(x -  val) == ms.end()){
                    res.clear();
                    return res;
                }
                res.push_back({val,x - val});
                ms.erase(ms.find(x - val));
                x = max(val, x - val);
            }
            return res;
        };
        for(int i = 0; !got && i < 2 * n - 1; i++){
            int x = a[i] + a[2 * n - 1];
            vector<pair<ll,ll>> res = calc(x);
            if(res.size() > 0){
                got = 1;
                cout << "YES" << endl;
                cout << x << endl;
                for(auto pp : res){
                    cout << pp.ff << " " << pp.ss << endl;
                }
            }
        }
        if(!got){
            cout << "NO" << endl;
        }
    }
    return 0;
}