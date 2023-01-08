#include<iostream>
#include<stack>
#include<queue>
using namespace std;
static int v;
class graph
{
    public:
    int adj_matrix[10][10];
    void insert();
    void dfs(int v1);
     void bfs(int v1);
     void display();
   graph()
   {
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            adj_matrix[i][j]=0;
        }
    }}
};
void graph::insert()
{
    cout<<"Enter total number of vertices: ";
    cin>>v;
    int v1,v2;
    char ans;
    do{
        cout<<"Enter 2 vertices connected by edge :";
        cin>>v1>>v2;
        adj_matrix[v1-1][v2-1]=1;
        adj_matrix[v2-1][v1-1]=1;
        cout<<"Do you want to continue :";
        cin>>ans;
    }while(ans!='n');
    }

void graph::dfs(int v1)
{
    stack<int>s;
    bool visited[v];
    for(int i=0;i<v;i++)
    {
        visited[i]=0;
    }
    s.push(v1);
    visited[v1-1]=1;
    while(!s.empty())
    {
        v1=s.top();
        s.pop();
        cout<<v1<<" ";
        for(int v2=0;v2<v;v2++)
        {
            if(adj_matrix[v1-1][v2]==1 && visited[v2]==0)
            {
                s.push(v2+1);
                visited[v2]=1;
            }
        }
    }
}
void graph::bfs(int v1)
{
   queue<int>s;
    bool visited[v];
    for(int i=0;i<v;i++)
    {
        visited[i]=0;
    }
    s.push(v1);
    visited[v1-1]=1;
    while(!s.empty())
    {
        v1=s.front();
        s.pop();
        cout<<v1<<" ";
        for(int v2=0;v2<v;v2++)
        {
            if(adj_matrix[v1-1][v2]==1 && visited[v2]==0)
            {
                s.push(v2+1);
                visited[v2]=1;
            }
        }
    }
}
void graph::display()
{
    for(int i=0;i<v;i++)
    {for(int j=0;j<v;j++)
       { cout<<adj_matrix[i][j]<<" ";}
    cout<<endl;}
   
}
int main()
{
    graph obj;
    obj.insert();
    obj.display();
    cout<<"Enter starting vertex : ";
    int v1;
    cin>>v1;
    cout<<"DFS: ";
    obj.dfs(v1);
    cout<<"\nBFS: ";
     obj.bfs(v1);
    return 0;
}
