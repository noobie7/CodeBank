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
    int n, m, d; cin >> n >> m >> d; d--;
    vector<int> a(m);
    int tot = 0; 
    for(int &i : a){
        cin >> i;
        tot += i;
    }
    int gaps = n - tot;
    if(d == 0 && gaps){
        cout << "NO" << endl;
        return 0;
    }
    if(!gaps){
        cout << "YES" << endl;
        int c = 1;
        for(int i : a){
            for(int j = 0; j < i; j++) cout << c << " ";
            c++;
        }
        cout << endl;
        return 0;
    }
    if((d)* (m + 1) < gaps){
        cout << "NO" << endl;
        return 0;
    }
    else{
        cout << "YES" << endl;
        vector<int> sequence;
        int i = 0;
        for(; i < gaps / d; i++){
            sequence.push_back(d);
            sequence.push_back(a[i]);
        }
        if(i < m){
            sequence.push_back(gaps % d);
            sequence.push_back(a[i++]);
            for( ; i < m; i++){
                sequence.push_back(a[i]);
            }
        }
        //pra(sequence);
        int out = 0;
        int c = 1;
        vector<int> ans;
        auto eject = [&](int val, int times){
            for(int i = 0; i < times; out++, i++){
                ans.push_back(val);
            }
        };
        for(int i = 0; i < (int)sequence.size(); i++){
            if(i & 1 ^ 1){
                if( gaps % d > 0 ){
                    if(i / 2 <= gaps / d){
                        eject(0, sequence[i]);
                    }
                    else{
                        eject(c++, sequence[i]);
                    }  
                }
                else{
                    if(i / 2 < gaps / d){
                        eject(0, sequence[i]);
                    }
                    else{
                        eject(c++, sequence[i]);
                    } 
                }
            }
            else{
                eject(c++, sequence[i]);
            }
        }
        for(int i = 0; i < n; i++){
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}