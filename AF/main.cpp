#include <bits/stdc++.h>
#define N 1005


using namespace std;

ifstream fin("bfs.in");
ofstream fout("bfs.out");

queue<int> q;

int ctComponents = 0;
vector<int> comp[N]; //to print the strongly connected components

class Graph {
private:
    int n, m;

    vector<int> adlist[N];
    bool viz[N] = {0};
    int dist[N] = {0};

    stack<int> s; //final times in dfs

    void dfCritical(int k, int father, int level[], int level_min[], vector<vector<int>>& sol); // dfs for critical edges
    void dfBiconnected(int k, int father, int level[N], int level_min[N], vector<vector<int>> &biconnected, pair<int, int> stackk[], int &vf_stack); //dfs for biconnected components

public:
    Graph() = default;
    Graph(int n, int m):n(n), m(m){}

    void readDirected();
    void readUndirected();

    void bfs(int first);   //for minimum path
    void dfs(int first);   //for connected components
    void dfsT(int first); //used only for Transpoused --> do not add nodes in s, print the node
                          //we will use "viz" from the transpoused graph
    void printDist();
    void connectedComponents();
    void printGraph();
    Graph transpose();
    void stronglyConnectedComponents();
    void sortTopo(); //dfs and we keep the final times, after a node is finished, we put it in the stack

    bool graphExistsHakimi(vector<int> &dg, int n); //the grades and number of nodes

    void biconnectedComponents();

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections); /*Input: n = 2, connections = [[0,1]] Output: [[0,1]]*/

};


void Graph::readDirected() {
    for(int i = 1; i <= m; ++i) {
        int x, y;
        fin >> x >> y;
        adlist[x].push_back(y);
    }
}

void Graph::readUndirected() {

    for(int i = 1; i <= m; ++i) {
        int x, y;
        fin >> x >> y;
        adlist[x].push_back(y);
        adlist[y].push_back(x);
    }
}

void Graph::printGraph() {
    for(int i = 1; i <= n; ++i) {
        fout << i <<":";
        for(int j = 0; j < adlist[i].size(); ++j)
            fout << adlist[i][j] << " ";
        fout <<"\n";

    }
}

void Graph::bfs(int first) {
    ///bfs detemines the shortest path
    int node, dim;
    dist[first] = 1;
    viz[first] = 1;
    q.push(first);

    while(!q.empty())
    {
        node = q.front();
        q.pop();
        dim = adlist[node].size();
        for(int i = 0; i < dim; ++i)
            if(!viz[adlist[node][i]])
        {
            fout << adlist[node][i] <<" ";
            viz[adlist[node][i]] = 1;
            dist[adlist[node][i]] = dist[node] + 1;
            q.push(adlist[node][i]);
        }
    }
}

void Graph::dfs(int node){
    int i, dim;
    viz[node] = 1;
    dim = adlist[node].size();
    for(i = 0; i < dim; ++i)
            if(!viz[adlist[node][i]])
                dfs(adlist[node][i]);
    s.push(node);
}

void Graph::printDist(){
    int i;
    for(i = 1; i <= n; ++i)
        fout << dist[i] - 1 << " ";
}

void Graph::connectedComponents() {
    ///a crossing with a dfs is a connected component
    int i, nr = 0;
    for(i = 1; i <= n; ++i)
        if(!viz[i])
    {
        nr++;
        dfs(i);
    }
    fout << nr;

}

void Graph::dfsT(int node){
    int i, dim;

    comp[ctComponents].push_back(node);//is part of the same component

    viz[node] = 1;
    dim = adlist[node].size();
    for(i = 0; i < dim; ++i)
            if(!viz[adlist[node][i]])
                dfsT(adlist[node][i]);

}

Graph Graph::transpose() {
    int i, j;
    Graph gt(n, m);
    for(i = 1; i <= n; ++i)
        for(j = 0; j < adlist[i].size(); ++j)
            gt.adlist[adlist[i][j]].push_back(i);
    return gt;

}

void Graph::stronglyConnectedComponents(){
///1 g transpouse = gt
///2 dfs g --> end times --> add in stack
///3 dfs on gt in descending order of end times(just substract from the stack)
///the nodes from a crossing = strongly connected component

    int node;
    for(int i = 1; i <= n; ++i)
        if(!viz[i])
            this->dfs(i);
    Graph gt = this->transpose();
    while(!s.empty())
    {
        node = s.top();
        s.pop();
        if(!gt.viz[node])
            {
                ctComponents++;
                gt.dfsT(node);
            }
    }

    int i, j;
    fout << ctComponents << "\n";

    for(i = 1; i <= ctComponents; ++i) {
        for(j = 0; j < comp[i].size(); ++j)
            fout <<comp[i][j] << " ";
        fout << "\n";
            }

}

void Graph::sortTopo(){
///condition : if exist edge u-->v then u is BEFORE v in topological sort
///determine the end times with dfs --> add them in a stack --> our solution
///if exist u->v ==> end_time[u] > end_time[v]

    for(int i = 1; i <= n; ++i)
        if(!viz[i])
            dfs(i);
    while(!s.empty())
    {
        fout << s.top() <<" ";
        s.pop();
    }

}

bool Graph::graphExistsHakimi(vector<int> &dg, int n) {
    ///sort the vector of degrees desc
    ///we start with the biggest degree v ant link it with the next v nodes (substract 1 from the next v elements)
    ///repeat until:
    ///1. all the remaining elements are 0 (graph exists)
    ///2. negative values encounter after substraction (doesn't exist)
    ///3. not enough elements remaining after substraction (doesn't exist)

    while(1)
    {
        sort(dg.begin(), dg.end(), greater<>());
        if(dg[0] == 0)
            return true; //all elements equal to 0
        int degree = dg[0];
        dg.erase(dg.begin() + 0); //delete the first element

        if(degree > dg.size())//check if enough elements are in the list
            return false;

        for(int i = 0; i < dg.size(); ++i)  //substract 1 from the following
        {
            dg[i]--;
            if(dg[i] < 0)   //check negative
                return false;
        }
    }
}

void Graph::dfCritical(int k, int father, int level[], int level_min[],  vector<vector<int>>& sol){
    ///dfs and keep the level and minimum level that we can reach from a node
    ///when we find " level[k] < level_min[node] " where node = child, it means that we need that edge to reach the ancestors--> critical edge

    if( father == -1)
        level[k] = 1;
    else
        level[k] = level[father] + 1;
    level_min[k] = level[k];

    int dim = adlist[k].size();
    for (int i = 0; i < dim; ++i)
    {
        int node = adlist[k][i];
        if(level[node])//if visited
        {
            if(node != father && level[node] < level_min[k])   //return edge --> check if we can reach a higher level
                level_min[k] = level[node];
        }
        else
        {

            dfCritical(node, k, level, level_min, sol);    //continue dfs

            if(level_min[k] > level_min[node]) //one of the childs has a return edge
                level_min[k] = level_min[node];


            ///determine critical connections
            if(level[k] < level_min[node])  //we can not reach that level or a higher level with a return edge
                {
                vector<int> current;
                current.push_back(node);
                current.push_back(k);
                sol.push_back(current);
                }
        }
    }

}

vector<vector<int>> Graph :: criticalConnections(int n, vector<vector<int>>& connections){
    int level[N] = {0};
    int level_min[N] = {0};

    for(int i = 0; i < connections.size(); ++i)//for each edge
    {
        adlist[connections[i][0]].push_back(connections[i][1]);
        adlist[connections[i][1]].push_back(connections[i][0]);
    }
    vector<vector<int>> sol;//solution of critical edges

    dfCritical(0, -1, level, level_min, sol);
    return sol;

}

void Graph::biconnectedComponents(){

    ///dfs and keep adding nodes in the stack until we finish the biconnected component
    ///keep the level and minimum level that we can reach from a node
    ///when we find " level_min[node] >= level[k] " where node = child, k = father we have to substract all the elements until k from the stack --> a new biconnected component

    int level[N] = {0};
    int level_min[N] = {0};

    vector<vector<int>> biconnected;//vector with the components
    pair<int, int> stackk[N * 2];// a stack  with the nodes visited in dfs(added by their edges)
                                // we have to keep edges bcs the articulation points are part of more biconnecte components
    int vf_stack = 0;


    dfBiconnected(1, 0, level, level_min, biconnected, stackk, vf_stack);

    fout << biconnected.size() << "\n";

    for(int i = 0; i < biconnected.size(); ++i)
    {
        vector <int> comp = biconnected[i];
        for(int j = 0 ; j < comp.size(); ++j)
            fout << comp[j] <<" ";
        fout <<"\n";
    }


}

void Graph::dfBiconnected(int k, int father, int level[N], int level_min[N], vector<vector<int>> &biconnected, pair<int, int> stackk[], int &vf_stack){
    level[k] = level[father] + 1;
    level_min[k] = level[k];

    int dim = adlist[k].size();
    for (int i = 0; i < dim; ++i)
    {
        int node = adlist[k][i];
        if(level[node])//if visited
        {
            if(node != father && level[node] < level_min[k])   //return edge --> check if we can reach a higher level
                level_min[k] = level[node];
        }
        else
        {
           stackk[++vf_stack] = {k, node};  //add in dfs order
            dfBiconnected(node, k, level, level_min, biconnected, stackk, vf_stack);    //continue dfs

            if(level_min[k] > level_min[node]) //one of the childs has a return edge
                level_min[k] = level_min[node];

            if(level_min[node] >= level[k]) //the condition that the biconnected component is complete
            {
                biconnected.push_back({});  //create e new biconnected component
                while(stackk[vf_stack].first != k)  //add all nodes from the stack until k
                    biconnected.back().push_back(stackk[vf_stack--].second);    //add at the last component the nodes
                biconnected.back().push_back(stackk[vf_stack].second);
                biconnected.back().push_back(stackk[vf_stack].first);   //add for the last edge both nodes the articulation point is part of more components
                vf_stack--;
            }
        }
    }

}
int main()
{
    int i, first, n, m;

/*
    fin >> n >> m;
    Graph g(n, m);
*/
///MINIMUM DISTANCE
    /*
    g.readOriented();
    g.bfs(first);
    g.printDist();
*/

/// CONNECTED COMPONENTS
/*
    g.readUndirected();
    g.connectedComponents();
*/

///STRONGLY CONNECTED COMPONENTS
///time limit exceeded pe un test
/*  g.readDirected();
    g.stronglyConnectedComponents();
*/

///TOPOLOGICAL SORT
/*
    g.readDirected();
    g.sortTopo();
*/

///HAVEL-HAKIMI
    /*
    vector<int> dg;
    fin >> n;
    Graph g(n, 0);
    for(int i = 1; i <= n; ++i)
    {
        fin >> first;
        dg.push_back(first);
    }
    if(g.graphExistsHakimi(dg, n))
        fout << "yes";
    else fout << "no";
*/

///CRITICAL CONNECTIONS
/*
    //fin >> n;
    n = 2;
    Graph g(n, 0);
    vector<vector<int>>connections = {{0,1}};
    vector<vector<int>> sol = g.criticalConnections(n, connections);
    fout << sol.size() << "\n";
    for(int i = 0; i < sol.size(); ++i)
    {
        for(int j = 0; j < sol[i].size(); ++j)
            fout << sol[i][j] << " ";
        fout <<"\n";
    }
*/

///BICONNECTED COMPONENTS
/*
    fin >> n >> m;
    Graph g(n, m);
    g.readUndirected();
    g.biconnectedComponents();

*/


    return 0;
}
