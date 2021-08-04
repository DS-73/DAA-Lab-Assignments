#include <iostream>

using namespace std;

void solve(){
    int n;      cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }

    int comparisons = 0, swaps = 0;
    for(int i = 0; i < n - 1; ++i){
        int min_index = i;
        for(int j = i + 1; j < n; ++j){
            if(arr[min_index] > arr[j]){
                min_index = j;
            }
            ++comparisons;
        }
        swap(arr[min_index], arr[i]);
        ++swaps;

    }

    for(int i = 0; i < n; ++i){
        cout << arr[i] << " ";
    }cout << endl;
    cout << "Comparisons = " << comparisons << endl;
    cout << "Swaps = " << swaps << endl;
    
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
