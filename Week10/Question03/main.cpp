#include <iostream>
#include <algorithm>

using namespace std;

void solve(int *array, int n){
    sort(array, array + n);
    
    bool flag = false;
    for(int i = 0; i < n; ++i){
        int freq = 1, j = i + 1;
        while(j < n && array[j] == array[i]){
            ++freq;     ++j;
        }

        if(freq > n/2){
            flag = true;    break;
        }
        i = j - 1;
    } 

    if(flag)        cout << "yes" << endl;
    else            cout << "no" << endl;

    if(n & 1){
        cout << array[n/2] << endl;
    } else{
        cout << (array[(n-1)/2] + array[n/2]) / 2.0 << endl;
    }
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

    solve(array, n);

    return 0;
}


