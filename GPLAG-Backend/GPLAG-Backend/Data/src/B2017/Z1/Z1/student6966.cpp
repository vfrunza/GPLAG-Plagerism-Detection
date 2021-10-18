#include <iostream>
#include <vector>
#include <cmath>

int DaLiJeBrojPalindroman(int numer) {
	int numero, c,a;
	int d(0), s(0);
	a = numero;
	while (numero!= 0) {
		c=abs(numero)% 10;
		s=d*10 + c;
		d=s;
		numero/= 10;
	}
	if(a==d) return 0;
	else return 1;
}
int DaLiJeBrojProst(int brojcic_1) {
	if (brojcic_1 <= 1) return false;
	for(int k(2); k < sqrt(brojcic_1); k++) {
		if(brojcic_1 % k == 0) return false;
	}
	return true;
}
std::vector<int>TernarniSistemPretvaranje(int brojcic_2) {
	std::vector<int> c;
	do{
		int x = brojcic_2 % 3;
		c.push_back(x);
		brojcic_2 /= 3;
	}	while(brojcic_2 != 0);
	return c;
}
std::vector<int> IzdvojiSimetricneTernarne(std::vector<int>W, bool blblbl) {
	std::vector<int> vektorcic;
	for(int i:W) {
		bool p;
		p = DaLiJeBrojPalindroman(vektorcic);
		if(blblbl) return p;
	
	}
}

int main ()
{
	return 0;
}