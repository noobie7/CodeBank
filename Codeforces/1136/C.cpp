/*
"An anomaly, I'm Muhammad Ali
  Cause I know one day I'm gonna be the"
                - Greatest, Eminem
*/
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include<bits/stdc++.h>
using namespace std;
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
const ll INF = 2e18;
const int inf = 2e9;
const int mod1 = 1e9 + 7;



int main(){
    Shazam;
    int n,m; cin >> n >> m;
    map< int , multiset<int> > one, two;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int k; cin>>k;
            one[i+j].insert(k);
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int k; cin>>k;
            two[i+j].insert(k);
        }
    }
    bool can = true;
    for(auto pp : one){
        int dd = pp.ff;
        if(pp.ss != two[dd]){
            can = false;
        }
    }
    cout<< ((can)? "YES" : "NO") << endl;
    return 0;
}