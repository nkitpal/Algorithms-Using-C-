#include<bits/stdc++.h>

using namespace std;



void BFS(int v,int s)
{
    int i,j,level[v], parent[v];

    int graph[v][v];

    queue<int>q;


    cout << "enter adjacency matrix in 0's and 1's : \n";


    for (i=0;i<v;i++){
        for (j=0;j<v;j++){
            cin >> graph[i][j];
        }
    }

    for (i=0;i<v;i++){
        level[i]=-1;
        parent [i]=-1;

    }

    // Exploration on Source

    level[s]=0;
    q.push(s);


    cout << "BFS("<<s<<"): ";

    while (!q.empty()){
            i=q.front();
            for (j=0;j<v;j++){
                if (graph[i][j]==1 && level[j]==-1){
                    level[j]=level[i]+1;
                    parent[j]=i;
                    q.push(j);
                }
            }

            cout << i << " " ;
            q.pop();

    }



}

int main()
{
    int v,s;

    cout << "Enter no of Vertices/Nodes : ";
    cin >> v;



    cout << "enter source Node Of BFS:";
    cin >> s;


    BFS(v,s);

    return 0;
}
