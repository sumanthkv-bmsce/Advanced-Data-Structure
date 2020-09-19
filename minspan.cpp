#include <bits/stdc++.h>

using namespace std;

struct edge {
    int a;
    int b;
    int w;
};

edge ar[100000];
int par[1000000];
int sum;
int find(int a) {
    if(par[a]<0) {
        return a;
    }

    return par[a] = find(par[a]);
}

void union1(int a,int b) {
        par[b] += par[a];
        par[a] = b;


}

int main() {
    int n,m,a,b,w,i;
    cin>>n>>m;

    for(i=0;i<m;i++) {
        cin>>a>>b>>w;

        ar[i].a = a;
        ar[i].b = b;
        ar[i].w = w;
    }

    for(i=1;i<=n;i++) {
        par[i] = -1;
    }

    sort(ar,ar+m,[](const edge &w1,const edge &w2){ return w1.w < w2.w; });

    int count = 0;

    for(i=0;i<m;i++) {

        int a1 = find(ar[i].a);
        int b1 = find(ar[i].b);

        if(a1!=b1) {
            union1(a1,b1);
            sum+=ar[i].w;
            count++;
        }

        if(count==n-1) {
            break;
        }
    }

    cout<<sum<<endl;

}