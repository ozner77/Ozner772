#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t;
    cin >> t;

    while(t--){
        ll n;
        cin >> n;

        vector<ll> V(n);
        for(int i=0;i<n;i++) cin >> V[i];

        ll k=0;
        for(int i=0;i<n-1;i++){
            if(V[i]>V[i+1]){
                k=max(k,V[i]-V[i+1]);
            }
        }

        if(k==0){
            cout<<"YES\n";
            continue;
        }

        vector<ll> A=V;
        for(int i=1;i<n;i++){
            if(A[i]<A[i-1]){
                A[i]+=k;
            }
        }

        bool ok=true;
        for(int i=0;i<n-1;i++){
            if(A[i]>A[i+1]){
                ok=false;
                break;
            }
        }

        if(ok) cout<<"YES\n";
        else cout<<"NO\n";
    }
}