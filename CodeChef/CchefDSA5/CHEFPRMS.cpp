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
    vector<int> p(204, 1);
    p[0] = 0;
    p[1] = 0;
    for(int i = 2; i < 204; i++){
        if(p[i]){
            for(int j = 2 * i; j < 204; j += i){
                p[j] = 0;
            }
        }
    }
    set<int> sp;
    vector<int> prime;
    for(int i = 2; i < 200; i++){
        if(p[i]){
            prime.push_back(i);
        }
    }
    int m = prime.size();
    for(int i = 0; i < m ; i++){
        for(int j = i + 1; j < m; j++){
            sp.insert(prime[i] * prime[j]);
        }
    }

    test(){
        int n; cin >> n;
        bool can = false;
        for(int i = 1; i < n; i++){
            if(sp.count(i) && sp.count(n-i))
                can = true;
        }
        cout << ((can)?"YES":"NO") << endl;
    }
    return 0;
}