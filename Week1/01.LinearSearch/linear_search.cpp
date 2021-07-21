#include <iostream>

using namespace std;

void linear_search(){
    int n;      cin >> n;

    int *arr = new int[n];
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }

    int key;        cin >> key;
    int no_of_comp = 0;     bool flag = false;
    
    for(int i = 0; i < n; ++i){
        ++no_of_comp;
        if(arr[i] == key){
            flag = true;
            break;
        }
    }

    if(flag){
        cout << "Present "<< no_of_comp << endl;
    }
    else{
        cout << "Not Present "<< no_of_comp << endl;
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
        linear_search();
    }

    return 0;
}

