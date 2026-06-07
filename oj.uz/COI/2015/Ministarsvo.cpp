#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n;
    cin>>n;
    vector<vector<ll>> adj(n),adj2(n);
    vector<vector<ll>> V(n,vector<ll>(n));
    ll maxisali=0;
    map<ll,ll> M,M2;
    ll prota=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ll a;
            cin>>a;
            V[i][j]=a;
            if(a==1){
                adj[i].push_back(j);
                adj2[j].push_back(i);
                M2[j]++;
                M[i]++;
                if(M[i]>maxisali){
                    maxisali=M[i];
                    prota=i;
                }
            }
        }
    }
    set<ll> S;
    if(M[prota]==n-1){
        cout<<-1;
    }else{
        cout<<3<<"\n";
        for(int i=0;i<n;i++){
            if(V[prota][i]==1){
                for(int j=0;j<n;j++){
                    if(V[i][j]==1){
                        V[i][j]=2;
                    }
                }
            }
            if(V[i][prota]==1){
                S.insert(i);
                V[i][prota]=3;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(V[i][j]==1){
                    if(S.count(i)>0 && S.count(j)>0){
                        V[i][j]=2;
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<V[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
}