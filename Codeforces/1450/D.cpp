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
#define pra(a) fl(i,0,a.size()) cout<<a[i];	cout<<endl;
#define pr(a,n) fl(i,0,n) cout<<a[i]<<" ";	cout<<endl;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
const ll INF = 2e18;
const int inf = 2e9;
const int mod1 = 1e9 + 7;


int mx = 3e5 + 100;
vector<int> nl(mx, 1e9), nr(mx,1e9);
int main(){
    Shazam;
    test(){
        int n; cin >> n;
        for(int i = 0; i < n +100 ; i++){
            nl[i] = 1e9;
            nr[i] = 1e9;
        }
        vector<int> a(n);
        get(a);
        int M = *max_element(all(a));
        for(int i = 0; i < n; i++){
            nl[i] = i-1;
            while(~nl[i] && a[nl[i]] <= a[i]){
                nl[i] = nl[nl[i]];
            }
        }
        for(int i = n-1; i >= 0; i--){
            nr[i] = i + 1;
            while(nr[i] < n && a[nr[i]] <= a[i]){
                nr[i] = nr[nr[i]];
            }
        }
        
        map<int,int> f;
        int un = 0;
        vector<int> ans(n);
        for(int i = 0; i <n; i++){
            f[a[i]] = min(nr[i] - i, i - nl[i]);
        }
        for(int i = 1; i <= n; i++){
             if(f.find(i)!= f.end()) un++;
            if(f.find(i)!=f.end() && i < mx);
            else   f[i] = 0;
           
        }
        vector<vector<int>> in(n+1);
        for(auto pp : f){
            if(pp.ff < M){
                in[pp.ss].push_back(pp.ff);
            }
        }
        set<int> curr;
        for(int i = 1; i < n; i++){
            for(int val : in[i]){
                curr.insert(val);
            }
            ans[i] = (curr.size() >= n - (i + 1) + 1 && *curr.begin() == 1 && *curr.rbegin() == curr.size());
        }
        ans[0] = (un == n);
        pra(ans);
    }
    return 0;
}