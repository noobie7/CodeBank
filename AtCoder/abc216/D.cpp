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
    vector<vector<int>> a(m);
    for(int i = 0; i < m; i++){
        int k; cin >> k;
        vector<int> curr(k);
        get(curr);
        reverse(all(curr));
        a[i] = curr;
    }
    set<int> visit;
    for(int i = 0; i < m; i++){
        visit.insert(i);
    }
    int count = 0;
    map<int,vector<int>> f;
    while(true){
        int got = 0;
        int emp = 0;
       
        if(visit.size() == 0 && count == 2 * n){
            cout << "Yes" << endl;
            return 0;
        }
        for(int i : visit){
            if(a[i].size() == 0) 
                continue;
          	int ele = a[i].back();
            f[ele].push_back(i);
        }

        set<int> cur;
        vector<int> rem;
        for(auto pp : f){
            if(pp.ss.size() == 2){
                got = 1;
                count += 2;
                rem.push_back(pp.ff);
                for(int i : pp.ss){
                    a[i].pop_back();
                    if(a[i].size())
                        cur.insert(i);
                }
            }
        }
        for(int i : rem){
            f.erase(f.find(i));
        }
        visit = cur;
        if(got == 0){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}