#include<bits/stdc++.h>
using namespace std;
double f(double x)
{
    return ((x+(5/x))/2.0);
}
int main()
{
    double n, x0,x1;
    cin >> n >> x0;
    vector<double> a;
    for (int i = 0; i <= n; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }
  
    while(1)
    {
        x1=f(x0);
        if(fabs(x0-x1)/x1<0.0005)
        break;
        x0=x1;
        
    }
    cout<<x1;
}