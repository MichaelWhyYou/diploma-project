const fs = require('fs');

function linearRegression(x, y) {
    let n = x.length;
    let sum_x = 0;
    let sum_y = 0;
    let sum_xy = 0;
    let sum_x2 = 0;

    for (var i = 0; i < n; i++) {
        sum_x += x[i];
        sum_y += y[i];
        sum_xy += x[i] * y[i];
        sum_x2 += x[i] * x[i];
    }

    let slope = (n * sum_xy - sum_x * sum_y) / (n * sum_x2 - sum_x * sum_x);
    let intercept = (sum_y - slope * sum_x) / n;

    return [slope, intercept];
}
  
fs.readFile('linear_regression_data.txt', 'utf8', (err, data) => {
    if (err) {
    console.error('Error opening file');
    return;
    }
    const lines = data.trim().split('\n');
    const x = lines[0].split(' ').map(parseFloat);
    const y = lines[1].split(' ').map(parseFloat);
    var result = linearRegression(x, y);
    
    console.log("Slope: " + result[0]);
    console.log("Intercept: " + result[1]);
});
  