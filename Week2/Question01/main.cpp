#include <iostream>

using namespace std;

int left_binary_search(int *arr, int n, int start, int end, int key){
    while(start <= end){
        int mid = start + (end - start)/2;
        if(arr[mid] == key){
            if(mid == 0 || arr[mid - 1] != key){
                return mid;
            }
            else{
                --end;
            }
            
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

int right_binary_search(int *arr, int n, int start, int end, int key){
    while(start <= end){
        int mid = start + (end - start)/2;
        if(arr[mid] == key){
            if(mid == n-1 || arr[mid + 1] != key){
                return mid;
            }
            else{
                ++start;
            }
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

    int key;        cin >> key;

    int left = left_binary_search(arr, n, 0, n - 1, key);
    int right = right_binary_search(arr, n, 0, n - 1, key);
    
    if(left == right && left == -1){
        cout << key << " - " << 0 << endl;
    }
    else{
        cout << key << " - " << right - left + 1 << endl;
    }
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
