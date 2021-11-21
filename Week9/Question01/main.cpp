#include <iostream>
#include <vector>
#include <string>
#include <climits>

using namespace std;

void solve(vector<vector<int>> &graph){
    for(int k = 0; k < graph.size(); ++k){
        for(int i = 0; i < graph.size(); ++i){
            for(int j = 0; j < graph.size(); ++j){
                if(graph[i][k] != INT_MAX && graph[k][j] != INT_MAX && (graph[i][j] > graph[i][k] + graph[k][j])){
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }   
    }

    for(int i = 0; i < graph.size(); ++i){
        for(int j = 0; j < graph.size(); ++j){
            if(graph[i][j] != INT_MAX)        cout << graph[i][j] << " ";
            else                              cout << "INF" << " "; 
        } cout << endl;
    } cout << endl;
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
            string s;       cin >> s;
            if(s == "INF")      graph[i][j] = INT_MAX;
            else                graph[i][j] = stoi(s);
        }
    }

    solve(graph);

    return 0;
}
