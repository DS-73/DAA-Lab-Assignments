#include <iostream>
#include <queue>

using namespace std;

bool solve(int **arr, int n){
    int *color_arr = new int[n];
    for(int i = 0; i < n; ++i){
        color_arr[i] = 0;
    }
 
    queue <int> q;  q.push(0);
    color_arr[0] = 1;

    while(!q.empty()){
        int ele = q.front();    q.pop();
        if(arr[ele][ele] != 0){
            return false;
        }

        for(int i = 0; i < n; ++i){
            if(arr[ele][i] != 0){
                if(color_arr[i] == 0){
                    color_arr[i] = color_arr[ele]*-1;
                    q.push(i);
                }
                else if(color_arr[i] == color_arr[ele]){
                    return false;
                }
            }
        }
    }

    return true;
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
    
    if(solve(arr, n)){
        cout << "Bipertite" << endl;
    }
    else{
        cout << "Not Bipertite" << endl;
    }
    delete[] arr;

    return 0;
}
