#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<queue>
#include<stack>

using namespace std;
template<typename T>

class graph{
public:
    int v;
    unordered_map<T,list<pair<T,int>>> adj;
    void addEdge(T u,T v,bool dir,int wt){
        adj[u].push_back({v,wt});
        if(!dir){
            adj[v].push_back({u,wt});
        }
    }

    void printAdjList(){
    for(auto i:adj){
        cout<<i.first<<"->";
        for(auto j:i.second){
            cout<<j<<",";
        }
        cout<<endl;
    }
    }

};

void BFS(graph<int> g,int u,vector<bool>&visited){
    queue<int>tovisit;
    tovisit.push(u);
    while(!tovisit.empty()){
        int temp=tovisit.front();
        tovisit.pop();
        cout<<temp<<"->";
        visited[temp]=true;
        for(auto i:g.adj[temp]){
            if(!visited[i.first]){
            tovisit.push(i.first);
            visited[i.first]=true;}
        }

    }
    cout<<endl;

}

void DFS(graph<int> g,int u, vector<bool>&visited){
    visited[u]=true;
    cout<<u<<"->";
    for(auto i:g.adj[u]){
        if(!visited[i.first]){
            DFS(g,i.first,visited);
        }
    }
}

bool cycleDetectionBFS(graph<int>g){
    queue<int>tovisit;
    vector<bool>visited(g.v,false);
    vector<int>parent(g.v,-1);
    tovisit.push(0);
    visited[0]=true;
    while(!tovisit.empty()){

        int temp=tovisit.front();
        tovisit.pop();
        // visited[temp]=true;
        for(auto i:g.adj[temp]){
            if(!visited[i.first]){
                visited[i.first]=true;
                tovisit.push(i.first);
                parent[i.first]=temp;
            }else{
                if(parent[temp]!=i.first){
                    return true;
                }
            }

        }
    }
    return false;
}

bool cycleDetection(graph<int>g,vector<bool> &visited,vector<bool>&dfsVisited,int start){
    visited[start]=true;
    dfsVisited[start]=true;
    for(auto i:g.adj[start]){
        
        if(!visited[i.first]){
            if(cycleDetection(g,visited,dfsVisited,i.first))
            return true;
        }else if(dfsVisited[i.first]){
            return true;
        }
        
    }
    dfsVisited[start]=false;
    return false;
}

void topSort(graph<int>g,int start,stack<int>&s,vector<bool>&visited){
    visited[start]=true;
    for(auto i:g.adj[start]){
        if(!visited[i.first]){
            topSort(g,i.first,s,visited);
        }
    }
    s.push(start);
}

void topSortKahnS_Alg(graph<int> g){
    queue<int>tovisit;
    vector<int>inDeg(g.v,0);
    for(auto i:g.adj){
        for(auto j:i.second){
            inDeg[j.first]++;
        }
    }
    for(int i=0;i<g.v;i++){
        if(inDeg[i]==0)
        tovisit.push(i);
    }

    while(!tovisit.empty()){
        int temp=tovisit.front();
        cout<<temp<<"->";
        tovisit.pop();
        for(auto &i:g.adj[temp]){
            if(--inDeg[i.first]==0)
            tovisit.push(i.first);
        }

    }
    cout<<"\n";
}

// void shortestPathUtil(graph<int>g,int src,vector<bool>&visited,vector<int>&dist){
//     visited[src]=true;
//     for(auto i:g.adj[src]){
//         if(!visited[i.first]){
//             visited[i.first]=true;
//             dist[i.first]=dist[src]+i.second;
//             shortestPathUtil(g,i.first,visited,dist);
//         }else{
//             dist[i.first]=min(dist[i.first],dist[src]+i.second);
//         }
//     }
// }

// void shortestPath(graph<int>g,int src){
//     vector<bool>visited(g.v,false);
//     vector<int>dist(g.v,__INT_MAX__);
//     dist[src]=0;
//     shortestPathUtil(g,src,visited,dist);
//     for(auto i:dist){
//         cout<<i<<" ";
//     }
//     cout<<"\n";
// }

void ShortestPathUtil(graph<int>g,int s,stack<int>sorted,vector<int>&dist,vector<bool>&visited){
    while(!sorted.empty()){
        int temp=sorted.top();
        visited[temp]=true;
        sorted.pop();
        for(auto &i:g.adj[temp]){
            if(!visited[i.first]){
                visited[i.first]=true;
                dist[i.first]=dist[temp]+i.second;
            }else{
                dist[i.first]=min(dist[i.first],dist[temp]+i.second);
            }
        }
    }
}

void ShortestPath(graph<int>g,int s){
    vector<int>dist(g.v,__INT_MAX__);
    vector<bool>visited(g.v,false);
    dist[s]=0;
    stack<int>sorted;
    topSort(g,s,sorted,visited);
    vector<bool>_visited(g.v,false);
    ShortestPathUtil(g,s,sorted,dist,_visited);
    for(int i=0;i<g.v;i++){
        cout<<dist[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int v,e;
    cin>>v>>e;
    graph<int> g;
    g.v=v;
    for(int i=0;i<e;i++){
        int a,b,wt;
        cin>>a>>b>>wt;
        g.addEdge(a,b,true,wt);
    }
    // g.printAdjList();
    // vector<bool>visited(v,false);
    // vector<bool>dfsvisited(v,false);
    // vector<int>parent(g.v,-1);

    // DFS(g,6,visited);
    // cout<<cycleDetection(g,visited,dfsvisited,0)<<endl;
    // stack<int>s;
    // topSort(g,0,s,visited);
    // while(!s.empty()){
    //     cout<<s.top()<<"->";
    //     s.pop();
    // }
    // cout<<endl;
    
    // topSortKahnS_Alg(g);
    ShortestPath(g,1);
    

    
}
