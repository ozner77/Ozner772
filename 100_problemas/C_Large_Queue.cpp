#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n;
    cin>>n;
    deque<pair<ll,ll>> D;
    ll suma=0;
    for(int i=0;i<n;i++){
        ll a;
        cin>>a;
        if(a==1){
            ll b,c;
            cin>>b>>c;
            D.push_back({b,c});
        }else{
            ll b;
            cin>>b;
            suma=0;
            while(b>0){
                pair<ll,ll> p=D[0];
                ll xa=p.first;
                ll xb=p.second;
                if(xa>=b){
                    suma+=(b*xb);
                    xa-=b;
                    if(xa==0){
                        D.pop_front();
                    }else{
                        D[0]={xa,xb};
                    }
                    break;
                }else{
                    b-=xa;
                    suma+=(xa*xb);
                    D.pop_front();
                }
            }
            cout<<suma<<"\n";
        }
    }
}