#include <iostream>

using namespace std;

bool solve(int *array, int index, int sum1, int sum2){
    if(index == 0){
        return sum1 == sum2;
    }
    return solve(array, index-1, sum1 + array[index-1], sum2) || solve(array, index-1, sum1, sum2 + array[index-1]);
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n;      cin >> n;

    int *array = new int[n];
    for(int i = 0; i < n; ++i){
        cin >> array[i];
    }

    if(solve(array, n, 0, 0)){
        cout << "yes" << endl;
    } else{
        cout << "no" << endl;
    }

    delete[] array;

    return 0;
}
