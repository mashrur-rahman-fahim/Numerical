#include<bits/stdc++.h>
using namespace std;
void linearRegression(vector<double>x,vector<double>y)
{
    double sumX=0,sumX2=0,sumY=0,sumXY=0;
    for(int i=0;i<x.size();i++)
    {
        sumX+=x[i];
        sumX2+=x[i]*x[i];
        sumY+=y[i];
        sumXY+=x[i]*y[i];
    }
    double b=(x.size()*sumXY - sumX*sumY)/(x.size()*sumX2-sumX*sumX);
    double a=(sumY-b*sumX)/(double)x.size();
    cout<<"The linear regression line is y = "<<a<<" + "<<b<<"x"<<endl;
    
}
void curveFitting(vector<double>x,vector<double>y)
{
    double sumX=0,sumX2=0,sumY=0,sumXY=0;
    for(int i=0;i<x.size();i++)
    {
        double logX = log(x[i]);
        double logY = log(y[i]);
        

        sumX += x[i];
        sumX2 += (x[i]*x[i]);
        sumY += logY;
        sumXY += (x[i] * logY);
    }
    
  int n = x.size();
    double c = ((n * sumXY) -( sumX * sumY)) / ((n * sumX2) - (sumX * sumX));
    double a = (sumY - c * sumX) /(double) n;
    double b=exp(c);
     a=exp(a);
    cout<<(a*(pow(b,2))); 
}
void langrange_dada(vector<double>x,vector<double>y,double xp)
{
    double yp=0;
    for(int i=0;i<x.size();i++)
    {
        double p=1;
        for(int j=0;j<x.size();j++)
        {
            if(j!=i)
                p*=(xp-x[j])/(x[i]-x[j]);
    }
    yp+=p*y[i];
    }
    cout<<"The value at x = "<<xp<<" is "<<yp<<endl;
        

}

void newton_kaka(vector<double>x,vector<double>y,double xp)
{
    vector<vector<double>>y1(x.size(),vector<double>(x.size(),0.0));
    y1[0]=y;
    for(int i=1;i<x.size();i++)
    {
        int k=i;
        for(int j=0;j<x.size()-i;j++)
        {    
            y1[i][j]=(y1[i-1][j+1]-y1[i-1][j])/(x[k]-x[j]);
            k++;
        }
    }
    double yp=y1[0][0];
    for(int i=1;i<x.size();i++)
    {
        double prdct_x=1;
        for(int j=0;j<i;j++)
        {
            prdct_x*=(xp-x[j]);
        }
        double val=y1[i][0];
        yp+=val*prdct_x;
    }
    cout<<"The value at x = "<<xp<<" is "<<yp<<endl;


}
vector<double> gaussianElimination(vector<vector<double>>& A, vector<double>& b, int degree) {
    int n = degree + 1;

    for (int i = 0; i < n; i++) {
        double maxVal = abs(A[i][i]);
        int maxRow = i;
        for (int k = i + 1; k < n; k++) {
            if (abs(A[k][i]) > maxVal) {
                maxVal = abs(A[k][i]);
                maxRow = k;
            }
        }

        swap(A[i], A[maxRow]);
        swap(b[i], b[maxRow]);

        for (int k = i + 1; k < n; k++) {
            double c = -A[k][i] / A[i][i];
            for (int j = i; j < n; j++) {
                if (i == j) {
                    A[k][j] = 0;
                } else {
                    A[k][j] += c * A[i][j];
                }
            }
            b[k] += c * b[i];
        }
    }

   
    vector<double> x(n);
    for (int i = n - 1; i >= 0; i--) {
        x[i] = b[i] / A[i][i];
        for (int k = i - 1; k >= 0; k--) {
            b[k] -= A[k][i] * x[i];
        }
    }

    return x;
}

void poly(vector<double>x,vector<double>y,int degree)
{
    int n=x.size();
    vector<double> sum_x(2 * degree + 1, 0.0);
    vector<double> sum_y(degree + 1, 0.0);

    for (int i = 0; i < 2 * degree + 1; i++) {
        for (int j = 0; j < n; j++) {
            sum_x[i] += pow(x[j], i);
        }
    }

    for (int i = 0; i < degree + 1; i++) {
        for (int j = 0; j < n; j++) {
            sum_y[i] += pow(x[j], i) * y[j];
        }
    }

    vector<vector<double>> A(degree + 1, vector<double>(degree + 1, 0.0));
    vector<double> b(degree + 1, 0.0);

    for (int i = 0; i <= degree; i++) {
        for (int j = 0; j <= degree; j++) {
            A[i][j] = sum_x[i + j];
        }
        b[i] = sum_y[i];
    }

    vector<double> coefficients = gaussianElimination(A, b, degree);

    for (int i = 0; i <= degree; i++) {
        cout << "Coeff a" << i << " = " << coefficients[i] << endl;
    }
    // a0=3
    // a1=2
    // a2=4
    // that means 3+2*x+4*x^2
    
   

}

void mse(vector<double>y,vector<double>y_hat){
    double mse=0;
    for(int i=0;i<y.size();i++)
    {
        mse+=(y[i]-y_hat[i])*(y[i]-y_hat[i]);
    }
    mse=mse/y.size();
    cout<<"Mean Squared Error: "<<mse<<endl;
 
}
int main()
{
    int n;
    cin>>n;
    vector<double>x,y;
    for(int i=0;i<n;i++)
    {
        double a,b;
        cin>>a>>b;
        x.push_back(a);
        y.push_back(b);
    }
//    linearRegression(x,y);
//    curveFitting(x,y);
//    cout<<endl;
//    double xp;
//    cin>>xp;
//    langrange_dada(x,y,xp);
//    newton_kaka(x,y,xp);
//    int deg;
//    cin>>deg;
//    poly(x,y,deg);
   

    


    
}