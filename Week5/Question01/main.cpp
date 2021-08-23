#include <iostream>

using namespace std;

void solve(char *arr, int n){
    int count_arr[26] = {0};
    for(int i = 0; i < n; ++i){
        ++count_arr[arr[i] - 'a'];
    }

    int max_index = 0;
    for(int i = 1; i < n; ++i){
        if(count_arr[i] > count_arr[max_index]){
            max_index = i;
        }
    }

    if(count_arr[max_index] == 1)
        cout << "No Duplicates Present" << endl;
    else
        cout << (char)('a' + max_index) << " - " << count_arr[max_index] << endl;
    
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    // Number of test cases
    int t;      cin >> t;

    while(t--){    
        // Size of character array
        int n;      cin >> n;

        char *arr = new char[n];
        for(int i = 0; i < n; ++i){
            cin >> arr[i];
        }

        // Solve function call
        solve(arr, n);
        delete[] arr; 
    }

    return 0;
}
