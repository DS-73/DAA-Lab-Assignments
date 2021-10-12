#include <iostream>
#include <climits>

using namespace std;

int get_node(int *distances, bool *visited, int n){
    int min = INT_MAX;
    for(int i = 0 ; i < n; ++i){
        if((min == -1 || distances[i] < distances[min]) && visited[i] == false){
            min = i;
        }
    }
    return min;
}

void get_path(int *node_info, int n, int node, int source){
    cout << node + 1<< " ";
    if(source == node){
        return;
    }
    get_path(node_info, n, node_info[node], source);
}

void solve(int **arr, int n, int source){
    int *distances = new int[n];
    for(int i = 0; i < n; ++i){
        distances[i] = INT_MAX;
    }   distances[source] = 0;

    int *node_info = new int[n]{0};    node_info[source] = source;    
    bool *visited = new bool[n] {false};

    for(int i = 0; i < n-1; ++i){
        int node = get_node(distances, visited, n);
        for(int j = 0; j < n; ++j){
            if(arr[node][j] != 0 && j != node){
                if(distances[j] > arr[node][j] + distances[node]){
                    distances[j] = arr[node][j] + distances[node];
                    node_info[j] = node;
                }
            }
        }
        visited[node] = true;
    }

    for(int i = 0; i < n; ++i){
        get_path(node_info, n, i, source);
        cout << ": " << distances[i] << endl;
    }

}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    int n;      cin >> n;

    int **arr = new int*[n];
    for(int i = 0; i < n; ++i){
        arr[i] = new int[n];
        for(int j = 0; j < n; ++j){
            cin >> arr[i][j];
        }
    }
    
    int source;         cin >> source;
    solve(arr, n, source-1);

    return 0;
}

