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
        int k; cin >> k;
        int ans = 1;
        set<vector<pair<int,int>>> bag;
        set<int> curr;
        vector<pair<int,int>> res;
        auto fac = [&](int x){
            vector<pair<int,int>> b;
            for(int i = 2; i * i <= x; i++){
                if(x % i == 0){
                    int cnt = 0;
                    while(x % i == 0){
                        x /= i;
                        cnt++;
                    }
                    b.push_back({i, cnt});
                }
            }
            if(x >= 2){
                b.push_back({x, 1});
            }
            if(b.size() == 0){
                return;
            }
            vector<int> cnt(b.size());
            for(int i = 0; i < b.size() ; i++){
                cnt[i] = b[i].ss;
            }
            int mx = *max_element(all(cnt));
            res.clear();
            for(int i = 0; i < b.size(); i++){
                if(mx - b[i].ss + mx & 1)
                res.push_back({b[i].ff , mx - b[i].ss + (mx & 1)});
            }
        };
        auto got = [&](vector<pair<int,int>> &a){

            vector<int> cnt(a.size());
            for(int i = 0; i < a.size(); i++){
                cnt[i] = a[i].ss;
            }
            int mn = *min_element(all(cnt));

            for(int i = mn; i >= 0; i--){
                vector<pair<int,int>> lol;
                for(int j = 0; j < a.size(); j++){
                    if(a[j].ss - i)
                        lol.push_back( {a[j].ff, a[j].ss - i} );
                }
                if(bag.find(lol) != bag.end()){
                    return 1;
                }
            }
            return 0;
        };
        auto ok = [&](int x){
            for(int i = 2; i * i < x; i++){
                if(x % i == 0){
                    return false;
                }
            }
            return true;
        };
        for(int i = 0; i < n; i++){
            int a; cin >> a;
            fac(a);
            if(a){
                if(curr.size()){
                    bool o = false;
                    for(auto num : curr){
                        if(ok(num)){
                            o = true;
                            break;                        
                        }
                    }
                    if(o){
                        curr.clear();
                        ans++;
                    }
                }
                continue;
            }
            if(got(res)){
                ans++;
                bag.clear(); 
                curr.clear();
                curr.insert(a);
            }
            bag.insert(res);

        }
        cout << ans << endl;
    }
    return 0;
}