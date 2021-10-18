/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector> 

std::vector<int> IzdvojiGadne(std::vector<int> v, bool log_vrijednost) {
	if(v.size() == 0) return v;
	
	std::vector<int> povratni;
	
	for(int i = 0; i < v.size(); i++){
//		std::cout << "Pretvaram " << v.at(i) << "!\n";
		int broj_nula{0};
		int broj_jedinica{0};
		int broj_dvica{0};
		int broj(v.at(i));
		//Nula odudara od algoritma pa je moramo posebno posmatrati
		if(v.at(i) == 0){
			broj_nula = 1;
			broj_jedinica = 0;
			broj_dvica = 0;
		}
		while(broj != 0){
			if(broj % 3 == 0)
			broj_nula++;
			if(broj % 3 == 1)
			broj_jedinica++;
			if(broj % 3 == 2)
			broj_dvica++;
			
		broj /= 3;
//	    std::cout << "Broj je sada: " << broj << std::endl;
			
		}
		
/*		std::cout << "Broj nula: " << broj_nula << std::endl;
		std::cout << "Broj jedinica: " << broj_jedinica << std::endl;
		std::cout << "Broj dvica: " << broj_dvica << std::endl; 
*/		
//		std::cout << "Provjeravam ima li ovog clana u povratnom vektoru i ako ne stavljam ga u povratni!\n";
		if(log_vrijednost){
//			std::cout << "Logicka je true!\n";
			bool control(1);
			for(int j = 0; j < povratni.size(); j++)
				if(v.at(i) == povratni.at(j)){
					control = false;
//					std::cout << "VEC SE NALAZI U VEKTORU!" << std::endl;
				}
			if(control && broj_nula % 2 == 0 && broj_jedinica % 2 == 0 && broj_dvica % 2 == 0){
				povratni.push_back(v.at(i));
//				std::cout << "Smjesten u povratni!" << std::endl;
			}
		}
		if(log_vrijednost == false){
//			std::cout << "Logicka je false!\n";
			bool control(1);
			for(int j = 0; j < povratni.size(); j++)
				if(v.at(i) == povratni.at(j)){
					control = false;
//					std::cout << "VEC SE NALAZI U VEKTORU!" << std::endl;
				}
				
			if(control && broj_nula == 0 && broj_jedinica % 2 == 1 && broj_dvica % 2 == 1)
				povratni.push_back(v.at(i));
			if(control && broj_jedinica == 0 && broj_nula % 2 == 1 && broj_dvica % 2 == 1)
				povratni.push_back(v.at(i));
			if(control && broj_dvica == 0 && broj_nula % 2 == 1 && broj_jedinica % 2 == 1)
				povratni.push_back(v.at(i));
			if(control && broj_nula == 0 && broj_jedinica == 0 && broj_dvica % 2 == 1)
				povratni.push_back(v.at(i));
			if(control && broj_nula == 0 && broj_dvica == 0 && broj_jedinica % 2 == 1)
				povratni.push_back(v.at(i));
			if(control && broj_jedinica == 0 && broj_dvica == 0 && broj_nula % 2 == 1)
				povratni.push_back(v.at(i));
			if(control && (broj_nula % 2 == 1 && broj_jedinica % 2 == 1 && broj_dvica % 2 == 1)){
				povratni.push_back(v.at(i));	
//				std::cout << "Smjesten u povratni!" << std::endl;
			}
		}
	}
	return povratni;
}

int main ()
{
	std::cout << "Unesite brojeve (0 za prekid unosa): ";
	std::vector<int> v;
	for(;;){
		int i;
		std::cin >> i;
		if(i != 0)
		v.push_back(i);
		else
		break;
	}
	
	std::vector<int> Opaki;
	Opaki = IzdvojiGadne(v, true);
//	std::cout << "Kreiran i popunjen vektor Opaki i njegova velicina je: " << Opaki.size() << "!\n";
	std::vector<int> Odvratni;
	Odvratni = IzdvojiGadne(v, false);
//	std::cout << "Kreiran i popunjen vektor Odvratni i njegova velicina je: " << Odvratni.size() << "!\n";
	
	std::cout << "Opaki: ";
	for(int i = 0 ; i < Opaki.size(); i++)
		std::cout << Opaki.at(i) << " ";
		
	std::cout << std::endl;
	
	std::cout << "Odvratni: ";
	for(int i = 0; i < Odvratni.size(); i++)
		std::cout << Odvratni.at(i) << " ";
		
	std::cout << std::endl;
	
	return 0;
}