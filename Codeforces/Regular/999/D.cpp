#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // mezcla muy buena para llaves grandes
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
ll xd;
bool ans;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
        ans=true;
        ll n,m;
        cin>>n>>m;
        xd=n-m;
        vector<ll> B;
        unordered_map<ll,ll,custom_hash> X;
        ll suma=0;
        ll suma2=0;
        for(int i=0;i<n;i++){
            ll a;
            cin>>a;
            X[a]++;
            suma+=a;
        }
        for(int i=0;i<m;i++){
            ll a;
            cin>>a;
            B.push_back(a);
            suma2+=a;
        }
        if(suma!=suma2){
            ans=false;
        }
        queue<ll> valoresnoencontrados;
        for(auto x:B){
            if(X[x]>0){
                X[x]--;
            }else{
                xd--;
                if(xd<0){
                    ans=false;
                    break;
                }
                valoresnoencontrados.push(x);
                while(!valoresnoencontrados.empty()){
                    ll uwu=valoresnoencontrados.front();
                    valoresnoencontrados.pop();
                    if(uwu==1){
                        ans=false;
                        break;
                    }
                    ll caca=uwu/2;
                    if(X[caca]>0){
                        X[caca]--;
                    }else{
                        xd--;
                        if(xd<0){
                            ans=false;
                            break;
                        }
                        valoresnoencontrados.push(caca);
                    }
                    if(X[uwu-caca]>0){
                        X[uwu-caca]--;
                    }else{
                        xd--;
                        if(xd<0){
                            ans=false;
                            break;
                        }
                        valoresnoencontrados.push(uwu-caca);
                    }
                }
                if(ans==false){
                    break;
                }
            }
        }
        if(ans){
            cout<<"Yes\n";
        }else{
            cout<<"No\n";
        }
    }
}