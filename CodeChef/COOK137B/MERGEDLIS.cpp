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
#define Shazam ios_base::sync_with_stdio(false);   cin.tie(NULL); cout.tie(NULL);
#define all(c) c.begin(),c.end()
#define endl "\n"
#define test() int t; cin>>t; while(t--)
#define get(a) for(auto &i : a)  cin>>i;
#define pra(a) for(auto i : a) cout<< i <<" ";	cout<<endl;
const ll INF = 2e18;
const int inf = 2e9;
const int mod1 = 1e9 + 7;



int main(){
    Shazam;
    test(){
        int n, m; cin >> n >> m;
        vector<int> a(n), b(m);
        get(a);
        get(b);
        vector<int> c;
        int mxa = 0, mxb = 0;
        for(int i = 0; i < n; i++){
            if(c.size() == 0){
                c.push_back(a[i]);
            }
            else{
                int pos = upper_bound(all(c), a[i]) - c.begin();
                if(pos == c.size()){
                    c.push_back(a[i]);
                }
                else{
                    c[pos] = a[i];
                }
            }
            mxa = max(mxa, (int)c.size());
        }
        c.clear();
        int ex = 0;
        for(int i = 0; i < m; i++){
            if(c.size() == 0){
                c.push_back(b[i]);
            }
            else{
                int pos = upper_bound(all(c), b[i]) - c.begin();

                if(pos == c.size()){
                    c.push_back(b[i]);
                }
                else{
                    c[pos] = b[i];
                }
            }
            mxb = max(mxb,  (int)c.size());
        }
        cout << mxa + mxb << endl;
    }
    return 0;
}