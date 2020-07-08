#include <iostream>
#include <string>
#include <unistd.h>
#include <stdio.h>
#include <cmath>

using namespace std;

double NCK(unsigned n, unsigned k)
{
    if (k > n)
        return 0;
    if (k * 2 > n)
        k = n - k;
    if (k == 0)
        return 1;

    int result = n;
    for (int i = 2; i <= k; ++i)
    {
        result *= (n - i + 1);
        result /= i;
    }
    return result;
}

int main()
{
    //1/5 (1 − 0.1t + 0.2t 2 − 0.3t 3 + 0.4t 4 − 0.5t)
    double A[6] = {1.0 / 5, -0.1 / 5, 0.2 / 5, -0.3 / 5, 0.4 / 5, -0.5 / 5};
    int n = 5;
    double sum = 0;
    string S = "";
    char result[100];

    for (int j = 0; j <= n; j++)
    {
        sum = 0;
        S = "";
        for (int i = 0; i <= j; i++)
        {
            sum += (NCK(j, i) / NCK(n, i)) * A[i];
            sprintf(result, "[(%dC%d)/(%dC%d) * %.3f]", j, i, n, i, A[i]);
            S += result;
            S += (1+i <= j)? "+":"";
        }
        cout << "[" << j << "] = " << sum << " = " << S << endl;
    }

    return 0;
}