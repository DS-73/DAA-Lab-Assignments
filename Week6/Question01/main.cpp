#include <iostream>
#include <queue>

using namespace std;

void solve(int **arr, int n, int v1, int v2){
    bool *visitedArray = new bool[n];
    for(int i = 0; i < n; ++i){
        visitedArray[i] = false;
    }

    queue<int> q;       q.push(v1);
    visitedArray[v1] = true;

    while(!q.empty()){
        for(int i = 0; i < n; ++i){
            if(arr[q.front()][i] != 0){
                if(i == v2){
                    cout << "Yes Path Exists" << endl;
                    return;
                }
                else if(!visitedArray[i]){
                    q.push(i);
                    visitedArray[i] = true;
                }
            }
        }
        q.pop();
    }
    cout << "No Such Path Exists" << endl;

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
    
    int v1, v2;     cin >> v1 >> v2;
    solve(arr, n, v1 - 1, v2 - 1);
    delete[] arr;

    return 0;
}
