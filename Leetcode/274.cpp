class Solution {
public:
    int hIndex(vector<int>& citations) {
        int arr[1001] = {0};
        for (auto it = citations.begin(); it != citations.end(); it++)
            arr[*it]++;
        for (int i = 999; i >= 0; i--)
            arr[i] += arr[i + 1];
        int h = 0;
        for (int i = 0; i <= 1000; i++)
        {
            if (arr[i] >= i) h = i;
        }

        return h;
    }   

};
