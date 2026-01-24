#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n,m;
    cin>>n>>m;
    ll suma=0;
    for(int i=0;i<n;i++){
        ll a;
        cin>>a;
        suma+=a;
    }
    if(suma<=m){
        cout<<"Yes\n";
    }else{
        cout<<"No\n";
    }
}