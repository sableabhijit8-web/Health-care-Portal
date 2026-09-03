#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;

class Graph {
    int V;
    list<int> *l;

public:
    Graph(int V){
     this->V = V;
     // in this we use a doublly link list
     l = new list<int> [V];
    }

    void addEdge(int u, int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }
    void printAdjList(){
        for(int i=0; i<V; i++){
            cout<< i << " : ";
            for(int neigh : l[i]){
                cout << neigh << " ";
            }
            cout << endl;
        }
   }

void BFS (){
    queue<int> Q;
    vector<bool> vis(V, false);

    Q.push(0);
    vis[0] = true;

    while(Q.size() > 0){
        int u = Q.front();
        Q.pop();
        cout<< u <<"";

        for(int V: l[u]){
            if(!vis[V]){
             vis[V] = true;
             Q.push(V);
            }
        }
    }

    cout<<endl;
}
void dfsHelper(int u , vector<bool> &vis){
    cout<< u <<" ";
    vis[u] = true;
    for(int V : l[u]){
        if(!vis[V]){
            dfsHelper(V,vis);
        }
    }
}
void dfs(){
    int src = 0;
    vector<bool> vis(V, false);

    dfsHelper(src, vis);
    cout<<endl;

}
bool iscycleundirdfs(int src, int parent, vector<bool> &vis){
    vis[src] = true;

    for(int v : l[src]){
        if(!vis[v]){
            if(iscycleundirdfs(v, src, vis))
                return true;
        }
        else if(v != parent){
            return true;
        }
    }
    return false;
}

bool iscycle(){
    vector<bool> vis(V, false);

    for(int i = 0; i < V; i++){
        if(!vis[i]){
            if(iscycleundirdfs(i, -1, vis))
                return true;
        }
        }
    return false;
}

// bool iscycleBFS(int src, vector<bool> &vis){
//     queue<pair<int, int>> q;

//     q.push({src,-1});
//     vis[src] = true;

//     while (q.size()>0)
//     {
//      int u = q.front().first;
//      int parU = q.front().second;
//      q.pop();

//      list<int> neighbors = l[u];
//     for(int v: neighbors){
//         if(!vis[v]){
//             q.push({v,u});
//             vis[v] = true;          
//         }
//         else if(v != parU){// cycle condition
//             return true;
//         }
//     }

//     }

//     return false;
// }

// bool iscycleb(){
//     vector<bool> vis(V, false);

//     for (int i = 0; i < V; i++)
//     {
//        if( !vis[i]){
//         if(iscycleBFS(i, vis)){
//             return true;
//         }
//        }

//     }
//     return false;
    
// }
};
int main(){
    Graph g(5);

    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,3);
    g.addEdge(2,4);

    cout<< "bfs :";
    g.BFS();

    cout<< "dfs :" ;
    g.dfs();
    
    cout<<"adjecencylist:";
     g.printAdjList();

    cout<<"cycle of dfs :";
    cout<<g.iscycle() << endl;

    // cout<<"cycle of bfs:";
    // cout<<g.iscycleb() << endl;

    return 0;

}


