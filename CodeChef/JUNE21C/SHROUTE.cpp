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
        int n, m; cin >> n >> m;
        vector<ll> a(n);
        get(a);
        vector<ll> b(m);
        get(b);
        vector<int> nearestTo(n, INT_MAX);
        int left = -1;
        for(int i = 0; i < n; i++){
            if(left != -1){
                nearestTo[i] = min(nearestTo[i], abs(left - i));
            }
            if(a[i] == 1) left = i;
        }
        int right = -1;
        for(int i = n - 1; i >= 0; i--){
            if(right != -1){
                nearestTo[i] = min(nearestTo[i], abs(i - right));
            }
            if(a[i] == 2) right = i;
        }
        for(int &i : nearestTo){
            if(i == INT_MAX)
                i = -1;
        }
        nearestTo[0] = 0;

        for(int i = 0; i < n; i++){
            if(a[i])
                nearestTo[i] = 0;
        }

        for(int i = 0; i < m; i++){
            cout << nearestTo[b[i] - 1] << " ";
        }
        cout << endl;
    }
    return 0;
}