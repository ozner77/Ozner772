#include <bits/stdc++.h>
using namespace std;
#define ll long long

string binary(ll num){
    if (num <= 0) return "0";
    string ans="";
    while(num>1){
        ans+=to_string(num%2);
        num/=2;
    }
    ans+=to_string(num);
    return ans;
}

ll bin_to_ll(string s){
    long long x=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='1'){
            x+=(1LL<<i);
        }
    }
    return x;
}
int main(){
    string s;
    cin>>s;
    if(s=="first"){
        ll t;
        cin>>t;
        while(t--){
            ll n;
            cin>>n;
            n--;
            string n_binario=binary(n);
            ll nxor=0;
            vector<ll> respuesta;
            ll con=0;
            for(int i=0;i<15;i++){
                if(i<n_binario.size()){
                    if(n_binario[i]=='1'){
                        respuesta.push_back(i+1);
                        nxor^=i+1;
                        con++;
                    }
                }else{
                    break;
                }
            }
            if(con%2==0){
                respuesta.push_back(16);
            }
            string nxor_binario=binary(nxor);
            for(int i=17;i<=20;i++){
                if(i-17<nxor_binario.size()){
                    if(nxor_binario[i-17]=='1'){
                        respuesta.push_back(i);
                    }
                }
            }
            cout<<respuesta.size()<<"\n";
            for(auto x:respuesta){
                cout<<x<<" ";
            }
            cout<<"\n";
        }
    }else{
        ll t;
        cin>>t;
        while(t--){
            ll n;
            cin>>n;
            string n_binary;
            ll n_number;
            map<ll,ll> M;
            ll con=0;
            ll realnxor=0;
            for(int i=0;i<n;i++){
                ll a;
                cin>>a;
                M[a]++;
                if(a<=15){
                    con++;
                }
            }
            for(int i=1;i<=15;i++){
                if(M[i]>0){
                    realnxor^=i;
                    n_binary+='1';
                }else{
                    n_binary+='0';
                }
            }
            string nxor_binary;
            ll nxor;
            for(int i=17;i<=20;i++){
                if(M[i]>0){
                    nxor_binary+='1';
                }else{
                    nxor_binary+='0';
                }
            }
            nxor=bin_to_ll(nxor_binary);
            n_number=bin_to_ll(n_binary);
            if(nxor!=realnxor){
                if(con%2==0 && M[16]>0){
                    ll nuncamasusocontinue=1;
                }else if(con%2==1 && M[16]==0){
                    ll nestorsileesestomedebes10bs=1;
                }else{
                    ll variar=nxor^realnxor;
                    n_number^=(1LL<<(variar-1));
                }
            }
            cout<<n_number+1<<"\n";
        }
    }
}