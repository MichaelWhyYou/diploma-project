#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

pair<double, double> linear_regression(vector<double> x, vector<double> y) {
    int n = x.size();
    double sum_x = 0.0, sum_y = 0.0, sum_xy = 0.0, sum_x2 = 0.0;
    for (int i = 0; i < n; i++) {
        sum_x += x[i];
        sum_y += y[i];
        sum_xy += x[i] * y[i];
        sum_x2 += x[i] * x[i];
    }
    double slope = (n * sum_xy - sum_x * sum_y) / (n * sum_x2 - sum_x * sum_x);
    double intercept = (sum_y - slope * sum_x) / n;
    return make_pair(slope, intercept);
}

int main() {
    std::ifstream inFile("linear_regression_data.txt");

    if (!inFile.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        return 1;
    }

    std::vector<double> x, y;

    // Pre-allocate memory for vectors
    const int numValues = 10000000;
    x.reserve(numValues);
    y.reserve(numValues);

    double val;

    // Read values from first row into x vector
    for (int i = 0; i < numValues; i++) {
        inFile >> val;
        x.push_back(val);
    }

    // Read values from second row into y vector
    for (int i = 0; i < numValues; i++) {
        inFile >> val;
        y.push_back(val);
    }

    inFile.close();

    pair<double, double> result = linear_regression(x, y);
    cout << "Slope: " << result.first << endl;
    cout << "Intercept: " << result.second << endl;
    return 0;
}
