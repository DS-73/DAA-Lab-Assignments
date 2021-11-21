#include <iostream>
#include <vector>

using namespace std;

void solve(vector<int> &v, int target){
    vector<int> dp(target + 1,0);
    dp[0] = 1;

    for(int i = 0; i < v.size(); ++i){
        for(int j = v[i]; j < dp.size(); ++j){
            if(dp[j - v[i]] != 0){
                dp[j] = dp[j] + dp[j - v[i]]; 
            }
        }
    }
    cout << dp[target] << endl;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n;      cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; ++i){
        cin >> v[i];
    }
    
    int target;     cin >> target;
    solve(v, target);

    return 0;
}
