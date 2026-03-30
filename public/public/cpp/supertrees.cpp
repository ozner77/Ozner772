#include "supertrees.h"
#include <vector>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct UF{
    vector<int> P, R;
    UF(int n){
        P.resize(n);
        R.assign(n, 1);
        for(int i=0;i<n;i++) P[i]=i;
    }
    int find(int x){
        if(P[x]==x) return x;
        return P[x]=find(P[x]);
    }
    bool unite(int a,int b){
        a=find(a);
        b=find(b);
        if(a==b) return false;
        if(R[a]<R[b]) swap(a,b);
        P[b]=a;
        R[a]+=R[b];
        return true;
    }
    bool same(int a,int b){
        return find(a)==find(b);
    }
};
int construct(std::vector<std::vector<int>> p) {
    ll n=p.size();
    vector<vector<int>> ans(n,vector<int>(n,0));
    UF uf1(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(p[i][j]==3){
                return 0;
            }
            if(p[i][j]>0 && !uf1.same(i,j)){
                uf1.unite(i,j);
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(p[i][j]==0 && uf1.same(i,j)){
                return 0;
            }
        }
    }
    UF uf2(n);
    for(int leader=0;leader<n;leader++){
        vector<int> XD;
        for(int j=0;j<n;j++) 
            if(uf1.find(j)==leader) XD.push_back(j);
        if(XD.size()<=1) continue;
        for(int a=0;a<XD.size();a++){
            for(int b=a+1;b<XD.size();b++){
                int nodo=XD[a], nodo2=XD[b];
                if(p[nodo][nodo2]==1 && uf2.unite(nodo,nodo2)){
                    ans[nodo][nodo2]=ans[nodo2][nodo]=1;
                }
            }
        }
        for(int a=0;a<XD.size();a++){
            for(int b=a+1;b<XD.size();b++){
                int nodo=XD[a], nodo2=XD[b];
                if(p[nodo][nodo2]==2 && uf2.same(nodo,nodo2)){
                    return 0;
                }
            }
        }
        vector<int> roots;
        for(int nodo: XD){
            if(uf2.find(nodo)==nodo) roots.push_back(nodo);
        }
        if(roots.size()==2){
            return 0;
        }
        if(roots.size()<=1){
            continue;
        }
        for(int a=0;a<roots.size();a++){
            int nodo=roots[a];
            int nodo2=roots[(a+1)%roots.size()];
            ans[nodo][nodo2]=ans[nodo2][nodo]=1;
        }
    }
    build(ans);
    return 1;
}