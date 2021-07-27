#include <iostream>

using namespace std;

int binary_search(int *arr, int start, int end, int key){
    while(start <= end){
        int mid = start + (end - start)/2;
        if(arr[mid] == key){
            return mid;
        }
        else if(arr[mid] < key){
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    return -1;
}

void solve(){
    int n;      cin >> n;

    int *arr = new int[n];
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }

    for(int i = 0; i < n-2; ++i){
        for(int j = i + 1; j < n-1; ++j){
            int sum = arr[i] + arr[j];

            int res = binary_search(arr, j, n - 1, sum);
            if(res != -1){
                cout << i + 1 << ", " << j + 1 << ", " << res + 1 << endl;
                return;
            }

        }
    }
    cout << "No sequence found." << endl;

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
