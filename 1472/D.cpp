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
        int eve = 0;
        int odd = 0;
        priority_queue<int> alice, bob;
        vector<ll> a(n);
        for(int i = 0 ; i < n; i++){
            cin >> a[i];
            if(a[i] & 1){
                odd++;
                bob.push(a[i]);
            }
            else{
                eve++;
                alice.push(a[i]);
            }
        }
        ll scorea = 0, scoreb = 0;
        int turn = 1;
        while(alice.size() || bob.size()){
            turn ^= 1;
            if(!alice.size()){
                ll val = bob.top();
                bob.pop();
                if(turn & 1 ^ 1){
                    scorea += 0;
                }
                else{
                    scoreb += val;
                }
                continue;
            }
            else if(!bob.size()){
                ll val = alice.top();
                alice.pop();
                if(turn & 1 ^ 1){
                    scorea += val;
                }
                else{
                    scoreb += 0;
                }
                continue;
            }
            if(alice.top() > bob.top()){
                ll val = alice.top();
                alice.pop();
                if(turn & 1 ^ 1){
                    scorea += val;
                }
                else{
                    scoreb += 0;
                }
            }
            else{
                ll val = bob.top();
                bob.pop();
                if(turn & 1 ^ 1){
                    scorea += 0;
                }
                else{
                    scoreb += val;
                }
            }
        }

        if(scorea == scoreb){
            cout << "Tie" << endl;
            continue;
        }
        cout << ((scorea > scoreb)? "Alice" : "Bob") << endl;
    }
    return 0;
}