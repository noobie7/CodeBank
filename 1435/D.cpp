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
    int n; cin>>n;
    int pos = 0, neg = 0;
    bool cant = false;
    vector<int> ans;
    int chkfrom  = -1;
    vector<int> st;

    vector<vector<int>> order(n+1);
    int c = 0;
    for(int i = 0 ; i < 2*n ; i++){
        char op; cin>>op;
        if(op == '+'){ pos++; c++;}
        else{
            int val; cin>>val; 
            if(val > n - (pos - neg) + 1){
               // cout<<"not valid entry of "<<val<<" should be less than "<<n-(pos-neg+1)<<endl;
                cant = true;
            }
            st.push_back(val); 
            if(order[c].size() && val < order[c].back()){ cant = true; 
            //cout<<"invalid contiguity "<<order[c].back()<<" "<<val<<endl;
            }
            order[c].push_back(val); 
            neg++;
        }
        if(neg > pos) cant = true;
       
    }
    if(cant){
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl;
        int cnt = 0;
        int last = -1;
        for(int i = c; i >=0 ; i--){
            if(order[i].size()==0) continue;
            for(int j : order[i]){
                if(last == -1){
                    last = j;
                    continue;
                }
                cout<<j<<" ";
                cnt++;
            }
            break;
        }
        for(int i = 0; i < c+1; i++){
            if(order[i].size()==0) continue;
            for(int j : order[i]){
                cout<<j<<" ";
                cnt++;
            }
            if(cnt >= n-1) break;
        }
        if(cnt!=n){
            cout<<last<<endl;
        }
    }
    return 0;
}