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
        ll a, b, n; cin >> a >> b >> n;
        vector<ll> attack(n), health(n);
        vector<array<ll,2>> ip(n);
        for(int i = 0 ; i < 2; i++){
            for(int j = 0; j < n; j++){
                cin >> ip[j][i];
            }
        }
        sort(all(ip));
        for(int i = 0; i < n; i++){
            attack[i] = ip[i][0];
            health[i] = ip[i][1];
        }
        for(int i = 0; i < n; i++){
            ll moves = (health[i] + a - 1) / a;
            b -= moves * attack[i];
            if(moves && b + attack[i] <= 0 ){
                cout << "NO" << endl;
                goto here;
            }
            if(b <= 0 && i != n - 1){
                cout << "NO" << endl;
                goto here;
            }
        }
        cout << "YES" << endl;
        continue;
        here :;
    }
    return 0;
}