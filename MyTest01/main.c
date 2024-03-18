#include <stdio.h>
#include <complex.h>
#include <stdlib.h>

#ifdef _MSVC_
typedef _Dcomplex double_complex;
#define CBuild _Cbuild
#else
typedef double complex double_complex;
#define CBuild CMPLX
#endif

double_complex *Add_Complex(double_complex* a, int num);

int main()
{
	double_complex first = CBuild(3.12, -2.29);
	double_complex second = CBuild(-8.12, -9.99);
	double_complex third = CBuild(9.12, 19.99);

	double_complex items[3];

	items[0] = first;
	items[1] = second;
	items[2] = third;

	double_complex* results;

	results = Add_Complex(items, 3);
	
	printf("Total sum is %.2lf + %.2lf i", creal(*results), cimag(*results) );

	free(results);
}

double_complex *Add_Complex(double_complex* a, int num)
{
	double real_part = 0.;
	double imag_part = 0.0;
	for (int idx = 0; idx < num; idx++)
	{
		real_part += creal(a[idx]);
		imag_part += cimag(a[idx]);

	}

	double_complex *result = (double_complex *) malloc(sizeof(double_complex));

	*result = CBuild(real_part, imag_part);

	return result;
}