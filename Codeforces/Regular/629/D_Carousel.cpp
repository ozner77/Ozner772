#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll> V,A;
        ll prev=-1;
        for(int i=0;i<n;i++){
            ll a;
            cin>>a;
            if(a!=prev){
                prev=a;
                V.push_back(a);
            }
            A.push_back(a);
        }
        if(V.size()==1){
            cout<<1<<"\n";
            for(int i=0;i<n;i++){
                cout<<1<<" ";
            }
        }else if(n%2==0){
            cout<<2<<"\n";
            for(int i=0;i<n;i++){
                cout<<(i%2+1)<<" ";
            }
        }else{
            bool ok=false;
            ll pos1;
            ll pos2;
            for(int i=1;i<n;i++){
                if(A[i]==A[i-1]){
                    ok=true;
                    pos1=i;
                    pos2=i-1;
                    break;
                }
            }
            ll cur=1;
            if(ok){
                cout<<2<<"\n";
                for(int i=0;i<n;i++){
                    if(i==pos2){
                        if(cur==2){
                            cout<<2<<" ";
                        }else{
                            cout<<1<<" ";
                        }
                    }else if(i==pos1){
                        if(cur==2){
                            cout<<2<<" ";
                            cur=1;
                        }else{
                            cout<<1<<" ";
                            cur=2;
                        }
                    }else{
                        cout<<cur<<" ";
                        if(cur==1){
                            cur=2;
                        }else{
                            cur=1;
                        }
                    }
                }
            }else{
                if(V[0]==V.back()){
                    cout<<2<<"\n";
                    for(int i=0;i<n;i++){
                        cout<<(i%2+1)<<" ";
                    }
                }else{
                    cout<<3<<"\n";
                    for(int i=0;i<n-1;i++){
                        cout<<(i%2+1)<<" ";
                    }
                    cout<<3;
                }
            }
        }
        cout<<"\n";
    }
}