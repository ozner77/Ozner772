#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    set<char> ans;
    string s;
    cin>>s;
    unordered_map<char,ll> M;
    for(auto x:s){
        M[x]++;
    }
    ll maxi=0;
    for(auto x:M){
        maxi=max(maxi,x.second);
    }
    for(auto x:M){
        if(x.second==maxi){
            ans.insert(x.first);
        }
    }
    cout<<*ans.begin();
}