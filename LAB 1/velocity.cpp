#include <iostream>
using namespace std;
int findTips(double v,int tips)
{
    if (v >= 1.0)
    {
        tips++;
        v = v - (0.425 * v);
        return findTips(v,tips);
    }
    else
        return tips;
}
int main()
{
    cout << "no of tips : " << findTips(40,0) << endl;
    return 0;
}