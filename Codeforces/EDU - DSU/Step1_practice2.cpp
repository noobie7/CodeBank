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
    int q; cin >> q;
    vector<list<int>> index(n);
    vector<int> mx(n);
    vector<int> mn(n);
    vector<int> leader(n);
    iota(all(leader), 0);
    iota(all(mx), 0);
    iota(all(mn), 0);
    for(int i = 0; i < n; i++){
        index[i].push_back(i);
    }
    for(int i = 0 ; i < q ; i++){
        string op; cin >> op;
        if(op.size() == 3){
            int a; cin>>a;
            a--;
            cout << mn[leader[a]] + 1 << " " << mx[leader[a]] + 1 << " " << (int)index[leader[a]].size() << endl;
        }
        else{
            int a,b; cin>>a>>b;
            a--;
            b--;
            if(leader[a]==leader[b]) continue;
            if(index[leader[a]].size() > index[leader[b]].size()) swap(a,b);
            mx[leader[b]] = max( mx[leader[a]] , mx[leader[b]] );
            mn[leader[b]] = min( mn[leader[a]] , mn[leader[b]] );
            for(int i : index[leader[a]]){
                index[leader[b]].push_back(i);
                leader[i] = leader[b];
            }

        }
    }

    return 0;
}