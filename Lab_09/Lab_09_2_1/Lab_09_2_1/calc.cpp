// файл реалізації – обчислення значення w

#include "Lab_09_2_1.h"

double calc_w(double x, double y)
{
#if IS_IN_RANGE(Z) // якщо 0 < Z < 5
	return MAX(SQR(x) + y + Z, x * y * Z);
#else              // якщо Z <= 0 або Z >= 5
	return MIN(SQR(x) + SQR(y + Z), x * y);
#endif
}