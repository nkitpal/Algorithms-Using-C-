#include<iostream>
#include<list>

using namespace std;

class Graph
{
    int v;
    list <int> *adj;


public:
    Graph(int v);
    void addEdgeUndir(int v1,int v2);
    void addEdgeDir (int v1,int v2);
    void DFS(int s);
    void DfsUtil(int s,bool visited []);

};

Graph :: Graph(int v)
{
    int i;

    this->v =v;

    adj =new list<int> [v+1];




}

void Graph::addEdgeDir(int v1,int v2){

    adj[v1].push_back(v2);

}

void Graph:: addEdgeUndir(int v1,int v2){

    adj[v1].push_back(v2);
    adj[v2].push_back(v1);

}

void Graph:: DFS(int s )
{
    int i;
    bool visited[v+1];

    for(i=0;i<=v;i++){
        visited[i]=false;
    }


    DfsUtil(s,visited);

}
void Graph:: DfsUtil(int s,bool visited [])
{
    visited[s]=true;


    cout << s << " " ;

    list<int>:: iterator itr;

    for (itr = adj[s].begin();itr!=adj[s].end();itr++){
        if (visited[*itr]==false){
            visited[*itr]=true;
            DfsUtil(*itr,visited);
        }
    }

}

int main()
{
    int v,s,v1,v2,i,n ;
    char Graph_type;

    cout << "Enter No.of Vertices : ";
    cin >> v;

    Graph G(v);

    cout << "Enter type of Graph (U For Undirected / D for Directed ): ";
    cin >> Graph_type;

    cout << "Enter no Edges: ";
    cin >> n;

    if (Graph_type== 'U' || Graph_type=='u'){
        for(i=0;i<n;i++){
        cout << "Enter Edge " << i+1 << endl;
        cin >> v1;
        cin >> v2;
        G.addEdgeUndir(v1,v2);
    }
    }
    else if (Graph_type=='D' || Graph_type=='d'){

            for(i=0;i<=n;i++){
            cout << "Enter Edge " << i+1 << endl;
            cin >> v1;
            cin >> v2;
            G.addEdgeDir(v1,v2);
        }
    }

    cout << "Enter Source Node : ";
    cin >> s;

    G.DFS(s);




    return 0;

}
