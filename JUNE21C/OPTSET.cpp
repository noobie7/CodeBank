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
        vector<vector<int>> bitcnt(32);
        set<int> avail;
        for(int mask = 0; mask <= n ; mask++){
            for(int bit = 0; bit < 32; bit++){
                if(mask & (1 << bit))
                    bitcnt[bit].push_back(mask);
            }
            avail.insert(mask);
        }
        vector<int> ans;
        for(int i = 31; i >= 0; i--){
            set<int, greater<int>> bag;
            for(int x : bitcnt[i]){
                if(avail.find(x) != avail.end())
                    bag.insert(x);
            }
            int times = bag.size() - (bag.size() & 1 ^ 1);
            for(int cnt = 0; cnt < times; cnt++){
                ans.push_back(*bag.begin());
                avail.erase(avail.find(*bag.begin()));
                bag.erase(bag.begin());
                if(ans.size() == k) 
                    goto here;
            }

        }
        here :;
        pra(ans);   
    }
    return 0;
}