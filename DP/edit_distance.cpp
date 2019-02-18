#include <string>
#include <iostream>
#include <vector>
using namespace std;

int main() 
{
    string first = "horse";
    string second = "ros";
    
    vector<vector<int>> dp(first.length()+1,vector<int>(second.length()+1,0));
    for (int i=0;i<=first.length();i++) {
        for (int j=0;j<=second.length();j++) {
            if (i == 0 ) {
                dp[i][j] = j; //minimum j operations
            } else if (j==0) {
                dp[i][j] = i; //minimum i operations
            }else if (first[i-1] == second[j-1]) {
                dp[i][j] =dp[i-1][j-1]; //if last character is same we need to see how many ways are there for rest of the strings
                //cout<<i<<" "<<j<<" "<<dp[i][j]<<"\n";
            } else {
                dp[i][j] = 1 + min(dp[i-1][j], //delete one character in first lengths to compare are [0..i-2][0..j-1]
                                min(dp[i-1][j-1], //replace one character in first lengths to compare [0..i-2][0..j-2]
                                    dp[i][j-1])); // insert one character in first lengths to compare [0..i-1][0..j-2]
                //cout<<i<<" "<<j<<" "<<dp[i][j]<<"\n";
            }
        }
    }
    cout<<dp[first.length()][second.length()];
    return dp[first.length()][second.length()];
    
}
