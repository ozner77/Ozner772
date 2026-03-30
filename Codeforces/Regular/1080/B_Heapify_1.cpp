#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t;
    cin>>t;
    while(t--){
        map<ll,ll> M;
        ll n;
        cin>>n;
        vector<ll> V,L;
        for(int i=0;i<n;i++){
            ll a;
            cin>>a;
            V.push_back(a);
            L.push_back(a);
        }
        sort(L.begin(),L.end());
        vector<vector<pair<ll,ll>>> A;
        vector<bool> visited(n,false);
        for(int i=0;i<n;i++){
            ll ind=i;
            if(!visited[i]){
                vector<pair<ll,ll>> B;
                while(ind<n){
                    visited[ind]=true;
                    B.push_back({V[ind],ind});
                    ind++;
                    ind*=2;
                    ind--;
                }
                A.push_back(B);
            }
        }
        for(auto x:A){
            ll mini=1e10;
            for(auto y:x){
                mini=min(mini,y.second);
            }
            sort(x.begin(),x.end());
            for(auto y:x){
                M[mini]=y.first;
                mini++;
                mini*=2;
                mini--;
            }
        }
        bool ok=true;
        for(int i=0;i<n;i++){
            if(L[i]!=M[i]){
                ok=false;
            }
        }
        if(ok){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }
}