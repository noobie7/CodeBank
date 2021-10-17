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
    int n, m; cin >> n >> m;
    vector<string> a(2 * n);
    get(a);
    auto ok = [&](pair<int, int> a, pair<int, int> b){
        if(a.ff == b.ff) return a.ss < b.ss;
        return a.ff > b.ff;
    };

    auto calc = [&](char a, char b){
        if(a == b) return 0;
        if( (a == 'G' && b == 'C') || (a == 'C' && b == 'P') || (a == 'P' && b == 'G') ) return 1;
        return -1;
    };

    vector<pair<int,int>> rank(2 * n);
    for(int i = 0; i < 2 * n; i++){
        rank[i].ss = i;
    }

    for(int round = 0; round < m; round++){
        for(int i = 0; i + 1 < 2 * n; i += 2){
            //update scores acc. to their ranks    
            char move_a = a[rank[i].ss][round];
            char move_b = a[rank[i + 1].ss][round];
            int res = calc(move_a, move_b);
            if(res == 0) continue;
            if(res == 1) rank[i].ff++;
            else         rank[i + 1].ff++;
        }
        sort(all(rank), ok);
    }
    for(auto pp : rank){
        cout << pp.ss + 1 << endl;
    }

    return 0;
}