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
    int nag = 3e6;
    vector<int> prime(nag,1);
    prime[0] = prime[1] = 0;
    for(int i = 2; i * i <= nag; i++){
        if(prime[i]){
            for(int j = 2 * i; j < nag; j += i){
                prime[j] = 0;
            }
        }
    }
    vector<int> uni;
    vector<pair<int,int>> purrfect;
    for(int i = 2; i < nag; i++){
        if(prime[i]){
            uni.push_back(i);
        }
    }

    for(int i = 0; i < uni.size(); i++){
        if(prime[i + 1]){
            purrfect.push_back({uni[i], i+1});
        }
    }
    
    int n; cin >> n;
    vector<int> a(2 * n);
    get(a);
    multiset<int> bag = multiset<int> (all(a));
    vector<int> ans;
    while(bag.size() && ans.size() < n){
        int bk = *bag.rbegin();
        bag.erase(bag.find(bk));
        if(prime[bk]){
            auto ps = *lower_bound(all(purrfect), make_pair(bk,0));
            bag.erase(bag.find(ps.ss));
            ans.push_back(ps.ss);
            continue;
        }
        int mx = 0;
        for(int div = 2; div * div <= bk; div++){
            if(bk % div == 0){
                mx = max({mx, div, bk/div});
            }
        }
        if(bag.count(mx)){
            bag.erase(bag.find(mx));
            ans.push_back(bk);
        }
    }
    pra(ans);
    
    return 0;
}