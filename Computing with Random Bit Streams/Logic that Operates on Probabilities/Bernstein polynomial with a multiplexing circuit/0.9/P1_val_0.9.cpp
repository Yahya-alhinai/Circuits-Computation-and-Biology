#include <iostream>
#include <stdlib.h>
#include <time.h>


#define PR 9    //Probability out of 10

using namespace std;

int main()
{
    int iSecret, iGuess;
    srand(time(NULL));

    long double sum = 0;
    long int count = 0;
    int num = 0;


    int k = 6;

    while (1)
    {
        num = ((rand() % 10) < PR ? 1 : 0) 
            + ((rand() % 10) < PR ? 1 : 0)
            + ((rand() % 10) < PR ? 1 : 0)
            + ((rand() % 10) < PR ? 1 : 0)
            + ((rand() % 10) < PR ? 1 : 0);

        if (num == 0)
            sum += 0.2;
        else if (num == 1)
            sum += 0.196;
        else if (num == 2)
            sum += 0.196;
        else if (num == 3)
            sum += 0.194;
        else if (num == 4)
            sum += 0.2;
        else if (num == 5)
            sum += 0.14;

        count++;

        if (!(count % 10000000))
            cout << "[" << count/10000000 << "] = " << (long double)sum / count << endl;
    }
    return 0;
}