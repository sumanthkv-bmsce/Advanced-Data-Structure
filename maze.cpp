#include <bits/stdc++.h>

using namespace std;
int vis[1001][1001];
int dist[1001][1001];
int m=8,n=8;

bool isValid(int x,int y) {
    if(x<1 || y<1 || x>n || y>m) {
        return false;
    }

    if(vis[x][y]==1) {
        return false;
    }

    return true;
}

int dx[] = { -2,-2,-1,-1,1,1,2,2 };
int dy[] = { -1,1,-2,2,-2,2,-1,1 };

void bfs(int srx,int sry) {
    queue<pair<int,int>> q;

    vis[srx][sry] = 1;

    dist[srx][sry] = 0;

    q.push({srx,sry});

    while(!q.empty()) {
        int currX = q.front().first;
        int currY = q.front().second;

        q.pop();

        for(int i=0;i<8;i++) {
            if(isValid(currX+dx[i],currY+dy[i])) {
                dist[currX+dx[i]][currY+dy[i]] = dist[currX][currY]+1;
                vis[currX+dx[i]][currY+dy[i]] = 1;
                q.push({currX+dx[i],currY+dy[i]});
            }
        }
    }

    
}

int main() {
    int t,srx,sry,enx,eny;
    string str1,str2;

    map<char,int> mp;
    mp.clear();

    mp['a'] = 1;
    mp['b'] = 2;
    mp['c'] = 4;
    mp['d'] = 3;
    mp['e'] = 4;
    mp['f'] = 5;
    mp['g'] = 6;
    mp['h'] = 7;
    cin>>t;
    while(t--) {

        memset(dist,0,sizeof(dist));
        memset(vis,0,sizeof(vis));
        cin>>str1>>str2;

        srx = mp[str1[0]];
        sry = str1[1]-48;

        enx = mp[str2[0]];
        eny = str2[1]-48;

        // cout<<srx<<" "<<sry<<endl;
        // cout<<enx<<" "<<eny<<endl;
        bfs(srx,sry);
        cout<<dist[enx][eny]<<endl;

        
    }




}