#include <string>
#include <iostream>
#include <vector>
using namespace std;

int main() 
{
    string first = "AGGTAB";
    string second = "GXTXAYB";
    
    vector<vector<int>> dp(first.length()+1,vector<int>(second.length()+1,0));
    for (int i=0;i<=first.length();i++) {
        for (int j=0;j<=second.length();j++) {
            if (i == 0 || j == 0) {
                continue;
            } else if (first[i-1] == second[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
                //cout<<i<<" "<<j<<" "<<dp[i][j]<<"\n";
            } else {
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                //cout<<i<<" "<<j<<" "<<dp[i][j]<<"\n";
            }
        }
    }
    cout<<dp[first.length()][second.length()];
    return dp[first.length()][second.length()];
    
}
