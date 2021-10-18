/*B 2016/2017, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <string>
#include <vector> 
#include <stdexcept>


//F.CIJA KOJA PROVJERAVA DA LI JE NESTO SLOVO
bool jelslovo(char a){
	if ((a>='A' && a<='Z') || (a>='a' && a<='z')) { return true;	}
	return false;
}


// TRAZENA F.CIJA OBRNI FRAZE
std :: string ObrniFraze(std :: string org, std::vector<std :: string> a)
{
	for (int i = 0; i < a.size(); i++) {
		std :: string pomocni=a[i];
		for(int j = 0; j < org.length(); j++){
			if (org[j] == pomocni[0]) {
				int brojac=0;
				int k=j;
				int r=0;
					while( k<org.size()  &&  r<pomocni.size()  &&  org[k] == pomocni[r]){
						k++;
						r++;
						brojac++;
				}
				if (brojac == pomocni.length()) {
					int zadnji=pomocni.length()-1;
					
						for(int t = j; t < j+brojac; t++ ){
							org[t] = pomocni[zadnji];
							zadnji--;
					}
					
					
				} else continue;
				
			} else continue;
			
		}
	}
	return org;
}
//KADA SE PIGLATIN F.CIJI POSALJE PRAZAN VEKTOR KORISTIMO OVU
std :: string PrazanVektor(std :: string org){
	for(int j=0; j<org.size(); j++){
		if (!jelslovo(org[j])) {continue;	}
		int brojac=0;
		int k=j;
		
		while (jelslovo(org[k])) {
			k++;
			brojac++;
		}
		char prvi=org[j];
		char drugi='a';
		char treci='y';
		org.erase(org.begin()+j);
		org.insert(org.begin()+j-1,prvi);
		org.insert(org.begin()+j,drugi);
		org.insert(org.begin()+j+1,treci);
		j=k+1;
	}
	return org;
}
// PIG LATIN F.CIJA
std :: string IzmijeniUPigLatin(std :: string org, std :: vector<std :: string> vs)
{ 
	for(int k=0; k<vs.size(); k++){
		for(int p=0; p<vs[k].length(); p++){
			if (!jelslovo(vs[k][p])) {
				throw std :: domain_error("Nekorektan izbor rijeci");
			}
		}
	}
	//AKO JE PRAZAN VEKTOR
	if (vs.size()==0) { 
		std :: string vrati;
		vrati=PrazanVektor(org);
		return vrati;
	} 
	else { 
	
	for(int i = 0; i < vs.size(); i++){
		std :: string pomocni=vs[i];
		for(int j = 0; j < org.length(); j++){
			if (org[j]==pomocni[0]) {
				int brojac=0;
				int k=j;
				int r=0;
			
			while( k<org.size() && r<pomocni.size() && org[k] == pomocni[r]){
				k++;
				r++;
				brojac++;
			}	//AKO JE J NULA NE PROVJERAVAJ PRETHODNI ZNAK
			if (j==0 && brojac==pomocni.length() && !((org[j+brojac]>='A' && org[j+brojac]<='Z') || (org[j+brojac]>='a' && org[j+brojac]<='z'))) {
				char prvi=org[j];
				char drugi='a';
				char treci='y';
				org.erase(org.begin()+j);
				org.insert(org.begin()+j+brojac-1,prvi);
				org.insert(org.begin()+j+brojac,drugi);
				org.insert(org.begin()+j+brojac+1,treci);
				
			}
			//AKO JE J+BROJAC JEDNAKO VELICINI NE PROVJERAVAJ NAREDNI ZNAK
			else if ((j+brojac)==org.size() && brojac==pomocni.length() && (!jelslovo(org[j-1])) ) {
				 char prvi=org[j];
				 char drugi='a';
				 char treci='y';
				 org.erase(org.begin()+j);
				 org.insert(org.begin()+j+brojac-1,prvi);
				 org.insert(org.begin()+j+brojac,drugi);
				 org.insert(org.begin()+j+brojac+1,treci);
				
			} 
			//AKO JE J NA SREDINI PROVJERAVAJ I J-1 I J+BROJAC+1
			else if((j+brojac)!=org.size() && j!=0 && brojac==pomocni.length() && !(jelslovo(org[j-1])) && !(jelslovo(org[j+brojac]))){
				char prvi=org[j];
				char drugi='a';
				char treci='y';
				org.erase(org.begin()+j);
				org.insert(org.begin()+j+brojac-1,prvi);
				org.insert(org.begin()+j+brojac,drugi);
				org.insert(org.begin()+j+brojac+1,treci);
			} else continue;
			
			} else continue;
		}
	}
	return org;	
	}
}

int main ()
{
	std :: string s,zaPig,zaObrni;
	std::vector<std :: string> fraze;
	std::cout << "Unesite recenicu: ";
	std :: getline(std :: cin, s);
	std::cout << "Unesite fraze: ";
	for(; ;){
	std :: string unos;
	std :: getline(std :: cin,unos);
	if (unos.length()==0) { break; }
	fraze.push_back(unos);
	}
	try{
	std::cout << "Recenica nakon PigLatin transformacije: "<<IzmijeniUPigLatin(s,fraze)<<std :: endl;
	}
	catch(std :: domain_error izuzetak){
		std::cout << "Izuzetak: " <<izuzetak.what()<<std :: endl;
	}
	
	std::cout << "Recenica nakon obrtanja fraza: " <<ObrniFraze(s,fraze);
	
	return 0;
}