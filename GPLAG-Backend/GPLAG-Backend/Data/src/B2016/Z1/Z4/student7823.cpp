#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

void dodaj_rijeci(std::vector<std::string> &vs, std::string s){
    bool ima=false;
      for (int j=0; j<vs.size(); j++) if (s==vs[j]) ima=false;
       if (ima==false)vs.push_back(s); 
}
std::string IzmijeniUPigLatin(std::string recenica, std::vector<std::string> fraze){
	for(int l=0;l<fraze.size();l++){	//Ispituje da li se nalaze nekorektna slova, ili razmak
		for(int c=0;c<fraze[l].size();c++){
			if(fraze[l][c]<'A' || fraze[l][c]>'z' || (fraze[l][c]>'Z' && fraze[l][c]<'a')) throw std::domain_error("Nekorektan izbor rijeci");
		}
	}
	if(fraze.size()==0){
		for(int i=0;i<recenica.size();i++){
			std::string prazan{recenica};
			if(recenica[i]==' ') continue;
			else{
				int poc{i};
				for(int j=i;j<recenica.size();j++){
					if(!(recenica[j]<'A' || recenica[j]>'z' || (recenica[j]>'Z' && recenica[j]<'a') || !((j+1)!=recenica.size()))) continue;
					else{
						if(j+1==recenica.size())j++;
						std::string pomocni{recenica.substr(poc, j-poc)};
						recenica.erase(poc, j);
						std::string prvo_slovo{pomocni.substr(0,1)};
						pomocni+=prvo_slovo+"ay";
						pomocni.erase(0, 1);
						recenica.insert(poc, pomocni);
						i=j+1;
						break;
					}
				}
			}
		}
		return recenica;
	}	//ako je spisak fraza prazan
	for(int i=0;i<recenica.size();i++){
		if(recenica[i]==' ') continue;
		else{
			int poc=i;
			for(int j=i;j<recenica.size();j++){
				if(!((recenica[j]<'A' || (recenica[j]>'Z' && recenica[j]<'a') || recenica[j]>'z' || !((j+1)!=recenica.size())))) continue;
				else{
					if (j==0) j=1; //ako je prvo slovo
					if(j+1==recenica.size()) j++;	//ako je kraj stringa
					std::string pomocni{recenica.substr(poc,j-poc)};
					for(int k=0;k<fraze.size();k++){
						if(pomocni==fraze[k]){
							recenica.erase(poc,j-poc);
							std::string prvo_slovo{pomocni.substr(0,1)};
							pomocni+=prvo_slovo+"ay";
							pomocni.erase(0, 1);
							recenica.insert(poc, pomocni);
							i=j+1;
							break;
						}
					}
				i=j;
				break;
				}
			}
		}
	}
	return recenica;
}
std::string ObrniFraze(std::string recenica, std::vector<std::string> fraze){
	for(int i=0;i<fraze.size();i++){
		for(int j=0;j<recenica.length();j++){
			if(recenica[j]==fraze[i][0]){ //da li se moze uzeti prvo slovo recenice i porediti se?
				std::string pomocni{recenica.substr(j,fraze[i].size())};
				if(pomocni==fraze[i]){
					std::string izdvojen{};
					for(int k=pomocni.length()-1;k>=0;k--){
						izdvojen+=pomocni[k];
					}
					recenica.erase(j,fraze[i].length());
					recenica.insert(j,izdvojen);
				}
			}
		}
	}
	return recenica;
}
int main (){
   std::cout<<"Unesite recenicu: ";
   std::string prva_rec{};
   std::getline(std::cin, prva_rec);
   
/*   std::cout<<"Koliko zelite unijeti rijeci: ";
   int n;
   std::cin>>n;
   std::cin.ignore(10000, '\n');
*/   
   std::string s;
   std::vector<std::string> recenica;
   std::cout<<"Unesite fraze: ";
   while((std::getline(std::cin, s)), s!=""){
   		dodaj_rijeci(recenica,s);
   }
   /*
   std::cout<<"Unesite rijeci: ";
   for(int i=0;i<n;i++){
      std::cin>>s;
      dodaj_rijeci(recenica,s);
   }
   */
   /*std::cout<<"vase rijeci glase: "<<std::endl;
   for(int i=0;i<n;i++){
      std::cout<<recenica[i]<<std::endl;
   
   }*/
	try{
			std::cout<<"Recenica nakon PigLatin transformacije: "<<IzmijeniUPigLatin(prva_rec,recenica)<<std::endl;
	}catch(std::domain_error izuzetak){
		std::cout<<"Izuzetak: "<<izuzetak.what()<<std::endl;
	}
	
	std::cout<<"Recenica nakon obrtanja fraza: "<<ObrniFraze(prva_rec,recenica);
	
	return 0;
}