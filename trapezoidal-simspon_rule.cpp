#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/* 
Trapezoidal kuralýnda istediðimiz n sayýsýnda alt alana (strip=þerit) bölüyoruz. 
n ne kadar büyükse analitik(gerçek) integral sonucuna o kadar yaklaþýyoruz

Yamuðun alaný = yükseklik * iki kenar toplamý / 2
*/

// fonksiyon ön tanýmlamalarý
double Trapezoidal(double (*f)(double), double a, double b, int n);
double Simpson(double (*f)(double), double a, double b, int n);
double Simpson2(double (*f)(double), double a, double b, int n);
double function(double);

int main()
{
	double (*f)(double);  // pointer ile fonksiyon parametresi olarak 
	f = function;         // fonksiyon iþaret edebiliyoruz
	
	double lower_bound, upper_bound;
	int i, strips;
	
	printf("enter lower limit");
	scanf("%lf", &lower_bound);
	printf("enter upper limit");
	scanf("%lf", &upper_bound);
	printf("enter number of strips"); // kaç bölgeye böleceksin?
	scanf("%d", &strips);
	
	printf("Trapezoidal solution is x=%.4lf for n=%d\n", Trapezoidal(f, lower_bound, upper_bound, strips), strips);
	printf("\nSimpson solution is x=%.4lf for n=%d\n", Simpson(f, lower_bound, upper_bound, strips), strips);
	printf("\nSimpson solution is x=%.4lf for n=%d\n", Simpson2(f, lower_bound, upper_bound, strips), strips);

	
	return 0;
}
                                /*alt ve üst aralýk - strip sayýsý*/										
double Trapezoidal(double (*f)(double), double a, double b, int n)  
{
	int i;
	double x_i_0, x_i_1, h, sum = 0;
	
	h = (b-a)/n; // her yamuðun yüksekliðinin ayný olduðu senaryoda h total aralýðýn aralýk sayýsýna bölümü ile bulunur.
	x_i_0 = a; // ilk olarak alt aralýðý girilen alt sýnýra eþitliyoruz
	
	for(i=0; i<n; i++)
	{
		x_i_1 = x_i_0 + h; // yamuðun üst sýnýrýný belirliyoruz
		sum += (f(x_i_1) + f(x_i_0)) * h / 2;  // yamuk alanlarýnýn kümülatif toplamý
		x_i_0 = x_i_1; // her adýmda yamuðun alt sýnýrýný bir saða kaydýrýyoruz
	}
	return sum;
}

double Simpson(double (*f)(double), double a, double b, int n)
{
	int i;
	double xposn, h, even_sum = 0, odd_sum=0, area;
	h = (b-a)/n;
	
	// tek strip için
	for (i = 1; i<n; i+=2)
	{
		xposn = a + (i*h);
		odd_sum = odd_sum + f(xposn);
	}
	
	// çift strip için
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
	
	// tek strip için
	for (i = 1; i<n; i+=2)
	{
		xposn = a + (i*h);
		odd_sum = odd_sum + f(xposn);
	}
	
	// çift strip için
	for (i=2; i<n; i+=2)
	{
		xposn = a + (i*h);
		even_sum = even_sum + f(xposn);
	}
	
	area = (0.375) * h * ((f(a) + f(b)) + 3*odd_sum + 3*even_sum);
	
	return area;
}

// istediðin fonksiyonu burada belirleyebilirsin  
double function(double x)
{
	//double sinus = sin(x);
	
	return sqrt(4 + pow(x, 2)); 
}
