#include <iostream>
#include <time.h>

using namespace std;

int partition(int *arr, int l, int u, int &comparison, int &swaps){
    srand(time(NULL));
    int index = rand() % (u - l) + l;
    swap(arr[index], arr[u]);

    int low_index = l - 1;   
    for(int i = l; i < u; ++i){
        if(arr[i] <= arr[u]){
            swap(arr[++low_index], arr[i]);
            ++swaps;
        }
        ++comparison;
    }
    swap(arr[++low_index], arr[u]);
    return low_index;
}

void quick_sort(int *arr, int l, int u, int &comparison, int &swaps){
    if(l < u){
        int pivot = partition(arr, l, u, comparison, swaps);

        quick_sort(arr, l, pivot - 1, comparison, swaps);
        quick_sort(arr, pivot + 1, u, comparison, swaps);
    }
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int t;      cin >> t;
    while(t--){
        int n, comparison = 0, swaps = 0;      cin >> n;
        
        int *arr = new int[n];
        for(int i = 0; i < n; ++i){
            cin >> arr[i];
        }

        quick_sort(arr, 0, n-1, comparison, swaps);

        for(int i = 0; i < n; ++i){
            cout << arr[i] << " ";
        }cout << endl;
        cout << "Comparison = " << comparison << endl;
        cout << "Swaps = " << swaps << endl;
        
        delete[] arr;
    }

    return 0;
}
