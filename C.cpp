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
    vector<ll> L;
    L.push_back(0);
    for(int i=1;i<n-1;i++){
        if(V[i]>V[i-1]){
            if(V[i]>V[i+1]){
                L.push_back(1);
            }else{
                L.push_back(0);
            }
        }else{
            if(V[i]<V[i-1]){
                L.push_back(2);
            }else{
                L.push_back(0);
            }
        }
    }
    L.push_back(0);
    
}