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
#define pra(a) fl(i,0,a.size()) cout<<a[i];	cout<<endl;
#define pr(a,n) fl(i,0,n) cout<<a[i]<<" ";	cout<<endl;
const ll INF = 2e18;
const int inf = 2e9;
const int mod1 = 1e9 + 7;



int main(){
    Shazam;
    test(){
        int n; cin>>n;
        string s; cin>>s;
        vector<char> ans(1,'-');
       
        for(char dig = '0'; dig < '9' ; dig++){
            vector<int> left, right, center;
            for(int i = 0; i < n; i++){
                if(s[i] < dig ){
                    left.push_back(i);
                }
                else if(s[i] > dig){
                    right.push_back(i);
                }
                else{
                    center.push_back(i);
                }
            }
            while( center.size() && right.size() && center.back() > right.front() ){
                left.push_back( center.back());
                center.pop_back();
            }
            while(center.size()){
                right.push_back( center.back() );
                center.pop_back();
            }
            sort(all(left));
            sort(all(right));
            string f = "";
            for(int i : left){
                f += s[i];
            }
            for(int i : right){
                f += s[i];
            }
            bool can = true;
            for(int i = 1; i < n; i++){
                if( f[i] < f[i-1]) 
                    can = false;
            }
            if(can){
                ans = vector<char> (n , '1');
                for(int i : right){
                    ans[i] = '2';
                }
                break;
            }
        }
        pra(ans);
    }
    return 0;
}