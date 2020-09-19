#include<bits/stdc++.h>

using namespace std;
int n,m;
int vis[1001][1001];
char arr[1001][1001];

bool isValid(int x,int y) {
    if(x<1 || y<1 || x>n || y>m) {
        return false;
    }

    if(vis[x][y]==0 || arr[x][y]=='#') {
        return false;
    }

    return true;
}

int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

void dfs(int x,int y) {

    vis[x][y] = 0;

    for(int i=0;i<4;i++) {
        if(isValid(x+dx[i],y+dy[i])) {
            dfs(x+dx[i],y+dy[i]);
        }
    }
}

int main() {

    int i,j;
    cin>>n>>m;
    
    for(i=1;i<=n;i++) {
        for(j=1;j<=m;j++) {
            vis[i][j] = 1;
        }
    }

    for(i=1;i<=n;i++) {
        for(j=1;j<=m;j++) {
            cin>>arr[i][j];
        }
    }

    int count = 0;
    for(i=1;i<=n;i++ ) {
        for(j=1;j<=m;j++) {
            if(vis[i][j]==1 && arr[i][j]=='.') {
                vis[i][j] = 0;
                count+=1;

                dfs(i,j);

            }
        }
    }

    cout<<count<<endl;

}