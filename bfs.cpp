#include<bits/stdc++.h>

using namespace std;
int n;
int vis[31][31];
int dist[31][31];
char arr[31][31];

int dx[] = {-1,0,1,0};
int dy[] = { 0,1,0,-1 };

bool isValid(int x,int y) {
    if(x<1 || y<1 || x>n || y>n) {
        return false;
    }

    if(vis[x][y]==1 || arr[x][y]=='T') {
        return false;
    }

    return true;
}



void bfs(int srcx,int srcy) {
    queue<pair<int,int>> q;
    dist[srcx][srcy] = 0;
    vis[srcx][srcy] = 1;

    q.push({srcx,srcy});

    while(!q.empty()) {
        int currX = q.front().first;
        int currY = q.front().second;

        q.pop();

        for(int i=0;i<4;i++) {
            if(isValid(currX+dx[i],currY+dy[i])) {
                int newX = currX+dx[i];
                int newY = currY+dy[i];

                dist[newX][newY] = dist[currX][currY]+1;
                vis[newX][newY] = 1;
                q.push({newX,newY});
            }
        }

    }

    
    
}

int main() {
    int i,j;
    cin>>n;
    int stX = 0,stY=0,edX = 0,edY=0;
    for(i=1;i<=n;i++) {
        for(j=1;j<=n;j++) {
            cin>>arr[i][j];

            if(arr[i][j]=='S') {
                stX = i;
                stY = j; 
            }

            if(arr[i][j]=='E') {
                edX = i;
                edY = j;
            }
        }
    }

    bfs(stX,stY);

    // for(i=1;i<=n;i++) {
    //     for(j=1;j<=n;j++) {
    //         cout<<dist[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    cout<<dist[edX][edY]<<endl;





    
    
}