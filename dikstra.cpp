#include<bits/stdc++.h>

using namespace std;

vector<pair<int,int>> adj[1001];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
int n,m;
int dist[1001];

void dikshtra() {

    q.push({0,1});
    dist[1] = 0;

    while(!q.empty()) {

        int dis = q.top().first;
        int node = q.top().second;

        q.pop();

        for(auto i=adj[node].begin();i!=adj[node].end();i++) {
            int nn = (*i).first;
            int dd = (*i).second;
            if(dist[nn]>dd+dis) {
                dist[nn] = min(dist[nn],dd+dis);

                q.push({dist[nn],nn});
                // cout<<dist[nn]<<" "<<nn<<endl;
            }
            
        }
    }

}

int main() {

    int i,a,b,w;
    cin>>n>>m;

    for(i=1;i<=n;i++) {
        dist[i] = INT_MAX;
    }

    for(i=0;i<m;i++) {
        cin>>a>>b>>w;

        adj[a].push_back({b,w});
        adj[b].push_back({a,w});

    }

    dikshtra();

    for(i=1;i<=n;i++) {
        cout<<dist[i]<<" ";
    }

    cout<<endl;

}