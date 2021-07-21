#include <iostream>

using namespace std;

int binary_search(int *arr, int n, int key, bool &flag){
    int l = 0, u = n - 1, no_of_comp = 0;
    while(l <= u){
        int mid = l + (u - l) / 2;      ++no_of_comp;
        if(arr[mid] == key){
            flag = true;
            break;
        }
        else if(arr[mid] < key){
            l = mid + 1;
        }
        else{
            u = mid - 1;
        }
    }

    return no_of_comp;
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
        bool flag = false;

        int res = binary_search(arr, n, key, flag);

        if(flag)    cout << "Present " << res << endl;
        else        cout << "Not Present " << res << endl;

        delete[] arr;
    }

    return 0;
}

