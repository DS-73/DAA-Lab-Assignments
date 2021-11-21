#include <iostream>
#include <algorithm>

using namespace std;

void solve(int *array, int n){
    sort(array, array + n);

    int acc = 0, sum = array[0];
    for(int i = 1; i < n; ++i){
        sum = sum + array[i];
        acc = acc + sum ;
    }

    cout << acc << endl;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n;          cin >> n;
    int *array = new int[n];
    for(int i = 0; i < n; ++i){
        cin >> array[i];
    }

    solve(array, n);

    return 0;
}

