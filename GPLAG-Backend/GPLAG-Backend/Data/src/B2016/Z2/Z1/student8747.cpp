/*B 16/17, Zadaća 2, Zadatak 1
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
	
*/
#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>

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

Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine){
	Tabla mat(n,std::vector<Polje>(n,Polje::Prazno));
	for(int i=0;i<mine.size();i++){
		if(mine[i].size()!=2) throw std::domain_error("Ilegalan format zadavanja mina");
		if(mine[i][1]>=n || mine[i][0]>=n) throw std::domain_error("Ilegalne pozicije mine");
		mat[mine[i][0]][mine[i][1]]=Polje::Mina;
	}
	return mat;
}

std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y){
	std::string s="Polje (";
	s+=(x+'0');
	s+=',';
	s+=(y+'0');
	s+=") ne postoji";
	if(x>=polja.size() || y>=polja.size() || x<0 || y<0) throw std::domain_error(s);
	std::vector<std::vector<int>> mat(3,std::vector<int>(3));
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			int a=x-1+i,b=y-1+j;
			int brojac(0);
			if((a-1>=0 && a-1<polja.size()) && (b-1>=0 && b-1<polja.size()) && polja[a-1][b-1]==Polje::Mina) brojac++;
			if((a-1>=0 && a-1<polja.size()) && (b>=0 && b<polja.size()) && polja[a-1][b]==Polje::Mina) brojac++;
			if((a-1>=0 && a-1<polja.size()) && (b+1>=0 && b+1<polja.size()) && polja[a-1][b+1]==Polje::Mina) brojac++;
			if((a>=0 && a<polja.size()) && (b-1>=0 && b-1<polja.size()) && polja[a][b-1]==Polje::Mina) brojac++;
			if((a>=0 && a<polja.size()) && (b+1>=0 && b+1<polja.size()) && polja[a][b+1]==Polje::Mina) brojac++;
			if((a+1>=0 && a+1<polja.size()) && (b-1>=0 && b-1<polja.size()) && polja[a+1][b-1]==Polje::Mina) brojac++;
			if((a+1>=0 && a+1<polja.size()) && (b>=0 && b<polja.size()) && polja[a+1][b]==Polje::Mina) brojac++;
			if((a+1>=0 && a+1<polja.size()) && (b+1>=0 && b+1<polja.size()) && polja[a+1][b+1]==Polje::Mina) brojac++;
			mat[i][j]=brojac;
		}
	}
	return mat;
}

void BlokirajPolje(Tabla &polja, int x, int y){
	std::string s="Polje (";
	s+=(x+'0');
	s+=',';
	s+=(y+'0');
	s+=") ne postoji";
	if(x>=polja.size() || x<0 || y>=polja.size() || y<0) throw std::domain_error(s);
	if(polja[x][y]==Polje::Prazno) polja[x][y]=Polje::BlokiranoPrazno;
	else if(polja[x][y]==Polje::Posjeceno) polja[x][y]=Polje::BlokiranoPosjeceno;
	else if(polja[x][y]==Polje::Mina) polja[x][y]=Polje::BlokiranoMina;
}

void DeblokirajPolje(Tabla &polja, int x, int y){
	std::string s="Polje ("; s+=(x+'0'); s+=','; s+=(y+'0'); s+=") ne postoji";
	if(x>=polja.size() || x<0 || y>=polja.size() || y<0) throw std::domain_error(s);
	if(polja[x][y]==Polje::BlokiranoPrazno) polja[x][y]=Polje::Prazno;
	else if(polja[x][y]==Polje::BlokiranoPosjeceno) polja[x][y]=Polje::Posjeceno;
	else if(polja[x][y]==Polje::BlokiranoMina) polja[x][y]=Polje::Mina;
}

Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer){
	int a(x),b(y);
	if(smjer==Smjerovi::Gore) a--;
	else if(smjer==Smjerovi::GoreDesno){ a--;b++;}
	else if(smjer==Smjerovi::GoreLijevo) {a--;b--;}
	else if(smjer==Smjerovi::Desno) b++;
	else if(smjer==Smjerovi::Lijevo) b--;
	else if(smjer==Smjerovi::DoljeDesno){a++;b++;}
	else if(smjer==Smjerovi::Dolje) a++;
	else if(smjer==Smjerovi::DoljeLijevo){a++;b--;}
	if(a<0 || a>=polja.size() || b<0 || b>=polja.size()) throw std::out_of_range("Izlazak van igrace table");
	if(polja[a][b]==Polje::BlokiranoPosjeceno || polja[a][b]==Polje::BlokiranoPrazno || polja[a][b]==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
	polja[x][y]=Polje::Posjeceno;
	x=a;y=b;
	if(polja[x][y]==Polje::Mina){
		for(int i=0;i<polja.size();i++){
			for(int j=0;j<polja[i].size();j++) polja[i][j]=Polje::Prazno;
		}
		return Status::KrajPoraz;
	}
	else if(polja[x][y]==Polje::Prazno || polja[x][y]==Polje::Posjeceno){
		bool ImaLiPrazno=true;
		for(int i=0;i<polja.size();i++){
			for(int j=0;j<polja[i].size();j++){
				if(polja[i][j]==Polje::Prazno && i!=a && j!=b) ImaLiPrazno=false;
			}
		}
		if(ImaLiPrazno) return Status::KrajPobjeda;
	}
	return Status::NijeKraj;
}

Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y){
	if(novi_x<0 || novi_x>=polja.size() || novi_y<0 || novi_y>=polja.size()) throw std::out_of_range("Izlazak van igrace table");
	if(polja[novi_x][novi_y]==Polje::BlokiranoPosjeceno || polja[novi_x][novi_y]==Polje::BlokiranoPrazno || polja[novi_x][novi_y]==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
	polja[x][y]=Polje::Posjeceno;
	x=novi_x; y=novi_y;
	if(polja[x][y]==Polje::Mina){
		for(int i=0;i<polja.size();i++){
			for(int j=0;j<polja[i].size();j++) polja[i][j]=Polje::Prazno;
		}
		return Status::KrajPoraz;
	}
	else if(polja[x][y]==Polje::Prazno || polja[x][y]==Polje::Posjeceno){
		bool ImaLiPrazno=true;
		for(int i=0;i<polja.size();i++){
			for(int j=0;j<polja[i].size();j++){
				if(polja[i][j]==Polje::Prazno && i!=x && j!=y) ImaLiPrazno=false;
			}
		}
		if(ImaLiPrazno) return Status::KrajPobjeda;
	}
	return Status::NijeKraj;
}

void PrijaviGresku(KodoviGresaka x){
	if(x==KodoviGresaka::PogresnaKomanda) std::cout << "Nerazumljiva komanda!" << std::endl;
	else if(x==KodoviGresaka::NedostajeParametar) std::cout << "Komanda trazi parametar koji nije naveden!" << std::endl;
	else if(x==KodoviGresaka::NeispravanParametar) std::cout << "Parametar komande nije ispravan!" << std::endl;
	else if(x==KodoviGresaka::SuvisanParametar) std::cout << "Zadan je suvisan parametar nakon komande!" << std::endl;
}

bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska){
	std::string a;
	std::cin >> a;
	if(a=="P1"){
		komanda=Komande::PomjeriJednoMjesto;
		std::string c;
		char s;
		while(char(std::cin.peek())==' ') s=std::cin.get();
		if(char(std::cin.peek())!='\n') std::cin>> c;
		if(c.size()==0){
			greska=KodoviGresaka::NedostajeParametar;
			return false;
		}else if(c=="GL") smjer=Smjerovi::GoreLijevo;
		else if(c=="GD") smjer=Smjerovi::GoreDesno;
		else if(c=="G") smjer =Smjerovi::Gore;
		else if(c=="D") smjer=Smjerovi::Desno;
		else if(c=="DoD") smjer=Smjerovi::DoljeDesno;
		else if(c=="Do") smjer=Smjerovi::Dolje;
		else if(c=="DoL") smjer=Smjerovi::DoljeLijevo;
		else if(c=="L") smjer=Smjerovi::Lijevo;
		else {
			greska=KodoviGresaka::NeispravanParametar;
			return false;
		}
		std::string kraj;
		while(char(std::cin.peek())==' ') s=std::cin.get();
		if(char(std::cin.peek())!='\n') std::cin>> kraj;
		if(kraj.size()>0) {
			greska=KodoviGresaka::SuvisanParametar;
			return false;
		}
	}else if(a=="P>" || a=="B" || a=="D"){
		if(a=="P>")
		komanda=Komande::PomjeriDalje;
		else if(a=="B") komanda=Komande::Blokiraj;
		else if(a=="D") komanda=Komande::Deblokiraj;
		int a1(0),b(0);
		std::string broj1,broj2;
		char slovo;
		while(char(std::cin.peek())==' ') slovo=std::cin.get();
		if(char(std::cin.peek())!='\n') std::cin >> broj1;
		if(broj1.size()==0){
			greska=KodoviGresaka::NedostajeParametar;
			return false;
		}
		for(int i=0;i<broj1.size();i++){
			if(broj1[i]>='0' && broj1[i]<='9') a1=a1*10+(broj1[i]-'0');
			else{
				greska=KodoviGresaka::NeispravanParametar;
				return false;
			}
		}
		x=a1;
		while(char(std::cin.peek())==' ') slovo=std::cin.get();
		if(char(std::cin.peek())!='\n') std::cin >> broj2;
		if(broj2.size()==0){
			greska=KodoviGresaka::NedostajeParametar;
			return false;
		}
		for(int i=0;i<broj2.size();i++){
			if(broj2[i]>='0' && broj2[i]<='9') b=b*10+(broj2[i]-'0');
			else{
				greska=KodoviGresaka::NeispravanParametar;
				return false;
			}
		}
		y=b;
		std::string kraj;
		while(char(std::cin.peek())==' ') slovo=std::cin.get();
		if(char(std::cin.peek())!='\n') std::cin >> kraj;
		if(kraj.size()>0){
			greska=KodoviGresaka::SuvisanParametar;
			return false;
		}
	}else if(a=="PO" || a=="Z" || a=="K"){
		if(a=="PO") komanda=Komande::PrikaziOkolinu;
		else if(a=="Z") komanda=Komande::ZavrsiIgru;
		else if(a=="K") komanda=Komande::KreirajIgru;
		char slovo=std::cin.get();
		while(slovo==' ') slovo=std::cin.get();
		std::string kraj;
		while(slovo!=' ' && slovo!='\n'){
			kraj.push_back(slovo);
			slovo=std::cin.get();
		}
		if(kraj.size()>0){
			greska=KodoviGresaka::SuvisanParametar;
			return false;
		}
	}else {
		greska=KodoviGresaka::PogresnaKomanda;
		return false;
	}
	return true;
}

void Zavrsi(Tabla &polja){
	for(int i=0;i<polja.size();i++){
		for(int j=0;j<polja[i].size();j++){
			polja[i][j]=Polje::Prazno;
		}
	}
	throw std::runtime_error("Igra zavrsena");
}

void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y,Smjerovi p_smjer = Smjerovi::Gore, int p_x = 0, int p_y = 0){
		if(komanda==Komande::PomjeriJednoMjesto){
			try{
				Status a=Idi(polja,x,y,p_smjer);
				if(a==Status::KrajPoraz){
					std::cout << "Nagazili ste na minu"<< std::endl;
					Zavrsi(polja);
				}else if(a==Status::KrajPobjeda){
					std::cout << "Bravo, obisli ste sva sigurna polja" << std::endl;
					Zavrsi(polja);
				}else{
					std::cout << "Tekuca pozicija igraca je (" << x << "," << y << ")" << std::endl;
				}
			}catch(std::out_of_range poruka){
				std::cout << poruka.what() << std::endl;
			}catch(std::logic_error izuzetak){
				std::cout << izuzetak.what() << std::endl;
			}
		}else if(komanda==Komande::PomjeriDalje){
			try{
				Status a =Idi(polja,x,y,p_x,p_y);
				if(a==Status::KrajPoraz){ 
					std::cout << "Nagazili ste na minu"<< std::endl;
					Zavrsi(polja);
				}
				else if(a==Status::KrajPobjeda){
					std::cout << "Bravo, obisli ste sva sigurna polja" << std::endl;
					Zavrsi(polja);
				}
				else 
					std::cout << "Tekuca pozicija igraca je (" << x << "," << y << ")" << std::endl;
			}catch(std::out_of_range poruka){
				std::cout << poruka.what() << std::endl;
			}catch(std::logic_error izuzetak){
				std::cout << izuzetak.what()<<std::endl;
			}
		}else if(komanda==Komande::Blokiraj){
			try{
				BlokirajPolje(polja,p_x,p_y);
			}catch(std::domain_error poruka){
				std::cout<< poruka.what()<< std::endl;
			}
		}else if(komanda==Komande::Deblokiraj){
			try{
				DeblokirajPolje(polja,p_x,p_y);
			}catch(std::domain_error izuzetak){
				std::cout << izuzetak.what() << std::endl;
			}
		}else if(komanda==Komande::PrikaziOkolinu){
			try{
				std::vector<std::vector<int>> mat=PrikaziOkolinu(polja,x,y);
				for(int i=0;i<mat.size();i++){
					for(int j=0;j<mat[i].size();j++){
						std::cout << mat[i][j] << " ";
					}
					std::cout << std::endl;
				}
			}catch(std::domain_error poruka){
				std::cout << poruka.what() << std::endl;
			}
		}else if(komanda==Komande::ZavrsiIgru){
				Zavrsi(polja);
		}else if(komanda==Komande::KreirajIgru){
			int n;
			std::cout << "Unesite broj polja: ";
			std::cin>> n;
			std::string unos;
			std::cout << "Unesite pozicije mina: ";
			std::vector<std::vector<int>> mine;
			while(1){
				std::cin >> unos;
				if(unos==".") break;
				if(unos[0]=='('&& unos[unos.size()-1]==')'){
					int brojac(0),brojac2(0);
					for(int i=1;i<unos.size()-1;i++){
						if(unos[i]==',') 
							brojac++;
						else if(!(unos[i]>='0' && unos[i]<n+'0')) brojac2++;
					}
					if(brojac!=1 || brojac2!=0) std::cout << "Greska, unesite ponovo!" << std::endl;
					else{
						int a(0),b(0);
						int i=1;
						while(unos[i]>='0' && unos[i]<='9'){
							a=a*10+(unos[i]-'0');
							i++;
						}
						i++;
						while(unos[i]>='0' && unos[i]<='9'){
							b=b*10+(unos[i]-'0');
							i++;
						}
						std::vector<int> red(2);
						red[0]=a;
						red[1]=b;
						mine.push_back(red);
					}
				}else{
					std::cout << "Greska, unesite ponovo!" << std::endl;
				}
			}
			try{
			polja=KreirajIgru(n,mine);
			}catch(std::domain_error poruka){
				std::cout << poruka.what() << std::endl;
			}
		}
}

int main ()
{
	try{
	Komande komanda;
	Smjerovi smjer;
	KodoviGresaka greska;
	Tabla polje;
	int x=0,y=0;
	for(;;){
		std::cout << "Unesite komandu: ";
		if(UnosKomande(komanda,smjer,x,y,greska)){
			 IzvrsiKomandu(komanda,polje,x,y,smjer,x,y);
		}
		else{
			PrijaviGresku(greska);
		}
	}
	}catch(std::runtime_error){
		std::cout <<"Dovidjenja!"<< std::endl;
	}
	return 0;
}