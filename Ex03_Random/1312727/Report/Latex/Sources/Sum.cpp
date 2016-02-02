using namespace std;

int SomeSum(int n, int& Assign, int& Comparision)
{
    Assign = Comparision = 0;
    int sum = 0, i = 1;         Assign += 2;
    int j;
    while (++Comparision && i <= n)
    {
        j = n - i;              ++Assign;
        while (++Comparision && j <= i*i)
        {
            sum = sum + i*j;    ++Assign;
            j = j + 1;          ++Assign;    
        }
        i = i + 1;              ++Assign;
    }

    return sum;
}