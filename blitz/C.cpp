#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t;
    cin>>t;
    while(t--){
    ll n;
    cin>>n;
    vector<ll> a(n),b(n);
    for(int i=0;i<n;i++){
        ll xd;
        cin>>xd;
        a.push_back(xd);
    }
    for(int i=0;i<n;i++){
        ll xd;
        cin>>xd;
        b.push_back(xd);
    }
    vector<int> pos_b(2 * n + 2, 1e9); 
    for (int i = 0; i < n; i++) {
        pos_b[b[i]] = i; 
    }
    vector<int> min_idx(2 * n + 2, 1e9);
    for (int x = 2 * n; x >= 1; x--) {
        min_idx[x] = min(pos_b[x], min_idx[x + 1]);
    }
    int ans = 1e9;
    for (int i = 0; i < n; i++) {
        int valor_a = a[i];
        int menor_j_valido = min_idx[valor_a + 1]; 

        ans = min(ans, i + menor_j_valido);
    }
    cout << ans << "\n";
    }
}