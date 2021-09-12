/*
"Won't stop until I'm phenomenal."
- Phenomenal, Eminem
 */
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
        int n; cin>>n;
        vector<pair<pair<int,int>, pair<int,int>>> eve(n);
        for(int i = 0 ; i < n; i++){
            cin>>eve[i].ff.ff>>eve[i].ff.ss>>eve[i].ss.ff;
            eve[i].ss.ss = i+1;
        }
        while(eve.size()){
            sort(all(eve));
            int x = eve.back().ff.ff;
            int y = eve.back().ff.ss;
            int z = eve.back().ss.ff;
            int i = eve.back().ss.ss;
            eve.pop_back();
            ll mn = INT_MAX;
            int ind = -1;
            for(int j = 0; j < eve.size(); j++){
                ll curr = 0;
                curr += abs(eve[j].ff.ff - x);
                curr += abs(eve[j].ff.ss - y);
                curr += abs(eve[j].ss.ff - z);
                if(curr < mn){
                    mn = curr;
                    ind = j;
                }
            }
            cout<<i<<" "<<eve[ind   ].ss.ss<<endl;
            eve.erase(eve.begin() + ind);
        }

    return 0;
}