/*B 2016/2017, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include<iostream>
#include<string>
#include<vector>
#include<stdexcept>

std::string ObrniFraze (std::string recenica, std::vector<std::string> fraze) {
	std::string obrnuta(recenica);
	for(int i=0; i<fraze.size(); i++) {
		for(int j=0;j<obrnuta.length();j++) {
			std::string pomoc(obrnuta.substr(j,fraze.at(i).length()));
			if(fraze.at(i)==pomoc) {
				int br(j);
				for(int k=pomoc.length()-1;k>=0;k--) {
					obrnuta.at(br)=pomoc.at(k);
					br++;
				}
			}
		}
	}
	return obrnuta;
}

std::string IzmijeniUPigLatin(std::string recenica, std::vector<std::string>rijec) {
	for(int i=0;i<rijec.size();i++) {
		for(int j=0;j<rijec.at(i).length();j++) {
			if(!((rijec.at(i).at(j)>='A' && rijec.at(i).at(j)<='Z')||
			(rijec.at(i).at(j)>='a' && rijec.at(i).at(j)<='z'))) throw std::domain_error("Izuzetak: Nekorektan izbor rijeci");
		}
	}
		std::string pig(recenica);
		int br(0);
			if(rijec.size()==1 && rijec.at(0).length()==0) {
				for(int j=0;j<pig.length();j++) {
					while(j<pig.size() && pig.at(j)==' ') j++;
					if(j==pig.size()) break;
					int pom(j);
					while(j<pig.size() && pig.at(j)!=' ') j++;
//					if(j==pig.size()) pig.resize(pig.size()+1);
						pig.resize(pig.size()+1);

					pig.insert(pig.begin()+j,pig.at(pom));
			//		pig.erase(pig.begin()+pom);
					pig.insert(pig.begin()+j,'y');
			//		pig.insert(pig.begin()+j,'a');
				}
			return pig;
			}
			
		for(int i=0;i<pig.length();i++) {
			std::string pomocna;
			while(br<pig.length() && ((pig.at(br)>='A' && pig.at(br)<='Z')||(pig.at(br)>='a' && pig.at(br)<='z'))) {
				pomocna.push_back(pig.at(br));
				br++;
			}
			br++;

			for(int j=0;j<rijec.size();j++) {
				if(pomocna==rijec.at(j)) {
					if(br>=pig.size()) pig.resize(br+1);
					pig.at(br-1)=pomocna.at(0);
					pig.erase(pig.begin()+(br-1-pomocna.size()));
					pig.insert(pig.begin()+br-1,' ');
					pig.insert(pig.begin()+br-1,'y');
					pig.insert(pig.begin()+br-1,'a');
					break;
				}
				
				
			}
		}
	return pig;
}

int main ()
{	std::string recenica;
	std::cout<<"Unesite recenicu: ";
	std::getline(std::cin,recenica);
	std::vector<std::string> fraze;
	std::string rijec;
	std::cout<<"Unesite fraze: ";
	for(;;){
		std::getline(std::cin,rijec);
	    fraze.push_back(rijec);
		if(std::cin.peek()=='\n') break;
    }
    try {
    	std::cout<<"Recenica nakon PigLatin transformacije: "<<IzmijeniUPigLatin(recenica,fraze)<<std::endl;
    }
    catch(std::domain_error izuzetak) {
    	std::cout<<izuzetak.what()<<std::endl;
    }
	std::cout<<"Recenica nakon obrtanja fraza: "<<ObrniFraze(recenica, fraze);
	
	return 0;
}