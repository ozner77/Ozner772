#include "bits/stdc++.h"
#define definir_tipo typedef
#define principal main
#define retornar return
#define usando using
#define espacio_de_nombre namespace
#define cadena string
#define la_transmisi_n_en_vivo_de_cadena stringstream
#define centrada cin
#define csalida cout
#define cerror cerr
#define imprimirf printf
#define escanearf scanf
#define NULO NULL
#define base_de_ios ios_base
#define sincronizar_con_stdio sync_with_stdio
#define mientras while
#define para for
#define hacer_mientras do_while
#define ordenar sort
#define inicio begin
#define fin end
#define rinicio rbegin
#define rfin rend
#define siguiente_permutaci_n next_permutation
#define empujar_atr_s push_back
#define eliminar_atr_s pop_back
#define empujar_adelante push_front
#define eliminar_adelante pop_front
#define eliminar pop
#define empujar push
#define cima top
#define vac_o empty
#define cola_de_prioridad priority_queue
#define m_s_grande greater
#define primero first
#define segundo second
#define estructura struct
#define conjunto set
#define mapa map
#define autom_tico auto
#define insertar insert
#define contar count
#define borrar erase
#define asignar assign
#define encontrar find
#define l_mite_inferior lower_bound
#define l_mite_superior upper_bound
#define empate tie
#define subcadena substr
#define conseguir_l_nea getline
#define par pair
#define hacer_par make_pair
#define finl endl
#define tama_o size
#define tama_o_de sizeof
#define conjunto_de_memorias memset
#define m_nimo min
#define m_ximo max
#define __mcd __gcd
#define valor_absoluto abs
#define si if
#define interruptor switch
#define cola queue
#define pila stack
#define constante const
#define si_no else
#define corriente_de_entrada_salida iostream
#define romper break
#define continuar continue
#define caso case
#define mapa_desordenado unordered_map
#define conjunto_desordenado unordered_set
#define atr_s back
#define frente front
#define estructura struct
#define clase class
#define privado private
#define p_blico public
#define permutaci_n_previa prev_permutation
#define falso false
#define verdadero true
#define revertir reverse
#define llenar fill
#define YYYY and 
#define OOOO or
#define operador operator
#define MUCHO LLONG_MAX
#define mucho INT_MAX
#define poco INT_MIN
#define POCO LLONG_MIN
#define conjunto_de_bits bitset
definir_tipo int entero;
definir_tipo long long largo_largo;
definir_tipo long int entero_largo;
definir_tipo short int entero_corto;
definir_tipo float flotar;
definir_tipo double doble;
definir_tipo char caracter;
definir_tipo void nada;
definir_tipo unsigned int no_signeado_entero;
definir_tipo unsigned long long no_signeado_largo_largo;
definir_tipo unsigned long int no_signeado_entero_largo;
definir_tipo unsigned short int no_signeado_entero_corto;
usando espacio_de_nombre std;
largo_largo lefti=1e18;
largo_largo righti=-1e18;
largo_largo sumi;
vector<vector<char>> grid;
map<pair<largo_largo,largo_largo>,largo_largo> M;
vector<vector<largo_largo>> L,R;
vector<vector<largo_largo>> dp;
vector<vector<largo_largo>> cost;
estructura pool {
    largo_largo L,R,W;
};
vector<vector<bool>> visited; 
nada floodfill(largo_largo i,largo_largo j) {
    si(i<0 OOOO j<0 OOOO i>=grid.size() OOOO j>=grid[0].size() OOOO grid[i][j]=='.' OOOO visited[i][j]) {
        retornar;
    }
    visited[i][j]=verdadero;
    lefti=min(lefti,j);
    righti=max(righti,j);
    sumi+=grid[i][j]-'0';
    floodfill(i+1,j);
    floodfill(i-1,j);
    floodfill(i,j+1);
    floodfill(i,j-1);
}
nada gabriel(entero id_taladro,entero l,entero r,entero opt_l,entero opt_r) {
    si(l>r) retornar;
    entero m=(l+r)/2;
    entero best_j=opt_l;
    dp[id_taladro][m]=-1;
    para(entero j=opt_l;j<=min(m-1,opt_r);j++) {
        largo_largo val=dp[id_taladro-1][j]+cost[j][m];
        si(val>dp[id_taladro][m]) {
            dp[id_taladro][m]=val;
            best_j=j;
        }
    }
    gabriel(id_taladro,l,m-1,opt_l,best_j);
    gabriel(id_taladro,m+1,r,best_j,opt_r);
}
entero principal() {
    base_de_ios::sincronizar_con_stdio(falso);
    centrada.tie(NULO);
    largo_largo n,m;
    centrada>>n>>m;
    grid.resize(n,vector<caracter>(m));
    visited.resize(n,vector<bool>(m,falso));
    L.resize(m);
    R.resize(m);
    para(largo_largo i=0;i<n;i++) {
        cadena s;
        centrada>>s;
        para(largo_largo j=0;j<m;j++) {
            grid[i][j]=s[j];
        }
    }
    vector<pool> pools;
    para(entero i=0;i<n;i++) {
        para(entero j=0;j<m;j++) {
            si(grid[i][j]!='.' YYYY !visited[i][j]) {
                lefti=1e18;
                righti=-1e18;
                sumi=0;
                floodfill(i,j);
                pools.push_back({lefti+1,righti+1,sumi});
            }
        }
    }
    vector<vector<largo_largo>> diff(m+2,vector<largo_largo>(m+2,0));
    para(constante autom_tico x:pools) {
        largo_largo l=x.L;
        largo_largo r=x.R;
        largo_largo w=x.W;
        diff[0][l]+=w;
        diff[l][l]-=w;
        diff[0][r+1]-=w;
        diff[l][r+1]+=w;
    }
    cost.assign(m+2,vector<largo_largo>(m+2,0));
    para(entero j=0;j<=m;++j) {
        para(entero i=0;i<=m;++i) {
            cost[j][i]=diff[j][i];
            si(j>0) {
                cost[j][i]+=cost[j-1][i];
            }
            si(i>0) {
                cost[j][i]+=cost[j][i-1];
            }
            si(j>0 YYYY i>0) {
                cost[j][i]-=cost[j-1][i-1];
            }
        }
    }
    dp.assign(m+1,vector<largo_largo>(m+1,0));
    para(entero i=1;i<=m;i++) {
        dp[1][i]=cost[0][i];
    }
    para(entero i=2;i<=m;i++) {
        gabriel(i,1,m,1,m);
    }
    para(entero i=1;i<=m;i++) {
        largo_largo ans=0;
        para(entero j=1;j<=m;j++) {
            ans=max(ans,dp[i][j]);
        }
        csalida<<ans<<"\n";
    }
}