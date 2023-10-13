#include<string.h>

int romanToInt(char * s){
    int num = 0;
    int len = strlen(s);
    for (int i = len; i >= 0; i--)
    {
        switch(s[i])
        {
            case 'I':
                if (s[i + 1] == 'V' || s[i + 1] == 'X')
                {
                    num--;
                }
                else
                {
                    num++;
                }
                break;
            case 'V':
                num += 5;
                break;
            case 'X':
                if (s[i + 1] == 'L' || s[i + 1] == 'C')
                {
                    num -= 10;
                }
                else
                {
                    num += 10;
                }
                break;
            case 'L':
                num += 50;
                break;
            case 'C':
                if (s[i + 1] == 'D' || s[i + 1] == 'M')
                {
                    num -= 100;
                }
                else
                {
                    num += 100;
                }
                break;
            case 'D':
                num += 500;
                break;
            case 'M':
                num += 1000;
                break;
        }
    }
    return num;
}
