#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;
        bool ok=true;
        vector<ll> A,B;
        for(int i=0;i<n;i++){
            ll a;
            cin>>a;
            A.push_back(a);
        }
        for(int i=0;i<n;i++){
            ll b;
            cin>>b;
            B.push_back(b);
        }
        ll ans=0;
        for(int i=0;i<n;i++){
            if(A[i]>=B[i]){
                ans+=(A[i]-B[i]);
            }else{
                ok=false;
            }
        }
        if(ok){
            cout<<ans<<"\n";
        }else{
            sort(B.begin(),B.end());
            sort(A.begin(),A.end());
            bool ok2=true;
            ll ans2=0;
            for(int i=0;i<n;i++){
                if(A[i]>=B[i]){
                    ans2+=(A[i]-B[i]);
                }else{
                    ok2=false;
                }
            }
            if(ok2){
                cout<<ans2+m<<"\n";
            }else{
                cout<<-1<<"\n";
            }
        }
    }
}