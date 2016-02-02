#include <bits/stdc++.h>

using namespace std;

int SomeSum(int n, int& Assign, int& Comparision)
{
    Assign = Comparision = 0;
    int sum = 0, i = 1;         Assign += 2;
    int j;
    int cc = 0;
    while (++Comparision && i <= n)
    {
        j = n - i;              ++Assign;
        while (++Comparision && j <= i*i)
        {
            //++cc;
            sum = sum + i*j;    ++Assign;
            j = j + 1;          ++Assign;    
        }
        i = i + 1;              ++Assign;
    }
   // cout << cc << endl;
    return sum;
}
int main(int argc, char const *argv[])
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    //
    
    int A, C;
    for(int i = 1; i <= 500; ++i)
    {
        int sum = SomeSum(i, A, C);
        cout << i  << '\t' << A << '\t' << C << endl;
    }
    cout << C << endl;
    /* code */
    
    return 0;
}