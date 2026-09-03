#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;

class Graph{
    int V;
    list<int> *l;

public:
    Graph (int v){
        this->V = v;
        l = new list<int>[V];
    }

void addedge(int u, int v){
    l[u].push_back(v);
}

void toposort(){
    vector<int> res;

    // calculate a indeg
    vector<int> indeg(V,0);
    for(int u=0; u<V; u++){
        for(int v: l[u]){
            indeg[v]++;
        }
    }
    queue<int> q;
    for(int i=0; i<V; i++){
        if(indeg[i] == 0){
            q.push(i);
        }
    }
    // dfs
    while (q.size() > 0){
        int curr = q.front();
        q.pop();
        res.push_back(curr);

        for(int v: l[curr]){
            indeg[v]--;
            if(indeg[v] == 0){
                q.push(v);
            }
        }

    }
    //return result
    for(int val: res){
        cout << val <<" ";
    }
    cout<<endl;
}
};
int main(){
    Graph g(6);

    g.addedge(3,1);
    g.addedge(2,3);
    g.addedge(4,0);
    g.addedge(4,1);
    g.addedge(5,0);
    g.addedge(5,2);

    g.toposort();

    return 0;
}
