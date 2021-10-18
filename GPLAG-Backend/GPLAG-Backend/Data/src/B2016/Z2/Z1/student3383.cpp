/*B 16/17, Zadaća 2, Zadatak 1
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
	
*/
#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>
#include <complex>

enum class Polje {
	Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina
};
enum class Smjerovi {
	GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo
};
enum class Status {
	NijeKraj, KrajPoraz, KrajPobjeda
};
enum class KodoviGresaka {
	PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar
};
enum class Komande {
	PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru
};
typedef std::vector<std::vector<Polje>> Tabla;

Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine){
	Tabla tabla(n, std::vector<Polje> (n, Polje::Prazno));
	for(auto i:mine){
		if(i.size() != 2) throw std::domain_error("Ilegalan format zadavanja mina");
		if(i.at(0)>=n || i.at(1)>=n) throw std::domain_error("Ilegalne pozicije mina");
		tabla.at(i.at(0)).at(i.at(1)) = Polje::Mina;
	}
	return tabla;
}

std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y){
	int n=polja.size();
	if(x>=n || y>=n){ 
		std::string x1 {char(x+'0')};
		std::string y1 {char(y+'0')};
		throw std::domain_error("Polje (" + x1 + "," + y1 + ") ne postoji");
	}
	std::vector<std::vector<int>> okolina(3, std::vector<int> (3,0));
	for(int i{0}; i<n; i++){
		for(int j{0}; j<n; j++){
			if((i==x-1 || i==x+1 || i==x) && (j==y-1 || j==y+1 || j==y)){
				int brojac{0};
				for(int k{0}; k<n; k++){
					for(int h{0}; h<n; h++){
						if((k==i-1 || k==i+1 || k==i) && (h==j-1 || h==j+1 || h==j) && !(k==i && h==j) && polja.at(k).at(h)==Polje::Mina){
							brojac++;
						}
					}
				}
				okolina.at(i).at(j)=brojac;
			}
		}
	}
	return okolina;
}

void BlokirajPolje(Tabla &polja, int x, int y){
	if(x>=polja.size() || y>=polja.size()) throw std::domain_error("Polje (x,y) ne postoji");
	if(polja.at(x).at(y) == Polje::Prazno) polja.at(x).at(y) = Polje::BlokiranoPrazno;
	else if(polja.at(x).at(y) == Polje::Posjeceno) polja.at(x).at(y) = Polje::BlokiranoPosjeceno;
	else if(polja.at(x).at(y) == Polje::Mina) polja.at(x).at(y) = Polje::BlokiranoMina;
}

void DeblokirajPolje(Tabla &polja, int x, int y){
	if(x>=polja.size() || y>=polja.size()) throw std::domain_error("Polje (x,y) ne postoji");
	if(polja.at(x).at(y) == Polje::BlokiranoPrazno) polja.at(x).at(y) = Polje::Prazno;
	else if(polja.at(x).at(y) == Polje::BlokiranoPosjeceno) polja.at(x).at(y) = Polje::Posjeceno;
	else if(polja.at(x).at(y) == Polje::BlokiranoMina) polja.at(x).at(y) = Polje::Mina;
}

Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer){
	int x1{x}, y1{y};
	if(smjer==Smjerovi::GoreLijevo){
		x1--;
		y1--;
	}
	else if(smjer==Smjerovi::Gore) x1--;
	else if(smjer==Smjerovi::GoreDesno){
		x1--;
		y1++;
	}
	else if(smjer==Smjerovi::Desno) y1++;
	else if(smjer==Smjerovi::Lijevo) y1--;
	else if(smjer==Smjerovi::DoljeDesno){
		x1++;
		y1++;
	}
	else if(smjer==Smjerovi::Dolje) x1++;
	else if(smjer==Smjerovi::DoljeLijevo){
		x1++;
		y1--;
	}
	if(x1<0 || y1<0 || x1>=polja.size() || y1>=polja.size()) throw std::out_of_range("Izlazak van igrace table");
	if(polja.at(x1).at(y1)==Polje::BlokiranoPosjeceno || polja.at(x1).at(y1)==Polje::BlokiranoPrazno || polja.at(x1).at(y1)==Polje::BlokiranoMina) 
	  throw std::logic_error("Blokirano polje");
	polja.at(x).at(y)=Polje::Posjeceno;
	x=x1;
	y=y1;
	if(polja.at(x).at(y)==Polje::Mina){
		for(int i{0}; i<polja.size(); i++){
			for(int j{0}; j<polja.size(); j++){
				polja.at(i).at(j)=Polje::Prazno;
			}
		}
		return Status::KrajPoraz;
	}
    for(int i{0}; i<polja.size(); i++)
      for(int j{0}; j<polja.size(); j++)
        if(polja.at(i).at(j)==Polje::Prazno) return Status::NijeKraj;
	
	return Status::KrajPobjeda;
}

Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y){
	if(novi_x>=polja.size() || novi_y>=polja.size()) throw std::out_of_range("Izlazak van igrace table");
	if(polja.at(novi_x).at(novi_y)==Polje::BlokiranoPosjeceno || polja.at(novi_x).at(novi_y)==Polje::BlokiranoPrazno || polja.at(novi_x).at(novi_y)==Polje::BlokiranoMina)
	  throw std::logic_error("Blokirano polje");
	polja.at(x).at(y)=Polje::Posjeceno;
	x=novi_x;
	y=novi_y;
	if(polja.at(x).at(y)==Polje::Mina){
	    for(int i{0}; i<polja.size(); i++)
	        for(int j{0}; j<polja.size(); j++)
	            polja.at(i).at(j)=Polje::Prazno;
	    return Status::KrajPoraz;
	}
	for(int i{0}; i<polja.size(); i++)
	    for(int j{0}; j<polja.size(); j++)
	        if(polja.at(i).at(j)==Polje::Prazno) return Status::NijeKraj;
	        
	return Status::KrajPobjeda;        
}

void PrijaviGresku(KodoviGresaka parametar){
	if(parametar==KodoviGresaka::PogresnaKomanda) std::cout << "Nerazumljiva komanda!";
	else if(parametar==KodoviGresaka::NedostajeParametar) std::cout << "Komanda trazi parametar koji nije naveden!";
	else if(parametar==KodoviGresaka::NeispravanParametar) std::cout << "Parametar komande nije ispravan!";
	else if(parametar==KodoviGresaka::SuvisanParametar) std::cout << "Zadan je suvisan parametar nakon komande!";
}

bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska){
	std::string unos;
	std::cin.ignore(10000,'\n');
	std::getline(std::cin ,unos);
	int znak{0};
	for(int i{0}; i<unos.length(); i++){
		while(unos[i]==' ' && i<unos.length()) i++;
		if(unos[i]=='K' || unos[i]=='Z'){                         /*  Za  Z  i  K  */
			znak=i;
			i++;
			while(unos[i]==' ' && i<unos.length()) i++;
			if(i==unos.length()){
				if(unos[znak]=='K')	komanda=Komande::KreirajIgru;
				else komanda=Komande::ZavrsiIgru;
				return true;
			}
			else{
				greska=KodoviGresaka::SuvisanParametar;
				return false;
			}
		}
		if(unos[i]=='P' || unos[i]=='B' || unos[i]=='D'){                    /*   Za  P   i   B  i   D      */
			bool Da_li_je_B{false}, Da_li_je_D{false};
		    if(unos[i]=='B') Da_li_je_B=true;
		    else if(unos[i]=='D') Da_li_je_D=true;
			i++;
			if(unos[i]=='O'){                                                  /*  Za O   */
			    i++;
				while (unos[i]==' ' && i<unos.length()) i++;
				if(i==unos.length()){
					komanda=Komande::PrikaziOkolinu;
					return true;
				}
				else{
					greska=KodoviGresaka::SuvisanParametar;
					return false;
				}
			}
			else if(unos[i]=='>' || unos[i-1]=='B' || unos[i-1]=='D'){                            /*  Za  > i  B i D*/
			    i++;
				while (unos[i]==' ' && i<unos.length()) i++;
				if(i==unos.length()){
					greska=KodoviGresaka::NedostajeParametar;
					return false;
				}
				if(unos[i]>='0' && unos[i]<='9'){
				    int brx{0};
				    while(unos[i]>='0' && unos[i]<='9' && i<unos.length()){
					    brx*=10;
				    	brx=brx+unos[i]-'0';
				    	i++;
			    	}
			    	if(unos[i]==' '){
			    		i++;
			    		int bry{0};
			    		while(unos[i]>='0' && unos[i]<='9'){
			    			bry*=10;
			    			bry=bry+unos[i]-'0';
		    				i++;
		    			}
		    			while(i<unos.length()){
		    				if(unos[i]!=' '){
		    					greska=KodoviGresaka::NeispravanParametar;
		    					return false;
		    				}
		    				i++;
		    			}
		    			if(i==unos.length()){
			    		    x=brx;
			    	    	y=bry;
			    	    	if(Da_li_je_B) komanda=Komande::Blokiraj;
			    	    	else if(Da_li_je_D) komanda=Komande::Deblokiraj;
			    	    	else komanda=Komande::PomjeriDalje;
			         		return true;
		    			}
			    	}
		    		else{
			     		greska=KodoviGresaka::NeispravanParametar;
			     		return false;
			     	}
		    	}
		    	else {
		    		greska=KodoviGresaka::NedostajeParametar;
		    		return false;
		    	}
    		}
    		else if(unos[i]=='1'){                                                /*    Za       1     */
    			i++;
    			while(unos[i]==' ' && i<unos.length()) i++;
    			if(unos[i]=='G' || unos[i]=='D' || unos[i]=='L'){              /*  Za   G    D    L   */
    				int j=i;
    				j++;
    				while(unos[j]==' ' && j<unos.length()) j++;
    				if(j==unos.length()){
    					if(unos[i]=='G') smjer=Smjerovi::Gore;
    					else if(unos[i]=='D') smjer=Smjerovi::Desno;
    					else if(unos[i]=='L') smjer=Smjerovi::Lijevo;
    					return true;
    				}
    				else if(j==i+1 && unos[i]=='G' && (unos[j]=='L' || unos[j]=='D')){       /* Za      GL      GD       */
    					while(unos[j]==' ' && j<unos.length()) j++;
    					if(j==unos.length()){
    						if(unos[i+1]=='L') smjer=Smjerovi::GoreLijevo;
    						else if(unos[i+1]=='D') smjer=Smjerovi::GoreDesno;
    						return true;
    					}
    				}
    				else if(j==i+1 && unos[i]=='D' && unos[j]=='o'){
    					j++;
    					if(unos[j]=='D' || unos[j]=='L'){
    						while(unos[j]==' ' && j<unos.length()) j++;
    						if(j==unos.length()){
    							if(unos[i+2]=='D') smjer=Smjerovi::DoljeDesno;
    							else if(unos[i+2]=='L') smjer=Smjerovi::DoljeLijevo;
    							return true;
    						}
    					}
    					else{
    						while(unos[j]==' ' && j<unos.length()) j++;
    						if(j==unos.length()){
    							smjer=Smjerovi::Dolje;
    							return true;
    						}
    					}
    				}
    				else{
    					greska=KodoviGresaka::SuvisanParametar;
    					return false;
    				}
    				
    			}
    			else{
    				greska=KodoviGresaka::NedostajeParametar;
    				return false;
    			}
    		}
    	}
    }
    greska=KodoviGresaka::PogresnaKomanda;
    return false;
}

void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer = Smjerovi::Gore, int p_x = 0, int p_y = 0){
	Status status;
	if(komanda == Komande::PomjeriJednoMjesto){ 
		status = Idi(polja, x, y, p_smjer);
		std::string x1{char(x+'0')};
		std::string y1{char(y+'0')};
		std::cout << "Tekuca pozicija igraca je (" + x1 + "," + y1 + ")";
	}
	else if(komanda == Komande::PomjeriDalje){ 
		status = Idi(polja, x, y, p_x, p_y);
		std::string x1{char(x+'0')};
		std::string y1{char(y+'0')};
		std::cout << "Tekuca pozicija igraca je (" + x1 + "," + y1 + ")";
	}
    else if(komanda == Komande::Blokiraj){ 
    	try{
    	   BlokirajPolje(polja, x, y);
    	}
    	catch(std::domain_error izuzetak){
    		std::cout << izuzetak.what() << std::endl;;
    	}
    }
    else if(komanda == Komande::Deblokiraj){ 
    	try{
    	   DeblokirajPolje(polja, x, y);
    	}
    	catch(std::domain_error izuzetak){
    		std::cout << izuzetak.what() << std::endl;
    	}
    }
	else if(komanda == Komande::PrikaziOkolinu){ 
		std::vector<std::vector<int>> okolina(3, std::vector<int> (3,0));
		okolina=PrikaziOkolinu(polja, x, y);
		for(auto i:okolina){
		   for(auto j:i) std::cout << j << " ";
		   std::cout << std::endl;
		}
	}
	else if(komanda == Komande::ZavrsiIgru){
		for(int i{0}; i<polja.size(); i++){ 
			for(int j{0}; j<polja.at(i).size(); j++)
			    polja.at(i).at(j) = Polje::Prazno;
		}
		throw std::runtime_error("Igra zavrsena");
	}
	else if(komanda == Komande::KreirajIgru){
		std::cout << "Unesite broj polja: ";
		int n;
		std::cin >> n;
		std::cout << "Unesite pozicije mina: ";
		std::complex<int> x;
		std::vector<std::vector<int>> mine(n, std::vector<int> (n, 0));
		for(;;){
			std::cin >> x;
			if(std::cin.peek() == '.') break;
			if(std::cin && x.real() < n && x.imag() < n && x.real() >= 0 && x.imag() >= 0){
				mine.at(x.real()).at(x.imag()) = 1;
			}
			else
			   std::cout << "Greska, unesite ponovo";
		}
		polja=KreirajIgru(n,mine);
	}
}

int main ()
{
	try{
	   std::cout << "Unesite komandu: ";
	   Komande komanda;
	   Smjerovi smjer;
       int x, y;
	   KodoviGresaka greska;
	   Tabla polje;
	   for(;;){
	      if(!UnosKomande(komanda,smjer,x,y,greska)) PrijaviGresku(greska);
	      else 
	         IzvrsiKomandu(komanda,polje,x,y);
	   }
	}
	catch(...){
		return 0;
	}
	return 0;
}