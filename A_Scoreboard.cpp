#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n;
    ll a=0;
    ll b=0;
    cin>>n;
    for(int i=0;i<n;i++){
        ll x,y;
        cin>>x>>y;
        a+=x;
        b+=y;
    }
    if(a>b){
        cout<<"Takahashi\n";
    }else if(b>a){
        cout<<"Aoki\n";
    }else{
        cout<<"Draw\n";
    }
}