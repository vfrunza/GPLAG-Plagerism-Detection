/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <cmath>
#include <vector>
#include <limits>

std::vector<int> IzdvojiGadne (std::vector<int> kopija , bool uslov) //opaki - tacno , odvratni - netacno
{
	std::vector<int> povratni;		// kopirano iz proslo uradjene funkcije
	if(static_cast<int>(kopija.size() )==0) return povratni;
	//brisanje duplih brojeva
	for(int i=0; i< static_cast<int>(kopija.size() - 1) ; i++){
		for(int j=i+1; j< static_cast<int>(kopija.size() ) ; j++){
			if(kopija.at(i) == kopija.at(j)) {
				kopija.erase(kopija.begin() + j);
				j--;
			}
		}
	}
	for(int i=0; i	<	static_cast<int>(kopija.size() ); i++){
		int a{kopija.at(i)} , broj_nula(0), broj_jedinica(0), broj_dvica(0);
		while(a!=0){
			int b;
			b=std::abs(a%3);
			a/=3;
			a=std::abs(a);
			if(b==0) broj_nula++;
			else if(b==1) broj_jedinica++;
			else broj_dvica++;
		}
		if(kopija.at(i)==0)broj_nula++;
		if(	(broj_nula%2 ==0) && (broj_jedinica%2==0) && (broj_dvica%2==0) && uslov	) povratni.push_back(kopija.at(i));
		else if(!(uslov)){
			if((broj_nula%2!=0) && (broj_jedinica%2!=0) && (broj_dvica%2!=0)) povratni.push_back(kopija.at(i));
			// kad nema 2 clana
			else if((broj_nula == 0) && (broj_jedinica==0) && (broj_dvica%2!=0))	povratni.push_back(kopija.at(i));
			else if((broj_nula == 0) && (broj_dvica==0) && (broj_jedinica%2!=0))	povratni.push_back(kopija.at(i));
			else if((broj_nula != 0) && (broj_dvica==0) && (broj_jedinica==0))	povratni.push_back(kopija.at(i));
			//veliki if da pokrije sve ostale slucajeve
			else if( ( (broj_nula==0) && (broj_jedinica%2!=0) && (broj_dvica%2!=0) )	|| 	
			( (broj_nula%2!=0) && (broj_jedinica==0) && (broj_dvica%2!=0) )	|| 
			( (broj_nula%2!=0) && (broj_jedinica%2!=0) && (broj_dvica==0) ))
			povratni.push_back(kopija.at(i));
			
			
		}
	}
	return povratni;
}

int main ()
{
	std::cout<< "Unesite brojeve (0 za prekid unosa): ";
	std::vector<int> v, novi_1, novi_2;
	int n;
	while(std::cin >> n, n!=0){
		v.push_back(n);
	}
	novi_1 = IzdvojiGadne(v,true);
	novi_2 = IzdvojiGadne(v,false);
	std::cout << "Opaki:";
	for(int x : novi_1) std::cout << " " << x;
	std::cout<<std::endl;
	
	std::cout << "Odvratni:";
	for(int x : novi_2) std::cout << " " << x;
	std::cout<<std::endl;
	
	
	return 0;
}
