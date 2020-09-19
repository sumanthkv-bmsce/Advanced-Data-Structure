#include <bits/stdc++.h>

using namespace std;

int level[1001];
int par[1001];
int dist[1001][1001];

void dfs(int n) {

    int maxN = log2(n);

    for(int i=2;i<=maxN;i++) {
        for(int j=1;j<=n;j++) {
            if(dist[j][i-1]!=-1) {
                dist[j][i] = dist[dist[j][i-1]][i-1];
            }
        }
    }

}

int lca(int a,int b,int n) {
    if(level[a]<level[b]) {
        swap(a,b);
    }

    int d = level[a]-level[b];

    while(d>0) {
        
        int diff = log2(d);

        a = dist[a][diff+1];

        d-=pow(2,diff);

    }

    int maxN = log2(n),pos;

    for(int i=maxN+1;i>0;i--) {
        
        // cout<<dist[a][i]<<" "<<dist[b][i]<<endl;
        if(dist[a][i]!=-1) {
            pos = i;
            if(dist[a][i]!=dist[b][i]) {
                a = dist[a][i];
                b = dist[b][i];
                pos = i;
                // cout<<" a " <<a<<" "<<b<<endl;
            }
        }
    }

    return dist[a][pos];
}

int main() {

    int n,m,i,a,b,p,q;
    cin>>n>>m;

    memset(par,-1,sizeof(par));
    memset(dist,-1,sizeof(dist));

    vector<int> adj[n+1];

    for(i=0;i<m;i++) {
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);

        level[b] = level[a]+1;
        par[b] = a;
        dist[b][1] = a;
    }

    dfs(n);

    while(1) {
        cin>>p>>q;

        int l = lca(p,q,n);
        int dist =level[p]+level[q]-2*level[l];

        cout<<"Distance between "<<p<<" "<<q<<" is "<<dist<<endl;
    }
}