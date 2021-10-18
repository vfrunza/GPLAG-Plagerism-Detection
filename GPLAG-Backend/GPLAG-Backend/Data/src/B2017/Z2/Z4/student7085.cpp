/*B 2017/2018, Zadaća 2, Zadatak 4

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za
	autotestove javiti se na forum (c2).
*/
#include <iostream>
#include <vector>
#include <deque>
#include <stdexcept>
#include <cmath>
#include <algorithm>


std::vector<int> ProstiFaktori(int n)
{

	std::vector<int> rez;
	if (n == 0) {
		rez.push_back(n);
		return rez;
	}
	
	if(n == 1)
		rez.push_back(n);
	else {
		int a(n), b;
		int c(a%2);
		while(c == 0) {
			b = a/2;
			rez.push_back(2);
			a = b;
			c = a%2;
		}
		for(int i(3); i<=a; i=i+2) {
			int c(a%i);
			while(c == 0) {
				b = a/i;
				rez.push_back(i);
				a = b;
				c = a%i;
			}
		}
	}
	return rez;
}

bool myfunction (int i,int j)
{

	std::vector<int> temp1, temp2;
	temp1 = ProstiFaktori(i);
	temp2 = ProstiFaktori(j);

	if (temp1.size() == temp2.size()) return i>j;

	return temp1.size()>temp2.size();



}
int funkcija (int a, int b)
{

	int temp =  -2*a + b;
	return temp;
}


int search(int arr[], int n, int x)
{
	int i;
	for (i = 0; i < n; i++)
		if (arr[i] == x)
			return i;
	return -1;
}


template <typename Tip, typename Tip2, typename Tip3, typename Tip4, typename Tip5>

Tip SortirajPodrucjeVrijednosti (Tip poc, Tip kraj, Tip2 poc2, Tip3 poc3, Tip4 fun, Tip5 fun2)
{
	int vel(0);
	int *pok = poc;
	int a(0);
	while (pok!=kraj) {
		vel++;
		pok++;
	}

	std::sort (poc,kraj,fun2);
	std::sort (poc2,poc2+vel,fun2);
	int *b = poc3;
	int *c = poc;
	int *d = poc2;


	while (c != kraj) {
		int *temp = b;
		while (temp) {

			if (fun(*c,*d)==*temp)  {
			
				break;
			}
			
			if (search(&temp[0],vel,fun(*c,*d))==-1) {

				throw std::logic_error ("Izuzetak: Vrijednost koja odgovara nekom od parova nije nadjena");
			}
			
			temp++;

		}
		c++;
		d++;
	}
 std::cout << "Nakon sortiranja podrucja vrijednosti imamo sljedece trojke: " << std::endl;

 	b = poc3;
	 c = poc;
	 d = poc2;


	while (c != kraj) {
		int *temp = b;
		while (temp) {

			if (fun(*c,*d)==*temp)  {
				std::cout << "f(" << *c << ", " << *d << ") = " << *temp << std::endl;
				a++;
				break;
			}
			
					temp++;

		}
		c++;
		d++;
	}


	return 0;

}



bool Unesen(int broj, std::vector<int> v1)
{

	for (auto x : v1) if (x==broj) return true;



}

int main ()
{
	std::cout << "Unesite broj elemenata: ";
	int n;

	std::cin >> n;

	std::vector<int> v1,v2,v3;
	int temp;

	std::cout << "Unesite elemente prvog vektora: ";

	while (v1.size()!=n) {

		std::cin>>temp;

		if (Unesen(temp,v1)) continue;

		v1.push_back(temp);
	}

	std::cout << "Unesite elemente drugog vektora: ";

	while (v2.size()!=n) {

		std::cin>>temp;
		if (Unesen(temp,v2)) continue;
		v2.push_back(temp);
	}

	std::cout << "Unesite elemente treceg vektora: " << std::endl;

	while (v3.size()!=n) {

		std::cin>>temp;
		if (Unesen(temp,v3)) continue;
		v3.push_back(temp);
	}


	try {
		SortirajPodrucjeVrijednosti(&v1[0],&v1[n],&v2[0],&v3[0],funkcija,myfunction);



	} catch (const std::logic_error &e) {
		std::cout << e.what() << std::endl;
		return 0;
	}

	return 0;
}