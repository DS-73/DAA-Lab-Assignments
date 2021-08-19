#include <iostream>
#include <time.h>

using namespace std;

int partition(int *arr, int l, int u){
    srand(time(NULL));
    int index = rand() % (u - l) + l;
    swap(arr[u], arr[index]);

    int low_index = l - 1;
    for(int i = l; i < u; ++i){
        if(arr[i] <= arr[u]){
            swap(arr[++low_index], arr[i]);
        }
    }
    swap(arr[++low_index], arr[u]);
    return low_index;
}

void search(int *arr, int l, int u, int k){
    if(l < u){
        int pivot = partition(arr, l, u);
        if(pivot == k){
            return;
        }
        else if(pivot > k)
            search(arr, l, pivot - 1, k);
        else
            search(arr, pivot + 1, u, k - pivot);
    }
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int t;      cin >> t;
    while(t--){
        int n;      cin >> n;
        int *arr = new int[n];
        for(int i = 0; i < n; ++i){
            cin >> arr[i];
        }

        int k;      cin >> k;
        search(arr, 0, n - 1, k - 1);
        cout << arr[k-1] << endl;

        delete[] arr;
    }
        

    return 0;
}
