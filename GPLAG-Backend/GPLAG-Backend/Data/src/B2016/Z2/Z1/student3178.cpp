#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

enum class Polje { Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina};
enum class Smjerovi {GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo};
enum class KodoviGresaka { PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar };
enum class Komande {PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru };
enum class Status {NijeKraj, KrajPoraz, KrajPobjeda};

typedef std::vector<std::vector<Polje>> Tabla;

Tabla KreirajTablu(int n){
	return Tabla(n, std::vector<Polje>(n, Polje::Prazno)) ;}
	


Tabla KreirajIgru(int n, const std::vector<std::vector<int>> mine){
	auto nova_tabla(KreirajTablu(n));
	for(int i{0}; i<mine.size(); i++){
		if( mine[i].size() !=2) throw std::domain_error ("Ilegalan format zadavanja mina");} //UHVATI OVO GDE TREBA}
	for(int i{0}; i<mine.size(); i++){
		for(int j{0}; j<2; j++){
	    if (mine[i][j] <0 || mine[i][j] >= n)  throw std::domain_error ("Ilegalne pozicije mina"); //UHVATI OVO GDE TREBA		
		}
     }
    for(int i{0}; i<n; i++){
		for(int j{0}; j<n; j++){
			for(int l{0}; l<mine.size(); l++){
		       	if(mine[l][0] == i && mine[l][1] == j)
	  nova_tabla[i][j] = Polje::Mina;
			}}}
	return nova_tabla;
}

	
void BlokirajPolje(Tabla &polja, int x, int y){
	if(x<0 || x>= polja.size() || y<0 || y>= polja.size() ) throw std::domain_error ("Polje (" + std::to_string(x) + "," + std::to_string(y)+ ") ne postoji");
  
if(polja[x][y] == Polje::Prazno) polja[x][y] = Polje::BlokiranoPrazno;
if(polja[x][y] == Polje::Posjeceno) polja[x][y] = Polje::BlokiranoPosjeceno;
if(polja[x][y] == Polje::Mina) polja[x][y] = Polje::BlokiranoMina;
}

void DeblokirajPolje(Tabla &polja, int x, int y){
	if(x<0 || x>= polja.size() || y<0 || y>= polja.size() ) throw std::domain_error ("Polje (" + std::to_string(x) + "," + std::to_string(y)+ ") ne postoji");
if(polja[x][y] == Polje::BlokiranoPrazno) polja[x][y] =  Polje::Prazno;
if(polja[x][y] == Polje::BlokiranoPosjeceno) polja[x][y] = Polje::Posjeceno;
if(polja[x][y] == Polje::BlokiranoMina) polja[x][y] = Polje::Mina;
}

bool GraniceSuUredu(const int& x, const int& y, const int& vel){
	return x>=0 && x<vel && y>=0 && y<vel;}
	
bool ShouldIIncerement(const int& x, const int& y, const Tabla& tabla)	{
	return GraniceSuUredu(x,y,tabla.size()) && tabla[x][y] == Polje::Mina;}
	
int PrebrojOk(int x,int y, const Tabla& tabla){
	int br=0;
	if(ShouldIIncerement(x+1, y, tabla)) br++;
	if(ShouldIIncerement(x+1, y-1, tabla)) br++;
	if(ShouldIIncerement(x+1, y+1, tabla)) br++;
	if(ShouldIIncerement(x, y+1, tabla)) br++;
	if(ShouldIIncerement(x, y-1, tabla)) br++;
	if(ShouldIIncerement(x-1, y+1, tabla)) br++;
	if(ShouldIIncerement(x-1, y, tabla)) br++;
	if(ShouldIIncerement(x-1, y-1, tabla)) br++;
	return br;}
	
std::vector<std::vector<int>> PrikaziOkolinu(const Tabla& polja, int x, int y) {
	if(x<0 || x>= polja.size() || y<0 || y>= polja.size() ) throw std::domain_error ("Polje (" + std::to_string(x) + "," + std::to_string(y)+ ") ne postoji");
	std::vector<std::vector<int>> fr;
	for(int i= x-1; i<x+2; i++){
		std::vector<int> tmp;
		for(int j = y-1; j< y+2; j++){
			if(GraniceSuUredu(i,j,polja.size())){
				tmp.push_back(PrebrojOk(i,j,polja));
		}
	}
	fr.push_back(tmp);
}
		return fr; }
	

Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer){
       int tmpx = x, tmpy = y;
       
       switch (smjer) {
       	   case Smjerovi::Desno:
            	y++;
            	break;
           case Smjerovi::Lijevo:
            	y--;
            	break;
            case Smjerovi::Gore:
            	x--;
            	break;
            case Smjerovi::Dolje:
            	x++;
            	break;
            case Smjerovi::GoreDesno:
            	x--;
            	y++;
            	break;
            case Smjerovi::GoreLijevo:	
            	x--;
            	y--;
            	break;
            case Smjerovi::DoljeDesno:
                x++;
                y++;
                break;
            case Smjerovi::DoljeLijevo:   
                x++;
                y--;
                break;
            default:
            break;
       }     
       if(!GraniceSuUredu(x, y, polja.size())){
       	x = tmpx;
       	y = tmpy;
       	throw std::out_of_range("Izlazak van igrace table");
       }
       
       if(polja[x][y] == Polje::BlokiranoPrazno || polja[x][y] == Polje::BlokiranoMina || polja[x][y] == Polje::BlokiranoPosjeceno){
          x=tmpx;
          y=tmpy;
          throw std::logic_error("Blokirano polje");
       }
       
       polja[tmpx][tmpy] = Polje::Posjeceno;
       
              
       if(polja[x][y] == Polje::Mina){
       	for(int i{0}; i<polja.size(); i++){
       	   	for(int j{0}; j<polja.size(); j++){
       	   		polja[i][j] = Polje::Prazno;
       	   	}
       	 }
       	 return Status::KrajPoraz;
       }else{
       	int br{0};
      
       	for(int i{0}; i<polja.size(); i++){
       	   	for(int j{0}; j<polja.size(); j++)	{
       	   		if(polja[i][j] != Polje::Mina && polja[i][j] == Polje::Prazno)
       	   		br++;
       	   	}
       	}
       if(br==1){
return Status::KrajPobjeda;
}
}
return Status::NijeKraj;
}



Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y ){
	 if(!GraniceSuUredu(novi_x, novi_y, polja.size())){
       	throw std::out_of_range("Izlazak van igrace table");
       }
      
       if(polja[novi_x][novi_y] == Polje::BlokiranoPrazno || polja[novi_x][novi_y] == Polje::BlokiranoMina || polja[novi_x][novi_y] == Polje::BlokiranoPosjeceno) throw std::logic_error("Blokirano polje");
	
	polja[x][y] = Polje::Posjeceno;
	
	if(polja[novi_x][novi_y] == Polje::Mina){
		for(int i{0}; i<polja.size(); i++){
       	   	for(int j{0}; j<polja.size(); j++)	{
       	   		polja[i][j] = Polje::Prazno;
       	   	}
		}
		return Status::KrajPoraz;
	}
		int br=0;
		for(int i=0; i<polja.size(); i++){
			for(int j=0; j<polja.size(); j++){
				if(polja[i][j] != Polje::Mina && polja[i][j] == Polje::Prazno)
				br++;
			}
		}
		
		if(br == 1){
			return Status::KrajPobjeda;
		}
		
		x = novi_x;
		y = novi_y;
		
		return Status::NijeKraj;
		}
		
		
void PrijaviGresku(KodoviGresaka kod_greske){
	if( kod_greske==KodoviGresaka::PogresnaKomanda) std::cout<<"Nerazumljiva komanda!";
	else if (kod_greske==KodoviGresaka::NedostajeParametar) std::cout<<"Komanda trazi parametar koji nije naveden!";
	else if (kod_greske==KodoviGresaka::NeispravanParametar) std::cout <<"Parametar komande nije ispravan!";
	else std::cout << "Zadan je suvisan parametar nakon komande!";
	std::cout << std::endl;
	}


bool DajKomandu(std::string s, Komande &komanda, KodoviGresaka &greska, std::string &kom){
	int i{0};
	while(i<s.length() && s[i] == ' ') i++;
	kom= "";
	
	while(i<s.length() && s[i] != ' ') {
		kom.push_back(s[i]);
		i++;
		}
		
	if(kom == "P1") komanda = Komande::PomjeriJednoMjesto;
	else if(kom == "P>") komanda = Komande::PomjeriDalje;
	else if(kom == "B") komanda = Komande::Blokiraj;
	else if(kom == "D") komanda = Komande::Deblokiraj;
	else if(kom == "PO")komanda = Komande::PrikaziOkolinu;
    else if(kom == "Z")komanda = Komande::ZavrsiIgru;
	else if(kom == "K")komanda = Komande::KreirajIgru;
	else{
		 greska = KodoviGresaka::PogresnaKomanda;
		 return false;
	}
    return true;
	}



bool DajSmjer(std::string s, KodoviGresaka &greska, Smjerovi &smjer){
	int i{0};
	while(i<s.length() && s[i] == ' ') i++;
	while(i<s.length() && s[i] != ' ') i++;
	while(i<s.length() && s[i] == ' ') i++;
	
	if(i == s.length()){
		greska = KodoviGresaka::NedostajeParametar;
		return false;
	}
	std::string tmp("");
	
	while(i<s.length() && s[i] != ' ') {
		tmp.push_back(s[i]);
		i++;
		}
	
	if(tmp == "GL") smjer = Smjerovi::GoreLijevo;
	else if(tmp == "G") smjer = Smjerovi::Gore;
	else if(tmp == "GD") smjer = Smjerovi::GoreDesno;
	else if(tmp == "D") smjer = Smjerovi::Desno;
	else if(tmp == "DoD") smjer = Smjerovi::DoljeDesno;
	else if(tmp == "Do") smjer = Smjerovi::Dolje;
	else if(tmp == "DoL") smjer = Smjerovi::DoljeLijevo;
	else if(tmp == "L") smjer = Smjerovi::Lijevo;
	else {
		greska = KodoviGresaka::NeispravanParametar;
		return false;
	}
	
    while(i<s.length() && s[i] == ' ') i++;
    
    if( i != s.length()){
    	greska = KodoviGresaka::SuvisanParametar;
    	return false;
    }
    return true;
}
	
bool JelBroj(std::string s, int &broj){
	if(s.length() == 0) return false;
	for(int i{0}; i<s.length(); i++)
	if(s[i] < '0' || s[i] > '9') return false;
	
	broj = 0;
	
	for(int i{0}; i<s.length(); i++){
		broj = broj*10 + s[i] - '0';
}
return true;
}

bool DajParametre(std::string s, int &x, int &y, KodoviGresaka &greska){
	int i{0};
    while(i<s.length() && s[i] == ' ') i++;
	while(i<s.length() && s[i] != ' ') i++;
	while(i<s.length() && s[i] == ' ') i++;
	
	if(i == s.length()){
		greska = KodoviGresaka::NedostajeParametar;
		return false;
	}
	
	std::string br1("");
	std::string br2("");
	int tmpx(0);
	int tmpy(0);
	
	
	while(i< s.length() && s[i]  != ' '){
		br1.push_back(s[i]);
		i++;
	}
	
	if(!JelBroj(br1,tmpx)){
		greska=KodoviGresaka::NeispravanParametar;
		return false;
	}
	
	while(i< s.length() && s[i]  == ' ') i++;
	
	if(i == s.length()){
		greska = KodoviGresaka::NedostajeParametar;
		return false;}
		
		while( i < s.length() && s[i] != ' '){
			br2.push_back(s[i]);
			i++;
		}
		
		
		if(!JelBroj(br2, tmpy)){
			greska = KodoviGresaka::NeispravanParametar;
			return false;
		}
		
	while(i< s.length() && s[i]  == ' ') i++;
	
	if(i != s.length()){
		greska = KodoviGresaka::SuvisanParametar;
		return false;
	}
	x=tmpx;
	y=tmpy;
	return true;
}

bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska){
	
	std::string unos;
	std::getline(std::cin, unos);
	std::string kom("");
	
	if(!DajKomandu(unos, komanda, greska, kom)) return false;
	
	if( kom == "P1" && !DajSmjer(unos, greska, smjer)) return false;
	
	else if((kom == "P>" || kom == "B" || kom == "D") && !DajParametre(unos,x,y,greska)) return false;
	else if(kom == "PO" || kom == "Z" || kom == "K"){
		int i{0};
		while(i<unos.length() && unos[i] == ' ') i++;
    	while(i<unos.length() && unos[i] != ' ') i++;
    	while(i<unos.length() && unos[i] == ' ') i++;
	
    	if(unos.length() != i){
		greska = KodoviGresaka::SuvisanParametar;
		return false;
	    }
	}
	return true;
}

bool DajPoziciju(std::string s, int& x, int& y){
     if(s.length() < 5) return false;
     
     if(s[0] != '(' || s[s.length() -1] != ')') return false;
     
     int i(1);
     std::string br1("");
     
     while(i<s.length() && s[i] != ',') {
     	br1.push_back(s[i]);
     	i++;
}

   if(i==s.length()) return false;
   if(!JelBroj(br1,x)) return false;
   i++;

   br1 = "";
   while(i<s.length() && s[i] != ')'){
   	br1.push_back(s[i]);
   	i++;
   }
   
   if(!JelBroj (br1, y)) return false;
   return true;
}


void UnosZaKreiranjeIgre(Tabla& polja){
	int n;
	std::cout <<"Unesite broj polja: ";
	std::cin >> n;
	std::vector<std::vector<int>> mine;
	
	std::string s("");
	std::cout <<"Unesite pozicije mina: ";
	do{
		std::getline(std::cin, s);
		if(s=="" || s==".") {
		continue;}
		
		int x, y;
		if(!DajPoziciju(s, x, y)) std::cout << "Greska, unesite ponovo!"<< std::endl;
		
		else {
			if(x < 0 || x>= n || y<0 || y >= n){
				std::cout << "Greska, unesite ponovo!" << std::endl;
				continue;
			}
			mine.push_back({x, y});
		}
	}while( s != ".");
	
    polja = KreirajIgru(n, mine);
	
}


void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer = Smjerovi::Gore, int p_x = 0, int p_y = 0){
	Status status;
	std::vector<std::vector<int>> okolina;
	
	switch(komanda){
		case Komande::Blokiraj:
		     BlokirajPolje(polja, p_x, p_y);
		     break;
	    case Komande::Deblokiraj:
	         DeblokirajPolje(polja, p_x, p_y);
	         break;
	    case Komande::KreirajIgru:
	         UnosZaKreiranjeIgre(polja);
	         x=0; y=0;
	         break;
	    case Komande::PomjeriDalje:
	         status = Idi(polja, x, y, p_x, p_y);
	        if(status== Status::KrajPobjeda){
	    	std::cout << "Bravo, obisli ste sva sigurna polja" << std::endl;
		throw std::runtime_error("Igra zavrsena");}
		else if(status == Status::KrajPoraz){
			std::cout << "Nagazili ste na minu" <<std::endl;
			throw std::runtime_error("Igra zavrsena");
		}
		else
		std::cout << "Tekuca pozicija igraca je ("<<x<<","<<y<<")"<<std::endl;
		break;
		
		case Komande::PomjeriJednoMjesto:
		status = Idi(polja, x, y, p_smjer);
		if(status == Status::KrajPobjeda){
			std::cout <<"Bravo, obisli ste sva sigurna polja"<<std::endl;
			throw std::runtime_error("Igra zavrsena");}
		else if(status ==Status::KrajPoraz){
			std::cout << "Nagazili ste na minu" <<std::endl;
			throw std::runtime_error("Igra zavrsena");
		}
		else 
		std::cout << "Tekuca pozicija igraca je ("<<x<<","<<y<<")"<<std::endl;
		break;
		case Komande::PrikaziOkolinu:
		okolina = PrikaziOkolinu(polja, x, y);
		for(std::vector<int> v : okolina) {
			for(int x : v) std::cout << x << " ";
			std::cout<< std::endl;
	    }
	    break;
	    case Komande::ZavrsiIgru:
	    for(int i{0}; i<polja.size(); i++){
	    	for(int j{0}; j<polja.size(); j++)
	    	polja[i][j] = Polje::Prazno;
	    }
	    throw std::runtime_error("Igra zavrsena");
	    break;
	    default:
	    break;
		}
 }
	




int main ()
{
	Komande komanda;
	Smjerovi smjer;
	KodoviGresaka greska;
	Tabla polja;
int x,y,p_x,p_y;

while(true){
	std::cout<<"Unesite komandu: ";
	try{
		if(!UnosKomande(komanda, smjer, p_x, p_y, greska))
		PrijaviGresku(greska);
		else IzvrsiKomandu(komanda, polja, x, y, smjer, p_x, p_y);
	}
	catch(std::runtime_error e){
		std::cout <<"Dovidjenja!" << std::endl;
		break;
	}
	catch(std::logic_error e){
		std::cout<< e.what() << std::endl;
		
	}
}
		
	return 0;
}