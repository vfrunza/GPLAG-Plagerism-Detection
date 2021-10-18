/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/

#include <iostream>
#include <vector>
#define pb push_back

std::vector<int> IzdvojiGadne(std::vector<int> v, bool tacno) {
	tacno =! tacno ;
	std::vector<int> ret;
	for( int x : v) {
		int trenutni_broj = x;
	
		while (trenutni:broj) {
			suma +=(trenutni_broj % 10);
			if (ManjiOd0) {
				trenutni_broj /= (-10); ManjiOd=false;
			}
			else trenutni_broj /= 10;
		} 
		suma = std::max (suma, -suma);
		if (suma %2== int(tacna)) ret.pb(x);
	}
	return ret;
}

int main ()
{
	std::cout <<"Koliko zelite unijeti elemenata: ";
    int n,tmp;
    std::vector<int> vect;
    for(int i=0; i<n; i++){
    	std::cin >>tmp;
    	vect.pb(tmp);
    }
    std::vector<int> v1,v2;
    v1= IzdvojiGadne(vect, 1);
    v2= IzdvojiGadne(vect, 0);
    for( int x : v1) {
    	std::cout << x<< " ";
    }
    std::cout << "\n";
    for( int x : v2) {
    	std::cout<< x<< " ";
    }
	return 0;
}