#include <iostream>

using namespace std;

void merge(int *arr, int l, int mid, int h, int &counter, int &inversion){
    int n1 = mid - l + 1, n2 = h - mid;
    
    int *arr1 = new int[n1];
    for(int i = 0; i < n1; ++i)     arr1[i] = arr[l + i];
    
    int *arr2 = new int[n2];
    for(int i = 0; i < n2; ++i)     arr2[i] = arr[mid + i + 1];

    int i = 0, j = 0, k = l;
    while(i < n1 && j < n2){
        if(arr1[i] < arr2[j]){
            arr[k++] = arr1[i++];
        }
        else{
            arr[k++] = arr2[j++];
            inversion += mid - i - l + 1;
        }
        ++counter;
    }
    
    while(i < n1){
        arr[k++] = arr1[i++];
    }
    while(j < n2){
        arr[k++] = arr2[j++];
    }

}

void merge_sort(int *arr, int l, int h, int &counter, int &inversion){
    if(l < h){
        int mid = l + (h - l)/2;
        merge_sort(arr, l, mid, counter, inversion);
        merge_sort(arr, mid + 1, h, counter, inversion);

        merge(arr, l, mid, h, counter, inversion);    
    }
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int t;      cin >> t;

    while(t--){
        int n, counter = 0, inversion = 0;      cin >> n;
        int *arr = new int[n];
        for(int i = 0; i < n; ++i){
            cin >> arr[i];
        }

        merge_sort(arr, 0, n - 1, counter, inversion);

        for(int i = 0; i < n; ++i){
            cout << arr[i] << " ";
        }cout << endl;
        cout << "Comparision = " << counter << endl;
        cout << "Inversion = " << inversion << endl;
        delete[] arr;
    }
    
    return 0;
}
