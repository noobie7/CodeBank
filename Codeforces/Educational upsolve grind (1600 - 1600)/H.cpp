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
    int n; cin >> n;
    int k; cin >> k;
    set<pair<int,int>> bag; // {rightmost occ. of an element , element's val}
    // set<int> vis; // presence of an element
    vector<int> last(1e6 + 5);
    int l = 1, r = 1;
    int cl = 1, cr = 1;

    auto update = [&](){
        if( cr - cl > r - l ){
            r = cr;
            l = cl;
        }
    };
    for(int i = 1; i <= n; i++){
        int val; cin >> val;
        if(last[val]){
            bag.erase(bag.find(make_pair(last[val], val)));
            last[val] = i;
            bag.insert({last[val], val});
            cr = i;
            update();
        }
        else{
            if(bag.size() < k){
                last[val] = i;
                bag.insert({last[val], val});
                cr = i;
                update();
            }
            else{
                auto pp = *bag.begin();
                int leftmostright = pp.ff;
                int rem = pp.ss;
                last[rem] = 0;
                bag.erase(bag.begin());
                last[val] = i;
                bag.insert({last[val], val});
                cl = leftmostright + 1;
                cr = i;
                update();
            }
        }
    }
    cout << l << " " << r << endl;
    return 0;
}