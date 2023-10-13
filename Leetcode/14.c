#include<string.h>

char * longestCommonPrefix(char ** strs, int strsSize){
    int lpl = strlen(strs[0]);
    for (int i = 1; i < strsSize; i++)
    {
        for (int j = 0; j < lpl; j++)
        {
            if (strs[i][j] != strs[0][j] || strs[i][j] == 0)
            {
                lpl = j;
                break;
            }
        }
    }
    strs[0][lpl] = 0;
    return strs[0];
}
