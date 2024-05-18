#include <bits/stdc++.h>
using namespace std;
double f(vector<double> &a, double x)
{
    double res = 0;
    for (int i = 0; i < a.size(); i++)
    {
        res = res * x + a[i];
    }
    return res;
}
double df(vector<double> &a, double x)
{
    double res = 0;
    int n = a.size()-1;
    for (int i = 0; i < a.size() - 1; i++)
    {
        res = res * x + a[i] * (n - i);
    }
    return res;
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
    while(a.size()-1>0){
    while(1)
    {
       
        x1=x0-(f(a,x0)/df(a,x0));
        if((fabs(x1-x0)/x1)<0.0005)
        break;
       x0=x1;
       
    }
    cout<<x1<<" ";
    vector<double>temp;
    temp.push_back(a[0]);
    for(int i=1;i<a.size()-1;i++)
    {
        double t=temp[i-1]*x1+a[i];
        temp.push_back(t);
    }
    a.clear();
    a=temp;
    }
}