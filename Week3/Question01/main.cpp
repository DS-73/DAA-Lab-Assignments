#include <iostream>

using namespace std;

void solve(){
    int n;      cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }

    int comparisons = 0, shifts = 0;
    for(int i = 1; i < n; ++i){
        int j = i - 1, key = arr[i];
        while(j > -1 && arr[j] > key){
            ++comparisons;     ++shifts;
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key; 
        ++shifts;
    }
    for(int i = 0; i < n; ++i){
        cout << arr[i] << " ";
    }cout << endl;
    cout << "Comparisons = " << comparisons << endl;
    cout << "Shifts = " << shifts << endl;

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

