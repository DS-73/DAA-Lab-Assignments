#include <iostream>
#include <cmath>

using namespace std;

void solve(){
    int n;      cin >> n;

    int *arr = new int[n];
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }

    int key, counter = 0;        cin >> key;

    for(int i = 0; i < n - 1; ++i){
        for(int j = i + 1; j < n; ++j){
            if(abs(arr[i] - arr[j]) == key){
                ++counter;
            }
        }
    }
    cout << counter << endl;

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
