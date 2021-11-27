#include <stdio.h>

// Link To Problem -> https://www.hackerrank.com/challenges/almost-sorted/problem?isFullScreen=false
// Approach -> check if swapping the anomalies (search from left and right for those) sorts the array, if not check if reversing the sub-array formed by the anomalies sorts the array, if not GG

int main()
{
    int n, i;
    scanf("%d", &n);

    int a[n];

    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for (i = 1; i < n; i++)
        if (a[i] < a[i - 1])
            break;

    // check if input is sorted
    if (i == n)
    {
        printf("yes");
        return 0;
    }

    int l, r;

    if (a[0] > a[1])
        l = 0;
    else
        for (i = 1; i < n - 1; i++)
            if (a[i] > a[i - 1] && a[i] > a[i + 1])
            {
                l = i;
                break;
            }

    if (a[n - 1] < a[n - 2])
        r = n - 1;
    else
        for (i = n - 2; i > 0; i--)
            if (a[i] < a[i - 1] && a[i] < a[i + 1])
            {
                r = i;
                break;
            }

    // swapping
    int temp;
    temp = a[l];
    a[l] = a[r];
    a[r] = temp;

    // check for sorted
    for (i = 1; i < n; i++)
        if (a[i] < a[i - 1])
            break;

    if (i == n)
    {
        printf("yes\nswap %d %d", l + 1, r + 1);
        return 0;
    }

    // back to original state
    temp = a[l];
    a[l] = a[r];
    a[r] = temp;

    for (i = l; i <= (l + r) / 2; i++)
    {
        temp = a[i];
        a[i] = a[l + r - i];
        a[l + r - i] = temp;
    }

    // check for sorted
    for (i = 1; i < n; i++)
        if (a[i] < a[i - 1])
            break;

    if (i == n)
    {
        printf("yes\nreverse %d %d", l + 1, r + 1);
        return 0;
    }

    printf("no");
}