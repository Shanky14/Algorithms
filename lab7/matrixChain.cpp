#include <iostream>
#include <vector>
#include <algorithm>
#include<chrono>
#define INF 999999
using namespace std;
using namespace std::chrono;
void printParenthesis(int i,int j,int s[10][10])
{
    if (i==j)
    {
        cout<<"A"<<i;
    }
    else
    {
        cout<<"(";
        printParenthesis(i,s[i][j],s);
        printParenthesis(s[i][j]+1,j,s);
        cout<<")";
    }
    
}
void MCM(int n, int p[])
{
    int m[10][10];
    int s[10][10];
    int i,j;

    for (int i = 0; i < n; i++)
    {
        m[i][i]=0;
    }
    
    for (int l = 2; l < n; l++)
    {
        for ( i = 1; i < n - l + 1; i++)
        {
             j = i + l - 1;
            m[i][j] = INF;
            for (int k = i; k < j; k++)
            {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
    cout<<"Minimum number of multiplications: "<<m[1][n-1];   

    cout<<"\nparenthesis: ";
    printParenthesis(1,n-1,s);
    cout<<endl;
}

int main()
{
    int p[]={5,10,6,8,5,15};
    int n=sizeof(p)/sizeof(p[0]);

    MCM(n,p);

    return 0;
}