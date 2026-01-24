#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n;
    cin>>n;
    ll suma=0;
    bool ok=true;
    string ans="";
    for(int i=0;i<n;i++){
        string S;
        cin>>S;
        ll a;
        cin>>a;
        suma+=a;
        if(suma>100){
            ok=false;
        }
        if(ok){
            for(int j=0;j<a;j++){
                ans+=S;
            }
        }
    }
    if(ok){
        cout<<ans<<"\n";
    }else{
        cout<<"Too Long\n";
    }
}