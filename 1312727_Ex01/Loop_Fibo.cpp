#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <ctime>
#include <utility>

using namespace std;

//fibonacci đệ quy
int fib(int n, int& C, int &A)
{
    
    if (++C && n <= 1)
        return 1;
    return fib(n-1, C, A)+fib(n-2,C,A);
}

//fibonacci không đệ quy
int fibonacci(int n, int& C, int& A)
{
    C = 0; 
    A = 0;

    
    if (++C && n <= 1) //1 ss
        return 1;

    int last = 1;           ++A;
    int nextToLast = 1;     ++A;
    int answer = 1;         ++A;

     ++A;  //gán i = 2 lúc bắt đầu vòng lặp
    for(int i = 2 ; ++C && i <= n; ++i, ++A) //so sánh i <= n mỗi khi tăng i, ++i tương đương với i = i+1 nên tính là 1 phép gán
    {
        answer = last + nextToLast;     ++A;
        nextToLast = last;              ++A;
        last = answer;                  ++A;
    }
    
    return answer;
}

void latex1(int n = 15)
{
    freopen("e:/output_algo.txt","w", stdout);
    vector<int> a;
    a.resize(n);
    for(int i = 0; i < a.size(); ++i)
        {
            a[i] = i;
        }
    cout << "\\begin{tabular}{c|c c c}" << endl;
    cout << "Input & \\multicolumn{2}{c}{Output}\\\\" << endl;
    cout << "Fib(n) & So sánh & Gán\\\\" << endl;
    cout << "\\hline"<<endl;
    for(int i = 0; i < a.size(); ++i)
        {
            int C, A;
            C = A = 0;
            int t = fibonacci(a[i], C, A);
            cout << a[i] << " & " << t << " & " << C << " & " << A << "\\\\" << endl;
           //cout << "\\hline" << endl;
        }
    cout << "\\end{tabular}"<<endl;
}

void latex2(int n = 15)
{
    freopen("e:/output_re_algo.txt", "w", stdout);
    vector<int> a;
    a.resize(n);
     cout << "\\begin{tabular}{c|c c c}" << endl;
    cout << "Input & \\multicolumn{2}{c}{Output}\\\\" << endl;
    cout << "Fib(n) & So sánh & Gán\\\\" << endl;
    cout << "\\hline"<<endl;

    for(int i = 0; i < a.size(); ++i)
        {
            int C, A;
            C = A = 0;
            a[i] = i;
            int t = fib(a[i], C, A);
            cout << a[i] << " & " << t << " & " << C << " & " << A << "\\\\" << endl;
           //cout << "\\hline" << endl;
        }
    cout << "\\end{tabular}"<<endl;
}
int main()
{
    latex1(15);
    latex2(15);
        srand(time(0));
    int A, C;
    int n = 15;
    int lo[111],re[111];
    re[0] = re[1]  = 1;
    for(int i = 2; i <= n; ++i)
        re[i] = re[i-1] + re[i-1] + 1;
    for(int i = 0; i <= n; ++i)
        lo[i] = i*4;

    freopen("lo.txt", "w", stdout);
    for(int i = 0; i <= n; ++i)
        cout << i << ' ' << lo[i] <<endl;
    freopen("re.txt", "w", stdout);    
      for(int i = 0; i <= n; ++i)
        cout << i << ' ' << re[i] <<endl;
    

    
    //cout << C << ' ' << A << endl;

    

    return 0;
}