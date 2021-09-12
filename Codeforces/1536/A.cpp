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
        vector<int> a(n);
        get(a);
        sort(all(a));
        vector<int> b = a;
        set<int> bag;
        for(int i : a) bag.insert(i);
        bool cant = false;
        if(*bag.begin() < 0){
            cout << "No" << endl;
            continue;
        }
        int c = 0;
        while(b.size() < 300 ){
            c = 0;
            for(int i = 0; i < a.size(); i++){
                for(int j = i + 1; j < a.size(); j++){
                    if(bag.find(abs(a[i] - a[j])) == bag.end()){
                        if(bag.size() == 300){
                            cant = true;
                            goto here;
                        }
                        bag.insert(abs(a[i] - a[j]));
                        b.push_back(abs(a[i] - a[j]));
                        c |= 1;
                        
                    }
                    
                    
                }
            }
            
            if(!c) break;
            sort(all(b));
            a = b;
        }
        here :;
        cout << (!cant ? "Yes" : "No" ) << endl;
        if(cant) continue;
        cout << bag.size() << endl;
        for(int i : bag) cout << i << " ";
        cout << endl;
    }
    return 0;
}