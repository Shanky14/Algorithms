#include <iostream>
#include <vector>
#include <string>

using namespace std;
vector<vector<int>> c;
vector<vector<char>> p;
void LCS(string X, string Y)
{
    int m = X.size();
    int n = Y.size();

    c.resize(m + 1, vector<int>(n + 1));
    p.resize(m + 1, vector<char>(n + 1));
    c[0][0]=0;

    for (int i = 1; i <= m; i++)
    {
        c[i][0] = 0;
    }
    for (int j = 1; j <= n; j++)
    {
        c[0][j] = 0;
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (X[i-1] == Y[j-1])
            {
                c[i][j] = 1 + c[i - 1][j - 1];
                p[i][j] = 'D';
            }
            else if (c[i - 1][j] >= c[i][j - 1])
            {
                c[i][j] = max(c[i - 1][j], c[i][j - 1]);
                p[i][j]='U';
            }
            else{
                c[i][j]=c[i][j-1];
                p[i][j]='L';
            }
        }
    }
}
void write(string X, int i, int j)
{
     if (i == 0 || j == 0)
        return;

    if (p[i][j] == 'D')
    {
        write(X, i - 1, j - 1);
        cout << X[i - 1] << " ";
    }
    else if (p[i][j] == 'U')
    {
        write(X, i - 1, j);
    }
    else
    {
        write(X, i, j - 1);
    }  
}

int main()
{
    string X, Y;

    cout << "Enter first string: ";
    cin >> X;

    cout << "Enter second string: ";
    cin >> Y;

    LCS(X, Y);

    cout << "\nLength of LCS: " << c[X.length()][Y.length()] << endl;

    cout << "LCS: ";
    write(X, X.length(), Y.length());
    cout << endl;

    return 0;
}