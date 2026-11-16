// заголовний файл – макровизначення та оголошення функції

#pragma once

#define Z 3 // константа для умовної компіляції

// макроси математичних та логічних операцій
#define SQR(x) ((x) * (x))
#define ABS(x) (((x) < 0) ? -(x) : (x))
#define MAX(y, z) (((y) > (z)) ? (y) : (z))
#define MIN(y, z) (((y) < (z)) ? (y) : (z))
#define IS_IN_RANGE(z) (((z) > 0) && ((z) < 5))

// макрос виведення результату
#define PRINTR(w) cout << "Result: " << #w << " = " << (w) << endl

double calc_w(double x, double y);