#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        string s;
        cin>>s;
        vector<ll> V,L;
        ll con0=0;
        for(auto x:s){
            if((x-'0')==0){
                con0++;
            }
            V.push_back(x-'0');
            L.push_back(x-'0');
        }
        bool ok=false;
        sort(L.begin(),L.end());
        for(int i=0;i<n;i++){
            if(V[i]!=L[i]){
                ok=true;
            }
        }
        if(ok){
            cout<<"Alice\n";
            vector<ll> ans;
            for(int i=0;i<n;i++){
                if(V[i]!=L[i]){
                    ans.push_back(i+1);
                }
            }
            cout<<ans.size()<<"\n";
            for(auto x:ans){
                cout<<x<<" ";
            }
            cout<<"\n";
        }else{
            cout<<"Bob\n";
        }
    }
}