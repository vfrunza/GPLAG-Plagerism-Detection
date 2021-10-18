#include <iostream>
#include <functional>

int Kvadrat(int x) {return x*x;}

std::function<int(int)> IteriranaFunkcija (std::function<int(int)> f, int n)
{
	return [f,n](int x){if(n<=0) return x; for(int i(0);i<n;i++) x=f(x); return x;};
}

int main ()
{
	std::cout<<IteriranaFunkcija(Kvadrat,-5)(4);
	return 0;
}