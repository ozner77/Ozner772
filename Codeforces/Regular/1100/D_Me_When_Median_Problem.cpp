#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll> A,B;
        ll maxi=0;
        for(int i=0;i<n;i++){
            ll a;
            cin>>a;
            A.push_back(a);
            maxi=max(maxi,a);
        }
        for(int i=0;i<n;i++){
            ll a;
            cin>>a;
            B.push_back(a);
            maxi=max(maxi,a);
        }
        ll l=0;
        ll r=maxi;
        ll ansi=0;
        while(l<=r){
            ll mid=(l+r)/2;
            ll con1=0;
            ll con2=0;
            ll last=-1;
            for(int i=0;i<n;i++){
                if(A[i]>=mid && B[i]>=mid){
                    con2++;
                    last=2;
                } else if(A[i]<mid && B[i]<mid){
                    if(last!=0){
                        con1++;
                        last=0;
                    }
                }
            }
            if(con2>con1){
                ansi=mid;
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        cout<<ansi<<"\n";
    }
}