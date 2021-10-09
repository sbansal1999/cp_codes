#include <stdio.h>
#include <math.h>

/*
https://www.hackerrank.com/challenges/queens-attack-2/problem
First Idea is to grab each neighbouring tile and then move further into that direction until we hit the end or hit an obstacle (not working for huge board ~100k)
Second Idea is insteading of going through each neighbour imagine 4 lines passing through the queen in each direction (l -> r , t -> b , left diag, right diag)
generalizing l -> r and t -> b is easy
need to find a way to generalize left and right diag
*/

int main()
{
    int n, k, yQ, xQ, count = 0, obs = 0;
    scanf("%d %d", &n, &k);
    scanf("%d %d", &yQ, &xQ);

    int ep[8][3] = {0};

    int sum = yQ + xQ;
    //for left diagonal
    if (sum - 1 <= n)
    {
        ep[0][0] = 1;
        ep[0][1] = sum - 1;

        ep[1][0] = sum - 1;
        ep[1][1] = 1;
    }
    else
    {
        ep[0][0] = sum - n;
        ep[0][1] = n;

        ep[1][0] = n;
        ep[1][1] = sum - n;
    }

    //horizontal
    ep[2][0] = 1;
    ep[2][1] = yQ;

    ep[3][0] = n;
    ep[3][1] = yQ;

    int diff = xQ - yQ;

    //for left-end of right diagonal
    if (1 - diff > 0)
    {
        ep[4][0] = 1;
        ep[4][1] = 1 - diff;
    }
    else
    {
        ep[4][0] = diff + 1;
        ep[4][1] = 1;
    }

    //for right-end of right diagonal
    if (diff >= 0)
    {
        ep[5][0] = n;
        ep[5][1] = n - diff;
    }
    else
    {
        ep[5][0] = diff + n;
        ep[5][1] = n;
    }

    //vertical
    ep[6][0] = xQ;
    ep[6][1] = n;

    ep[7][0] = xQ;
    ep[7][1] = 1;

    while (k)
    {
        int x, y, change = -1;
        scanf("%d %d", &y, &x);

        if (x + y == sum)
        {
            //left diagonal
            if (x < xQ && x > ep[0][0])
                change = 0;
            else if (x > xQ && x < ep[1][0])
                change = 1;
        }
        else if (x - y == diff)
        {
            //right diagonal
            if (x < xQ && x > ep[4][0])
                change = 4;
            else if (x > xQ && x < ep[5][0])
                change = 5;
        }
        else if (y == yQ)
        {
            if (x < xQ && x > ep[2][0])
                change = 2;
            else if (x > xQ && x < ep[3][0])
                change = 3;
        }
        else if (x == xQ)
        {
            if (y > yQ && y < ep[6][1])
                change = 6;
            else if (y < yQ && y > ep[7][1])
                change = 7;
        }

        if (change >= 0)
        {
            ep[change][0] = x;
            ep[change][1] = y;
            ep[change][2] = 1;
        }

        k--;
    }

    count += ep[0][1] - ep[1][1]; //left diag
    count += ep[3][0] - ep[2][0]; //horizontal
    count += ep[5][1] - ep[4][1]; //right diag
    count += ep[6][1] - ep[7][1]; //vertical

    for (int i = 0; i < 8; i++)
        if (ep[i][2] == 1)
            obs++;

    printf("%d", count - obs);
}
