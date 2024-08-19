#include<bits/stdc++.h>

double calculateLinearRegression(int n, const std::vector<double>& x, const std::vector<double>& y) {
    double sumX = 0, sumX2 = 0, sumY = 0, sumXY = 0;
    for (int i = 0; i < n; i++) {
        sumX += x[i];
        sumX2 += x[i] * x[i];
        sumY += y[i];
        sumXY += x[i] * y[i];
    }
    double b = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);
    double a = (sumY - b * sumX) / (double)n;
    return a + b * x[0];  // Return the y value for the first x value
}

TEST(LinearRegressionTest, PositiveAndNegativeValues) {
    int n = 5;
    std::vector<double> x = {-2, -1, 0, 1, 2};
    std::vector<double> y = {-3, -1, 1, 3, 5};
    double expectedY = 0.9;  // Expected y value for x = 0
    double calculatedY = calculateLinearRegression(n, x, y);
    EXPECT_NEAR(expectedY, calculatedY, 0.001);
}