#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n,m;
    cin>>n>>m;
    vector<ll> A,B;
    vector<ll> V;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        ll xd;
        cin>>xd;
        if(s=="ATK"){
            A.push_back(xd);
        }else{
            B.push_back(xd);
        }
    }
    for(int i=0;i<m;i++){
        ll val;
        cin>>val;
        V.push_back(val);
    }
    ll act=m;
    sort(A.begin(),A.end());
    sort(V.rbegin(),V.rend());
    ll i1=0;
    ll i2=0;
    ll ans=0;
    vector<bool> used(m,false);
    while(i1<A.size() && i2<V.size()){
        if(V[i2]>=A[i1]){
            ans+=V[i2]-A[i1];
            act--;
            i1++;
            i2++;
        }else{
            i2++;
        }
    }
    ll ansi2=0;
    ll total=0;
    ll in1=0;
    ll in2=0;
    sort(V.begin(),V.end());
    sort(B.begin(),B.end());
    while(in1<B.size() && in2<m){
        if(V[in2]>B[in1]){
            total++;
            used[in2]=true;
            in1++;
            in2++;
        }else{
            in2++;
        }
    }
    in1=0;
    in2=0;
    while(in1<A.size() && in2<V.size()){
        if(V[in2]>=A[in1] && !used[in2]){
            used[in2]=true;
            total++;
            ansi2+=V[in2]-A[in1];
            in1++;
            in2++;
        }else{
            in2++;
        }
    }
    if(total==n){
        for(int i=0;i<m;i++){
            if(!used[i]){
                ansi2+=V[i];
            }
        }
    }
    cout<<max(ans,ansi2);
}