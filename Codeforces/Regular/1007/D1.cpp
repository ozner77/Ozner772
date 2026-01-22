#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> V;
ll xd;
ll solve(ll num){
    if(num%2!=0){
        return xd;
    }
    if(num<=V.size()){
        return xd^V[num-1];
    }
    return xd^solve(num/2);
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,l,r;
        cin>>n>>l>>r;
        xd=0;
        V.clear();
        for(int i=0;i<n;i++){
            ll a;
            cin>>a;
            V.push_back(a);
        }
        if(n%2==0){
            n++;
            ll ans=0;
            for(int i=0;i<n/2;i++){
                ans=ans^V[i];
            }
            V.push_back(ans);
        }
        for(auto x:V){
            xd=xd^x;
        }
        ll suma=0;
        for(int i=0;i<n;i++){
            suma+=V[i];
            if((i+1)*2>n){
                if(suma%2==0){
                    V.push_back(0);
                    V.push_back(0);
                }else{
                    V.push_back(1);
                    V.push_back(1);
                }
            }
        }
        if(l<=V.size()){
            cout<<V[l-1]<<"\n";
            continue;
        }
        ll respu=solve(l/2);
        cout<<respu<<"\n";
    }
}