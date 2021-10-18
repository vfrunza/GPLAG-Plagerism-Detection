/*B 2017/2018, Zadaća 2, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na forum (c2).
*/
#include <iostream>
#include <stdexcept>
#include <type_traits>

void UnistiMatricu (int **mat,int n){
	if (mat==nullptr) return;
	for (int i(0);i<n;i++){
		delete[] mat i;
	}
	delete[] mat;
}


template<typename tip>
void AlocirajKontinualno (const std::vector<tip> &v1, int &koliko_puta){
	
}

template<typename tip>
void AlocirajFragmentirano (const std::vector<tip> &v1, int &koliko_puta){
	int pocetak(0),kraj,period,br(1);
	int **mat=nullptr;
	for (int i(0);i<v1.size()-1;i++){
		for (int j(i+1);i<v1.size();j++){
			if (v1.at(i)==v1.at(j)){
				i++;
			//	br++;
			//	if (v1.at(i)==v1.at(pocetak))
			}
		}
		if (v1.at(i)==v1.at(pocetak)) break;
	}
	int n=koliko_puta*period;
	try{
		mat=new int *[n];
		for (int i(0);i<n;i++){
			mat[i]=nullptr;
		}
		for (int i(0);i<=period;i++){
			if (i!=period) mat[i]=new int [i+1];
			else if (i==period && koliko_puta!=br) {
				i=0;
				br++;
			}
			else break;
		}
	}
	catch (std::bad_alloc e){
		UnistiMatricu (mat,n);
		throw e;
	}
	
}

int main ()
{
	return 0;
}