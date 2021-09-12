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
        int n, k; cin >> n >> k;
        ll mx = 1;
        ll okl = -1;
        ll okr = -1;
        for(ll i = 2; i <=n; i++){
           for(ll j = 1; j < i; j++){
               if(j * (i - j)  == k && i + 2 <= n ){
                   okl = j;
                   okr = i - j;
               }
               mx = max(mx, j * ( i - j));
           }
        }      
        if(k > mx || okl == -1){
            cout << -1 << endl;
            continue;
        }  
       
        vector<int> line( n - ( okl + okr ));
        iota(all(line),1);
        
        vector<pair<int,int>> vp;
        for(int i = 0; i < line.size()-1; i++){
            vp.push_back({line[i], line[i+1]});
        }
        int curr = line.size();
        for(int i = line.size(); i < okl + line.size() ; i++){
            vp.push_back({line.back(),i+1});
            curr++;
        }
        for(int i = curr; i < okr + curr; i++ ){
            vp.push_back({line.front(), i + 1});
        }
        cout << vp.size() << endl;
        for(auto pp : vp){
            cout << pp.ff << " " << pp.ss << endl;
        }
    }
    return 0;
}