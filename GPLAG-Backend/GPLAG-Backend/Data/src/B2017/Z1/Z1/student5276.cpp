/*B 2017/2018, Zadaća 1, Zadatak 1

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.
*/
#include <iostream>
#include <vector>
#include <cmath>

using std::vector;
using std::cin;
using std::cout;
using std::endl;



unsigned int DajNaopakBroj(unsigned int a)
{

	unsigned int novi = 0;
	
	while (a > 0) {
		
		novi *= 10;
		
		novi+= a%10;
	
		a/=10;
		
	}
	
	return novi;
}


bool JelPalindrom(unsigned int a)
{
	if( a == DajNaopakBroj(a))
     return true;
	else return false;
}




vector<int> PalindromskaOtpornost(vector<int>a)

{
	
	vector<int> ret;
	
	for(int i=0; i<a.size() - 1; i++) {
		
		int PalOtp = 0;
		
			if(JelPalindrom(abs (a.at(i))) == 1 ) {
				ret.push_back(PalOtp);
			}

		    else {
			
			    unsigned int br = abs(a.at(i)) ;
			   
			    while ( JelPalindrom(br) != 1) {
			    	
			    	PalOtp++;
			    	
			    	br += DajNaopakBroj(br);
			    
			}
			
			ret.push_back(PalOtp);
			
		}
	}
	return ret;
}


int main ()
{

	
	int broj=0;
	
	cout<<"Koliko zelite unijeti elemenata: ";
	
	cin>>broj;
	
	   vector<int> a(broj);
	   
	cout<<"Unesite elemente: ";
     
    for(int i=0; i<broj; i++) {
        cin>>a.at(i);
    }
    
    std::vector<int> novi = PalindromskaOtpornost(a) ;
    
    for(int i = 0; i < broj; i++)
     cout<< "Palindromska otpornost broja " <<a.at(i)<<" iznosi "<< novi.at(i)<<endl;


	return 0;
}