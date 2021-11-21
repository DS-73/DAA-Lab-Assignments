#include <iostream>
#include <vector>
#include <queue>
#include <climits>

#define ipair pair<int, int> 

using namespace std;

void solve(vector<vector<int>> &graph){
    priority_queue<ipair, vector<ipair>, greater<ipair>> min_heap;
    min_heap.push(make_pair(2, 0));      // <weight, index>

    vector<int> weight(graph.size(), INT_MAX);
    vector<bool> visited(graph.size(), false);

    weight[0] = 0;
    while(!min_heap.empty()){
        int index = min_heap.top().second;      min_heap.pop();
        if(!visited[index]){
            visited[index] = true;
            for(int i = 0; i < graph.size(); ++i){
                if(graph[index][i] < weight[i] && graph[index][i] != 0){
                    weight[i] = graph[index][i];
                    min_heap.push(make_pair(weight[i], i));
                }
            }
        }
    }

    int cost = 0;
    for(int i = 0; i < weight.size(); ++i){
        cout << weight[i] << " ";
        cost = cost + weight[i];
    }cout << endl;
    
    cout << "Minimum cost : " << cost << endl;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n;      cin >> n;
    vector<vector<int>> graph(n, vector<int>(n));
    for(int i = 0; i < graph.size(); ++i){
        for(int j = 0; j < graph[i].size(); ++j){
            cin >> graph[i][j];
        }
    }

    solve(graph);

    return 0;
}
