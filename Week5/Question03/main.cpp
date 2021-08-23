#include <iostream>

using namespace std;

void solve(int *arr1, int m, int *arr2, int n){
    int index1 = 0, index2 = 0;
    
    while(index1 < m && index2 < n){
        if(arr1[index1] == arr2[index2]){
            cout << arr1[index1] << " ";
            ++index1;       ++index2;
        }
        else if(arr1[index1] < arr2[index2]){
            ++index1;
        }
        else{
            ++index2;
        }
    }
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int m;      cin >> m;
    int *arr1 = new int[m];
    for(int i = 0; i < m; ++i){
        cin >> arr1[i];
    }
    
    int n;      cin >> n;
    int *arr2 = new int[n];
    for(int i = 0; i < n; ++i){
        cin >> arr2[i];
    }

   solve(arr1, m, arr2, n);

    return 0;
}
