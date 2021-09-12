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
    string s; cin >> s;
    int n = (int)s.size();
    vector<int> a(n);
    int curr = 0;
    for(int i = 0; i < n; i++){
        a[i] = s[i] - '0';
        curr += a[i];
    }
    if(curr % 3 == 0){
        cout << 0 << endl;
        return 0;
    }
    sort(all(a));
    reverse(all(a));
    a.push_back(0);
    reverse(all(a));
    for(int i = 1; i < n + 1; i++ ){
        a[i] += a[i-1] ;
    }
    int req = (curr % 3);
    int mn = 1000;
 
    for(int i = 1; i < n+1; i++){
        for(int j = i ; j < n+1; j++){
            if( ( a[j]-a[i-1] ) % 3 == req){
                mn = min(mn, j-i + 1);
            }
        }
    }
    cout << ((mn == 1000 || mn == n)?-1:mn) << endl;
    return 0;
}