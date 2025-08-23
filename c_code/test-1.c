#include<stdio.h>
#include<stdbool.h>
typedef struct
{
    char data[30];
    int top;
} sqstack;
bool check(char *str)
{
    sqstack a;
    a.top = 0;
    int i = 0;
    while (*(str + i) != '\n')
    {
        switch (*(str + i))
        {
            case '}':
                if (a.data[a.top-1] != '{')
                {
                    printf("匹配失败\n");
                    return false;
                }
                else
                    a.top--;
                break;
            case ']':
                if (a.data[a.top-1] != '[')
                {
                    printf("匹配失败\n");
                    return false;
                }
                else
                    a.top--;
                break;
            case ')':  
                if (a.data[a.top-1] != '(')
                {
                    printf("匹配失败\n");
                    return false;
                }
                else
                    a.top--;
                break;
            default:
                a.data[a.top] = *(str + i);
                a.top++;
                break;
        }
        i++;
    }
    printf("匹配成功\n");
    return true;
}
int main()
{
    char str[30];
    scanf("%s", str);
    check(str);
    return 0;
}