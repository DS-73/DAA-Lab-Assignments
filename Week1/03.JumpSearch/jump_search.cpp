#include <iostream>
#include <cmath>

using namespace std;

int jump_search(int *arr, int n, int key, bool &flag){
    int prev = 0, curr = sqrt(n);

    int no_of_comp = 1;
    while(curr < n && arr[curr] < key){
        prev = curr;    curr += sqrt(n);
        ++no_of_comp;
    }

    while(prev < n){
        ++no_of_comp;   
        if(arr[prev] == key){
            flag = true;
            return no_of_comp;
        }
        else if(arr[prev] > key){
            break;
        }
        ++prev;
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

        // Array must be sorted for binary search
        int *arr = new int[n];
        for(int i = 0; i < n; ++i){
            cin >> arr[i];
        }
        int key;        cin >> key;

        bool flag = false;
        int res = jump_search(arr, n, key, flag);
        if(flag){
            cout << "Present " << res << endl;
        }
        else{
            cout << "Not Present " << res << endl;
        }
        delete[] arr;

    }

    return 0;
}

