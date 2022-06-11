#include <iostream>
#include <cstdlib>
#include <list>

using namespace std;

struct Node
{
    int data;
    struct Node* next;
};

struct AdjList
{
    struct Node* head;
};

class Graph
{
private:
    int V;
    AdjList* array;
    list<int>* adj;
public:
    Graph(){}

    void Createvertex(int V){
        this->V = V;
        array = new AdjList[V];		 
        for (int i = 0; i < V; ++i)
            array[i].head = NULL;  	
        adj = new list<int>[V];
    }

    void addEdge(int src, int dest)
    {

       adj[src].push_back(dest);
        Node* newNode = new Node;  
        newNode->data = dest;		
        newNode->next = NULL;		
                                            
        newNode->next = array[src].head;	
        array[src].head = newNode;			

        newNode = new Node; 				
        newNode->data = src;
        newNode->next = NULL;				// 0--->NULL

        newNode->next = array[dest].head;	
        array[dest].head = newNode;			
    }

    void showGraphStructure()
    {
        int v;
        for (v = 0; v < V; ++v)
        {
            Node* tmp = array[v].head;		//tmp has the address of (0,1..)vertex head 
            cout << "\n Adj list of vertex: " << v << "\n head: ";
            while (tmp)
            {
                cout << "-> " << tmp->data;
                tmp = tmp->next;
            }
            cout << endl;
        }
    }


    void DFSUtil(int v, bool visited[])
    {

        visited[v] = true;
        cout << v << " ";


        list<int>::iterator i;
        for (i = adj[v].begin(); i != adj[v].end(); ++i)
            if (!visited[*i])
                DFSUtil(*i, visited);
    }


    void DFS(int v)
    {

        bool* visited = new bool[V];
        for (int i = 0; i < V; i++)
            visited[i] = false;


        DFSUtil(v, visited);
    }

    void BFS(int s)
    {

        bool* visited = new bool[V];
        for (int i = 0; i < V; i++)
            visited[i] = false;


        list<int> queue;


        visited[s] = true;
        queue.push_back(s);


        list<int>::iterator i;

        while (!queue.empty())
        {

            s = queue.front();
            cout << s << " ";
            queue.pop_front();


            for (i = adj[s].begin(); i != adj[s].end(); ++i)
            {
                if (!visited[*i])
                {
                    visited[*i] = true;
                    queue.push_back(*i);
                }
            }
        }
    }

};

int main()
{
    Graph gh;
    gh.Createvertex(5);
    gh.addEdge(0, 1);
    gh.addEdge(1, 4);
    gh.addEdge(1, 0);
    gh.addEdge(1, 4);
    gh.addEdge(1, 2);
    gh.addEdge(1, 3);
    gh.addEdge(2, 1);
    gh.addEdge(2, 3);
    gh.addEdge(3, 1);
    gh.addEdge(3, 4);
    gh.addEdge(3, 2);
    gh.addEdge(4, 3);
    gh.addEdge(4, 0);
    gh.addEdge(4, 1);

    gh.showGraphStructure();

    cout << "DFS " << endl;
    gh.DFS(0);

    cout<<endl << "BFS " << endl;
    gh.BFS(2);
    return 0;
}