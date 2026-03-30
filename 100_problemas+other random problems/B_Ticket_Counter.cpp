#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll cur=0;
    ll n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        ll t;
        cin>>t;
        if(t>=cur){
            cout<<t+m<<"\n";
            cur=t+m;
        }else{
            cout<<cur+m<<"\n";
            cur+=m;
        }
    }
}