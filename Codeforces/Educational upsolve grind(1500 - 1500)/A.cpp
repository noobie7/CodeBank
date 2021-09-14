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
    int n, m; cin >> n >> m;
    set<int> bag;
    vector<int> a, b;
    for(int i = 0; i < n; i++){
        int k; cin >> k;
        bag.insert(k);
    }
    for(int i : bag){
        a.push_back(i);
    }
    bag.clear();
    for(int i = 0; i < m; i++){
        int k; cin >> k;
        bag.insert(k);
    }
    for(int i : bag){
        b.push_back(i);
    }
    n = a.size();
    m = b.size();
    bag.clear();
    for(int i : a){
        bag.insert(i);
    }
    auto ok = [&](long long x){
        set<int> curr = bag;
        for(int i : b){
            if(curr.empty()) return true;
            while(*curr.begin() >= i - x && *curr.begin() <= i + x){
                curr.erase(curr.begin());
                if(curr.empty()) return true;
            }
        }
        return curr.empty();
        
    };
    
    auto bs = [&](long long lo, long long hi){
        while(hi-lo > 1){
            long long mid = lo + (hi - lo)/2;
            if(ok(mid))
         
                hi = mid;
            else 
         
                lo = mid;
        }
        return hi;
    };
    
    cout<<bs(-1, 2e9 + 5)<<endl;


    return 0;
}