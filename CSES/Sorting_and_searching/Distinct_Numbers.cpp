#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    set<ll> S; //Es un vector, PERO no puedes acceder a sus pocisiones manualmente osea no existe S[0] o S.back(), su ventaja
    //es que mantiene todos los elementos ordenados de mayor a menor Y no permite elementos duplicados
    ll n;
    cin>>n;
    for(int i=0;i<n;i++){
        ll a;
        cin>>a;
        S.insert(a);
    }
    cout<<S.size();
}