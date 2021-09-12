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
    int n, l, r;  
    cin >> n >> l >> r;
    vector<int> a(n), b(n);
    get(a);
    get(b);
    bool cant = false;
    for(int i = 0; i < l-1 ; i++){
        cant |= (a[i]!=b[i]);
    }
    for(int i = r; i < n ; i++){
        cant |= (a[i]!=b[i]);
    }
    vector<int> adash, bdash;
    for(int i = l-1; i < r; i++){
        adash.push_back(a[i]);
        bdash.push_back(b[i]);
    }
    sort(all(adash));
    sort(all(bdash));
    cant |= (adash != bdash);
    cout << ((cant)? "LIE" : "TRUTH") << endl;
    return 0;
}