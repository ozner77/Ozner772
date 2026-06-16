#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n,x,y;
    cin>>n>>x>>y;
    vector<ll> V;
    for(int i=0;i<n;i++){
        ll a;
        cin>>a;
        V.push_back(a);
    }
    for(int i=0;i<n;i++){
        ll con1=0;
        ll con2=0;
        bool ok1=true;
        bool ok2=true;
        for(int j=i-1;j>=0;j--){
            if(con1<x){
                if(V[j]<=V[i]){
                    ok1=false;
                }
            }else{
                break;
            }
            con1++;
        }
        for(int j=i+1;j<n;j++){
            if(con2<y){
                if(V[j]<=V[i]){
                    ok2=false;
                }
            }else{
                break;
            }
            con2++;
        }
        if(ok1 && ok2){
            cout<<i+1;
            return 0;
        }
    }
}
