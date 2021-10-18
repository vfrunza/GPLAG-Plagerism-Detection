#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <complex>
#include <stdexcept>
#include <sstream>

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
    PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu,
    ZavrsiIgru, KreirajIgru
};


typedef std::vector<std::vector<Polje>> Tabla;
Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine);
std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y);
void BlokirajPolje(Tabla &polja, int x, int y);
void DeblokirajPolje(Tabla &polja, int x, int y);
Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer);
Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y);
std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y);
//_____________________________________________________________________________
void PrijaviGresku(KodoviGresaka a){
	if(a == KodoviGresaka::PogresnaKomanda) std::cout <<"Nerazumljiva komanda!"<<std::endl;
	else if(a == KodoviGresaka::NedostajeParametar) std::cout << "Komanda trazi parametar koji nije naveden!" <<std::endl;
	else if(a == KodoviGresaka::NeispravanParametar) std::cout<< "Parametar komande nije ispravan!" << std::endl;
	else std::cout << "Zadan je suvisan parametar nakon komande!" << std::endl;
	
}


//_____________________________________________________________________________
std::vector<std::string> RazdvojPoRazmacima(std::string &s){
	std::vector<std::string> temp;
	std::string k;
	k = "";
	for(int i=0; i<s.length(); i++){
		while(i<s.length() && s[i] != ' ') k.push_back(s[i++]);
		if(k != ""){
			temp.push_back(k);
			k="";
		}
	}
	return temp;
}

bool KomandaJeTacna(const std::string &s){
	return (s == "P1" || s == "P>" || s == "B" ||s == "D" || s == "PO" || s == "Z" || s == "K");
}

bool BrojJe(const std::string &s){
	for(int i=0; i<s.length(); i++){
		if(s[i] < '0' || s[i] > '9' ) return false;
	}
	return true;
}

bool ProvjeriParametre(const std::vector<std::string> &vs, KodoviGresaka &greska){
	if(vs.size()>3){
		greska = KodoviGresaka::SuvisanParametar;
		return false;
	}
	if(vs.size()<3){
		if(vs.size()==2 && !BrojJe(vs[1])) greska = KodoviGresaka::NeispravanParametar;
		else greska = KodoviGresaka::NedostajeParametar;
		return false;
	}
	if(!BrojJe(vs[1]) || !BrojJe(vs[2]) ) {
		greska = KodoviGresaka::NeispravanParametar;
		return false;
	}
	return true;
}

int PretvoriUBroj(std::string s){
	int k = 0;
	std::string f = "";
	for(auto i=s.begin() ; i<s.end() ; i++) {
		if(*i >='0' || *i<='9') f+=(*i);	
	}
	for(int i = 0; i<f.length(); i++)
	{
		k*=10;
		int broj = f[i] - '0';
		k+=broj;
	}
	return k;
}

bool SmjerJeTacan(const std::string &s){
	return(s == "GL" || s == "G" || s == "GD" || s == "D" || s == "DoD" || s == "Do" || s == "DoL" || s == "L");
}

bool ProvjeriSmjer(const std::vector<std::string> &vs, KodoviGresaka &greska){
	if(vs.size()<2){
		greska = KodoviGresaka::NedostajeParametar;
		return false;
	}
	if(vs.size()>2){
		greska = KodoviGresaka::SuvisanParametar;
		return false;
	}
	if(!SmjerJeTacan(vs[1])){
		greska = KodoviGresaka::NeispravanParametar;
		return false;
	}
	return true;
}
Smjerovi DajSmjer(const std::string &s){
	if(s == "G") return Smjerovi::Gore;
	if(s == "GL") return Smjerovi::GoreLijevo;
	if(s == "GD") return Smjerovi::GoreDesno;
	if(s == "D") return Smjerovi::Desno;
	if(s == "DoD") return Smjerovi::DoljeDesno;
	if(s == "Do") return Smjerovi::Dolje;
	if(s == "DoL") return Smjerovi::DoljeLijevo;
	return Smjerovi::Lijevo;
}
bool UnosKomande (Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska){
	
	std::string unos;
	std::getline(std::cin, unos);
	std::vector<std::string> vs= RazdvojPoRazmacima(unos);
	//std::cin.ignore(10000,'\n');
	if(!KomandaJeTacna(vs[0])){
		greska = KodoviGresaka::PogresnaKomanda;
		return false;
	}
	if(vs[0] == "K") komanda = Komande::KreirajIgru;
	else if(vs[0] == "Z") komanda = Komande::ZavrsiIgru;
	else if(vs[0] == "PO") komanda = Komande::PrikaziOkolinu;
	else if(vs[0] == "P>" || vs[0] == "B" || vs[0] =="D"){
		if(!ProvjeriParametre(vs,greska))return false;
		if(vs[0] == "P>") komanda = Komande::PomjeriDalje;
		else if(vs[0] == "B") komanda = Komande::Blokiraj;
		else if (vs[0] == "D") komanda = Komande::Deblokiraj;
		x = PretvoriUBroj(vs[1]);
		y = PretvoriUBroj(vs[2]);
	}
	else{
		if(!ProvjeriSmjer(vs,greska)) return false;
		komanda=Komande::PomjeriJednoMjesto;
		smjer = DajSmjer(vs[1]);
	}
	return true;
}
//_________________________________________________________________________
bool IspravnoUnesenaMina(std::string s, int &prvakoordinata, int &drugakoordinata){
	int zarezbrojac(0), razmakbrojac(0);
	for(int i=0; i<s.length() ; i++){
		if(s[i] == ',') zarezbrojac++;
		if(s[i] != ',' && s[i] != ' ' && s[i] !='(' && s[i] != ')' && (s[i]<'0' || s[i]>'9') && s[i]) return false;
		if(s[i] == ' ') razmakbrojac++;
	}
	if(zarezbrojac != 1) return false;
	int i(0);
	std::string temp;
	while(s[i++] != ','){
		if(s[i]==' ' || s[i] == '(' || s[i] == ')' ||s[i] == ',')continue;
		temp.push_back(s[i]);
	}
	prvakoordinata = PretvoriUBroj(temp);
	temp.resize(0);
	for(;i<s.length();i++){
		if(s[i]==' ' || s[i] == '(' || s[i] == ')')continue;
		else temp.push_back(s[i]);
	}
	drugakoordinata = PretvoriUBroj(temp);
	return true;
}
/*
void FunkcijaZaUnosMina(std::vector<std::vector<int>> &mine, const int &n){
	std::cout<<"Unesite pozicije mina: ";
	std::cin.ignore(10000,'\n');
	std::cin.clear();
	int prvakoordinata(-19), drugakoordinata(-19);
	while(1){
		std::vector<int> pomocni;
		std::string mjestomine;
		std::getline(std::cin, mjestomine);
		std::cout << "STRING = "<<mjestomine;
		if(IspravnoUnesenaMina(mjestomine)){
			prvakoordinata=-19;
			drugakoordinata=-19;
			PretvoriMjestoMineuVektor(mjestomine,prvakoordinata,drugakoordinata);
			if(prvakoordinata >=n || prvakoordinata<0 || drugakoordinata>=n ||drugakoordinata<0){
				std::cin.ignore(10000, '\n');
				std::cin.clear();
				std::cout<<"Greska, unesite ponovo!" << std::endl;
			}
			else if(prvakoordinata == -19 && drugakoordinata == -19 ){
				std::cout << "DOSAO";
				std::cin.ignore(10000,'\n');
				std::cin.clear();
				break;
			}
			else{
				pomocni.push_back(prvakoordinata);
				pomocni.push_back(drugakoordinata);
				mine.push_back(pomocni);
				std::cin.ignore(10000,'\n');
			}
		}
		else{
			std::cin.ignore(10000,'\n');
			std::cin.clear();
			std::cout<<"Greska, unesite ponovo!" << std::endl;
		}
	}
	
}
*/
//_________________________________________________________________________
void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer = Smjerovi::Gore, int p_x = 0, int p_y = 0){

		//x=p_x;
		//y=p_y;
		if(komanda == Komande::Blokiraj) BlokirajPolje(polja,p_x,p_y);
		else if(komanda == Komande::Deblokiraj) DeblokirajPolje(polja,p_x,p_y);
		else if(komanda == Komande::PomjeriDalje){
			try{
			Status s = Idi(polja,x,y,p_x,p_y);
			if( s == Status::KrajPobjeda){
				std::cout << "Bravo, obisli ste sva sigurna polja"<< std::endl;
				komanda = Komande::ZavrsiIgru;// 
				IzvrsiKomandu(komanda,polja,x,y,p_smjer,p_x,p_y);
			}
			else if( s == Status::KrajPoraz){
				std::cout << "Nagazili ste na minu"<< std::endl;
				komanda = Komande::ZavrsiIgru;//
				IzvrsiKomandu(komanda,polja,x,y,p_smjer,p_x,p_y);
			}
			std::cout << "Tekuca pozicija igraca je ("<<x<<","<<y<<")"<<std::endl;
			}
			catch(std::logic_error e){
				std::cout << e.what() << std::endl;
			}
			catch(std::out_of_range o){
				std::cout << o.what() << std::endl;
			}
		}
		else if(komanda == Komande::PomjeriJednoMjesto){
		    try{
			Status s= Idi(polja,x,y,p_smjer);
			std::cout << "Tekuca pozicija igraca je ("<<x<<","<<y<<")"<<std::endl;
			if( s == Status::KrajPobjeda){
				std::cout << "Bravo, obisli ste sva sigurna polja"<< std::endl;
				komanda = Komande::ZavrsiIgru;
				IzvrsiKomandu(komanda,polja,x,y,p_smjer,p_x,p_y);
			}
			else if( s == Status::KrajPoraz){
				std::cout << "Nagazili ste na minu"<< std::endl;
				komanda = Komande::ZavrsiIgru;
				IzvrsiKomandu(komanda,polja,x,y,p_smjer,p_x,p_y);
			}
		    }
			catch(std::logic_error e){
				std::cout << e.what() << std::endl;
			}
			catch(std::out_of_range o){
				std::cout << o.what() << std::endl;
			}
		    
		}
		else if(komanda == Komande::PrikaziOkolinu){
			std::vector<std::vector<int>> okolina = PrikaziOkolinu(polja,x,y);
			for(std::vector<int> temp : okolina){
				for(int i : temp) std::cout<< i << " ";
				std::cout << std::endl;
			}
		}
		else if(komanda == Komande::ZavrsiIgru){
			for(int i=0 ; i<polja.size(); i++){
				for(int j=0; j<polja[i].size(); j++) polja[i][j]=Polje::Prazno;
			}
			throw std::runtime_error("Dovidjenja!");
		}
		else if(komanda == Komande::KreirajIgru){
			//trazi velicinu
			std::cout << "Unesite broj polja: ";
			int z;
			std::cin >> z;
			std::vector<std::vector<int>> mine;
			//FunkcijaZaUnosMina(mine, z);
			int prvakoordinata, drugakoordinata;
			std::string mjestomine;
			std::cout<<"Unesite pozicije mina: ";
			while(1){
				std::vector<int> pomocni;
				std::cin >> mjestomine;
				if(IspravnoUnesenaMina(mjestomine,prvakoordinata,drugakoordinata)){
					if(prvakoordinata>=z || drugakoordinata>=z || prvakoordinata <0 || drugakoordinata <0){
						std::cin.ignore(10000,'\n');
						std::cin.clear();
						std::cout<<"Greska, unesite ponovo!"<<std::endl;
					}
					else{
						pomocni.push_back(prvakoordinata);
						pomocni.push_back(drugakoordinata);
						mine.push_back(pomocni);
					}
				}
				else if(mjestomine =="."){
					std::cin.ignore(10000,'\n');
					std::cin.clear();
					break;
				}
				else{
					std::cin.ignore(10000,'\n');
					std::cin.clear();
					std::cout<<"Greska, unesite ponovo!"<<std::endl;
				}
			}
			polja = KreirajIgru(z, mine);
			x=0;
			y=0;
		}
	
}
//_________________________________________________________________________
void MineSuUredu(const int &n, const std::vector<std::vector<int>> &mine){
	for(int i=0; i<mine.size(); i++){
		if(mine[i].size() != 2) throw std::domain_error("Ilegalan format zadavanja mina");
	}
	for(int i=0; i<mine.size(); i++){
		for(int j=0; j<mine[i].size() ; j++){
			if(n<=mine[i][j] || mine[i][j]<0) throw std::domain_error("Ilegalne pozicije mina");
		}
	}
}

Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine){
	MineSuUredu(n,mine);
	Tabla t;
	t.resize(n);
	for(int i=0; i<t.size(); i++){
		for(int j=0; j<n ; j++){
			t[i].push_back(Polje::Prazno);
		}
	}
	for(int i=0; i<mine.size(); i++){
		for(int j=0; j<n; j++){
			for(int k=0; k<n; k++){
				if(j==mine[i][0] && k==mine[i][1]) t[j][k]=Polje::Mina;
			}
		}
	}
	return t;
}
//__________________________________________________________________________
int PrebrojiPolja(const Tabla &polja,const int &x,const int &y){
	int br(0);
	for(int i=x-1; i<=x+1; i++){
		for(int j=y-1; j<=y+1; j++){
			if(i<0 || i>=polja.size()) continue;
			if(j<0 || j>=polja.size()) continue;
			if(i == x && j == y) continue;
			if(polja[i][j] == Polje::Mina) br++;
		}
	}
	return br;
}



bool VanTable(int &x, int &y, int vel){
	if(x<0 || x>=vel || y<0 || y>=vel) return true;
	return false;
}
//Profesorova FUNKCIJA
template<typename T>
std::string PretvoriUString(T x){
	std::ostringstream s;
	s << x;
	return s.str();
}

void Testiraj(int &x, int &y, int vel){
	std::string s;
	s=PretvoriUString(x);
	s+=",";
	s+= PretvoriUString(y);
	if(VanTable(x,y,vel)) throw std::domain_error("Polje (" + s + ") ne postoji");
}


std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y){
	Testiraj(x, y, (int)(polja.size()) );
	std::vector<std::vector<int>> v;
	for(int i=x-1; i<=x+1; i++){
		std::vector<int> a;
		for(int j=y-1; j<= y+1 ; j++){
			if(i<0 || i>=polja.size() ) continue;
			if(j<0 || j>=polja.size() ) continue;
			a.push_back(PrebrojiPolja(polja,i,j));
		}
		v.push_back(a);
	}
	return v;
}
//_______________________________________________________________________________
void BlokirajPolje(Tabla &polja, int x, int y){
	Testiraj(x,y,(int) polja.size());
	if(polja[x][y] == Polje::Prazno) polja[x][y] = Polje::BlokiranoPrazno;
	else if(polja[x][y] == Polje::Mina) polja[x][y] = Polje::BlokiranoMina;
	else if(polja[x][y] == Polje::Posjeceno)polja[x][y] = Polje::BlokiranoPosjeceno;
}

void DeblokirajPolje(Tabla &polja, int x, int y){
	Testiraj(x,y,(int)polja.size());
	if(polja[x][y] == Polje::BlokiranoPrazno) polja[x][y] = Polje::Prazno;
	else if(polja[x][y] == Polje::BlokiranoMina) polja[x][y] = Polje::Mina;
	else if(polja[x][y] == Polje::BlokiranoPosjeceno) polja[x][y] = Polje::Posjeceno;
}
//_____________________________________________________________
bool Bl_okirano_Po_lja(const Tabla &polja,int x,int y){
	if(polja[x][y] == Polje::BlokiranoMina || polja[x][y] == Polje::BlokiranoPosjeceno || polja[x][y] == Polje::BlokiranoPrazno) return true;
	return false;
}

bool PobjedioUIgri(const Tabla &polja){
	int br(0);
	for(int i=0; i<polja.size(); i++){
		for(int j=0; j<polja[i].size(); j++){
			if(polja[i][j] == Polje::Prazno) br++;
		}
	}
	
	return br==1;
}


Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer){
	int kx(0), ky(0);
	// radim bez validacije
	if(smjer == Smjerovi::Desno){
		ky = 1;
		y++;
	}
	else if(smjer == Smjerovi::Dolje){
		kx = 1;
		x++;
	}
	else if(smjer == Smjerovi::DoljeDesno){
		kx=1;
		ky=1;
		x++;
		y++;
	}
	else if(smjer == Smjerovi::DoljeLijevo){
		ky=-1;
		kx=1;
		y--;
		x++;
	}
	else if(smjer == Smjerovi::Gore){
		kx=-1;
		x--;
	}
	else if(smjer == Smjerovi::GoreDesno){
		ky=1;
		kx=-1;
		x--;
		y++;
	}
	else if(smjer == Smjerovi::GoreLijevo){
		kx=-1;
		ky=-1;
		y--;
		x--;
	}
	else if(smjer == Smjerovi::Lijevo){
		ky=-1;
		y--;
	}
	
	
	if( VanTable(x,y,(int)polja.size()) ){
		x-=kx;
		y-=ky;
		throw std::out_of_range("Izlazak van igrace table");
	}
	if(Bl_okirano_Po_lja(polja, x, y)){
		throw std::logic_error("Blokirano polje");
	}
	if(x < polja.size() && y < polja.size()) polja[x-kx][y-ky] = Polje::Posjeceno;
	
	if(polja[x][y] == Polje::Mina){
		//std::vector<std::vector<int>> temp;
		//polja = KreirajIgru((int)polja.size(), temp);
		return Status::KrajPoraz;
	}
	else if(PobjedioUIgri(polja)) return Status::KrajPobjeda;
	else return Status::NijeKraj;
}

Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y){
	if(VanTable(novi_x, novi_y, (int)polja.size() )) throw std::out_of_range("Izlazak van igrace table");
	if(Bl_okirano_Po_lja(polja, novi_x,novi_y)) throw std::logic_error("Blokirano polje");
	if(x < polja.size() && y < polja.size()) polja[x][y] = Polje::Posjeceno;
	x=novi_x;
	y=novi_y;
	if(polja[x][y] == Polje::Mina){
		return Status::KrajPoraz;
	}
	else if(PobjedioUIgri(polja)) return Status::KrajPobjeda;
	else return Status::NijeKraj;
}
//______________________________________________________________________________

int main (){
	try{
		Komande komanda;
		Tabla polja;
		int x(0),y(0);
		Smjerovi p_smjer;
		KodoviGresaka greska;
		int p_x(0), p_y(0);
		while(1){
			std::cout <<"Unesite komandu: ";
			if(UnosKomande(komanda,p_smjer,p_x,p_y,greska) ){
				IzvrsiKomandu(komanda,polja,x,y,p_smjer,p_x,p_y);
			
			}
			else PrijaviGresku(greska);
		}
	}
	catch(std::runtime_error a){
		std::cout << a.what() << std::endl;
	}
	return 0;
}