#include<iostream>
#include<list>
#include<queue>

using namespace std;

class Graph
{
    int v;

    list <int> *adj;
public:
    Graph(int v);

    void BFS(int s);

    void AddEdge(int v1,int v2);


};

Graph::Graph(int v)
{
    this->v = v;

    adj = new list<int> [v];
}

void Graph :: AddEdge(int v1,int v2)
{
    adj[v1].push_back(v2);
    adj[v2].push_back(v1);
}

void Graph :: BFS(int s)
{
    int i,j,level[v],parent[v];

    queue<int>exp;

    list<int> :: iterator itr;

    for(i=0;i<v;i++){
        parent[i]=-1;
        level[i]=-1;
    }

    level[s]=0;
    parent[s]=0;
    exp.push(s);

    while(!exp.empty()){
            j= exp.front();



            for(itr = adj[j].begin();itr!=adj[j].end();itr++){
                if(level[*itr]==-1){
                    exp.push(*itr);
                    level[*itr]=level[j]+1;
                    parent[*itr] = j;
                }
            }
            exp.pop();
            cout << j ;
            if(!exp.empty())
                cout << "->";


    }
}



int main ()
{
    int v,i,n,v1,v2,s;

    cout << "Enter no.of vertices: ";

    cin >> v;

    Graph G(v);

    cout << "How many Total Edges : " ;

    cin >> n;

    for(i=0;i<n;i++){
        cout << "Enter Edge "  << i+1 << endl;
        cin >> v1 ;
        cin >> v2 ;
        G.AddEdge(v1,v2);
    }

    cout << "Enter Source Node :" ;
    cin >> s;

    G.BFS(s);


}
