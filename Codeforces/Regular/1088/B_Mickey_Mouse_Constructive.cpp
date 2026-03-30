#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll x,y;
        cin>>x>>y;
        ll ans=0;
        ll uwu=abs(x-y);
        for(int i=1;i<=uwu;i++){
            if(uwu%i==0){
                ans++;
            }
        }
        if(x==y){
            ans=1;
        }
        cout<<ans<<"\n";
        for(int i=0;i<x;i++){
            cout<<1<<" ";
        }
        for(int i=0;i<y;i++){
            cout<<-1<<" ";
        }
        cout<<"\n";
    }
}