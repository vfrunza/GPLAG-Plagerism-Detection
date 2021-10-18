/*B 16/17, Zadaća 2, Zadatak 1
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
	
*/
#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include <cstring>
#include <iomanip>

enum class Polje{
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

typedef std::vector<std::vector<Polje> > Tabla;

Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine){
	Tabla tabla(n);
	for(int i=0;i<n;i++){
		tabla[i].resize(n, Polje::Prazno);
	}
	for(int i=0;i<mine.size();i++){
		if(mine[i].size()!=2)throw std::domain_error("Ilegalan format zadavanja mina");
		if(mine[i][0]<0 || mine[i][0]>=n || mine[i][1]<0 || mine[i][1]>=n)throw std::domain_error("Ilegalne pozicije mina");
		tabla[mine[i][0]][mine[i][1]]=Polje::Mina;
	}
	return tabla;
}

int dajbrojmina(const Tabla &polja, int x, int y){
	int pox[3]={-1, 0, 1};
	int poy[3]={-1, 0, 1};
	int n=polja.size();
	int rjes=0;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(i==1 && j==1)continue;
			int xi=x+pox[i];
			int yi=y+poy[j];
			if(!(xi<0 || yi<0 || xi>=n || yi>=n)){
				if(polja[xi][yi]==Polje::Mina)rjes++;
			}
		}
	}
	return rjes;
}

std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y){
	int n=polja.size();
	if(x<0 || y<0 || x>=n || y>=n)throw std::domain_error("Polje ("+std::to_string(x)+","+std::to_string(y)+") ne postoji");
	std::vector<std::vector<int>> rjes{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
	int pox[3]={-1, 0, 1};
	int poy[3]={-1, 0, 1};
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			int xi=x+pox[i];
			int yi=y+poy[j];
			rjes[i][j]=dajbrojmina(polja, xi, yi);
		}
	}
	return rjes;
}

void BlokirajPolje(Tabla &polja, int x, int y){
	int n=polja.size();
	if(x<0 || y<0 || x>=n || y>=n)throw std::domain_error("Polje ("+std::to_string(x)+","+std::to_string(y)+") ne postoji");
	if(polja[x][y]==Polje::Mina)polja[x][y]=Polje::BlokiranoMina;
	if(polja[x][y]==Polje::Prazno)polja[x][y]=Polje::BlokiranoPrazno;
	if(polja[x][y]==Polje::Posjeceno)polja[x][y]=Polje::BlokiranoPosjeceno;
}

void DeblokirajPolje(Tabla &polja, int x, int y){
	int n=polja.size();
	if(x<0 || y<0 || x>=n || y>=n)throw std::domain_error("Polje ("+std::to_string(x)+","+std::to_string(y)+") ne postoji");
	if(polja[x][y]==Polje::BlokiranoMina)polja[x][y]=Polje::Mina;
	if(polja[x][y]==Polje::BlokiranoPrazno)polja[x][y]=Polje::Prazno;
	if(polja[x][y]==Polje::BlokiranoPosjeceno)polja[x][y]=Polje::Posjeceno;
}

Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer){
	int n=polja.size();
	int promx=0, promy=0;
	if(smjer==Smjerovi::GoreLijevo || smjer==Smjerovi::Gore || smjer==Smjerovi::GoreDesno){
		promx=-1;
	}
	if(smjer==Smjerovi::DoljeLijevo || smjer==Smjerovi::Dolje || smjer==Smjerovi::DoljeDesno){
		promx=1;
	}
	if(smjer==Smjerovi::GoreLijevo || smjer==Smjerovi::Lijevo || smjer==Smjerovi::DoljeLijevo){
		promy=-1;
	}
	if(smjer==Smjerovi::GoreDesno || smjer==Smjerovi::Desno || smjer==Smjerovi::DoljeDesno){
		promy=1;
	}
	promx+=x;
	promy+=y;
	if(promx<0 || promy<0 || promx>=n || promy>=n)throw std::out_of_range("Izlazak van igrace table");
	if(polja[promx][promy]==Polje::BlokiranoMina || polja[promx][promy]==Polje::BlokiranoPosjeceno || polja[promx][promy]==Polje::BlokiranoPrazno){
		throw std::logic_error("Blokirano polje");
	}
	polja[x][y]=Polje::Posjeceno;
	x=promx;
	y=promy;
	if(polja[x][y]==Polje::Mina){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				polja[i][j]=Polje::Prazno;
			}
		}
		return Status::KrajPoraz;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if((i!=x || j!=y) && polja[i][j]==Polje::Prazno)return Status::NijeKraj;
		}
	}
	return Status::KrajPobjeda;
}

Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y){
	int n=polja.size();
	int promx=novi_x;
	int promy=novi_y;
	if(promx<0 || promy<0 || promx>=n || promy>=n)throw std::out_of_range("Izlazak van igrace table");
	if(polja[promx][promy]==Polje::BlokiranoMina || polja[promx][promy]==Polje::BlokiranoPosjeceno || polja[promx][promy]==Polje::BlokiranoPrazno){
		throw std::logic_error("Blokirano polje");
	}
	polja[x][y]=Polje::Posjeceno;
	x=promx;
	y=promy;
	if(polja[x][y]==Polje::Mina){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				polja[i][j]=Polje::Prazno;
			}
		}
		return Status::KrajPoraz;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if((i!=x || j!=y) && polja[i][j]==Polje::Prazno)return Status::NijeKraj;
		}
	}
	return Status::KrajPobjeda;
}

void PrijaviGresku(KodoviGresaka a){
	if(a==KodoviGresaka::PogresnaKomanda)std::cout<<"Nerazumljiva komanda!\n";
	if(a==KodoviGresaka::NedostajeParametar)std::cout<<"Komanda trazi parametar koji nije naveden!\n";
	if(a==KodoviGresaka::SuvisanParametar)std::cout<<"Zadan je suvisan parametar nakon komande!\n";
	if(a==KodoviGresaka::NeispravanParametar)std::cout<<"Parametar komande nije ispravan!\n";
}

bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska){
	std::string s;
	std::getline(std::cin, s);
	while(s.size()!=0 && (s[0]==' ' || s[0]=='\t')){
		s.erase(s.begin());
	}
	while(s.size()!=0 && (s[int(s.size())-1]==' ' || s[int(s.size())-1]=='\t')){
		s.erase(s.end()-1);
	}
	if(s==""){
		greska=KodoviGresaka::PogresnaKomanda;
		return false;
	}
	if(s.size()==1){
		if(s=="K"){
			komanda=Komande::KreirajIgru;
			return true;
		} else
		if(s=="Z"){
			komanda=Komande::ZavrsiIgru;
			return true;
		} else {
			greska=KodoviGresaka::PogresnaKomanda;
			return false;
		} 
	}
	if(s.size()==2){
		if(s=="PO"){
			komanda=Komande::PrikaziOkolinu;
			return true;
		} else {
			greska=KodoviGresaka::PogresnaKomanda;
			return false;
		}
	}
	if(s[0]=='D' && s[1]==' '){
		int poz=2;
		int broj1=0;
		int broj2=0;
		bool minus=false;
		if(s[poz]=='-'){
			minus=true;
			poz++;
		}
		while(s[poz]>='0' && s[poz]<='9'){
			broj1*=10;
			broj1+=s[poz]-'0';
			poz++;
		}
		if(minus)broj1=-broj1;
		minus=false;
		if(s[poz]==' '){
			poz++;
			if(s[poz]=='-'){
				minus=true;
				poz++;
			}
			while(s[poz]>='0' && s[poz]<='9'){
				broj2*=10;
				broj2+=s[poz]-'0';
				poz++;
			}
			if(minus)broj2=-broj2;
			if(s[poz]==' '){
				greska=KodoviGresaka::SuvisanParametar;
				return false;
			}
			if(poz!=s.size()){
				greska=KodoviGresaka::NeispravanParametar;
				return false;
			}
			komanda=Komande::Deblokiraj;
			x=broj1;
			y=broj2;
			return true;
		} else {
			greska=KodoviGresaka::NeispravanParametar;
			return false;
		}
	}
	if(s[0]=='B' && s[1]==' '){
		int poz=2;
		int broj1=0;
		int broj2=0;
		bool minus=false;
		if(s[poz]=='-'){
			minus=true;
			poz++;
		}
		while(s[poz]>='0' && s[poz]<='9'){
			broj1*=10;
			broj1+=s[poz]-'0';
			poz++;
		}
		if(minus)broj1=-broj1;
		minus=false;
		if(s[poz]==' '){
			poz++;
			if(s[poz]=='-'){
				minus=true;
				poz++;
			}
			while(s[poz]>='0' && s[poz]<='9'){
				broj2*=10;
				broj2+=s[poz]-'0';
				poz++;
			}
			if(minus)broj2=-broj2;
			if(s[poz]==' '){
				greska=KodoviGresaka::SuvisanParametar;
				return false;
			}
			if(poz!=s.size()){
				greska=KodoviGresaka::NeispravanParametar;
				return false;
			}
			komanda=Komande::Blokiraj;
			x=broj1;
			y=broj2;
			return true;
		} else {
			greska=KodoviGresaka::NeispravanParametar;
			return false;
		}
	}
	
	
	if(s[0]=='P' && s[1]=='>' && s[2]==' '){
		int poz=3;
		int broj1=0;
		int broj2=0;
		bool minus=false;
		if(s[poz]=='-'){
			minus=true;
			poz++;
		}
		while(s[poz]>='0' && s[poz]<='9'){
			broj1*=10;
			broj1+=s[poz]-'0';
			poz++;
		}
		if(minus)broj1=-broj1;
		minus=false;
		if(s[poz]==' '){
			poz++;
			if(s[poz]=='-'){
				minus=true;
				poz++;
			}
			while(s[poz]>='0' && s[poz]<='9'){
				broj2*=10;
				broj2+=s[poz]-'0';
				poz++;
			}
			if(minus)broj2=-broj2;
			if(s[poz]==' '){
				greska=KodoviGresaka::SuvisanParametar;
				return false;
			}
			if(poz!=s.size()){
				greska=KodoviGresaka::NeispravanParametar;
				return false;
			}
			komanda=Komande::PomjeriDalje;
			x=broj1;
			y=broj2;
			return true;
		} else {
			greska=KodoviGresaka::NeispravanParametar;
			return false;
		}	
	} 
	
	if(s[0]=='P' && s[1]=='1' && s[2]==' '){
		if(s=="P1 GL"){
			smjer=Smjerovi::GoreLijevo;
			komanda=Komande::PomjeriJednoMjesto;
			return true;
		} else if(s=="P1 G"){
			smjer=Smjerovi::Gore;
			komanda=Komande::PomjeriJednoMjesto;
			return true;
		} else if(s=="P1 GD"){
			smjer=Smjerovi::GoreDesno;
			komanda=Komande::PomjeriJednoMjesto;
			return true;
		} else if(s=="P1 D"){
			smjer=Smjerovi::Desno;
			komanda=Komande::PomjeriJednoMjesto;
			return true;
		} else if(s=="P1 DoD"){
			smjer=Smjerovi::DoljeDesno;
			komanda=Komande::PomjeriJednoMjesto;
			return true;
		} else if(s=="P1 Do"){
			smjer=Smjerovi::Dolje;
			komanda=Komande::PomjeriJednoMjesto;
			return true;
		} else if(s=="P1 DoL"){
			smjer=Smjerovi::DoljeLijevo;
			komanda=Komande::PomjeriJednoMjesto;
			return true;
		} else if(s=="P1 L"){
			smjer=Smjerovi::Lijevo;
			komanda=Komande::PomjeriJednoMjesto;
			return true;
		} else {
			greska=KodoviGresaka::NeispravanParametar;
			return false;
		}
	} 
	
	greska=KodoviGresaka::PogresnaKomanda;
	return false;
}

void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer = Smjerovi::Gore, int p_x = 0, int p_y = 0){
	if(komanda==Komande::KreirajIgru){
		std::vector<std::vector<int> > a;
		int n;
		std::cout<<"Unesite broj polja: ";
		std::cin>>n>>std::ws;
		std::cout<<"Unesite pozicije mina: ";
		do{
			std::string unos;
			std::getline(std::cin, unos);
			while(unos.size()!=0 && (unos[int(unos.size())-1]==' ' || unos[int(unos.size())-1]=='\t')){
				unos.erase(unos.end()-1);
			}
			if(unos==".")break;
			int poz=0;
			if(unos[0]!='('){
				std::cout<<"Greska, unesite ponovo!\n";
				continue;
			}
			poz++;
			int broj1=-1;
			int broj2=-1;
			while(unos[poz]>='0' && unos[poz]<='9'){
				if(broj1==-1)broj1=0;
				broj1*=10;
				broj1+=unos[poz]-'0';
				poz++;
			}
			if(unos[poz]==','){
				poz++;
				while(unos[poz]>='0' && unos[poz]<='9'){
					if(broj2==-1)broj2=0;
					broj2*=10;
					broj2+=unos[poz]-'0';
					poz++;
				}
				if(unos[poz]!=')'){
					std::cout<<"Greska, unesite ponovo!\n";
					continue;
				}
				poz++;
				if(broj1<0 || broj2<0 || broj1>=n || broj2>=n || poz!=unos.size()){
					std::cout<<"Greska, unesite ponovo!\n";
					continue;
				}
				a.push_back(std::vector<int>{broj1, broj2});
			} else {
				std::cout<<"Greska, unesite ponovo!\n";
				continue;
			}
		}while(true);
		polja=KreirajIgru(n, a);
	}
	if(komanda==Komande::PomjeriDalje){
		try{
			Status st=Idi(polja, x, y, p_x, p_y);
			std::cout<<"Tekuca pozicija igraca je ("+std::to_string(x)+","+std::to_string(y)+")\n";
			if(st==Status::KrajPoraz){
				std::cout<<"Nagazili ste na minu\n";
				for(int i=0;i<polja.size();i++){
					for(int j=0;j<polja[i].size();j++){
						polja[i][j]=Polje::Prazno;
					}
				}
				throw std::runtime_error("Igra zavrsena");
			}
			if(st==Status::KrajPobjeda){
				std::cout<<"Bravo, obisli ste sva sigurna polja\n";
				for(int i=0;i<polja.size();i++){
					for(int j=0;j<polja[i].size();j++){
						polja[i][j]=Polje::Prazno;
					}
				}
				throw std::runtime_error("Igra zavrsena");
			}
		}
		catch(std::out_of_range g){
			std::cout<<g.what()<<"\n";
		}
		catch(std::logic_error g){
			std::cout<<g.what()<<"\n";
		}
	}
	if(komanda==Komande::PomjeriJednoMjesto){
		try{
			Status st=Idi(polja, x, y, p_smjer);
			std::cout<<"Tekuca pozicija igraca je ("+std::to_string(x)+","+std::to_string(y)+")\n";
			if(st==Status::KrajPoraz){
				std::cout<<"Nagazili ste na minu\n";
				for(int i=0;i<polja.size();i++){
					for(int j=0;j<polja[i].size();j++){
						polja[i][j]=Polje::Prazno;
					}
				}
				throw std::runtime_error("Igra zavrsena");
			}
			if(st==Status::KrajPobjeda){
				std::cout<<"Bravo, obisli ste sva sigurna polja\n";
				for(int i=0;i<polja.size();i++){
					for(int j=0;j<polja[i].size();j++){
						polja[i][j]=Polje::Prazno;
					}
				}
				throw std::runtime_error("Igra zavrsena");
			}
		}
		catch(std::out_of_range g){
			std::cout<<g.what()<<"\n";
		}
		catch(std::logic_error g){
			std::cout<<g.what()<<"\n";
		}
	}
	if(komanda==Komande::Blokiraj){
		try{
			BlokirajPolje(polja, p_x, p_y);
		}
		catch(std::domain_error g){
			std::cout<<g.what()<<"\n";
		}
	}
	if(komanda==Komande::Deblokiraj){
		try{
			DeblokirajPolje(polja, p_x, p_y);
		}
		catch(std::domain_error g){
			std::cout<<g.what()<<"\n";
		}
	}
	if(komanda==Komande::ZavrsiIgru){
		for(int i=0;i<polja.size();i++){
			for(int j=0;j<polja[i].size();j++){
				polja[i][j]=Polje::Prazno;
			}
		}
		throw std::runtime_error("Igra zavrsena");
	}
	if(komanda==Komande::PrikaziOkolinu){
		auto ff=PrikaziOkolinu(polja, x, y);
		for(auto i:ff){
			for(auto j:i){
				std::cout<<j<<" ";
			}
			std::cout<<"\n";
		}
	}
}

int main ()
{
	int x=0, y=0;
	int trenx=0, treny=0;
	Komande kom=Komande::KreirajIgru;
	Smjerovi smjer=Smjerovi::Gore;
	KodoviGresaka kod=KodoviGresaka::PogresnaKomanda;
	Tabla tabla;
	do{
		std::cout<<"Unesite komandu: ";
		bool ff=UnosKomande(kom, smjer, x, y, kod);
		if(ff){
			if(tabla.size()==0 && kom!=Komande::KreirajIgru)PrijaviGresku(KodoviGresaka::PogresnaKomanda); else {
				try{
					IzvrsiKomandu(kom, tabla, trenx, treny, smjer, x, y);
				}
				catch(std::runtime_error g){
					std::cout<<"Dovidjenja!";
					break;
				}
			}
		} else {
			PrijaviGresku(kod);
		}
	}while(true);
	return 0;
}