#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll a,b;
    cin>>a>>b;
    ll x,y,z;
    cin>>x>>y>>z;
    z++;
    if(z>b){
        z=1;
        y++;
    }
    if(y>a){
        y=1;
        x++;
    }
    cout<<x<<" "<<y<<" "<<z;
}