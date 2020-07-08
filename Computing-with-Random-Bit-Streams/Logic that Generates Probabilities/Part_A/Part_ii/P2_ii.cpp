#include <iostream>
#include <iomanip>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <cmath>

using namespace std;

int i = 0;
string S = "";
char result[100];

void solve(long double x, int i)
{
    if (i > 32)
        return;

    if (abs(x - 0.5) < 0.00000001 || abs(x - 0.4) < 0.00000001)
    {
        sprintf(result, "%1.10Lf", x);
        S += result;
        cout << "[" << i << "] = " << S << endl
             << endl;
        return;
    }

    if (x > 0.5)
    {
        sprintf(result, "%1.10Lf (-1) ", x);
        S += result;
        solve(1 - x, ++i);
        return;
    }

    if (x <= 0.4)
    {
        if (fork() == 0)
        {
            sprintf(result, "%1.10Lf (0.5) ", x);
            S += result;
            solve(x * 2, ++i);
            return;
        }
        else
        {
            sprintf(result, "%1.10Lf (0.4) ", x);
            S += result;
            solve(x * 2.5, ++i);
            return;
        }
    }
    else
    {
        sprintf(result, "%1.10Lf (0.5) ", x);
        S += result;
        solve(x * 2, ++i);
    }

    return;
}

int main()
{
    solve(0.876543219, i);

    return 0;
}
