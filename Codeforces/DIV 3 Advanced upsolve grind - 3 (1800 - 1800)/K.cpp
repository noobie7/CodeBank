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

        int b, w; cin >> b >> w;
        if(!b || (!w)){
            if(b + w > 1){
                cout << "NO" << endl;
            }
            else{
                cout << "YES" << endl;
                if(b){
                    cout << "1 2" << endl;
                }
                else{
                    cout << "1 2" << endl;
                }
            }
            continue;
        }
        vector<pair<int, int>> black, white;
        set<pair<int,int>> uni;
        int row = (b > w? 2 : 3);
        for(int i = 0; i < min(b,w); i++){
            black.push_back({row, 2 * i + ( b <= w ? 2 : 3)});
            white.push_back({row, 2 * i + ( b <= w ? 3 : 2)});
            uni.insert({row, 2 * i + ( b <= w ? 2 : 3)});
            uni.insert({row, 2 * i + ( b <= w ? 3 : 2)});
        }
        int k = min(b,w);
        b -= k;
        w -= k;
        if(b || w){
            vector<int> dx = {-1, 1, 0, 0};
            vector<int> dy = {0, 0, 1, -1};
            int on = (b ? b : w);
            for(auto pp : (b ? white : black)){
                int cnt = 0;
                for(int i = 0; i < 4; i++){      
                    if(!uni.count(make_pair(pp.ff + dx[i], pp.ss + dy[i]))){
                        (!b ? white : black).push_back(make_pair(pp.ff + dx[i], pp.ss + dy[i]));
                        uni.insert(make_pair(pp.ff + dx[i], pp.ss + dy[i]));
                        (b ? b-- : w--);
                        cnt++;
                    }
                    if(!w && !b){
                        goto here;
                    }
                }
                if(!cnt) break;

            }
        }
        here:;
        if(w || b){
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
            for(auto pp : black){
                cout << pp.ff << " " << pp.ss << endl;
            }
            for(auto pp : white){
                cout << pp.ff << " " << pp.ss << endl;
            }
        }
    }
    return 0;
}