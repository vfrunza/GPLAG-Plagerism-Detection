/*B 2016/2017, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include<iostream>
#include<vector>
#include<string>
#include<stdexcept>

typedef std::string String;
typedef std::vector<std::string> SVektor;

bool NijeSlovo(String rijec){
	for(int i=0;i<rijec.size();i++){
		if(!((rijec[i]>='a'&&rijec[i]<='z')||(rijec[i]>='A'&&rijec[i]<='Z')))
		return false;
	}
	return true;
}

bool ImaRijec(String rijec, SVektor rijeci){
	for(int i=0;i<rijeci.size();i++){
		if(rijec==rijeci[i])
			return true;}
	return false;
}

String ObrniFraze(String recenica, SVektor fraze){
	
	if(recenica.size()==0){
		return recenica;
	}
	
	for(int i=0;i<fraze.size();i++){
		
		if(fraze[i].size()>recenica.size()) continue;
		for(int j=0;j<=recenica.size()-fraze[i].size();j++){
			if(recenica.substr(j,fraze[i].size())==fraze[i]){
				int x=fraze[i].size()-1;
				int p=j;
				while(x>=0){
					recenica[p]=fraze[i][x];
					x--;
					p++;
				}
			}
		}
	}
	return recenica;
}

String IzmijeniUPigLatin(String recenica, SVektor rijeci){
	for(int i=0; i<rijeci.size(); i++){
		if(!NijeSlovo(rijeci[i]))
			throw std::domain_error("Nekorektan izbor rijeci");
	}
	
	if (recenica.size()==0) {
		return recenica;		
	}
	
	if(rijeci.size()==0){
		for(int i=0;i<recenica.size();i++){
			if((recenica[i]>='a'&&recenica[i]<='z')||(recenica[i]>='A'&&recenica[i]<='Z')){
			//	int brojac(0);
				int indeks=i;
				while(i<recenica.size() &&((recenica[i]>='a'&&recenica[i]<='z')||(recenica[i]>='A'&&recenica[i]<='Z'))){
					i++;
					//brojac++;
				}
				recenica.insert(recenica.begin()+i, recenica[indeks]);
				recenica.insert(recenica.begin()+i+1,'a');
				recenica.insert(recenica.begin()+i+2,'y');
				recenica.erase(recenica.begin()+indeks);
				i+=2;
			}
		}//kraj for petlje za recenicu
	}//kraj ifa
	else {
		for(int j=0;j<rijeci.size();j++){
			if(rijeci[j].size()>recenica.size()) continue;
			for(int i=0;i<recenica.size();i++){

				if((recenica[i]>='a'&&recenica[i]<='z')||(recenica[i]>='A'&&recenica[i]<='Z')){
					int brojac(0);
					int indeks=i;
					while(i<recenica.size()&&((recenica[i]>='a'&&recenica[i]<='z')||(recenica[i]>='A'&&recenica[i]<='Z'))){
						brojac++;
						i++;
					}
					if(recenica.substr(indeks,brojac)==rijeci[j]){
						recenica.insert(recenica.begin()+i, recenica[indeks]);
						recenica.insert(recenica.begin()+i+1,'a');
						recenica.insert(recenica.begin()+i+2,'y');
						recenica.erase(recenica.begin()+indeks);
						i++;
					}
				}
			}
		}
	}
	return recenica;
}

int main (){
	
	String recenica,fraza;
	SVektor fraze;
	
	std::cout<<"Unesite recenicu: ";
	std::getline(std::cin,recenica);
	
	std::cout<<"Unesite fraze: ";	
	for(; ;){
		std::getline(std::cin,fraza);
		
		if(fraza.length()==0)
		break;
		
		fraze.push_back(fraza);

	}
	try{
		String a=IzmijeniUPigLatin(recenica,fraze);
	std::cout<<"Recenica nakon PigLatin transformacije: "<<a;}
	catch(std::domain_error izuzetak){ std::cout<<"Izuzetak: "<<izuzetak.what();}
	std::cout<<std::endl;
	std::cout<<"Recenica nakon obrtanja fraza: "<<ObrniFraze(recenica, fraze);
	
	return 0;
}