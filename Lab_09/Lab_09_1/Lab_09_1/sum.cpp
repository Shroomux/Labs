// файл реалізації функції обчислення суми ряду

#include <math.h>

#include "dod.h"
#include "sum.h"
#include "var.h"

using namespace nsDod;
using namespace nsVar;

void nsSum::sum()
{
	n = 0;
	a = 1.0 / x;
	s = a;
	do
	{
		n++;
		dod(); // виклик процедури обчислення доданку
		s += a;
	} while (fabs(a) > e);
	s *= 2;
}