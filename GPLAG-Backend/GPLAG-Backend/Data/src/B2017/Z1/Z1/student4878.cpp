#include <iostream>
#include <vector>

using namespace std; 

int TernarniZapis(int a) 
{
	int ostatak, broj=0, x=1;
	while(a!=0) {
		ostatak=a%3;
		broj=ostatak*x + broj;
		a/=3;
		x*=10;
	}
	return broj;
}
bool Simetricnost(int a) 
{
	int ostatak, broj=0, a1=a;
	while(a!=0) {
		ostatak=a%10;
		broj=broj*10 + ostatak;
		a/=10;
	}
	if(broj==a1) return true;
	else return false;
}
int main ()
{
	cout<<TernarniZapis(727);
	if(Simetricnost(101)==true) cout<<"jest"; else cout<<"nije";
	return 0;
}