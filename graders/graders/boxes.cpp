#include "boxes.h"
#include <bits/stdc++.h>
using namespace std;
#define ll long long
long long delivery(int N, int K, int L, int p[]) {
    vector<ll> V;
    for(int i=0;i<N;i++){
        if(p[i]!=0) V.push_back(p[i]);
    }
    if(V.empty()) return 0;
    sort(V.begin(),V.end());
    N = V.size();
    vector<ll> dpl(N,0), dpr(N,0);
    for(int i=0;i<N;i++){
        if(i<K) dpl[i]=2*V[i];
        else dpl[i]=dpl[i-K]+2*V[i];
    }
    for(int i=N-1;i>=0;i--){
        if(N-1-i<K) dpr[i]=2*(L-V[i]);
        else dpr[i]=dpr[i+K]+2*(L-V[i]);
    }
    ll ans = LLONG_MAX;
    for(int i=0;i+1<N;i++){
        ans = min(ans, dpl[i] + dpr[i+1]);
    }
    for(int i=0;i+K+1<N;i++){
        ans = min(ans, dpl[i] + dpr[i+K+1] + L);
    }
    ans = min(ans, dpl[N-1]);
    ans = min(ans, dpr[0]);
    if(N<=K) ans = min(ans, (ll)L);
    return ans;
}