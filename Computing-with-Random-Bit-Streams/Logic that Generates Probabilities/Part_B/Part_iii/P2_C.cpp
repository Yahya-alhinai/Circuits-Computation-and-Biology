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

    if (abs(x - 0.5) < 0.000000001 || abs(x - 0.4) < 0.000000001)
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
    solve(0.5078125, i); // 0.1000001 --> 0.5078125

    return 0;
}
