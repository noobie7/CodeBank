/*
"An anomaly, I'm Muhammad Ali
  Cause I know one day I'm gonna be the"
                - Greatest, Eminem
*/
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
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
    string a, b; cin >> a >> b;
    for(int i = 0; i < a.size(); i++){
        if(a[i] != b[i]){
            int ok = 0;
            if(i + 1 < a.size()){
                swap(a[i], a[i + 1]);
                ok |= (a == b);
                swap(a[i], a[i + 1]);
            }
            if(i){
                swap(a[i], a[i + 1]);
                ok |= (a == b);
            }
            cout << (ok ? "Yes" : "No") << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}