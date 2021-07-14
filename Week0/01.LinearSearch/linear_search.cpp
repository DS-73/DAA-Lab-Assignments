#include <iostream>

using namespace std;

void linear_search(int *arr, int n, int key){

    int no_of_comp = 0;         // Variable to count total number of comparisions

    for(size_t i = 0; i < n; ++i){
        ++no_of_comp;
        if(arr[i] == key){
            cout << endl << "> Key found at index : " << i;
            cout << endl << "Number of comparisons : " << no_of_comp;
            return;
        }
    }

    cout << endl << "> Key not matched";
    cout << endl << "Number of comparisons : " << no_of_comp;

}

int main(){

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int t;      cin >> t;   // number of test cases
    while(t--){
        int n;      cin >> n;

        int *arr = new int[n]; 
        for(size_t i = 0; i < n; ++i){
            cin >> arr[i];      
        }

        // key to be searched in array
        int key;        cin >> key;
        linear_search(arr, n, key);    // linear search function call
        cout << endl;

        delete[] arr;
    }

    return 0;
}
