#include <iostream>
#include <algorithm>

using namespace std;

typedef struct activity{
    int start, end, position;
} Activity;

bool comp(Activity a, Activity b){
    return a.end < b.end;
}

void solve(Activity *array, int n){
    sort(array, array+n, comp);
    int last_end = -1, count = 0;

    int *position_array = new int[n], iter = 0;
    for(int i = 0; i < n; ++i){
        if(last_end < array[i].start ){
            last_end = array[i].end;
            position_array[iter++] = array[i].position; 
            ++count;        
        }
    }

    cout << "No. of non-conflicting activities : " << count << endl;
    cout << "List of selected activities : ";
    for(int i = 0; i < iter; ++i){
        cout << position_array[i];
        if(i != iter-1)     cout << ", ";
    }

}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n;      cin >> n;
    Activity *array = new Activity[n];
    for(int i = 0; i < n; ++i)
        cin >> array[i].start;

    for(int i = 0; i < n; ++i){
        cin >> array[i].end;
        array[i].position = i + 1;
    }
    solve(array, n);

    return 0;
}

