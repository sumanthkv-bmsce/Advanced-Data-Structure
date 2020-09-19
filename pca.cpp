#include <bits/stdc++.h>

using namespace std;
 vector<int> adj[1001];
 int par[1001];
 int level[1001];
 int count;
 
 int arr[1001][1001];

void fillAll(int n,int m) {
    int i,j;
    int maxN = log2(n);
    for(i=2;i<=maxN+1;i++) {
        for(j=1;j<=n;j++) {
            int par = arr[j][i-1];
            if(par!=-1) {
                arr[j][i] = arr[par][i-1];
                continue;
            }

            arr[j][i] = -1;
        }
    }
}

 void lca(int a,int b) {
    
    if(level[a]<level[b]) {
        swap(a,b);
    }

    int d = level[a]-level[b];

    while(d>0) {
        int diff = log2(d);
        a = arr[a][diff+1];
        d = d - pow(2,diff);
    }

    while(par[a]!=par[b]) {
        a = par[a];
        b = par[b];
    }

    cout<<"LCA is "<<par[a]<<endl;


 }

int main() {
   
    int n,i,a,b,m,p,q;
    cin>>n>>m;

    for(i=1;i<=n;i++) {
        par[i] = -1;
    }

    for(i=0;i<m;i++) {
        cin>>a>>b;

        adj[a].push_back(b);
        adj[b].push_back(a);
        level[b] = level[a]+1;
        par[b] = a;
        arr[b][1] = a;
    }

    for(i=1;i<=n;i++) {
        if(arr[i][1]==0) {
            arr[i][1] = -1;
        }
    }

    fillAll(n,m);

    cin>>p>>q;

    lca(p,q);

}