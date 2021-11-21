#include <iostream>
#include <algorithm>

using namespace std;

typedef struct item{
    int value, weight;
} Item;

bool comp(Item a, Item b){
    return a.value/(float)a.weight > b.value/(float)b.weight;
}

void solve(Item *array, int n, int knapsack){
    sort(array, array + n, comp);

    float cost = 0;     int last_index = n-1;
    for(int i = 0; i < n; ++i){
        if(array[i].weight < knapsack){
            cost = cost + array[i].value;
            knapsack = knapsack - array[i].weight;
        } else{
            cost = cost + ((array[i].value/(float)array[i].weight) * knapsack);
            array[i].weight = knapsack;

            last_index = i;
            break;    
        }
    }

    cout << "Maximum Value : " << cost << endl;
    cout << "Item - Weight" << endl;
    for(int i = 0; i <= last_index; ++i){
        cout << array[i].value << "\t-\t" << array[i].weight << endl;
    }

}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n;      cin >> n;
    Item *array = new Item[n];
    for(int i = 0; i < n; ++i)
        cin >> array[i].weight;

    for(int i = 0; i < n; ++i)
        cin >> array[i].value;
    
    int knapsack;       cin >> knapsack;
    solve(array, n, knapsack);

    delete[] array;

    return 0;
}
