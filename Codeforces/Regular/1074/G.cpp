#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<vector<ll>> V;
        map<ll,map<ll,ll>> contador,part,extra;
        for(ll i=0;i<n;i++){
            ll l;
            cin>>l;
            vector<ll> L(l);
            for(ll j=0;j<l;j++){
                cin>>L[j];
                contador[i][L[j]]++;
            }
            sort(L.begin(),L.end());
            V.push_back(L);
        }
        vector<ll> MEX(n,0);
        ll ind=0;
        for(auto x:V){
            set<ll> S;
            for(auto y:x){
                S.insert(y);
            }
            ll con=0;
            bool continuar=true;
            ll con2=0;
            ll LOL=-1;
            for(auto y:S){
                if(y!=con){
                    if(continuar){
                        continuar=false;
                        con2++;
                        LOL=y;
                    }else{
                        break;
                    }
                }else{
                    part[ind][y]=1;
                }
                con++;
            }
            if(LOL==-1){
                LOL=con+1;
                con2++;
            }
            extra[ind][LOL]=con2;
            MEX[ind]=con-con2;
            ind++;
        }
        ll suma=0;
        for(auto x:MEX){
            suma+=x;
        }
        ll ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<V[i].size();j++){
                if(part[i][V[i][j]]==1 && contador[i][V[i][j]]==1){
                    
                }
            }
        }
    }
}