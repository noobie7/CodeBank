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

#define F cout << "NO" << endl; continue;
#define Y cout << "YES" << endl; continue;

int main(){
    Shazam;
    test(){
        int n; cin >> n; 
        vector<ll> a(n);
        get(a);
        if(n == 1){
            F
        }
        auto check = [&](vector<ll> a){
            for(int i = 0; i < a.size() - 1; i++){
                if(a[i] > a[i + 1]) return 0;
                a[i + 1] -= a[i];
                a[i] = 0;
            }
            return (int)( a.back() == 0 );
        };
        if(check(a)){
            Y
        }
        swap(a[0], a[1]);
        if(check(a)){
            Y
        }
        swap(a[0], a[1]);    
        swap(a[n - 1] , a[n - 2]);
        if(check(a)){
            Y
        }
        swap(a[n - 1] , a[n - 2]);
        vector<ll> p(n), s(n);
        vector<ll> b = a;
        p[0] = b[0];
        for(int i = 1; i < n; i++){
            if(p[i-1] == -1 || b[i - 1] > b[i]){
                p[i] = -1;
            }
            else{
                b[i] -= b[i - 1];
                b[i - 1] = 0;
                p[i] = b[i];
            }
        }
        b = a;
        s[n - 1] = b[n - 1];
        for(int i = n - 2; i >= 0; i--){
            if(s[i+1] == -1 || b[i + 1] > b[i]){
                s[i] = -1;
            }
            else{
                b[i] -= b[i + 1];
                b[i + 1] = 0;
                s[i] = b[i];
            }
        }
        for(int i = 1; i + 2 < n; i++){
            vector<ll> og = {p[i-1] , a[i + 1] , a[i], s[i + 2]};
            if(p[i-1] == -1 || s[i + 2] == -1){
                continue;
            }
            if(check(og)){
                cout << "YES" << endl;
                goto here;
            }
        }
        F
        here:;
    }
    return 0;
}