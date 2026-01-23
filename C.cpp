#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n;
    cin>>n;
    vector<ll> V;
    for(int i=0;i<n;i++){
        ll a;
        cin>>a;
        V.push_back(a);

    }
    bool up,prevup;
    ll con,con2;
    if(V[1]>V[0]){
        up=true;
        prevup=false;
        con=2;
    }else{
        up=false;
        prevup=false;
    }
    con2=0;
    ll ans=0;
    for(int i=2;i<n;i++){
        if(V[i]>V[i-1]){
            if(up){
                con++;
            }else if(prevup){
                
            }
        }
    }
}