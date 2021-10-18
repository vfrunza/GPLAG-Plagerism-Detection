
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <iterator>
#include <sstream>
#include <cctype>
#include <stdexcept>

std::vector<std::string> split(const std::string ss){
	std::istringstream s(ss);
	std::vector<std::string> tokens{std::istream_iterator<std::string>{s},
    std::istream_iterator<std::string>{}};
	return tokens;
}
std::string myreplaceDva(std::string &recenica, const std::string &frazaZaZamjenu, const std::string &saOvimZamjeniti){
	return(recenica.replace(recenica.find(frazaZaZamjenu), frazaZaZamjenu.length(), saOvimZamjeniti));
}

std::string myreplace(std::string recenicaTri, const std::string frazaZaZamjenu, const std::string saOvimZamjeniti){
  std::string::size_type pos = 0u;
		while((pos = recenicaTri.find(frazaZaZamjenu, pos)) != std::string::npos){
     		recenicaTri.replace(pos, frazaZaZamjenu.length(), saOvimZamjeniti);
     		pos += frazaZaZamjenu.length();
  		}
  return recenicaTri;
}

std::string myreplaceTri(std::string recenicaTri, const std::string frazaZaZamjenu, const std::string saOvimZamjeniti){
	std::string::size_type pos = 0u;
	while((pos = recenicaTri.find(frazaZaZamjenu, pos)) != std::string::npos){
  		if(recenicaTri[pos-1]==' ' || pos==0u){
     	recenicaTri.replace(pos, frazaZaZamjenu.length(), saOvimZamjeniti);
  		}
     pos += frazaZaZamjenu.length();
    }
    return recenicaTri;
}

std::string zamjenaSlova(std::string frazaZamjenaPrva){
	int duzina = frazaZamjenaPrva.size();
	std::string ReturnFraza=frazaZamjenaPrva;
    std::string drugo(1,frazaZamjenaPrva[0]);

	ReturnFraza.replace(0,1, "");
	ReturnFraza.replace(ReturnFraza.end(),ReturnFraza.end(), drugo);	
	return ReturnFraza;
}


std::string ObrniFraze(std::string recenicaDva, std::vector<std::string>fraze) {
	std::string noviString;
	std::string noviFrazaDva;
	for(int i=0; i<fraze.size()-1; i++) {
		noviString=fraze[i];		
		
		std::reverse(noviString.begin(), noviString.end());           //standardna fukcija za izvrtanje slova u frazi
		//std::cout<<"Fraza:"<< fraze[i]<<std::endl;
		//std::cout<<"Recenica:"<<recenicaDva<<std::endl;
		recenicaDva=myreplace(recenicaDva, fraze[i],noviString);
	}
	return recenicaDva;
}

std::string IzmijeniUPigLatin(std::string recenica, std::vector<std::string>fraze) {
	char PrazanProstor='	';
	for(int i=0; i<fraze.size(); i++){
		for(int j=0; j<fraze[i].size(); j++){ 
			if(fraze[i][j]==PrazanProstor){
				throw ("Nekorektan izbor rijeci");
				return 0;
			}
		}
	}
	
	
	
	
	std::string noviString;
	
	if (fraze.size()>1){ //slucaj kada su vektoru poslate odredjene fraze
		for (int i=0; i<fraze.size()-1; i++) {
			std::string novaFraza=zamjenaSlova(fraze[i]);
			
			noviString=novaFraza+"ay";
			recenica=myreplaceTri(recenica, fraze[i], noviString);
		}
	}
	else if(fraze.size()<=1){ //slucaj kada je IzmijeniUPigLatin poslat prazan vektor, fraza na svakoj se rijeci dodaje "ay"
    							                    //u ovom primjeru nikada vektor nije prazan, jer zadnji element vektora je "speace" i to se mora uzeti u obzir 
		std::string RecenicaBezKaraktera=recenica;
		std::vector<char>karakteri = {'.',',',';',':','+','?','!',')','(','/','@','=','*','-','_'} ;
		for (int i=0; i<karakteri.size(); i++) {
				int t=0;
				int len=RecenicaBezKaraktera.length();
				while(t<len){
				    if(RecenicaBezKaraktera[t]==karakteri[i]){
				        RecenicaBezKaraktera.erase(t,1);
				        len--;
				    }
				    else
				        t++;
				}
		}
		
		std::vector<std::string> razbijenaRecenica ;
		razbijenaRecenica=split(RecenicaBezKaraktera);
		
			for(int i=0; i<razbijenaRecenica.size(); i++) {
				
			std::string novaFraza=zamjenaSlova(razbijenaRecenica[i]);
			
			noviString=novaFraza+"ay";
			recenica=myreplaceTri(recenica, razbijenaRecenica[i], noviString);
	    	}
		
	}
	return recenica;
}
int main(){
	std::string recenica;
	std::string recenicaDva;
	std::string recenicaObrnuta;
	std::string fraza;
	std::vector<std::string> frazeDva;
	std::cout<<"Unesite recenicu: ";
	getline(std::cin, recenica);
	std::cout<<"Unesite fraze: ";
	std::vector<std::string> fraze;
	//int i=0;
	do{
		getline(std::cin, fraza);
		fraze.push_back(fraza);
	} 
	while (fraza!="");
	frazeDva=fraze;
	recenicaObrnuta=recenica;
	std::cout<<"Recenica nakon PigLatin transformacije: ";
	try{
	recenicaDva=IzmijeniUPigLatin(recenica, fraze); 
    }catch(std::domain_error izuzetak){
    	std::cout<<izuzetak.what()<<std::endl;
    }
	std::cout<<recenicaDva;
	std::cout<<std::endl;
	std::cout<<"Recenica nakon obrtanja fraza: ";
	recenicaObrnuta=ObrniFraze(recenicaObrnuta, frazeDva); 
	std::cout<<recenicaObrnuta;
	
	return 0;
}
