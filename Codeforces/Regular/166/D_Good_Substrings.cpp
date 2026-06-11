#include <bits/stdc++.h>
using namespace std;
#define ll long long
const long long M1 = 1e9 + 7;
const long long M2 = 1e9 + 9;
long long P1, P2;
void generar_bases_random() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<long long> dist(300, 10000);
    P1=dist(rng);
    P2=dist(rng);
}
int main(){
    generar_bases_random();
    set<pair<ll,ll>> S;
    string s;
    cin>>s;
    string xd;
    cin>>xd;
    vector<ll> V(26);
    for(int i=0;i<xd.size();i++){
        if(xd[i]=='0'){
            V[i]=1;
        }
    }
    ll n=s.size();
    ll k;
    cin>>k;
    for(int i=0;i<n;i++){
        string ans="";
        ll curi=0;
        ll hash1=0;
        ll hash2=0;
        ll p1=1;
        ll p2=1;
        for(int j=i;j<n;j++){
            ll uwu=s[j]-'a';
            curi+=V[uwu];
            hash1=(hash1+p1*s[j])%M1;
            hash2=(hash2+p2*s[j])%M2;
            p1=(p1*P1)%M1;
            p2=(p2*P2)%M2;
            if(curi<=k){
                S.insert({hash1,hash2});
            }else{
                break;
            }
        }
    }
    cout<<S.size();
}