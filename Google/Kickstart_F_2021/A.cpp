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
    int c = 1;
    test(){
        int n; cin >> n;
        string s; cin >> s;
        vector<int> leftof(n), rightof(n);
        int left = -1;
        for(int i = 0; i < n; i++){
            if(s[i] == '1'){
                left = i;
            }
            if(left != -1)
                leftof[i] = abs(left - i);
            else
                leftof[i] = -1;
        }
        int right = -1;
        for(int i = n - 1; i >= 0; i--){
            if(s[i] == '1'){
                right = i;
            }
            if(right != -1)
                rightof[i] = abs(right - i);
            else
                rightof[i] = -1;
        }
        ll ans = 0;
        for(int i = 0; i < n; i++){
            assert((leftof[i] != -1 || rightof[i] != -1));
            if(leftof[i] == -1){
                ans += rightof[i];
            }
            else if(rightof[i] == -1){
                ans += leftof[i];
            }
            else{
                ans += min(leftof[i], rightof[i]);
            }
            
        }
        cout<<"Case #"<<c<<": "<< ans <<endl;;
        c++;
    }
    return 0;
}