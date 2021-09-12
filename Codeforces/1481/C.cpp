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
    test(){
        int n; cin >> n;
        int m; cin >> m;
        vector<int> a(n);
        get(a);
        vector<int> b(n);
        get(b);
        vector<int> c(m);
        get(c);
        map<int,vector<int>> color_at, same_color_at;
        map<int,int> future_demand;
        for(int i : c){
            future_demand[i]++;
        }

        for(int i = 0; i < n; i++){
            same_color_at[b[i]];
            color_at[b[i]];
            if(a[i] == b[i])
                same_color_at[b[i]].push_back(i);
            else
                color_at[b[i]].push_back(i);
        }
        for(auto pv : same_color_at){
            for(int i : pv.ss){
                color_at[pv.ff].push_back(i);
            }
            reverse(all(color_at[pv.ff]));
        }
        vector<int> final(n);
        vector<int> assigned;
        for(int i : c){
            if(color_at.count(i)){
                final[color_at[i].back()] = i;
                assigned.push_back(color_at[i].back() + 1);
                if(color_at[i].size() > 1) color_at[i].pop_back();
            }
            else if(future_demand.size()){
                int dothis = -1;
                for(auto pp : future_demand){
                    if(pp.ff != i && color_at.count(pp.ff)){
                        dothis = pp.ff;
                        break;
                    }
                }
                if(dothis == -1){
                    goto here;
                }
                assigned.push_back(color_at[dothis].back() + 1);
                final[color_at[dothis].back()] = i;
            }
            else{
                break;
            }
            future_demand[i]--;
            if(future_demand[i] == 0){
                future_demand.erase(future_demand.find(i));
            }
        }
        for(int i = 0; i < n; i++){
            if(!final[i] && a[i] == b[i]){
                final[i] = b[i];
            }
        }
        if(final == b){
            cout << "YES" << endl;
            pra(assigned);
        }
        else{
            here:;
            cout << "NO" << endl;
        }

    }
    return 0;
}