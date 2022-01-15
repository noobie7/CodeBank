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
#define Shazam ios_base::sync_with_stdio(false);   cin.tie(NULL); cout.tie(NULL);
#define all(c) c.begin(),c.end()
#define endl "\n"
#define test() int t; cin>>t; while(t--)
#define get(a) for(auto &i : a)  cin>>i;
#define pra(a) for(auto i : a) cout<< i <<" ";	cout<<endl;
const ll INF = 2e18;
const int inf = 2e9;
const int mod1 = 1e9 + 7;



int main(){
    Shazam;
    int n, m, q; 
    cin >> n >> m >> q;
    vector<vector<int>> ed;
    vector<int> ans(q);
    for(int i = 0; i < m; i++){
        int a, b, w;
        cin >> a >> b >> w;
        a--;
        b--;
        vector<int> c_ed;
        c_ed.push_back(w);
        c_ed.push_back(a);
        c_ed.push_back(b);
        c_ed.push_back(0);
        ed.push_back(c_ed);
    }
    for(int i = 1; i <= q; i++){
        int a, b, w;
        cin >> a >> b >> w;
        a--;
        b--;
        vector<int> c_ed;
        c_ed.push_back(w);
        c_ed.push_back(a);
        c_ed.push_back(b);
        c_ed.push_back(i);
        ed.push_back(c_ed);
    }
    sort(all(ed));
    vector<int> leader(n);
    iota(all(leader), 0);
    vector<list<int>> lister(n);
    for(int i = 0; i < n; i++){
        lister[i].push_back(i);
    }
    for(int i = 0; i < ed.size(); i++){
        if(ed[i].back()){
            int a = ed[i][1];
            int b = ed[i][2];
            a = leader[a];
            b = leader[b];
            if(a != b){
                ans[ed[i].back() - 1] = 1;
            }
            continue;
        }
        int a = ed[i][1];
        int b = ed[i][2];
        a = leader[a];
        b = leader[b];
        if(a == b) continue;
        if(lister[a].size() > lister[b].size()){
            swap(a, b);
        }
        for(int i : lister[a]){
            leader[i] = b;
            lister[b].push_back(i);
        }
    }
    for(int i = 0; i < ans.size(); i++){
        cout << (ans[i] ? "Yes" : "No") << endl;
    }

    return 0;
}