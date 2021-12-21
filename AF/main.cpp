#include <bits/stdc++.h>
#define N 305  ///the maximum number of nodes in the graph
#define M 305   ///the maximum number of edges
#define inf 200000000

using namespace std;
ifstream fin("bfs.in");
ofstream fout("bfs.out");

 struct edge {
     int x, y, cost;
    };

typedef pair < int, int > Pair; // define our pair for an easier use

class Graph {
private:

    int n, m;

    vector<int> adlist[N];  //adjent list
    vector < Pair > adcost[N];   ///USED FOR DIJKSTRA & bellmanFord : the adjent list for cost
                                    ///ad[x] = (y,c) where c = cost for the edge from x->y
    edge edges[N];

    stack<int> s; //final times in dfs

    vector<vector<int>> transpose();

    void dfCritical(int k, int father, int level[], int level_min[], vector<vector<int>>& sol); // dfs used in the algorithm for critical edges
    void dfBiconnected(int k, int father, int level[N], int level_min[N], vector<vector<int>> &biconnected, pair<int, int> stackk[], int &vf_stack); //dfs used in the algorithm for biconnected components
    void dfsDiameter(int node, int& maxi, int &nextNode, int dist[]); //dfs for diametr of the tree--> save the maximum path &use dist, not viz bcs we need distance
    void dfsT(int node, bool vizTransp[], int ctComponents,  vector<vector<int>> &comp, vector<vector<int>>edgesTranspose); //used only for Transpouse --> do not add nodes in s, print the node
    bool bfsFlow(int parent[], int rflow[N][N]);//returns if there is a path from source to sink, also updated the parents array

    int representant(int node, int repres[N]);  //finding the root for the tree where is part node
    void reunite(int x, int y, int h[N], int repres[N]); //union 2 trees for apm
    friend bool compare(edge A, edge B);//to compare costs of 2 edges

    bool findMatchBipartite(bool bip_graph[N][N], int vertex, bool seen[], vector<int> &match);

public:

    Graph() = default;
    Graph(int n  = 0, int m = 0):n(n), m(m){}

    void readDirected();
    void readUndirected();
    void readUndirectedCost();
    void readDirectedCost();
    void readDirectedFlow(int matrix_flow[N][N]);

    void bfs(int first, bool viz[], int dist[], queue<int>& q);   //for minimum path
    void dfs(int first, bool viz[]);   //for connected components

    void printDist(int dist[]);
    int connectedComponents();
    void printGraph();

    vector<vector<int>> stronglyConnectedComponents(bool viz[], int &ctComponents);
    stack<int> sortTopo(bool viz[]); //dfs and we keep the final times, after a node is finished, we put it in the stack

    bool graphExistsHakimi(vector<int> &dg, int n); //the grades and number of nodes
    vector<vector<int>> biconnectedComponents();
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections); /*Input: n = 2, connections = [[0,1]] Output: [[0,1]]*/

    int kruskal(vector<pair<int, int>> & sol);
    void disjoint();
    vector<int> dijkstra();
    vector<int> bellmanFord();

    void royFloyd(int d[N][N]);
    int graphDiameter();
    int fordFulkerson(int matrix_flow[N][N]);

    vector<int> Euler();
    vector<int> maxBipartite(int &sol);

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
        vector<int> ::iterator it;
        it = find(adlist[x].begin(),adlist[x].end(), y);
        if(it != adlist[x].end())
            m--;   //we have duplicates
        else
        {
            adlist[x].push_back(y);
            adlist[y].push_back(x);
        }
    }
}

void Graph::readUndirectedCost() {
     for(int i = 1; i <= m; ++i) {
        int x, y, cost;
        fin >> x >> y >> cost;
        adlist[x].push_back(y);
        adlist[y].push_back(x);
        edges[i].x = x;
        edges[i].y = y;
        edges[i].cost = cost;
    }
}

void Graph::readDirectedCost() {
      for(int i = 1; i <= m; ++i) {

        int x, y, cost;
        fin >> x >> y >> cost;
        adcost[x].push_back(make_pair(y,cost));
    }
}

void Graph::readDirectedFlow(int matrix_flow[N][N]) {
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
    {
        int x, y, fl;
        fin >> x >> y >> fl;
        matrix_flow[x][y] = fl;
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

void Graph::bfs(int first, bool viz[], int dist[], queue<int>& q) {
    ///bfs detemines the shortest path
    int node, dim;
    dist[first] = 1;
    viz[first] = 1;
    q.push(first);

    while(!q.empty())   //for each node add all his neighbors that haven't been visisted yet & update minimum distance
    {
        node = q.front();
        q.pop();
        dim = adlist[node].size();
        for(int i = 0; i < dim; ++i)
            if(!viz[adlist[node][i]])
        {
            cout << adlist[node][i] <<" ";
            viz[adlist[node][i]] = 1;
            dist[adlist[node][i]] = dist[node] + 1;
            q.push(adlist[node][i]);
        }
    }
}

void Graph::dfs(int node, bool viz[]) {
    int i, dim;
    viz[node] = 1;
    dim = adlist[node].size();
    for(i = 0; i < dim; ++i)
            if(!viz[adlist[node][i]])//contiune the dfs from the new node
                    dfs(adlist[node][i],viz);

    s.push(node);   //after we finish with a node --> we add it in the stack --> "final times"
}

void Graph::printDist(int dist[]) {
    int i;
    for(i = 1; i <= n; ++i)
        fout << dist[i] - 1 << " ";
}

int Graph::connectedComponents() { //returns the number of connected components
    ///a crossing with a dfs is a connected component
    int i, nr = 0;
    bool viz[N] = {0};
    for(i = 1; i <= n; ++i)
        if(!viz[i]) //we found another component
    {
        nr++;
        dfs(i, viz);
    }
    return nr;
}


vector<vector<int>> Graph::biconnectedComponents() { //returns a the biconnected components
    ///keep adding nodes in the stack until we finish the biconnected component
    int level[N] = {0};
    int level_min[N] = {0};

    vector<vector<int>> biconnected;//vector with the components
    pair<int, int> stackk[N * 2];// a stack  with the nodes visited in dfs(added by their edges)
                                // we have to keep edges bcs the articulation points are part of more biconnecte components
    int vf_stack = 0;

    dfBiconnected(1, 0, level, level_min, biconnected, stackk, vf_stack);

    return biconnected;
}

void Graph::dfBiconnected(int k, int father, int level[N], int level_min[N], vector<vector<int>> &biconnected, pair<int, int> stackk[], int &vf_stack) {
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

void Graph::dfsT(int node, bool vizTransp[],int ctComponents, vector<vector<int>> &comp, vector<vector<int>>edgesTranspose) {

    comp[ctComponents].push_back(node);//is part of the same component

    vizTransp[node] = 1;

    int dim = edgesTranspose[node].size();
    for(int i = 0; i < dim; ++i)
            if(!vizTransp[edgesTranspose[node][i]])
                    dfsT(edgesTranspose[node][i], vizTransp, ctComponents, comp, edgesTranspose);
}

vector<vector<int>> Graph::transpose() {//returns the edges of transpouse graph

    vector<vector<int>> edgesTranspose;
    edgesTranspose.resize(n+1);
    for(int i = 1; i <= n; ++i)
        for(int j = 0; j < adlist[i].size(); ++j)
            edgesTranspose[adlist[i][j]].push_back(i);

    return edgesTranspose;
}

vector<vector<int>> Graph::stronglyConnectedComponents(bool viz[], int &ctComponents) {//returns the components and via ctComponents their number
///1 g transpouse
///2 dfs g --> end times --> add in stack
///3 dfs on gt in descending order of end times(just substract from the stack)
///the nodes from a crossing = strongly connected component

    vector<vector<int>>comp;    //the strongly connected components(result)
    comp.resize(n+1);

    for(int i = 1; i <= n; ++i)
        if(!viz[i])
            dfs(i,viz);

    vector<vector<int>> edgesTranspose = transpose();

    bool vizTransp[N] ={0};//viz for transpouse graph
    while(!s.empty())   //dfs on graph transpouse in reverse order of the final times
    {
        int node = s.top();
        s.pop();

        if(!vizTransp[node])//a crossing with dfs means a strongly connected component
            {
                ctComponents++;
                dfsT(node, vizTransp, ctComponents, comp, edgesTranspose);
            }
    }
    return comp;
}


stack<int> Graph::sortTopo(bool viz[]) { // return a stack with the order
///condition : if exist edge u-->v then u is BEFORE v in topological sort
///determine the end times with dfs --> add them in a stack --> our solution
///if exist u->v ==> end_time[u] > end_time[v]

    for(int i = 1; i <= n; ++i)
        if(!viz[i])
            dfs(i, viz);
  return s;

}

bool Graph::graphExistsHakimi(vector<int> &dg, int n) {
    ///sort the vector of degrees desc
    ///we start with the biggest degree v ant link it with the next v nodes (substract 1 from the next v elements)
    ///repeat until:
    ///1. all the remaining elements are 0 (graph exists)
    ///2. negative values encounter after substraction (doesn't exist)
    ///3. not enough elements remaining after substraction (doesn't exist)

    while(1)    ///mai eficient count sort!!!
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

void Graph::dfCritical(int k, int father, int level[], int level_min[],  vector<vector<int>>& sol) {
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

vector<vector<int>> Graph :: criticalConnections(int n, vector<vector<int>>& connections) {
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


bool compare(edge A, edge B) {
    return A.cost < B.cost;
}

int Graph::representant(int node, int repres[N]) {
    while(repres[node] != 0)    //father -> father >>searching for root
        node = repres[node];
    return node;
}

void Graph::reunite(int repres1, int repres2, int h[N], int repres[N]) {
    ///the smaller tree becomes child
    if(h[repres1] < h[repres2])
    {
        h[repres2] += h[repres1];
        repres[repres1] = repres2;
    }
    else{
        h[repres1] += h[repres2];
        repres[repres2] = repres1;
    }
}

int Graph::kruskal(vector<pair<int, int>> & sol) { //returns the cost and via sol the edges
    ///sort the edges in ascending order of their costs
    ///initially, each node --> a solo component
    ///iterate throw edges and verify if the ends are part of the same component --> if not reunite them (union & find)

    int total_cost = 0; //the solution
    int h[N] = {0}; //h[x] = height of the tree with the root x
    int repres[N] = {0}; //the representant of a tree

    sort(this->edges + 1, this->edges + m + 1, compare);

    for(int i = 1; i <= m && sol.size() != n-1; ++i)//for each edge until we choose n-1
    {
        int repres1 = representant(edges[i].x, repres);
        int repres2 = representant(edges[i].y, repres);

        if(repres1 != repres2) //if they are not part of the same component
        {
            total_cost += edges[i].cost;
            sol.push_back(make_pair(edges[i].x, edges[i].y));
            reunite(repres1, repres2, h, repres);
        }
    }
    return total_cost;
}

void Graph::disjoint() {
    ///UNION & FIND
    ///at the beginning each vertex it's a solo component (repres = 0)
    ///when we reunite 2 component, the smaller one becomes the other child --> update repres

     int h[N] = {0}; //h[x] = height of the tree with the root x
     int repres[N] = {0}; //the representant of a tree

     for(int i = 1; i <= m; ++i)
     {
         int x, y, task;
         fin >> task >> x >> y;
         if(task == 1)
            reunite(x, y, h, repres);
         else
         {
            int repres1 = representant(x, repres);
            int repres2 = representant(y, repres);

            if(repres1 != repres2)
                fout << "NU\n";
            else fout << "DA\n";
         }
     }
}
vector<int> Graph::dijkstra() {
    ///O((e+v)log(v))
    ///the minimum path from a source to all others
    ///a priority queue with (cost, vertex) that keep in ascending order the minimum path to a vertex from the start
    ///at a moment in front of the queue will be a vertex whose path can not be any better
    ///take that node, itarete its neighbours and try to update path --> if one can be updated read the pair(cost, vertex) in the priority queue
    ///viz -- if we already decided the minimum path to that node
        /// --(bcs at a moment we may have entered multiple times a node in the queue) (first time with a worse price, then with a better one)

    priority_queue < Pair, vector < Pair >, greater < Pair > > queue_edges; ///add (for used edges in ascending order of their costs)
                                                                            ///pair(cost, node) where cost = source->node
                                                                            ///for DIJKSTRA
    int viz[N] = {0};
    vector<int> dist;
    dist.reserve(n);

    for(int i = 1; i <= n; ++i)
        dist[i] = inf;
    int source = 1; //the start node
    queue_edges.push(make_pair(0, source)); ///the cost is 0 to arrive at the source
    dist[source] = 0;

    while(!queue_edges.empty())//we will add in the queue all the updated paths (cost, node) --> priority queue ordered by their costs
    {                          //at a moment we will choose the minimum cost existent
        int node = queue_edges.top().second;
        queue_edges.pop();

        if(viz[node] == 1)continue;  //skip this node bcs we already had a path to it
            else viz[node] = 1; //continue from this node

        for(int i = 0; i < adcost[node].size(); ++i)//for all nodes that "node" is connected to
        {
            int vertex = adcost[node][i].first;
            int cost = adcost[node][i].second;

            //try to update minimum cost
            if(cost + dist[node] < dist[vertex])
            {
                dist[vertex] = dist[node] + cost;
                queue_edges.push(make_pair(dist[vertex], vertex));
            }
        }
    }
    return dist;

    ///CLASSIC METHOD:
    //initialize all costs to infinity
    //update the arrays with info about edges out of source
    //while there are non-infinite costs for paths that we haven't confirmed a path to yet
        //pick the vertex with the smallest cost
        //mark the vertex as having a path to it
        //for each out of the vertex
            //if there is no path to the ending vertex yet
                //update the array info IF the cost using this edge is less then current cost
}

vector<int> Graph::bellmanFord() {  //returns a vector with minimum costs, if it's not possible the vector returned will contain n values of -inf
    /// O(nm)
    ///like Dijkstra but can contain negativ costs (dijkstra =greedy , bellman-ford != gr)
    ///after k iterations --> will be calculated the costs for node, where exists a path of lg k source -> node

    //at an iteration is enough to "relax" the edges from vertex that have already been updated --> queue
    //if  exists negativ circuit --> NO SOLUTION
    //                            --> it means that after n-1 steps still exists a vertex to be updated

    int viz[N] = {0};
    vector<int> dist;
    dist.reserve(n);
    bool exists = true;
    int time_in_queue[N] = {0}; //for negativ circuit --> how many times a vertex is visitied
    queue<int> queue_edges;

    for(int i = 1; i <= n; ++i)
    {
        viz[i] = 0;
        time_in_queue[i] = 0;
        dist[i] = inf;
    }
    dist[1] = 0;
    viz[1] = 1;
    queue_edges.push(1);

    while(!queue_edges.empty())
    {
        int node = queue_edges.front();
        queue_edges.pop();
        viz[node] = 0;  //it is not in queue anymore
        time_in_queue[node]++;
        if(time_in_queue[node] >= n)
        {
            exists = false;
            break;
        }
        for(int i = 0; i < adcost[node].size(); ++i)  //for each neighbour
        {
            int vertex = adcost[node][i].first;
            int cost = adcost[node][i].second;

            if(dist[node] + cost < dist[vertex])//try to update minimum cost until vertex (with i edges)
            {
                dist[vertex] = dist[node] + cost;
                if(viz[vertex] == 0)
                    queue_edges.push(vertex);
            }
        }
    }
    if(exists == false)
        for(int i = 1; i <= n; ++i)
             dist[i] = -inf; //cazul in care nu exista
    return dist;
}

void Graph::royFloyd(int d[N][N]) { //returns via d the matrix with shortest paths
    ///minimum path between each 2 nodes
    ///for each pair of nodes try an intermediate

    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
        {
            fin >> d[i][j];
            if(d[i][j] == 0)d[i][j] = inf -1; //bcs it's no edge and we do not want to influence the minimum with the "0"
        }
    for(int k = 1; k <=n; ++k)
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= n; ++j)
                if(d[i][j] > d[i][k] + d[k][j])
                    d[i][j] = d[i][k] + d[k][j];
}

void Graph::dfsDiameter(int node, int& maxi, int &nextNode, int dist[]) {
    int i, dim;
    dim = adlist[node].size();
    for(i = 0; i < dim; ++i)
            if(!dist[adlist[node][i]])//use dist bcs and not viz, bcs we want the distance
                {
                    dist[adlist[node][i]] = dist[node] + 1;
                    if(dist[adlist[node][i]] > maxi) ///for diameter --> max time between 2 leaves
                    {
                        maxi = dist[adlist[node][i]];
                        nextNode = adlist[node][i];
                    }
                    dfsDiameter(adlist[node][i], maxi, nextNode, dist);

                }
}

int Graph::graphDiameter() {//returns the diameter
    ///the maximum distance between 2 leaves
    ///dfs from a node --> then dfs from the last node visisted bcs we know that s a leaf
    int nextNode = 0;
    int aux = 0; //used just for the second call to have the parameter
    int maxi = 0;   ///the maximum path

    int dist[N];
    for(int i = 1; i <= n; ++i)
        dist[i] = 0;
    dfsDiameter(1, maxi, nextNode, dist);

    for(int i = 1; i <= n; ++i)
        dist[i] = 0;
    maxi = 0;
    dfsDiameter(nextNode, maxi, aux, dist);

    return maxi + 1; //bcs we should have statred with 1
}

bool Graph::bfsFlow(int parent[], int rflow[N][N]) {
    //update the visited array to 0;
    int viz[N] ={0};
    queue<int> q; //a queue at the usual bfs

    q.push(1);//first vertex
    viz[1] = 1;
    parent[1] = -1;
    while(!q.empty()) {
        int vertex = q.front();
        q.pop();

        for(int i = 1; i <= n; ++i)
        if(!viz[i] && rflow[vertex][i] > 0) {
            if(i == n) //we made the all path
            {
                parent[i] = vertex;
                return true;
            }
        q.push(i);
        parent[i] = vertex;
        viz[i] = true;
        }
    }
    return false;
}

int Graph::fordFulkerson(int matrix_flow[N][N]) {//returns the maximum flow

    ///while there is a path to s->f in the residual graph update the flow

    int parent[N];//for bfs to know the path
    int rflow[N][N];//residual graph --> initially the graph
    int max_flow = 0;
    for(int i = 1; i <= n; ++ i)
        for(int j = 1; j <= n; ++j)
            rflow[i][j] = matrix_flow[i][j];

    while(bfsFlow(parent, rflow)) {   //while there is a path
            // find the minimum in the path
            int mini_flow = inf;
            for(int vertex = n; vertex != 1; vertex = parent[vertex])
            {
                int father = parent[vertex];
                mini_flow = min(mini_flow, rflow[father][vertex]);
            }
            //update residual capacities of the edges and reverse edges along the path
             for(int vertex = n; vertex != 1; vertex = parent[vertex])
            {
                int father = parent[vertex];
                rflow[vertex][father] += mini_flow;
                rflow[father][vertex] -= mini_flow;
            }
            //add the flow to the total flow
            max_flow += mini_flow;
    }
    return max_flow;
}


vector<int> Graph::Euler() {//returns the circuit

    vector < Pair > graf[N]; // garf[x] = (nr_edge, y) --> to mark just once the edge as being used
                            // graf[y] = (nr_edge, x)
    bool eliminated[M] ={0}; //the edges that will be eliminated
    stack<int> stack_nodes;
    vector<int> euler_cicle;

    ///verify first of all if it is possible to have an eulerian cicle
    ///Fleury alg: start from a vertex at at every moment we choose an non-critical edge. delete the edge and moving to it's end, we continue the alg in the same manner
    ///the cicle is eulerian

    for(int i = 1; i <= m; ++i)
    {
        int x, y;
        fin >> x >> y;
        graf[x].push_back(make_pair(i, y));
        graf[y].push_back(make_pair(i, x));
    }

    for(int i = 1; i <= n; ++i)
        if(graf[i].size() %2 == 1)//it can't have an euler cicle
    {
        euler_cicle.push_back(-1);
        return euler_cicle;
    }

    stack_nodes.push(1);
    while(!stack_nodes.empty())//like a dfs
    {
        int node = stack_nodes.top();
        if(!graf[node].empty())//if it still has neighbours
        {
            Pair p = graf[node].back();
            graf[node].pop_back();

            int nr_edge = p.first;
            int vertex = p.second;

            if(!eliminated[nr_edge])
            {
                eliminated[nr_edge] = 1; //we eliminate it
                stack_nodes.push(vertex);//will continue from here
            }
        }
        else    //we can add it to the solution
        {
            stack_nodes.pop();
            euler_cicle.push_back(node);
        }
    }
    return euler_cicle;
}


bool Graph::findMatchBipartite(bool bip_graph[N][N], int vertex, bool seen[], vector<int>& match) { ///if we find a match for the current vertex
    //a dfs based function that tries all possibilites to assign a job to the applicant
    //if a job isn't assigned->we assign it
    //if it is assigned to x, we try to check recursively if x can have another job
    //to make sure that we don't assign multiple times the same job to a candidate--> seen
    for(int i = 1; i <= m; ++ i)//try every job
    {
        if(bip_graph[i][vertex] && !seen[i])//if thwy have a connection and the job is not used yet
        {
            seen[i] =1;//to not repeat it at the current job
            //if it s not assigned or it is assigned to smb that can have another job
            if(match[i] == -1 || findMatchBipartite(bip_graph, match[i], seen, match))
            {
                match[i] = vertex;
                return true;
            }
        }
    }
    return false;
}

vector<int> Graph::maxBipartite(int &sol) {// returns the matches (-1 if no match) and via parameter the maximum number of edges of couple

    bool bip_graph[N][N];
    //lines with jobs and columns with candidates
    int e;
    fin >> e;
    for(int i = 1; i <= e; ++i)
    {
        int x, y;
        fin >> x >> y;
        bip_graph[y][x] = 1;

    }
    //n -- aplicants(left)
    //m -- jobs(right)
    vector<int> match;
    match.reserve(m);
    for(int i = 1; i <= m; ++ i)
        match[i] = -1;
    sol = 0;
    for(int i = 1; i <= n; ++i)//for every aplicant
    {
        bool seen[N];
        memset(seen, 0, sizeof(seen));//not seen
        if(findMatchBipartite(bip_graph, i,seen, match))
            sol++;//found  job;
    }
    return match;
}


void solveMinimumDistance() {
    //https://infoarena.ro/problema/bfs

    int first, n, m;
    fin >> n >> m >> first;
    Graph g(n, m);
    bool viz[N] = {0};
    int dist[N] = {0};      //the minuimum distance from a particular vertex to all others
    queue<int> q;   //to add nodes at bfs

    g.readDirected();
    g.bfs(first,viz, dist, q);
    g.printDist(dist);
}

void solveConnectedComponents() {
    //https://infoarena.ro/problema/dfs

    int  n, m;
    fin >> n >> m;
    Graph g(n, m);
    bool viz[N] = {0};

    g.readUndirected();
    fout << g.connectedComponents();
}

void solveBiconnectedComponents() {
    //https://infoarena.ro/problema/biconex

    int  n, m;
    fin >> n >> m;
    Graph g(n, m);

    g.readUndirected();
    vector<vector<int>> biconnected = g.biconnectedComponents();

    fout << biconnected.size() << "\n";

    for(int i = 0; i < biconnected.size(); ++i)
    {
        vector <int> comp = biconnected[i];
        for(int j = 0 ; j < comp.size(); ++j)
            fout << comp[j] <<" ";
        fout <<"\n";
    }
}

void solveStronglyConnectedComponents() {
    //https://infoarena.ro/problema/ctc

    int  n, m;
    fin >> n >> m;
    Graph g(n, m);

    bool viz[N] = {0};
    int ctComponents = 0;   //strongly connected components

    g.readDirected();
    vector<vector<int>> comp = g.stronglyConnectedComponents(viz, ctComponents); //to print the strongly connected components

    fout << ctComponents << "\n";

    for(int i = 1; i <= ctComponents; ++i) {
        for(int j = 0; j < comp[i].size(); ++j)
            fout <<comp[i][j] << " ";
        fout << "\n";
            }
}

void solveTopologicalSort() {
    //https://infoarena.ro/problema/sortaret

    int  n, m;
    fin >> n >> m;
    bool viz[N] = {0};
    Graph g(n, m);
    g.readDirected();
    stack<int> nodes = g.sortTopo(viz);
    while(!nodes.empty())
    {
        fout << nodes.top() <<" ";
        nodes.pop();
    }
}

void solveHavelHakimi() {
    int n, first;
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
}

void solveCriticalConnections() {
    int n;
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
}
void solveKruskal() { ///PARTIAL TREE WITH MINIMUM COST
    //https://infoarena.ro/problema/apm

    int  n, m;
    vector<pair<int, int>> sol;
    fin >> n >> m;
    Graph g(n, m);
    g.readUndirectedCost();

    fout << g.kruskal(sol) << "\n" << sol.size() <<"\n";
    for(int i = 0; i < sol.size(); ++i)
        fout << sol[i].first << " " << sol[i].second << "\n";

}
void solveDisjoint() { ///UNINION & FIND
    //https://infoarena.ro/problema/disjoint

    int  n, m;
    fin >> n >> m;
    Graph g(n, m);
    g.disjoint();;

}

void solveDijkstra() {///THE PATH WITH MINIMUM COST FROM A SPECIFIC NODE
   //https://infoarena.ro/problema/dijkstra

   int  n, m;
   fin >> n >> m;
   Graph g(n, m);
   g.readDirectedCost();
   vector<int> dist = g.dijkstra();

   for(int i = 2; i <= n; ++i)
        if(dist[i] == inf)
            fout << 0 << " ";
        else fout << dist[i] << " ";
}

void solveBellmanFord() {///THE PATH WITH MINIMUM COST FROM A SPECIFIC NODE (with negative costs)
   //https://infoarena.ro/problema/bellmanford

   int  n, m;
   fin >> n >> m;
   Graph g(n, m);
   g.readDirectedCost();
   vector<int> dist = g.bellmanFord();
   bool exista = false;
   for(int i = 1; i <= n; ++i)
    if(dist[i] != -inf)
        exista = true;
   if(exista == true)
    for(int i = 2; i <= n; ++i)
                fout << dist[i] << " ";
    else
        fout << "Ciclu negativ!";
}

void solveRoyFloyd() { //--> MINIMUM PATH BETWEEN EACH 2 NODES
    //https://infoarena.ro/problema/royfloyd

    int n;
    fin >> n;
    Graph g(n);

    int d[N][N];    //the matrix with costs
    g.royFloyd(d);
    for(int i = 1; i <= n; ++i)
            {
                for(int j = 1; j <= n; ++j)
                    if(i == j || d[i][j] == inf)
                        fout << 0 <<" ";
                    else fout << d[i][j] << " ";
                fout <<"\n";
            }
}

void solveDiameter() {
    //https://infoarena.ro/problema/darb

    int n;
    fin >> n;
    Graph g(n, n - 1);
    g.readUndirected();
    fout << g.graphDiameter();
}

void solveMaximumFlow() {
    //https://infoarena.ro/problema/maxflow

    int  n, m;
    int matrix_flow[N][N];  ///the flow on an edge
    fin >> n >> m;
    Graph g(n, m);
    g.readDirectedFlow(matrix_flow);
    fout << g.fordFulkerson(matrix_flow);
}

void solveEuler() {
    //https://infoarena.ro/problema/ciclueuler

    int  n, m;
    fin >> n >> m;
    Graph g(n, m);
    vector<int> euler_cicle = g.Euler();
    if(euler_cicle[0] == -1) fout << -1;
    else
    for(int i = 0; i < euler_cicle.size() - 1; ++i)
        fout << euler_cicle[i] << " ";
}

void solveMaxBiparite() {
   //https://infoarena.ro/problema/cuplaj

   int  n, m;
   fin >> n >> m;
   Graph g(n, m);
   int sol;
   vector<int> match = g.maxBipartite(sol);

   fout << sol <<"\n";
    for(int i = 1; i <= m; ++i)//for every job that has an applicant
        if(match[i] != -1)
            fout << match[i] << " " << i << "\n";
}

 int main()
{
    solveStronglyConnectedComponents();

    return 0;
}
