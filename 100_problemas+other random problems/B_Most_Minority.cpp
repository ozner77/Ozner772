#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n,m;
    cin>>n>>m;
    vector<vector<char>> V(n);
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        for(auto x:s){
            V[i].push_back(x);
        }
    }
    vector<ll> one,zer;
    vector<ll> ans(n,0);
    for(int i=0;i<m;i++){
        one.clear();
        zer.clear();
        for(int j=0;j<n;j++){
            if(V[j][i]=='1'){
                one.push_back(j);
            }else{
                zer.push_back(j);
            }
        }
        if(one.size()<zer.size()){
            for(auto x:one){
                ans[x]++;
            }
        }else{
            for(auto x:zer){
                ans[x]++;
            }
        }
    }
    ll maxi=0;
    for(auto x:ans){
        maxi=max(x,maxi);
    }
    ll res=1;
    for(auto x:ans){
        if(x==maxi){
            cout<<res<<" ";
        }
        res++;
    }
}