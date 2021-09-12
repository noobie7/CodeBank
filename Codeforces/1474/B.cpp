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
const int nag = 1e6;


int main(){
    Shazam;
    vector<ll> primes;
    vector<int> is(nag,1);
    is[0] = 0;
    is[1] = 1;
    for(int i = 2; i < nag; i++){
        for(int j = 2 * i; j < nag; j += i){
            is[j] = 0;
        }
    }
    for(int i = 0; i < nag; i++){
        if(is[i]){
            primes.push_back(i);
        }
    }
    test(){
        ll d; cin >> d;
        ll num = 1;
        ll curr = 1;
        for(int i = 0; i < 2; i++){
            num *= (*lower_bound(all(primes), curr + d));
            curr = (*lower_bound(all(primes), curr + d));
        }
        cout << num << endl;
    }
    return 0;
}