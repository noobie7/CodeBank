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
        int p3 = 1;
        for(int i = 0; i < n; i++){
            p3 *= 3;
        }
        for(int p = 1; p < p3 ; p++){
            int k = p;
            ll sum = 0;
            for(int i = 0; i < n; i++){
                int c = k % 3;
                if(c == 2) c = -1;
                k /= 3;
                sum += c * a[i];
            }
            if(sum == 0){
                cout << "YES" << endl;
                goto here;
            }
        }
        cout << "NO" << endl;
        continue;
        here :;
    }
    return 0;
}