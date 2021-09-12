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
    vector<vector<char>> board(8, vector<char> (8));
    map<char, vector<pair<int,int>>> bag;
    set<pair<int,int>> forbidden;
    ll bkx, bky;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            cin >> board[i][j];
            if(board[i][j] != '.' && board[i][j] != 'B'){
                bag[board[i][j]].push_back({i, j});
            }
            if(board[i][j] == 'B'){
                bkx = i;
                bky = j;
            }
        }
    }
    auto ok = [&](int x, int y){
        return !(forbidden.find({x, y}) != forbidden.end());
    };
    auto valid = [&](int x, int y){
        return (x >= 0 && x <= 7 && y >= 0 && y <= 7);
    };
    for(auto c : bag){
        if(c.ff == 'W'){
            for(auto [x, y] : bag['W']){
                for(int i = -1; i < 2; i++){
                    for(int j = -1; j < 2; j++){
                        if(i == 0 && j == 0) continue;
                        if(valid(x + i , y + j)) 
                            forbidden.insert({x + i, y + j});
                    }
                }
            }
        }
        if(c.ff == 'S'){
            for(auto [x, y] : bag['S']){
                auto last = {0, 0};
                for(int i = 1; i + x < 8 && i + y < 8 && board[x + i][y + i] == '.' ; i++) {
                    forbidden.insert({x + i , y + i});
                    last = {x + i, y + i};
                }
                forbidden.insert({last.ff + 1, last.ss + 1});
                for(int i = 1; i + x < 8 && -i + y >= 0 && board[x + i][y - i] == '.' ; i++) {
                    forbidden.insert({x + i , y - i});
                    last = {x + i, y - i};
                }
                forbidden.insert({last.ff + 1, last.ss - 1});
                for(int i = 1; -i + x >= 0 && i + y < 8 && board[x - i][y + i] == '.' ; i++){
                    forbidden.insert({x - i , y + i});
                    last = {x - i, y + i};
                }
                forbidden.insert({last.ff - 1, last.ss + 1});
                for(int i = 1; -i + x >= 0 && -i + y >= 0 && board[x - i][y - i] == '.' ; i++){
                    forbidden.insert({x - i , y - i});
                    last = {x - i, y - i};
                }
                forbidden.insert({last.ff - 1, last.ss - 1});
            }
        }
        if(c.ff == 'R'){
            for(auto [x, y] : bag['R']){
                auto last = {0, 0};
                for(int i = 1; i + x < 8 && board[i + x][y] == '.'; i++) {
                    forbidden.insert({i + x, y});
                    last = {x + i, y};
                }
                forbidden.insert({last.ff + 1, last.ss});
                for(int i = 1; - i + x >= 0 && board[-i + x][y] == '.'; i++) {
                    forbidden.insert({-i + x, y});
                    last = {x - i, y};
                }
                forbidden.insert({last.ff - 1, last.ss});
                for(int i = 1; i + y < 8 && board[x][y + i] == '.'; i++) {
                    forbidden.insert({ x, i + y});
                    last = {x, y + i};
                }
                forbidden.insert({last.ff, last.ss + 1});
                for(int i = 1; y - i >= 0 && board[x][y - i] == '.'; i++) {
                    forbidden.insert({x, y - i});
                    last = {x , y - i};
                }
                forbidden.insert({last.ff , last.ss - 1});
            }
        }
        if(c.ff == 'Q'){
            for(auto [x, y] : bag['Q']){
                auto last = {0, 0};
                for(int i = 1; i + x < 8 && i + y < 8 && board[x + i][y + i] == '.' ; i++) {
                    forbidden.insert({x + i , y + i});
                    last = {x + i, y + i};
                }
                forbidden.insert({last.ff + 1, last.ss + 1});
                for(int i = 1; i + x < 8 && -i + y >= 0 && board[x + i][y - i] == '.' ; i++) {
                    forbidden.insert({x + i , y - i});
                    last = {x + i, y - i};
                }
                forbidden.insert({last.ff + 1, last.ss - 1});
                for(int i = 1; -i + x >= 0 && i + y < 8 && board[x - i][y + i] == '.' ; i++){
                    forbidden.insert({x - i , y + i});
                    last = {x - i, y + i};
                }
                forbidden.insert({last.ff - 1, last.ss + 1});
                for(int i = 1; -i + x >= 0 && -i + y >= 0 && board[x - i][y - i] == '.' ; i++){
                    forbidden.insert({x - i , y - i});
                    last = {x - i, y - i};
                }
                forbidden.insert({last.ff - 1, last.ss - 1});
                
                for(int i = 1; i + x < 8 && board[i + x][y] == '.'; i++) {
                    forbidden.insert({i + x, y});
                    last = {x + i, y};
                }
                forbidden.insert({last.ff + 1, last.ss});
                for(int i = 1; - i + x >= 0 && board[-i + x][y] == '.'; i++) {
                    forbidden.insert({-i + x, y});
                    last = {x - i, y};
                }
                forbidden.insert({last.ff - 1, last.ss});
                for(int i = 1; i + y < 8 && board[x][y + i] == '.'; i++) {
                    forbidden.insert({ x, i + y});
                    last = {x, y + i};
                }
                forbidden.insert({last.ff, last.ss + 1});
                for(int i = 1; y - i >= 0 && board[x][y - i] == '.'; i++) {
                    forbidden.insert({x, y - i});
                    last = {x , y - i};
                }
                forbidden.insert({last.ff , last.ss - 1});
            }
        }
       
    }
    int x = bkx;
    int y = bky;

    bool check = (forbidden.find({x, y}) != forbidden.end());
    bool surroundedCheck = 1;
    for(int i = -1; i < 2; i++){
        for(int j = -1; j < 2; j++){
            if(i == 0 && j == 0) continue;
            surroundedCheck &= (forbidden.find({x+ i, y + j}) != forbidden.end());
            cout << x + i << " " << y + j << " " << surroundedCheck << endl;
        }
    }
    if(check && surroundedCheck){
        cout << "CheckMate" << endl;
    }
    else if(check){
        cout << "Check" << endl;
    }
    else if(surroundedCheck){
        cout << "StaleMate" << endl;
    }
    else{
        cout << "Nothing" << endl;
    }
    return 0;
}