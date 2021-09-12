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
    vector<int> uni = {4, 8, 15, 16, 23, 42};
    vector<vector<int>> can(6, vector<int>(6));
    map<int,int> pos;
    for(int i = 1; i <= 6; i++){
        pos[uni[i-1]] = i - 1;
    }
    int beg = -1;
    int end = -1;
    for(int i = 1; i <= 4; i++){
        cout << "? " << i << " " << i + 1 << endl;
        int res; cin >> res;
        if(i == 1){
            beg = res;
        }
        if(i == 4){
            end = res;
        }
        for(int j = 5; j >= 0; j--){
            if(res % uni[j] == 0 && binary_search(all(uni), res/uni[j])){
                can[i-1][(pos[res/uni[j]])]++;
                can[i-1][pos[uni[j]]]++;
                can[i][(pos[uni[j]])]++;
                can[i][pos[res/uni[j]]]++;
                break;
            }
        }
    }
    set<int> bag;
    for(int i : uni){
        bag.insert(i);
    }
    
    vector<int> ans(6);
    for(int i = 1; i < 4; i++){
        for(int j = 0; j < 6; j++){
            if(can[i][j] == 2){
                ans[i] = uni[j];
                break;
            }
        }
    }
    ans[0] = beg / ans[1];
    ans[4] = end / ans[3];
    for(int i = 0; i <= 4; i++){
        bag.erase(bag.find(ans[i]));
    }
   
    cout << "! ";
    for(int i = 0; i <= 4; i++){
        cout << ans[i] << " ";
    } 
    cout << *bag.begin() << endl;
    return 0;
}