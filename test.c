#include <stdio.h>
#include <string.h>

int getHr(char[]);
void replaceHR(int, char[]);

//Find why !!! in the end

int main()
{
    char str[10];

    scanf("%s", str);

    int hr = getHr(str);

    if (str[8] == 'P')
    {
        if (hr < 12)
            hr += 12;
    }
    else if (hr == 12)
        hr = 0;

    replaceHR(hr, str);
    printf("%s", str);
}

int getHr(char str[])
{
    char first = str[0] - 48;
    char second = str[1] - 48;

    if (first == '0')
        return (second);
    return (first * 10 + second);
}

void replaceHR(int hr, char str[])
{
    int first = hr / 10;
    int second = hr % 10;

    str[0] = first + 48;
    str[1] = second + 48;

    // for (int i = 8; i < strlen(str); i++)
    //     str[i] = ' ';

}
