#include<iostream>
#include<queue>

using namespace std;

int main()
{
    int v,i,j,k;

    cin >> v;

    queue<int>zero_indeg;

    int graph[v+1][v+1],indeg[v+1],LP[v+1];

    for(i=1;i<v+1;i++){
        for(j=1;j<v+1;j++){
            cin >> graph[i][j];
        }
    }

    for(i=1;i<v+1;i++){
        indeg[i]=0;
        LP[i]=0;
        for(j=1;j<v+1;j++){
            indeg[i] = indeg[i]  + graph[j][i];
        }
    }

    for(i=1;i<v+1;i++){
        if(indeg[i]==0)
            zero_indeg.push(i);
    }

    while(!zero_indeg.empty()){
        j=zero_indeg.front();
        indeg[j]=-1;
        for(k=1;k<v+1;k++){
            if(graph[j][k]==1){
                indeg[k] = indeg[k] - 1;
                LP[k] = max(LP[k],1+LP[j]);
                if(indeg[k]==0){
                    zero_indeg.push(k);
                }
            }
        }

        zero_indeg.pop();
        cout << j ;
        if(!zero_indeg.empty())
            cout << "->";

    }

    cout << "\n";
    //Longest Path

    for(i=1;i<v+1;i++){
        cout << "Longest Path of V(" << i << ") :" <<LP[i]<<endl;
    }

    return 0;

}
