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
        int a, b, c; 
        cin >> a >> b >> c;
        int oa = a, ob = b, oc = c;
        if(abs(a - b) == 1){
            cout << -1 << endl;
            continue;
        }
        if(a > b){
            swap(a, b);
        }
        b -= (a - 1);
        a -= (a - 1);
        if(max({oa, ob, oc}) > 2 * (b - 1)){
            cout << -1 << endl;
            continue;
        }
        if(c <= (b - 1)){
            b += (c - a);
            a += (c - a);
            cout << b << endl;
        }
        else{
            a += (c - (b));
            b += (c - (b));
            cout << a << endl;
        }
    }
    return 0;
}