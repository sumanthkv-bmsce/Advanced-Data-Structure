#include <bits/stdc++.h>

using namespace std;

int n,m;
bool vis[1001][1001];

bool isValid(int x,int y) {
    if(x<=0 || x>n || y<=0 || y>m) {
        return false;
    }

    if(vis[x][y] == 1) {
        return false;
    }

    return true;

}

void dfs(int x,int y) {
    vis[x][y] = 1;

    cout<<x<<" "<<y<<endl;
    if(isValid(x-1,y)) {
        dfs(x-1,y);
    }

    if(isValid(x,y+1)) {
        dfs(x,y+1);
    }

    if(isValid(x+1,y)) {
        dfs(x+1,y);
    }

    if(isValid(x,y-1)) {
        dfs(x,y-1);
    }
}

int main() {
    cin>>n>>m;

    memset(vis,0,sizeof(vis));


    dfs(1,1);
    

}