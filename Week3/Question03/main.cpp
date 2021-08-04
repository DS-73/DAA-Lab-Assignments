#include <iostream>

using namespace std;

int partition(int *arr, int l, int u){
    int index = l - 1;
    for(int i = l; i < u; ++i){
        if(arr[i] < arr[u]){
            ++index;
            swap(arr[i], arr[index]);
        }
    }
    ++index;
    swap(arr[index], arr[u]);

    return index;
}

void qsort(int *arr, int l, int u){
    if(l < u){
        int pivot = partition(arr, l, u);

        qsort(arr, l, pivot - 1);
        qsort(arr, pivot + 1, u);
    }
}

void solve(){
    int n;      cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }

    // Quick Sort T.C. - O(nlogn)
    qsort(arr, 0, n - 1);

    for(int i = 1; i < n; ++i){
        if(arr[i] == arr[i - 1]){
            cout << "YES" << endl;
            return ;
        }
    }
    cout << "NO" << endl;

    delete[] arr;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int t;      cin >> t;

    while(t--){
        solve();
    }

    return 0;
}
