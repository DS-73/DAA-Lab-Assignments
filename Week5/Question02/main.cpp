#include <iostream>
#include <time.h>

using namespace std;

int partition(int *arr, int l, int u){
    srand(time(NULL));
    int random_index = rand() % (u - l) + l;
    swap(arr[u], arr[random_index]);

    int lower_index = l - 1;
    for(int i = l; i < u; ++i){
        if(arr[i] <= arr[u]){
            swap(arr[++lower_index], arr[i]);
        }
    }

    swap(arr[++lower_index], arr[u]);
    return lower_index;
}

void q_sort(int *arr, int l, int u){
    if(l < u){
        int pivot = partition(arr, l, u);

        q_sort(arr, l, pivot - 1);
        q_sort(arr, pivot + 1, u);
    }
}

void search(int *arr, int n, int key){
    bool flag = true;
    int i = 0, j = n - 1;
    
    while(i < j){
        if(arr[i] + arr[j] == key){
            cout << arr[i] << " " << arr[j] << ", ";
            --j;        flag = false;
        }
        else if(arr[i] + arr[j] > key){
            --j;
        }
        else{
            ++i;
        }
    }

    if(flag){
        cout << "No Such pair Exist";
    }cout << endl;
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
        int key;        cin >> key;

        q_sort(arr, 0, n-1);
        search(arr, n, key);

        delete[] arr;
    }

    return 0;
}
