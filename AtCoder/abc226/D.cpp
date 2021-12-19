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
    int n; cin >> n;
    vector<pair<int,int>> a(n);
    for(int i = 0; i < n; i++){
        int x, y; cin >> x >> y;
        a[i] = make_pair(x, y);
    }
    sort(all(a));
    set<pair<int,int>> bag;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            bag.insert(make_pair(a[j].ff - a[i].ff, a[j].ss - a[i].ss));
        }
    }
    vector<pair<int,int>> val;
    for(auto pp : bag){
        val.push_back(pp);
    }
    bag.clear();
    for(int i = 0; i < val.size(); i++){
        int g = gcd(val[i].ff, val[i].ss);
        val[i].ff /= g;
        val[i].ss /= g;
        bag.insert(val[i]);
    }
    cout << bag.size() * 2 << endl;
    return 0;
}