#include <iostream>
#include <vector>

using namespace std;


class Solution
{

    /*
    dp[i][j] which denotes the max coins achieved by bursting balloons from [i][j].
    Taking example from the given test case.[3, 1, 5, 8]
    which can also be written as [1, 3, 1, 5, 8, 1]
    dp[0][3] = max(1x3x1 + dp[1,3],
    1x1x1 + dp[0,0] + dp[2,3], 1x5x1 + dp[0,1] + dp[3,3],
    1x8x1 + dp[0,2]


    pattern : Matric chain multiplication
    dp[i][j] = max(dp[i][j], dp[i][k] + dp[k+1][j] + p[i-1]*p[k]*p[j])

    observation: 
     * what if the element we are choosing is the last one to burst?
     ---> this is forming the decision tree    
     --->lets cache the left and right boundaries of the sub-problem
        ---> we can use a 2D matrix to store the result
        ---> by this way we are comnsidering n*n sub-problems or subsequences for n elements
        ---> overall time complexity is O(n^3)
        ---> space complexity is O(n^2)

    */
    int dfs(int l, int r, vector< vector<int> > &dp, vector<int > &balloons)
    {

        if (l > r)
            return 0;

        if (dp[l][r] != -1)
            return dp[l][r];

        dp[l][r] = INT_MIN;

        int left = (l == 0) ? 1 : balloons[l - 1];
        int right = (r == balloons.size() - 1) ? 1 : balloons[r + 1];

        for (int i = l; i < r + 1; i++)
        {
            int coins = left * balloons[i] * right;

            coins += dfs(l, i - 1, dp, balloons) + dfs(i + 1, r, dp, balloons);

            dp[l][r] = max(dp[l][r], coins);
        }

        return dp[l][r];
    }

    int iterative(vector<int> &nums, vector<vector<int> > &dp)
    {

        int n = nums.size();

        for (int len = 0; len < n; len++)
        {
            for (int l = 0; l + len < n; l++)
            {
                int r = l + len;
                for (int k = l; k <= r; k++)
                {
                    int leftNum = l == 0 ? 1 : nums[l - 1];
                    int rightNum = r == n - 1 ? 1 : nums[r + 1];

                    int left = k == l ? 0 : dp[l][k - 1];
                    int right = k == r ? 0 : dp[k + 1][r];

                    dp[l][r] = max(dp[l][r], leftNum * nums[k] * rightNum + left + right);
                }
            }
        }
        return dp[0][n - 1];
    }

public:
    int maxCoins(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];

        // vector<vector<int>> dp(n+2,vector<int>(n+2,-1));
        vector<vector<int> > dp(n, vector<int>(n, 0));

        // return dfs(0,n-1,dp,nums);

        return iterative(nums, dp);
    }
};

int main()
{
    Solution s;
    int arr[] = {3, 1, 5, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
 
    vector<int> nums(arr, arr + n);
    cout << s.maxCoins(nums) << endl;
    return 0;
}