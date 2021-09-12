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
    string s , t;
    cin >> s >> t;

    vector<int> ab,ba;
    for(int i = 0; i < n; i++){
        if(s[i] == t[i]) continue;
        if(s[i] == 'a')
            ab.push_back(i+1);
        if(s[i] == 'b')
            ba.push_back(i+1);
    } 
    if(abs((int)ab.size() - (int)ba.size()) & 1) cout<<-1<<endl; 
    else{
        if((int)ab.size() < (int)ba.size()) swap(ab,ba);
        cout<<((int)ab.size() + 1)/ 2  + ((int)ba.size() + 1)/2  <<endl;
        while( (int) ab.size() > 1) {
            cout << ab.back() << " ";
            ab.pop_back();
            cout << ab.back() << endl;
            ab.pop_back();
        }
        while( (int) ba.size() > 1) {
            cout << ba.back() << " ";
            ba.pop_back();
            cout << ba.back() << endl;
            ba.pop_back();
        }
        if(ba.size()){
            cout<< ba.back() << " " << ba.back() << endl;
            cout<< ab.back() << " " << ba.back() << endl;
        }
    }
    return 0;
}