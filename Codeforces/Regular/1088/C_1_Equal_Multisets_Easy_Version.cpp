#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        vector<ll> A,B;
        for(int i=0;i<n;i++){
            ll a;
            cin>>a,
            A.push_back(a);
        }
        for(int i=0;i<n;i++){
            ll a;
            cin>>a;
            B.push_back(a);
        }
        map<ll,ll> M;
        bool ans=true;
        if(n!=k){
            map<ll,ll> XD;
            for(int i=0;i<k;i++){
                XD[A[i]]++;
            }
            for(int i=0;i<k;i++){
                if(B[i]!=-1){
                    if(XD[B[i]]==0){
                        ans=false;
                    }
                }
            }
            for(int i=k;i<n;i++){
                ll j=i-k;
                if(A[i]==A[j]){
                    ll uwunt,uwunte;
                    if(B[i]==-1 && B[j]==-1){
                        uwunt=A[i];
                        uwunte=A[j];
                    }else if(B[i]==-1){
                        uwunt=B[j];
                        uwunte=B[j];
                    }else if(B[j]==-1){
                        uwunt=B[i];
                        uwunte=B[i];
                    }else{
                        uwunt=B[i];
                        uwunte=B[j];
                    }
                    if(uwunt!=uwunte){
                        if(B[i]==-1){
                            B[i]=A[i];
                        }
                        if(B[j]==-1){
                            B[j]=A[j];
                        }
                        if(A[i]!=B[i] || A[j]!=B[j]){
                            ans=false;
                        }

                    }else{
                        B[j]=A[j];
                        B[i]=A[i];
                    }
                }else{
                    if(B[i]==-1){
                            B[i]=A[i];
                        }
                        if(B[j]==-1){
                            B[j]=A[j];
                        }
                        if(A[i]!=B[i] || A[j]!=B[j]){
                            ans=false;
                        }
                }
            }
        }
        if(ans){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }
}