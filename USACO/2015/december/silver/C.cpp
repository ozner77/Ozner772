#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ifstream cin("bcount.in");
    ofstream cout("bcount.out");
    ll n,q;
    cin>>n>>q;
    vector<ll> A,B,C;
    A.push_back(0);
    B.push_back(0);
    C.push_back(0);
    for(int i=0;i<n;i++){
        ll a;
        cin>>a;
        if(a==1){
            A.push_back(A[i]+1);
            B.push_back(B[i]);
            C.push_back(C[i]);
        }else if(a==2){
            A.push_back(A[i]);
            B.push_back(B[i]+1);
            C.push_back(C[i]);
        }else{
            A.push_back(A[i]);
            B.push_back(B[i]);
            C.push_back(C[i]+1);
        }
    }
    for(int i=0;i<q;i++){
        ll a,b;
        cin>>a>>b;
        cout<<A[b]-A[a-1];
        cout<<" ";
        cout<<B[b]-B[a-1];
        cout<<" ";
        cout<<C[b]-C[a-1];
        cout<<"\n";
    }
}