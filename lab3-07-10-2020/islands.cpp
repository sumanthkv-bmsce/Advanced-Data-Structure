#include<bits/stdc++.h>

using namespace std;
int n,m;
bool vis[1001][1001];
int arr[1001][1001];
int parent[1001][1001];
int par[1001];

bool isValid(int x,int y) {
    if(x<=0 || x>n || y<=0 || y>m) {
        return false;
    }

    if(vis[x][y] == 1 || arr[x][y]==0) {
        return false;
    }

    return true;

}

int find(int x) {

    while(par[x]!=x) {
        x = par[x];
    }

    return x;

}

void union_both(int x,int y,int part) {
    vis[x][y] = 1;

    parent[x][y] = part;  

    int xr = find(x);
    int yr = find(y);

    if(xr<yr) {

        par[xr] = yr;

    }
    else {
        par[yr] = xr;
    }

    if(isValid(x-1,y)) {
        union_both(x-1,y,part);
    }

    if(isValid(x-1,y+1)) {
        union_both(x-1,y+1,part);
    }

    if(isValid(x,y+1)) {
        union_both(x,y+1,part);
    }

    if(isValid(x+1,y+1)) {
        union_both(x,y-1,part);
    }

    if(isValid(x+1,y)) {
        union_both(x+1,y,part);
    }

    if(isValid(x+1,y-1)) {
        union_both(x,y-1,part);
    }

    if(isValid(x,y-1)) {
        union_both(x,y-1,part);
    }
   
    if(isValid(x-1,y-1)) {
        union_both(x,y-1,part);
    }




}

int main() {
    int i,j;
    cin>>n>>m;

    memset(vis,0,sizeof(vis));
    memset(parent,-1,sizeof(parent));

    for(i=1;i<=n;i++) {
        for(j=1;j<=m;j++) {
            cin>>arr[i][j];
        }
        par[i] = i;
    }

    int count = 1;
    for(i=1;i<=n;i++) {
        for(j=1;j<=m;j++) {
            if(vis[i][j]==0 && arr[i][j]==1) {
                vis[i][j] = 1;

                union_both(i,j,count);
                count++;

            }
        }
    }

    map<int,int> mp;
    mp.clear();

    for(i=1;i<=n;i++) {
        for(j=1;j<=m;j++) {
            if(parent[i][j]!=-1) {
                mp[parent[i][j]]++;
            }
        }
    }

    cout<<"Total number of islands are "<<mp.size()<<endl;


   

    
}