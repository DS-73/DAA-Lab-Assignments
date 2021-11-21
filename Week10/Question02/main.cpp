#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct job{
    int position, duration, deadline;
}Jobs;

bool comp(const Jobs a, const Jobs b){
    return a.deadline < b.deadline;
}

void solve(vector<Jobs> &array, int n){
    sort(array.begin(), array.end(), comp);
    int sum = 0, counter = 0;

    vector<int> result;
    for(int i = 0; i < n; ++i){
        if(array[i].duration + sum <= array[i].deadline){
            result.push_back(array[i].position);
            ++counter;
            sum = sum + array[i].duration;
        } 
        array[i].duration = sum + array[i].duration;
    }
    
    cout << "Max number of tasks : " << counter << endl;
    cout << "Selected task number : ";

    sort(result.begin(), result.end());
    for(int i = 0; i < result.size(); ++i){
        cout << result[i];
        if(i != result.size()-1)      cout << ", ";
    }cout << endl;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n;      cin >> n;

    vector<Jobs> array(n);
    for(int i = 0; i < n; ++i){
        cin >> array[i].duration;
    }
    for(int i = 0; i < n; ++i){
        cin >> array[i].deadline;
        array[i].position = i + 1;
    }

    solve(array, n);

    return 0;
}

