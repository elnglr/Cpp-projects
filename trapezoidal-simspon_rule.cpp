#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/* 
Trapezoidal kural�nda istedi�imiz n say�s�nda alt alana (strip=�erit) b�l�yoruz. 
n ne kadar b�y�kse analitik(ger�ek) integral sonucuna o kadar yakla��yoruz

Yamu�un alan� = y�kseklik * iki kenar toplam� / 2
*/

// fonksiyon �n tan�mlamalar�
double Trapezoidal(double (*f)(double), double a, double b, int n);
double Simpson(double (*f)(double), double a, double b, int n);
double Simpson2(double (*f)(double), double a, double b, int n);
double function(double);

int main()
{
	double (*f)(double);  // pointer ile fonksiyon parametresi olarak 
	f = function;         // fonksiyon i�aret edebiliyoruz
	
	double lower_bound, upper_bound;
	int i, strips;
	
	printf("enter lower limit");
	scanf("%lf", &lower_bound);
	printf("enter upper limit");
	scanf("%lf", &upper_bound);
	printf("enter number of strips"); // ka� b�lgeye b�leceksin?
	scanf("%d", &strips);
	
	printf("Trapezoidal solution is x=%.4lf for n=%d\n", Trapezoidal(f, lower_bound, upper_bound, strips), strips);
	printf("\nSimpson solution is x=%.4lf for n=%d\n", Simpson(f, lower_bound, upper_bound, strips), strips);
	printf("\nSimpson solution is x=%.4lf for n=%d\n", Simpson2(f, lower_bound, upper_bound, strips), strips);

	
	return 0;
}
                                /*alt ve �st aral�k - strip say�s�*/										
double Trapezoidal(double (*f)(double), double a, double b, int n)  
{
	int i;
	double x_i_0, x_i_1, h, sum = 0;
	
	h = (b-a)/n; // her yamu�un y�ksekli�inin ayn� oldu�u senaryoda h total aral���n aral�k say�s�na b�l�m� ile bulunur.
	x_i_0 = a; // ilk olarak alt aral��� girilen alt s�n�ra e�itliyoruz
	
	for(i=0; i<n; i++)
	{
		x_i_1 = x_i_0 + h; // yamu�un �st s�n�r�n� belirliyoruz
		sum += (f(x_i_1) + f(x_i_0)) * h / 2;  // yamuk alanlar�n�n k�m�latif toplam�
		x_i_0 = x_i_1; // her ad�mda yamu�un alt s�n�r�n� bir sa�a kayd�r�yoruz
	}
	return sum;
}

double Simpson(double (*f)(double), double a, double b, int n)
{
	int i;
	double xposn, h, even_sum = 0, odd_sum=0, area;
	h = (b-a)/n;
	
	// tek strip i�in
	for (i = 1; i<n; i+=2)
	{
		xposn = a + (i*h);
		odd_sum = odd_sum + f(xposn);
	}
	
	// �ift strip i�in
	for (i=2; i<n; i+=2)
	{
		xposn = a + (i*h);
		even_sum = even_sum + f(xposn);
	}
	
	area = (0.3333) * h * ((f(a) + f(b)) + 4*odd_sum + 2*even_sum);
	
	return area;
}

double Simpson2(double (*f)(double), double a, double b, int n)
{
	int i;
	double xposn, h, even_sum = 0, odd_sum=0, area;
	h = (b-a)/n;
	
	// tek strip i�in
	for (i = 1; i<n; i+=2)
	{
		xposn = a + (i*h);
		odd_sum = odd_sum + f(xposn);
	}
	
	// �ift strip i�in
	for (i=2; i<n; i+=2)
	{
		xposn = a + (i*h);
		even_sum = even_sum + f(xposn);
	}
	
	area = (0.375) * h * ((f(a) + f(b)) + 3*odd_sum + 3*even_sum);
	
	return area;
}

// istedi�in fonksiyonu burada belirleyebilirsin  
double function(double x)
{
	//double sinus = sin(x);
	
	return sqrt(4 + pow(x, 2)); 
}
