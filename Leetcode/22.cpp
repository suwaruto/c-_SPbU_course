class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string>> res(n + 1);
        res[0] = {""};
        res[1] = {"()"};
        for (int i = 2; i <= n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                for (auto it1 = res[j].begin(); it1 != res[j].end(); it1++)
                {
                    for (auto it2 = res[i - j - 1].begin(); 
                        it2 != res[i - j - 1].end(); it2++)
                    {
                        res[i].push_back('(' + *it2 + ')' + *it1);
                    }
                }
            }
        }

        return res[n];
    }
};

/*
    (<0>)<n - 1>    
    (<1>)<n - 2>
    ...
    (<n - 1>)<0>

    (<0>)<1> -> ()()
    (<1>)<0> -> (())
*/
