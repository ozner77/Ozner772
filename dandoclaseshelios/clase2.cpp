#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    vector<ll> V={1,2,3};
    cout<<V.size()<<"\n"; //numero de elementos en el vector
    cout<<V[0]<<"\n"; //posición específica de un Vector
    cout<<V.back(); //último elemento
    cout<<V[V.size()-1]<<"\n"; //último elemento
    V.push_back(1); //introducir un elmento al final del vector
    ll n;
    cin>>n;
    vector<ll> A(n);
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    for(int i=0;i<n;i++){
        cout<<A[i]<<" ";
    }
}