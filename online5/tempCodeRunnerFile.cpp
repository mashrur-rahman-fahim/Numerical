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
    double sumX=0,sumX2=0,sumY=0,sumXY=0;
    for(int i=0;i<n;i++)
    {
        sumX+=x[i];
        sumX2+=x[i]*x[i];
        sumY+=y[i];
        sumXY+=x[i]*y[i];
    }
    double b=(n*sumXY - sumX*sumY)/(n*sumX2-sumX*sumX);
    double a=(sumY-b*sumX)/(double)n;
    cout<<"The linear regression line is y = "<<a<<" + "<<b<<"x"<<endl;
    


    
}