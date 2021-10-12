#include <iostream>
#include <climits>
#include <queue>

using namespace std;

void solve(int **array, int n, int source, int destination, int path){
    int *distances = new int[n];      int original_path = path;
    for(int i = 0; i < n; ++i){
        distances[i] = INT_MAX;
    } distances[source] = 0;

    queue<int> q;       q.push(source);
    int counter = 1;
    while(--path){
        int temp_counter = 0;
        while(counter--){
            for(int i = 0; i < n; ++i){
                if(array[q.front()][i] != 0 && i != destination){
                    if(distances[i] > distances[q.front()] + array[q.front()][i]){
                        distances[i] = distances[q.front()] + array[q.front()][i];
                        q.push(i);      ++temp_counter;
                    }
                }
            }
            q.pop();
        } counter = temp_counter;
    }
    
    int min_distance = INT_MAX;
    while(!q.empty()){
        if(array[q.front()][destination] != 0){
            min_distance = min(min_distance, distances[q.front()] + array[q.front()][destination]);
        }
        q.pop();
    }

    if(min_distance == INT_MAX){
        cout << "No path from (" << source + 1 << ", " << destination + 1 << ") with " << original_path << " exist";
    } 
    else{
        cout << "Weight of shortest path (" << source + 1 << ", " << destination + 1 << ") with ";
        cout << original_path << " : " << min_distance;
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
        for(int j = 0; j < n; ++j){
            cin >> array[i][j];
        }
    }
    int source, destination, path;        cin >> source >> destination >> path;
    solve(array, n , source - 1, destination - 1, path);

    return 0;
}

