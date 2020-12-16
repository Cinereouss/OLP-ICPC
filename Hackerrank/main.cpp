#include <iostream>

using namespace std;

int main()
{
    long int T, N;
        while(cin >> N)
        {
            long int lim3 = N - N%3;
            long int lim5 = N - N%5;
            long int lim15 = N - N%15;

            long int dem3 = (lim3 - 3)/3 + 1;
            long int dem5 = (lim5 - 0)/5 + 1;
            long int dem15 = (lim15 - 15)/15 + 1;

            long int sum3 = ((lim3 + 3)*dem3)/2;
            long int sum5 = ((lim5 + 0)*dem5)/2;
            long int sum15 = ((lim15 + 15)*dem15)/2;

            long int print = sum3+sum5-2*sum15;
            cout << print;
        }
    return 0;
}

