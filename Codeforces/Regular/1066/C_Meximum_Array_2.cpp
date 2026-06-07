#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,k,q;
        cin>>n>>k>>q;
        vector<ll> a(n,0),b(n,0),c(n,0);
        for(ll i=0;i<q;i++){
            ll c,l,r;
            cin>>c>>l>>r;
            if(c==1){
                a[l-1]++;
                if(r<n){
                    a[r]--;
                }

            }else{
                b[l-1]++;
                if(r<n){
                    b[r]--;
                }
            }
        }
        ll con1=0;
        ll con2=0;
        for(ll i=0;i<n;i++){
            con1+=a[i];
            con2+=b[i];
            if(con1>0 && con2>0){
                c[i]=k+1;
            }else if(con1>0){
                c[i]=k;
            }else if(con2>0){
                c[i]=-1;
            }else{
                c[i]=676767;
            }
        }
        bool cadena=false;
        ll con=0;
        for(ll i=0;i<n;i++){
            if(c[i]==-1){
                c[i]=con;
                con++;
                if(con==k){
                    con=0;
                }
            }else{
                con=0;
            }
        }
        for(auto x:c){
            cout<<x<<" ";
        }
        cout<<"\n";
    }
}