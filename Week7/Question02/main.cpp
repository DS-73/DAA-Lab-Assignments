#include <iostream>

using namespace std;

const int MAX_VAL = 10000009;

void get_node(int *node_info, int index, int n, int source){
    cout << index + 1<< " ";
    if(index == source){
        return;
    }
    get_node(node_info, node_info[index], n, source);
}

void solve(int **array, int n, int source){
    int *distance = new int[n];
    for(int i = 0; i < n; ++i){
        distance[i] = MAX_VAL;
    }   distance[source] = 0;

    int *node_info = new int[n]{0};        node_info[source] = source;
    for(int it = 0; it < n-1; ++it){
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(array[i][j] != 0){
                    if(distance[j] > distance[i] + array[i][j]){
                        distance[j] = distance[i] + array[i][j];
                        node_info[j] = i;
                    }
                }
            }
        }
    }

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(array[i][j] != 0){
                if(distance[j] > distance[i] + array[i][j]){
                    cout << "Negative Cycle Detected";
                    return;
                }
            }
        }
    }

    for(int i = 0; i < n; ++i){
        get_node(node_info, i, n, source);
        cout << ": " << distance[i] << endl;
    }

}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n;      cin >> n;
    int **array = new int*[n];
    for(int i = 0; i < n; ++i){
        array[i] = new int[n];
        for(int j = 0; j < n ; ++j){
            cin >> array[i][j];
        }
    }
    int source;     cin >> source;    
    solve(array, n, source - 1);


    return 0;
}

