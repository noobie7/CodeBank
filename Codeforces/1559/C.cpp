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
    test(){
        int n; cin >> n;
        vector<int> a(n);
        get(a);
        if(a.front() == 1){
            cout << n + 1 << " ";
            for(int i = 1; i <= n; i++){
                cout << i << " ";
            }
            cout << endl; 
            continue;
        }
        for(int i = 0; i < n - 1; i++){
            if(a[i] == 0 && (a[(i + 1)] == 1)){
                for(int j = 1; j <= i + 1; j++){
                    cout << j << " ";
                }
                cout << n + 1 << " ";
                for(int j = i + 2; j <= n; j++){
                    cout << j << " ";
                }
                cout << endl;
                goto here;
            }
        }
        if(count(all(a), 0) == n){
            for(int i = 0; i <= n; i++){
                cout << i + 1 << " ";
            }
            cout << endl;
            continue;
        }
        cout << -1 << endl;
        continue;
        here:;
    }
    return 0;
}