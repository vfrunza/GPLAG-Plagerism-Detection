/*B 16/17, Zadaća 2, Zadatak 4
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
*/
#include<iostream>
#include<string>
#include<vector>
#include<new>

using std::cin;
using std::cout;
using std::endl;

int PotencijalniKrivci(char **(&p), std::vector<std::string> v){
	char **a(nullptr)
	try{
	a=new char *niz[v.size()];
	int i(0);
	try{
		while (i<v.size()) {a[i]=new char[v[i].size()]; i++}
	}
	carch(std::bad_alloc){
		for(int j=0; j<i; j++) delete[] a[j];
		delete[] a;
		throw;
	}
	}
	catch(std::bad_alloc){
		std::cout<<"Problemi s memorijom!"<<
	}
	
	
return brojac;	
}


int main ()
{
	return 0;
}