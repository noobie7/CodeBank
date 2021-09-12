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
    set<pair<char,char>> bag;
    bag.insert({'d', 'b'});
    bag.insert({'b', 'd'});
    bag.insert({'o', 'o'});
    bag.insert({'x', 'x'});
    bag.insert({'v', 'v'});
    bag.insert({'w', 'w'});
    bag.insert({'p', 'q'});
    bag.insert({'q', 'p'});
    bag.insert({'w', 'w'});
    bag.insert({'A', 'A'});
    bag.insert({'H', 'H'});
    bag.insert({'I', 'I'});
    bag.insert({'M', 'M'});
    bag.insert({'O', 'O'});
    bag.insert({'T', 'T'});
    bag.insert({'U', 'U'});
    bag.insert({'V', 'V'});
    bag.insert({'W', 'W'});
    bag.insert({'Y', 'Y'});
    bag.insert({'X', 'X'});
    string s; cin >> s;
    int n = s.size();

    if(bag.find(make_pair(s[n/2], s[n - 1 - n/2])) == bag.end()){
        cout << "NIE" << endl;
        return 0;
    }

    for(int i = 0; i < n/2; i++){
        if(bag.find(make_pair(s[i], s[n - 1 - i])) == bag.end()){
            cout << "NIE" << endl;
            return 0;
        }
    }
    cout << "TAK" << endl;
    return 0;

}