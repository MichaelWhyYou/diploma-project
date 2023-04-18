#include <stdio.h>
#include <stdlib.h>

struct Pair {
    double first;
    double second;
};

struct Pair linear_regression(double *x, double *y, int n) {
    double sum_x = 0.0, sum_y = 0.0, sum_xy = 0.0, sum_x2 = 0.0;
    for (int i = 0; i < n; i++) {
        sum_x += x[i];
        sum_y += y[i];
        sum_xy += x[i] * y[i];
        sum_x2 += x[i] * x[i];
    }
    double slope = (n * sum_xy - sum_x * sum_y) / (n * sum_x2 - sum_x * sum_x);
    double intercept = (sum_y - slope * sum_x) / n;
    struct Pair result = { slope, intercept };
    return result;
}

int main() {
    FILE *inFile = fopen("linear_regression_data.txt", "r");

    if (!inFile) {
        fprintf(stderr, "Error opening file\n");
        return 1;
    }

    const int numValues = 10000000;
    double *x = (double *)malloc(numValues * sizeof(double));
    double *y = (double *)malloc(numValues * sizeof(double));

    double val;

    // Read values from first row into x array
    for (int i = 0; i < numValues; i++) {
        fscanf(inFile, "%lf", &val);
        x[i] = val;
    }

    // Read values from second row into y array
    for (int i = 0; i < numValues; i++) {
        fscanf(inFile, "%lf", &val);
        y[i] = val;
    }

    fclose(inFile);

    struct Pair result = linear_regression(x, y, numValues);
    printf("Slope: %lf\n", result.first);
    printf("Intercept: %lf\n", result.second);

    free(x);
    free(y);

    return 0;
}
