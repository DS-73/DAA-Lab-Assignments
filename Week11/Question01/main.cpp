#include <iostream>
#include <vector>

using namespace std;

vector<int> flatten_matrix(vector<pair<int, int>> &v){
    vector<int> res;        res.push_back(v[0].first);
    for(int i = 0; i < v.size(); ++i){
        res.push_back(v[i].second);
    }
    return res;
}

int solve(vector<int> &v){
    vector<vector<int>> dp(v.size(), vector<int>(v.size()));
    
    for (int i = 1; i < v.size(); ++i){
        dp[i][i] = 0;
    }
 
 
    for (int i = 1; i < v.size() - 1; i++){
        for (int j = 1; j < v.size() - i; j++){    
            int a = dp[j + 1][i + j] + v[j - 1] * v[j] * v[i + j]; 
            int b = dp[j][i + j- 1] + v[j-1] * v[i + j - 1] * v[i + j];    

            dp[j][i + j] = min(a, b);
        }
    }
    return dp[1][v.size() - 1];

}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n;      cin >> n;
    vector<pair<int, int>> v(n);
    for(int i = 0 ; i < n; ++i){
        cin >> v[i].first >> v[i].second;
    }

    vector<int> flat = flatten_matrix(v);
    cout << solve(flat);

    return 0;
}
