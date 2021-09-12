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
        vector<ll> c(3);
        get(c);
        vector<ll> a(5);
        get(a);
        bool can = true;
        for(int i = 0; i < 3; i++){
            if(a[i] > c[i]){
                can = false;
            }
        }
        if(!can){
            cout << "No" << endl;
            continue;
        }

        a[3] -= c[0] - a[0];
        a[4] -= c[1] - a[1];
        if(a[3] + a[4] <= c[2] - a[2] && (a[4] <=  c[2] - a[2]) && (a[3] <= c[2] - a[2])){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
        
        
    }
    return 0;
}