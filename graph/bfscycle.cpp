#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;

class Graph{
    int V;
    list<int>*l;

public:
    Graph(int V){
        this->V = V;
        l = new list <int>[V];
    }

void addedges(int u, int v){
    l[u].push_back(v);
    l[v].push_back(u);
}

 bool iscycleBFS(int src, vector<bool> &vis){
    queue<pair<int, int>> q;

    q.push({src,-1});
    vis[src] = true;

    while (q.size()>0)
    {
     int u = q.front().first;
     int parU = q.front().second;
     q.pop();

     list<int> neighbors = l[u];
    for(int v: neighbors){
        if(!vis[v]){
            q.push({v,u});
            vis[v] = true;          
        }
        else if(v != parU){// cycle condition
            return true;
        }
    }

    }

    return false;
}

bool iscycle(){
    vector<bool> vis(V, false);

    for (int i = 0; i < V; i++)
    {
       if( !vis[i]){
        if(iscycleBFS(i, vis)){
            return true;
        }
       }

    }
    return false;
    
}

};

int main(){
    Graph g(5);
    g.addedges(0,1);
    g.addedges(0,2);
    g.addedges(0,3);
    g.addedges(1,2);
    g.addedges(3,4);
    
    cout<<"cycle of bfs";
    cout<<g.iscycle() << endl;

    return 0;
}
