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
const int nag = 2e5 + 5;

vector<vector<int>> g(nag);

int main(){
    Shazam;
    int n; cin >> n;
    vector<array<int,2>> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i][0] >> a[i][1];
        a[i][0]--;
        a[i][1]--;
    }
    auto check = [&](int l, int r){
        vector<int> path;
        for(int i = 0; i < n; i++){
            int nxt = -1;
            if(a[l][1] == r){
                nxt = a[l][0];
                
            }
            else if(a[l][0] == r){
                nxt = a[l][1];
                
            }
            else{
                return 0;
            }
            path.push_back(nxt);
            l = r;
            r = nxt;
            
        }
        for(int i : path) cout << i + 1 << " ";
        cout << endl;
        return 1;
    };
    if(!check(0, a[0][0])){
        check(0, a[0][1]);
    }
    return 0;
}