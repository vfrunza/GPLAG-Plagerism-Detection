/*B 2017/2018, Zadaća 2, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na forum (c2).
*/
#include <iostream>
#include <cmath>
#include <vector>
#include <stdexcept>

enum class Polje {
	Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina
};
typedef std::vector<std::vector<Polje>> Tabla;
enum class Smjerovi {
	GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo
};
enum class Status {
	NijeKraj, KrajPoraz, KrajPobjeda
};
enum class Komande {
	PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru
};
enum class KodoviGresaka {
	PogresnaKomanda, NedostajeParametar, NeispravanParametar, SuvisanParametar
};

Tabla KreirajIgru (int n, const std::vector<std::vector<int>> &mine); //
std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y); //
void BlokirajPolje(Tabla &polja, int x, int y); //
void DeblokirajPolje (Tabla &polja, int x, int y); //
Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer); //
Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y); //
bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska); //
//void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer=Smjerovi::Gore, int p_x=0, int p_y=0);

Tabla KreirajIgru (int n, const std::vector<std::vector<int>> &mine) {
	if(n<=0) throw std::domain_error("Ilegalna veličina");
	for(int i=0;i<n;i++) {
		if(mine[i].size()!=2) throw std::domain_error("Ilegalan format zadavanja mina");
	}
	Tabla t;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++) {
			t[i][j]=Polje::Prazno;
		}
	}
	for(int i=0;i<mine.size();i++) { //redovi po glavnom vektoru za mine
		for(int k=0;k<n;k++){ //po tabli redovi
			for(int l=0;l<n;l++) { //po tabli kolone
				if(i>n || n<2) throw std::overflow_error("Ilegalne pozicije mina");
				if(mine[i][0]==k && mine[i][1]==l) {
					t[k][l]=Polje::Mina;
				}
			}
		}
	}
	return t;
}

std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y){
	if(x>polja.size() || y>polja.at(0).size()) throw std::domain_error("Polje (x,y) ne postoji");
	std::vector<std::vector<int>> mat; int br=0;
	mat.resize(3); mat[0].resize(3); mat[1].resize(3); mat[2].resize(3);
	for(int i=0;i<polja.size();i++){
		 br=0;
		for(int j=0;j<polja[i].size();j++) {
			for(int l=x-1; l<=x+1;l++) {
				for(int k=y-1;k<=y+1;k++) {
					if((i!=x && y!=y) && l<=i && k<=j && polja[l][k]==Polje::Mina) br++;
				}
			}
			mat[i][j]=br;
		}
	}
	return mat;
}

void BlokirajPolje(Tabla &polja, int x, int y) {
	if(x>polja.size() || y>polja[x].size()) throw std::domain_error("Polje (x,y) ne postoji");
	if(polja[x][y]==Polje::Prazno) polja[x][y]=Polje::BlokiranoPrazno;
	else if(polja[x][y]==Polje::Posjeceno) polja[x][y]=Polje::BlokiranoPosjeceno;
	else if(polja[x][y]==Polje::Mina) polja[x][y]=Polje::BlokiranoMina;
}

void DeblokirajPolje(Tabla &polja, int x, int y) {
	if(x>polja.size() || y>polja[0].size()) throw std::domain_error("Polje (x,y) ne postoji");
	else if(polja[x][y]==Polje::BlokiranoPrazno) polja[x][y]=Polje::Prazno;
	else if(polja[x][y]==Polje::BlokiranoPosjeceno) polja[x][y]=Polje::Posjeceno;
	else if(polja[x][y]==Polje::BlokiranoMina) polja[x][y]=Polje::Mina;
}

Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer) {
	polja.at(x).at(y)=Polje::Posjeceno;
	if(smjer==Smjerovi::GoreLijevo) {
		x-=1;
		y-=1;
	}
	else if(smjer==Smjerovi::Gore) x-=1;
	else if(smjer==Smjerovi::GoreDesno) {
		x-=1;
		y+=1;
	}
	else if(smjer==Smjerovi::Lijevo) y-=1;
	else if(smjer==Smjerovi::Desno) y+=1;
	else if(smjer==Smjerovi::Dolje) x+=1;
	else if(smjer==Smjerovi::DoljeDesno) {
		x+=1;
		y+=1;
	}
	else if(smjer==Smjerovi::DoljeLijevo) {
		x+=1;
		y-=1;
	}
}

Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y) {
	Status kraj;
	if(x>polja.size() || y>polja[x].size()) throw std::out_of_range("Izlazak van igrace table");
	if(polja[novi_x][novi_y]==Polje::BlokiranoPosjeceno || polja[novi_x][novi_y]==Polje::BlokiranoPrazno) throw std::logic_error("Blokirano polje");
	if(polja[novi_x][novi_y]==Polje::Mina){
		for(int i=0;i<polja.size();i++)
			for(int j=0;j<polja[i].size();j++)
				polja[i][j]=Polje::Prazno;
		return kraj=Status::KrajPoraz;
	}
	bool pobjeda(0);
	for(int i=0;i<polja.size();i++) {
		for(int j=0;j<polja[i].size();j++) {
			if(polja[i][j]==Polje::Posjeceno && polja[i][j]!=Polje::Mina && polja[i][j]!=Polje::Prazno)
				pobjeda=1;
			else if(polja[i][j]!=Polje::Posjeceno || polja[i][j]==Polje::Mina || polja[i][j]==Polje::Prazno) {
				pobjeda=0;
				break;
			}
		}
	}
	if(pobjeda) return kraj=Status::KrajPobjeda;
	return kraj=Status::NijeKraj;
}

void PrijaviGresku(KodoviGresaka kod) {
	if(kod==KodoviGresaka::PogresnaKomanda) std::cout<<"Nerazumljiva komanda!"<<std::endl;
	else if(kod==KodoviGresaka::NedostajeParametar) std::cout<<"Komanda trazi parametar koji nije naveden!"<<std::endl;
	else if(kod==KodoviGresaka::NeispravanParametar) std::cout<<"Parametar komande nije ispravan!"<<std::endl;
	else if(kod==KodoviGresaka::SuvisanParametar) std::cout<<"Zadan je suvisan parametar nakon komande!"<<std::endl;
}

bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska) {
	char prvi(std::cin.get()),slj,drugi,treci,cetvrti,peti,sesti,sedmi;
	if(prvi=='P') {
		drugi=std::cin.get();
		if(drugi=='1' || drugi=='>' || drugi=='O') {
				if (drugi=='1') {
					komanda=Komande::PomjeriJednoMjesto;
					treci=std::cin.get();
					if(treci==' ')
						while(treci==' ') std::cin.get();
					cetvrti=std::cin.get();
					if(cetvrti=='G') {
						peti=std::cin.get();
						sesti=std::cin.peek();
						if(peti==' ' ||peti=='\n') smjer=Smjerovi::Gore;
						else if(peti=='L' && (sesti==' '|| sesti=='\n')) smjer=Smjerovi::GoreLijevo;
						else if(peti=='D' && (sesti==' ' || sesti=='\n')) smjer=Smjerovi::GoreDesno;
						else greska=KodoviGresaka::SuvisanParametar;
					}
					if(cetvrti=='D'){
						peti=std::cin.get();
						char sedmi=std::cin.peek();
						if(peti==' ') smjer=Smjerovi::Desno;
						else if(peti=='o' && sesti==' ') smjer=Smjerovi::Dolje;
						
						else if(peti=='o' && sesti=='D' && (sedmi==' ' || sedmi=='\n')) smjer=Smjerovi::DoljeDesno;
						else if(peti=='o' && sesti=='L' && (sedmi==' ' || sedmi=='\n')) smjer=Smjerovi::DoljeLijevo;
						else greska=KodoviGresaka::SuvisanParametar;
					}
					if(cetvrti=='L') {
						peti=std::cin.peek();
						if(peti==' ') smjer=Smjerovi::Lijevo;
						else greska=KodoviGresaka::SuvisanParametar;
					}
					else greska=KodoviGresaka::NedostajeParametar;
					komanda=Komande::PomjeriJednoMjesto;
				}
				else if(drugi=='>') {
					treci=std::cin.get();
					if(treci==' ') {
						while(treci==' ') std::cin.get();
					cetvrti=std::cin.get();
					if(cetvrti>='0' && cetvrti<='9') {
						x=cetvrti;
						char sl(std::cin.get());
						while(sl>='0' && sl<='9') {
							x=sl;
							sl=std::cin.get();
							if(sl==' ') {
								while(sl==' ') {
									sl=std::cin.get();
									if(sl>='0'&& sl<='9') {
										y=sl;
										while(sl>='0'&&sl<='9') {
											y=sl;
											sl=std::cin.get();
										}
									}
									else greska=KodoviGresaka::PogresnaKomanda;
								}
							}
						}
					}
					else greska=KodoviGresaka::PogresnaKomanda;
					}
				komanda=Komande::PomjeriDalje;
				}
				else if(drugi=='O') {
					if(std::cin.peek()==' '|| std::cin.peek()=='\n') komanda=Komande::PrikaziOkolinu;
				}
				else greska=KodoviGresaka::PogresnaKomanda;
		}
		greska=KodoviGresaka::SuvisanParametar;
	}
	else if(prvi=='B' || prvi=='D') {
		slj=std::cin.get();
		if(slj==' ') {
			while(slj==' ') {
				slj=std::cin.get();
			}
			if(slj>='0'&&slj<='9') {
				x=slj;
				while(slj>='0'&&slj<='9') {
					x=slj;
				}
				if(slj==' '){
					while(slj==' ') {
						slj=std::cin.get();
					}
					if(slj>='0' && slj<='9') {
						y=slj;
						while(slj>='0' && slj<='9') {
							y=slj;
						}
					}
					else greska=KodoviGresaka::PogresnaKomanda;
				}
			}
			else greska=KodoviGresaka::PogresnaKomanda;
		}
		else greska=KodoviGresaka::SuvisanParametar;
	}
	else if(prvi=='Z'){
		slj=std::cin.peek();
		if(slj==' ' || slj=='\n') komanda=Komande::ZavrsiIgru;
		else greska=KodoviGresaka::SuvisanParametar;
	}
	else if(prvi=='K'){
		slj=std::cin.peek();
		if(slj==' '|| slj=='\n') komanda=Komande::KreirajIgru;
		else greska=KodoviGresaka::SuvisanParametar;
	}
	
	if(greska==KodoviGresaka::SuvisanParametar || greska==KodoviGresaka::NedostajeParametar|| greska==KodoviGresaka::NeispravanParametar)
		return false;
	return true;
}

void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer=Smjerovi::Gore, int p_x=0, int p_y=0) {
	Status rez;
	bool pom_kraj(false);
	try{
	if(komanda==Komande::PomjeriJednoMjesto && p_smjer==Smjerovi::Gore && (p_x!=0 ||p_y!=0)) rez=Idi(polja,x,y,p_x,p_y);
	//else if(komanda==Komande::PomjeriJednoMjesto && p_x==0 && p_y==0)	rez=Idi(polja,x,y,p_smjer);
	if(rez==Status::KrajPobjeda) std::cout<<"Bravo obisli ste sva sigurna polja"<<std::endl;
	else if(rez==Status::KrajPoraz) {
		std::cout<<"Nagazili ste na minu"<<std::endl;
		pom_kraj=true;
	}
	else if(komanda==Komande::PrikaziOkolinu) {
		std::vector<std::vector<int>> mat(PrikaziOkolinu(polja,x,y));
		for(int i=0;i<mat.size();i++) {
			for(int j=0;j<mat[i].size();j++) {
				std::cout<<mat[i][j]<<" ";
			}
			std::cout<<std::endl;
		}
	}
	else if(komanda==Komande::Blokiraj) {
		BlokirajPolje(polja,x,y);
	}
	else if(komanda==Komande::Deblokiraj) {
		DeblokirajPolje(polja,x,y);
	}
	else if(komanda==Komande::ZavrsiIgru || pom_kraj==true) {
		for(int i=0;i<polja.size();i++){
			for(int j=0;j<polja[i].size();j++) {
				polja[i][j]=Polje::Prazno;
			}
		}
		throw std::runtime_error("Igra zavrsena");
	}
	else if(komanda==Komande::KreirajIgru) {
		int n;
		std::cout<<"Unesite broj polja: ";
		while(!(std::cin>>n)) {
			std::cout<<"Greska, unesite ponovo!"<<std::endl;
			std::cin.clear();
			std::cin.ignore(1000,'\n');
		}
		std::cout<<"Unesite pozicije mina: ";
		char znak;
		bool g(0);
		while((znak=std::cin.get())!='.') {
			if(znak==' ') {
				while(znak==' ') znak=std::cin.get();
			}
			if(znak=='(') {
				if(znak=std::cin.get()==' ') {
					while((znak=std::cin.get())==' ') znak=std::cin.get();
					if(znak>='0' && znak<='9') {
						x=znak;
						znak=std::cin.get();
						while(znak>='0' && znak<='9') x=znak;
						if(znak==' ') 
							while(znak==' ') znak=std::cin.get();
						if(znak==',') {
							znak=std::cin.get();
							if(znak==' ') 
								while(znak==' ') znak=std::cin.get();
						if(znak>='0' && znak<='9') {
								y=znak;
								znak=std::cin.get();
								while(znak>='0'&& znak<='9') {
									y=znak;
									znak=std::cin.get();
								}
								if(znak==' ') {
									while(znak==' ') znak=std::cin.get();
								}															
						}
						else g=true;
						}
						else g=true;
				}
				else g=true;
			}
			else g=true;
		}
		if(g) std::cout<<"Greska, unesite ponovo!"<<std::endl;
		}
	}
	if(p_x!=x || p_y!=y) std::cout<<"Tekuća pozicija igrača je ("<<x<<","<<y<<")"<<std::endl;
	}
	catch(std::exception izuzetak){
		std::cout<<izuzetak.what();
	}
}

int main ()
{
	try{
	std::cout<<"Unesite komandu: ";
	if(UnosKomande) IzvrsiKomandu;
	else PrijaviGresku;
	}
	catch(...) {
		std::cout<<"Dovidjenja!";
		return 0;
	}
	return 0;
}