#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> ans;
    void backtrack(int start, vector<int> &res, int n, int k)
    {
        if (res.size() == k)
        {
            print(res);
            ans.push_back(res);
            return;
        }

        for (int i = start; i < n + 1; i++)
        {
            res.push_back(i);
            backtrack(i + 1, res, n, k);
            res.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k)
    {
        vector<int> current;
        backtrack(1, current, n, k);
        return ans;
    }

    void print(const vector<int> &res)
    {
        for (auto &num : res)
        {
            cout << num << ", ";
        }
        cout << endl;
    }
};

int main()
{
    int n = 4;
    int k = 2;

    Solution s;

    vector<vector<int>> result = s.combine(4, 2);

    return 0;
}