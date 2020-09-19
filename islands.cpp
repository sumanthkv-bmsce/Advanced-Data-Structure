#include<bits/stdc++.h>

using namespace std;
int n,m;
bool vis[1001][1001];
int arr[1001][1001];

bool isValid(int x,int y) {
    if(x<=0 || x>n || y<=0 || y>m) {
        return false;
    }

    if(vis[x][y] == 1 || arr[x][y]==0) {
        return false;
    }

    return true;

}

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

void dfs(int x,int y) {
    vis[x][y] = 1;

    // cout<<x<<" "<<y<<endl;
    // if(isValid(x-1,y)) {
    //     dfs(x-1,y);
    // }

    // if(isValid(x,y+1)) {
    //     dfs(x,y+1);
    // }

    // if(isValid(x+1,y)) {
    //     dfs(x+1,y);
    // }

    // if(isValid(x,y-1)) {
    //     dfs(x,y-1);
    // }

    for(int i=0;i<4;i++) {
        if(isValid(x+dx[i],y+dy[i])) {
            dfs(x+dx[i],y+dy[i]);
        }
    }
}

int main() {
    int i,j;
    cin>>n>>m;

    memset(vis,0,sizeof(vis));

    
    for(i=1;i<=n;i++) {
        for(j=1;j<=m;j++) {
            cin>>arr[i][j];
        }
    }

    int count = 0;
    
    for(i=1;i<=n;i++) {
        for(j=1;j<=m;j++) {
            if(vis[i][j]==0 && arr[i][j]==1) {
                vis[i][j] = 1;

                dfs(i,j);

                count+=1;


            }
        }
    }

    cout<<count<<endl;


    
}