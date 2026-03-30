#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n;
    cin>>n;
    vector<vector<char>> V(n);
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        for(auto x:s){
            V[i].push_back(x);
        }
    }
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        for(int j=0;j<n;j++){
            if(V[i][j]!=s[j]){
                cout<<i+1<<" "<<j+1;
            }
        }
    }
}