#include <iostream>
#include <queue>
#include <vector>
#include <climits>

#define ppair pair<int, pair<int, int>>

using namespace std;

priority_queue<ppair, vector<ppair>, greater<ppair>> get_heap(vector<vector<int>> &graph){
    priority_queue<ppair, vector<ppair>, greater<ppair>> heap;
    for(int i = 0; i < graph.size(); ++i){
        for(int j = 0; j < graph.size(); ++j){
            if(graph[i][j] != 0){
                heap.push(make_pair(graph[i][j], make_pair(i, j)));
            }     
        }
    }
    return heap;
}

int find(int u, vector<int> &disjoint_set){
    if(disjoint_set[u] < 0){
        return u;
    }
    return find(disjoint_set[u], disjoint_set);
}

void solve(vector<vector<int>> &graph, vector<int> &disjoint_set){
    priority_queue<ppair, vector<ppair>, greater<ppair>> min_heap = get_heap(graph);
    
    int weight = 0;
    while(!min_heap.empty()){
        int u = min_heap.top().second.first, v = min_heap.top().second.second;

        int pu = find(u, disjoint_set);
        int pv = find(v, disjoint_set);

        if(pu != pv){
            if(disjoint_set[pu] < disjoint_set[pv]){
                disjoint_set[pu] = disjoint_set[pu] + disjoint_set[pv];
                disjoint_set[pv] = pu;
            } else{
                disjoint_set[pv] = disjoint_set[pu] + disjoint_set[pv];
                disjoint_set[pu] = pv;
            }
            weight = weight + min_heap.top().first;
        }
        min_heap.pop();
    }
    
    cout << "Minimum spanning Weight : " << weight << endl;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n;      cin >> n;
    vector<vector<int>> graph(n, vector<int>(n));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> graph[i][j];
        }
    }

    vector<int> disjoint_set(n, -1);
    solve(graph, disjoint_set);

    return 0;
}

