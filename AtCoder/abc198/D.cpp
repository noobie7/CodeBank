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
    vector<int> val(10);
    iota(all(val), 0);
    string a, b, c; 
    cin >> a >> b >> c;
    set<char> bag;
    for(char c : a){
        bag.insert(c);
    }
    
    for(char c : b){
        bag.insert(c);
    }
    
    for(char c : c){
        bag.insert(c);
    }
    if(bag.size() > 10){
        cout << "UNSOLVABLE" << endl;
        return 0;
    }

    vector<char> letters;
    vector<int> whereat(26);
    for(char c : bag){
        letters.push_back(c);
    }
    for(int i = 0; i < letters.size(); i++){
        whereat[letters[i] - 'a'] = i;
    }
    auto getnum = [&](string s){
        ll res = 0;
        for(char c : s){
            int loc = whereat[c - 'a'];
            ll currval = val[loc];
            res *= 10LL;
            res += currval;
            if(!res) return 0LL;
        }
        return res;
    };

    do{
        ll num1 = getnum(a);
        ll num2 = getnum(b);
        ll num3 = getnum(c);
        if(num1 && num2 && num3 && num1 + num2 == num3){
            cout << num1 << endl;
            cout << num2 << endl;
            cout << num3 << endl;
            return 0;
        }
    }while(next_permutation(all(val)));
    cout << "UNSOLVABLE" << endl;
    return 0;
}