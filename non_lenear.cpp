#include <bits/stdc++.h>
using namespace std;
void gauss_el(vector<vector<double>> &coff, vector<double> &sol)
{
    int n = coff.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            double mul = coff[j][i] / coff[i][i];
            for (int k = i; k <= n; k++)
            {
                coff[j][k] = coff[j][k] - mul * coff[i][k];
            }
        }
    }
    sol[n - 1] = coff[n - 1][n] / coff[n - 1][n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        double sum = 0;
        for (int j = i + 1; j < n; j++)
        {
            sum = sum + coff[i][j] * sol[j];
        }
        sol[i] = (1 / coff[i][i]) * (coff[i][n] - sum);
    }
}
void gauss_jord(vector<vector<double>> &coff, vector<double> &sol)
{
    int n = coff.size();
    for(int i=0;i<n;i++)
    {
        if(coff[i][i]==0)
        {
            cout<<"amr jibon er moto...shomossha solve hbe na";
            break;
        }
        for(int j=0;j<n;j++)
        {
            if(i!=j)
            {
                double mul=coff[j][i]/coff[i][i];
                for(int k=0;k<n+1;k++)
                {
                    coff[j][k]=coff[j][k]-mul*coff[i][k];
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            sol[i]=coff[i][n]/coff[i][i];
        }
    }
  
}
void seidel(vector<vector<double>>&coff,vector<double>&sol)
{
     int n=coff.size();
    double all_err=0.00000001;
    for(int i=0;i<n;i++)
    sol[i]=0;
   
     double temp_err=0;
    do{
       temp_err=0;
        for(int i=0;i<n;i++)
        {
            double sum=0;
            for(int j=0;j<n;j++)
            {
                
                if(i!=j)
                {
                    sum=sum+coff[i][j]*sol[j];

                }
            }
            double temp=(1/coff[i][i])*(coff[i][n]-sum);
            double err=fabs(sol[i]-temp);
            if(err>temp_err)
            {
                temp_err=err;
            }
            sol[i]=temp;
            
        } 



    }while(temp_err>=all_err);
}
void jacobi(vector<vector<double>>&coff,vector<double>&sol)
{
    int n=coff.size();
    for(int i=0;i<n;i++)
    sol[i]=0;
    double all_err=0.00000001;
    double temp_err=0;
    do{
        temp_err=0;
        vector<double>temp(n);
            for(int i=0;i<n;i++)
            {
                double sum=0;
                for(int j=0;j<n;j++)
                {
                    if(i!=j)
                    {
                        sum=sum+coff[i][j]*sol[j];

                    }
                }
            
                 temp[i]=(1/coff[i][i])*(coff[i][n]-sum);
                double err=fabs(sol[i]-temp[i]);
                if(err>temp_err)
                temp_err=err;

            }
            for(int i=0;i<n;i++)
            sol[i]=temp[i];
    }while(temp_err>=all_err);
}
void inverse(vector<vector<double>>&coff,vector<double>&sol,vector<vector<double>>&inv)
{
    int n=coff.size();
    
    for (int i=0;i<n;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            coff[i].push_back(0);
        }
    }
   
    for(int i=n;i<2*n;i++)
    {
        for(int j=n;j<2*n;j++)
        {
            if(i==j)
            coff[i-n][j]=1;
            else
            coff[i-n][j]=0;

        }

    }
   for(int i=0;i<n;i++)
   {
    if(coff[i][i]==0)
    {
        cout<<"jibon bedona"<<endl;
        break;
    }
    for(int j=0;j<n;j++)
    {
        if(i!=j){
            double mul=coff[j][i]/coff[i][i];
            for(int k=0;k<2*n;k++)
            {
                coff[j][k]=coff[j][k]-mul*coff[i][k];
                
            }
        }
        
    }
   }
   for(int i=0;i<n;i++)
   {
    double div=coff[i][i];
    for(int j=0;j<2*n;j++)
    {
        coff[i][j]=coff[i][j]/div;
    }
   }
   for(int i=0;i<n;i++)
   {
    for(int j=n;j<2*n;j++)
    inv[i][j-n]=coff[i][j];
   }

}

void print(vector<double> &sol)
{
    for (int i = 0; i < sol.size(); i++)
    {
        cout << sol[i] << " ";
    }
}
void print1(vector<vector<double>>&inv)
{
    for (int i = 0; i < inv.size(); i++)
    {
        for (int j = 0; j < inv[i].size(); j++)
        cout<<inv[i][j]<<" ";
        cout<<endl;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<vector<double>> coff(n),inv(n,vector<double>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            double x;
            cin >> x;
            coff[i].push_back(x);
        }
    }
    vector<double> sol(n);
    gauss_el(coff, sol);
    gauss_jord(coff, sol);
    seidel(coff,sol);
    jacobi(coff,sol);

    inverse(coff,sol,inv);
    print1(inv);
    print(sol);
}
// 3
// 2 1 1 10
// 3 2 3 18
// 1 4 9 16