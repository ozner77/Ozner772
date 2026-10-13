#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n;
    cin>>n;
    string s;
    cin>>s;
    vector<ll> V;
    ll balls=0;
    for(auto x:s){
        if(x=='*'){
            V.push_back(1);
            balls++;
        }else if(x=='P'){
            V.push_back(2);
        }else{
            V.push_back(0);
        }
    }
    ll l=0;
    ll r=2*n;
    ll mid;
    while(l<r){
        mid=(l+r)/2;
        bool ok=true;
        vector<bool> eaten(n,false);
        ll eat=0;
        for(int i=0;i<n;i++){
            ll restante=mid;
            ll left=i;
            if(V[i]==2){
                for(int j=i;j>=0;j--){
                    if(abs(j-i)>restante){
                        break;
                    }
                    if(eaten[j]){
                        break;
                    }
                    if(V[j]==1){
                        eat++;
                        left=j;
                    }
                }
                for(int j=i;j>=left;j--){
                    eaten[j]=true;
                }
                ll d = i - left;
                restante = max(mid - 2*d, (mid - d)/2);
                restante--;
                for(int j=i+1;j<n;j++){
                    if(restante<0){
                        break;
                    }
                    if(V[j]==2){
                        break;
                    }
                    eaten[j]=true;
                    if(V[j]==1){
                        eat++;
                    }
                    restante--;
                    if(restante<0){
                        break;
                    }
                }
            }
        }
        if(eat<balls){
            l=mid+1;
        }else{
            r=mid;
        }
    }
    cout<<l;
}