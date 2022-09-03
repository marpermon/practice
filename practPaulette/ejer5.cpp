#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int random()
{   srand(time(0));
    int x=0;
    int A[200];
    for (int i = 0; i <200; i++)
    {A[i]= 1+rand()%500;
    if (50 <=A[i]<=450) {
           // cout << A[i] <<"+";
            x+=A[i];
    }}

     return x;
}

int main()
{

    cout << random() << endl;
    return 0;
}
