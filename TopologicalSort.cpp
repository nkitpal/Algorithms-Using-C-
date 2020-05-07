#include<iostream>
#include<queue>
#include<list>

using namespace std;

class Graph
{
    int v;

    list<int>*adj;

public:
    Graph(int v);
    void addEdge(int v1,int v2);
    void TopologicalSort();
};

Graph::Graph(int v)
{
    this->v = v;

    adj = new list<int> [v+1];
}

void Graph::addEdge(int v1,int v2)
{
    adj[v1].push_back(v2);

}
void Graph::TopologicalSort()
{
    int i,j;

    int indeg[v+1];

    list<int>:: iterator itr;

    queue<int>zero_indeg;

    for(i=1;i<v+1;i++){
        indeg[i]=0;
    }
    for(i=1;i<v+1;i++){
        for(itr=adj[i].begin();itr!=adj[i].end();itr++){
            indeg[*itr] =  indeg[*itr] + 1;
        }
    }
    for(i=1;i<v+1;i++){
        if(indeg[i]==0)
            zero_indeg.push(i);
    }



    while(!zero_indeg.empty()){

        j = zero_indeg.front();

        for(itr=adj[j].begin();itr!=adj[j].end();itr++){
            if(--indeg[*itr]==0)
                zero_indeg.push(*itr);
        }

        zero_indeg.pop();
        cout << j ;
        if(!zero_indeg.empty())
            cout << "->";
    }

}


int main()
{
    int v,m,i,v2,v1;

    cout << "Enter No of Vertices: ";
    cin >> v;

    Graph g(v);

    cout << "Enter no of Directed Egdes in the acyclic Graph : ";
    cin >> m;

    for(i=1;i<=m;i++){
        cout << "Enter Egde " << i << endl;
        cin >> v1 >> v2;
        g.addEdge(v1,v2);
    }

    g.TopologicalSort();

    return 0;
}
