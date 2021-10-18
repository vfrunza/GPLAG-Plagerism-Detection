/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include<iostream>
#include<vector>
#include<cmath>
//...TREBAM POPRAVITI TRECI SLUCAJ... IZLAZ IZ VEKTOR.SIZE().....
int Baza3 (int n){
	
	int br = std::abs(n);
	std::vector<int>baza;
	
	//...BINARNO POZITIV...
	while(br != 0){
		int b = br % 3;
		baza.push_back(b);
		br /= 3;
	}
	
	//...REVERSE VEKTOR SWAP ELEMENTE...
	/*
	for(int i = 0,j = baza.size() - 1; i < baza.size(), j >= 0; i++, j--){
		std::swap(baza[i],baza[j]);

	}
	*/
	
	int i = 0, j = baza.size() - 1;
	while(i < baza.size() && j >= 0){
		std::swap(baza[i],baza[j]);
		i++;
		j--;
	}
	/*...NEGATIVNI BROJEVI KOMPLEMENT BAZE 3...
	if(n < 0){
		for(int i = baza.size() - 1; i >= 0; i--){
			if(i == baza.size() - 1) baza[i] = 3 - baza[i];
			else baza[i] = 2 - baza[i];
		}
	}
	
	
	for(int i = 0; i < baza.size();i++)
	std::cout<<" | "<< baza[i];
	*/
	//...PREBROJI ELEMENTE...
	std::vector<int>vektbr;
	int br0 {0}, br1 {0} , br2 {0};
	
	for(int i = 0; i < baza.size(); i++){
			
		if(baza[i] == 0) br0++;
		else if(baza[i] == 1) br1++;
		else br2++;
		
	}
	/*
	if(br0 > 0) vektbr.push_back(br0);
	if(br1 > 0) vektbr.push_back(br1);
	if(br2 > 0) vektbr.push_back(br2);
	
	
	//...PARNI ILI NEPARNI...SVI..
	bool jeste;
	for(int i = 0; i < vektbr.size(); i++){
		if(vektbr[i] % 2 != 0) { jeste = 0;  break;}
		else jeste = 1;
	}
	*/
	
	//TRI SLUCAJA
	
	if(((br0 % 2 == 0) || (br0 == 0)) && ((br1 % 2 == 0) || (br1 == 0)) && ((br2 % 2 == 0) || (br2 == 0))) {
		return 1;
	}else if(((br0 % 2 != 0) || (br0 == 0)) && ((br1 % 2 != 0) || (br1 == 0)) && ((br2 % 2 != 0) || (br2 == 0))){
		return 0;
	}else{
		return 2;
	}
	
	
}

std::vector<int> IzdvojiGadne (std::vector<int>gadni,bool parametar){
	std::vector<int>opaki;
	std::vector<int>odvratni;
	
	//...BEZ PONAVLJANJA..IZBACI ELEMENTE...
	/*
	for(int i = 0; i < gadni.size();i++){
		for(int j = i + 1; j < gadni.size() ;j++){
		
				
			if(gadni[i] == gadni[j]){
				//..UKOLIKO JE ZADNJI ELEMENT...POPRAVI..
			//	if(j + 1 < gadni.size() - 1){ 
			for(int l = j; l < gadni.size();l++){ 
				gadni[ j ] = gadni[ j + 1];
				
				gadni.resize(gadni.size() - 1);
				j--;
			}
			}
			*/
			
		for (int i = 0; i < gadni.size(); i++) {
      for (int j = i + 1; j < gadni.size();) {
         if (gadni[j] == gadni[i]) {
            for (int k = j; k < gadni.size(); k++) {
                if(k + 1 < gadni.size())
                    gadni[k] = gadni[k + 1];
            }
            gadni.resize(gadni.size()-1);
         } else
            j++;
      }
   }
			/*
			else if(j == gadni.size() - 1){
				gadni.resize(gadni.size() - 1);
				i--;
			}
			
			}
			*/
	//	}
//	}
	
/*
	
	int i = 0,j = i + 1;
	while(i < gadni.size() && j < gadni.size()){
		if(gadni[i] == gadni[j]){
			gadni[j] = gadni[j + 1];
			gadni.resize(gadni.size() - 1);
			i--;
		}
	}
	*/
//		for(int i = 0; i < gadni.size();i++){
//		std::cout<<"|"<<gadni[i];
//	}
	//...POZOVI FUNKCIJU I STAVI U VEKTOR...
	for(int i = 0; i < gadni.size();i++){
	//...TRI SLUCAJA...
		if(Baza3(gadni[i]) == 1) opaki.push_back(gadni[i]);
		else  if(Baza3(gadni[i]) == 0) odvratni.push_back(gadni[i]);
		else continue;
	
	}
	
	//...U OVISNOSTI OD PARAMETRA VRATI TAJ VEKTOR...
	if(parametar) return opaki;
	else return odvratni;
}

int main ()
{
	//...UNOS ELEMENATA U VEKTOR...
	
	
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	/*
	std::vector<int>gadni;
	for(int i = 0; i < n; i++){
		int br;
		std::cin >> br;
		gadni.push_back(br);
	}
	*/
	
	int br;

	
	std::vector<int>gadni;
	while(std::cin >> br && br != 0){
		gadni.push_back(br);
	}
	
//	std::vector<int> gadni = {
//			123,12,123,1212,10102,-10102,333,1000,333,123
//};
	//for(int i = 0; i < gadni.size();i++){
	//	std::cout<<gadni[i]<<" ";
	//}
/*	
	//...POZIV FUNKCIJE...
	std::cout<<"Unesite parametar: \n";
	bool parametar;
	std::cin>>parametar;
	
	std::vector<int>izdvoji = IzdvojiGadne(gadni,parametar);
	
	if(parametar == true) { 
		std::cout<<"Opaki:  \n";
		for(int i = 0; i < izdvoji.size();i++){
		std::cout<< izdvoji[i] << " ";
		}
	}else{
		std::cout<<"Odvratni:  \n";
		for(int i = 0; i < izdvoji.size();i++){
		std::cout<< izdvoji[i] << " ";	
		}
	}
*/
	std::vector<int>opakibrojevi = IzdvojiGadne(gadni,true);
	std::cout<<"Opaki: ";
	for(int i = 0; i < opakibrojevi.size(); i++){
		std::cout<<opakibrojevi[i]<<" ";
	}
	
	std::vector<int>odvratnibrojevi = IzdvojiGadne(gadni,false);
	std::cout<<"\nOdvratni: ";
	for(int i = 0; i < odvratnibrojevi.size();i++){
		std::cout<<odvratnibrojevi[i]<<" ";
	}

return 0;	
}