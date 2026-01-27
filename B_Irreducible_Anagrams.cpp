#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    string s;
    cin>>s;
    ll n;
    cin>>n;
    vector<vector<ll>> P(100);
    for(int i=0;i<100;i++){
        P[i].push_back(0);
    }
    for(int i=0;i<s.size();i++){
        for(int j=0;j<100;j++){
            if(j==s[i]){
                P[j].push_back(P[j][i]+1);
            }else{
                P[j].push_back(P[j][i]);
            }
        }
    }
    
}