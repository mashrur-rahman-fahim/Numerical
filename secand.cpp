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

int main()
{
    double n, x1, x2,x3;
    cin >> n >> x1>>x2;
    vector<double> a;
    for (int i = 0; i <= n; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }
    while(a.size()-1){
    while (1)
    {
        double f1=f(a,x1),f2=f(a,x2);
        x3=(f2*x1-f1*x2)/(f2-f1);
        if(fabs(x3-x2)/x3<0.0005)
        break;
        x1=x2;
        x2=x3;
    }
    cout<<x3<<" ";
    vector<double>temp;
    temp.push_back(a[0]);
    for(int i=1;i<a.size()-1;i++)
    {
        double t=temp.back()*x3+a[i];
        temp.push_back(t);
    }
    a.clear();
    a=temp;

    }
}
