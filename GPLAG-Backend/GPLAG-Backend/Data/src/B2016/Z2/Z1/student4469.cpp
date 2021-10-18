/*B 16/17, Zadaća 2, Zadatak 1
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
	
*/
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <sstream>

enum class Polje { Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina };
typedef std::vector<std::vector<Polje>> Tabla;
enum class Smjerovi { GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo };
enum class Status { NijeKraj, KrajPoraz, KrajPobjeda };
enum class KodoviGresaka { PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar };
enum class Komande { PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru };

//FUNKCIJA KREIRA TABLU I POSTAVLJA MINE
Tabla KreirajIgru (int n, const std::vector<std::vector<int>> &mine) {
	Tabla t;
	t.resize(n);
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			t[i].push_back(Polje::Prazno);
			
	for (int i=0; i<mine.size(); i++) {
		if (mine[i].size()!=2) throw std::domain_error ("Ilegalan format zadavanja mina\n");
		for (int j=0; j<n; j++) {
			if (mine[i][0]<0 || mine[i][0]>=n) throw std::domain_error ("Ilegalne pozicije mina\n");
			if (mine[i][0]==j)
				for (int k=0; k<n; k++){
					if (mine[i][1]<0 || mine[i][1]>=n) throw std::domain_error ("Ilegalne pozicije mina\n");
					if (mine[i][1]==k) t[j][k]=Polje::Mina;
				}
		}
	}
	return t;
}

//izuzetak u stringu
std::string String_izuzetak(int x,int y){
	std::string s;
	s="Polje (";
	s+=std::to_string(x);
	s+=",";
	s+=std::to_string(y);
	s+=") ne postoji";
	return s;
}

//FUNKCIJA BLOKIRA DREDJENO POLJE (X,Y) NA TABLI, U ZAVISNOSTI OD TOGA DA LI JE POSJECENO, PRAZNO ILI MINA
void BlokirajPolje (Tabla &polja, int x, int y){
	std::string izuzetak;
	if (x<0 || y<0 || x>=polja.size() || y>=polja.size()) throw std::domain_error (String_izuzetak(x,y));
	for (int i=0; i<polja.size(); i++)
		if (x==i)
			for (int j=0; j<polja.size(); j++)
				if (y==j){
					if (polja[i][j]==Polje::Prazno) polja[i][j]=Polje::BlokiranoPrazno;
					if (polja[i][j]==Polje::Posjeceno) polja[i][j]=Polje::BlokiranoPosjeceno;
					if (polja[i][j]==Polje::Mina) polja[i][j]=Polje::BlokiranoMina;
				}
}

//FUNKCIJA DEBLOKIRA POLJE NA TABLI, U ZAVISNOSTI DA LI JE ONO BILO BLOK. PRAZNO POSJECENO ILI MINA
void DeblokirajPolje (Tabla &polja, int x, int y) {
	if (x<0 || y<0 || x>=polja.size() || y>=polja.size()) throw std::domain_error (String_izuzetak(x,y));
	for (int i=0; i<polja.size(); i++)
		if (x==i)
			for (int j=0; j<polja.size(); j++)
				if (y==j){
					if (polja[i][j]==Polje::BlokiranoPrazno) polja[i][j]=Polje::Prazno;
					if (polja[i][j]==Polje::BlokiranoPosjeceno) polja[i][j]=Polje::Posjeceno;
					if (polja[i][j]==Polje::BlokiranoMina) polja[i][j]=Polje::Mina;
				}
}

//funkcija koja cisti sva polja, tj. postavi ih na "Prazno"
void Ocisti (Tabla &polja) {
	for (int i=0; i<polja.size(); i++)
		for (int j=0; j<polja.size(); j++)
			polja[i][j]=Polje::Prazno;
}

//funkcija provjerava da li su sva mjesta bez mina posjecena, da nema ni jedno prazno
bool Pobjeda (Tabla &polja,int x, int y){
	for (int i=0; i<polja.size(); i++)
		for (int j=0; j<polja.size(); j++) {
			if (x==i && y==j);
			else if (polja[i][j]==Polje::Prazno || polja[i][j]==Polje::BlokiranoPrazno) return false;
		}
	return true;
}

//FUNKCIJA POMIJERA IGRACA SA POZICIJE (X,Y)-a njega postavi na posjeceno, pa se pomjeri za JEDNO MJESTO U ODREDJENOM SMJERU
Status Idi (Tabla &polja, int &x, int &y, Smjerovi smjer) {
	int ref1=x, ref2=y;
	polja[x][y]=Polje::Posjeceno;
	
	if (smjer==Smjerovi::GoreLijevo && (x-1>=0 && x-1<polja.size()) && (y-1>=0 && y-1<polja.size())) {x=x-1; y=y-1;}
	else if (smjer==Smjerovi::Gore && (x-1>=0 && x-1<polja.size())) {x=x-1;}
	else if (smjer==Smjerovi::GoreDesno && (x-1>=0 && x-1<polja.size()) && (y+1>=0 && y+1<polja.size())) {x=x-1; y=y+1;}
	else if (smjer==Smjerovi::Desno && (y+1>=0 && y+1<polja.size())) {y=y+1;}
	else if (smjer==Smjerovi::DoljeDesno && (x+1>=0 && x+1<polja.size()) && (y+1>=0 && y+1<polja.size())) {x=x+1; y=y+1;}
	else if (smjer==Smjerovi::Dolje && (x+1>=0 && x+1<polja.size())) {x=x+1;}
	else if (smjer==Smjerovi::DoljeLijevo && (x+1>=0 && x+1<polja.size())) {x=x+1; y=y-1;}
	else if (smjer==Smjerovi::Lijevo && (y-1>=0 && y-1<polja.size())) {y=y-1;}
	else throw std::out_of_range ("Izlazak van igrace table\n");
	
	if (polja[x][y]==Polje::BlokiranoPosjeceno || polja[x][y]==Polje::BlokiranoPrazno || polja[x][y]==Polje::BlokiranoMina) {
		x=ref1; y=ref2;
		throw std::logic_error ("Blokirano polje\n");
	} 
	
	if (polja[x][y]==Polje::Mina) { Ocisti(polja); return Status::KrajPoraz; }
	else if (Pobjeda(polja,x,y)) { Ocisti(polja); return Status::KrajPobjeda; }
	else return Status::NijeKraj;
}

//ISTA FUNKCIJA KAO PRETHODNA, SAMO OVA IMA 5 PARAMETARA, POMIJERA IGRACA NA MJESTO ZADANO PARAMETRIMA
Status Idi (Tabla &polja, int &x, int &y, int novi_x, int novi_y) {
	polja[x][y]=Polje::Posjeceno;
	if (novi_x<0 || novi_y<0 || novi_x>=polja.size() || novi_y>=polja.size()) throw std::out_of_range ("Izlazak van igrace table\n");
	else if (polja[novi_x][novi_y]==Polje::BlokiranoPosjeceno || polja[novi_x][novi_y]==Polje::BlokiranoPrazno || polja[novi_x][novi_y]==Polje::BlokiranoMina)
		throw std::logic_error ("Blokirano polje\n");
	else {
		x=novi_x;
		y=novi_y;
	}
	if (polja[x][y]==Polje::Mina) {Ocisti(polja); return Status::KrajPoraz; }
	else if (Pobjeda(polja,x,y)) {Ocisti(polja); return Status::KrajPobjeda; }
	else return Status::NijeKraj;
}

//funkcija koja odredjuje broj mina u okolini nekog polja
int BrojMina (const Tabla &polja, int a, int b){
	int mine=0;
	for (int i=a-1, m=0; m<3; i++,m++){
		for (int j=b-1,n=0; n<3; j++,n++){
			if (m==1 &&  n==1);
			else if (i>=0 && j>=0 && i<polja.size() && j<polja.size() && polja[i][j]==Polje::Mina ) mine++;
		}
	}
	return mine;
}

//FUNKCIJA KOJA ISPISUJE MATRICU 3X3, CIJI SU ELEMENTI BROJ MINA U OKOLINI TOG INDEXA
std::vector<std::vector<int>> PrikaziOkolinu (const Tabla &polja, int x, int y) {
	if (x<0 || y<0 || x>=polja.size() || y>=polja.size()) throw std::domain_error (String_izuzetak(x,y));
	std::vector<std::vector<int>> okolina(3,std::vector<int>(3));
	
	for (int i=x-1,m=0; m<3; m++,i++){
		for (int j=y-1, n=0; n<3; n++,j++){
			if (i>=0 && j>=0 && i<polja.size() && j<polja.size()) okolina[m][n]=BrojMina(polja,i,j);
			else okolina[m][n]=0;
		}
	}
	return okolina;
}

//FUNKCIJA ISPISUJE NA EKRAN KOD GRESKE KOJA JOJ SE SALJE KAO PARAMETAR
void PrijaviGresku (KodoviGresaka greska) {
	if (greska==KodoviGresaka::PogresnaKomanda) std::cout<<"Nerazumljiva komanda!\n";
	else if (greska==KodoviGresaka::NedostajeParametar) std::cout<<"Komanda trazi parametar koji nije naveden!\n";
	else if (greska==KodoviGresaka::NeispravanParametar) std::cout<<"Parametar komande nije ispravan!\n";
	else if (greska==KodoviGresaka::SuvisanParametar) std::cout<<"Zadan je suvisan parametar nakon komande!\n";
}

//FUNKCIJA ZA UNOS KOMANDE, DESIFRUJE KOMANDU I ISPITUJE DA LI JE ONA ISPRAVNA
bool UnosKomande (Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska) {
	std::string k;
	std::getline(std::cin,k);
	std::string pom,vel1,vel2;
	std::stringstream br1,br2,broj1,broj2;
	int br=0,broj=0,pomocni=0;
	for (int i=0; i<k.length(); i++){
		if (k[i]!=' ')
			for (int j=0; j<k.length() && k[j]!=' '; j++) {
				if (k[j]=='P' || k[j]=='B' || k[j]=='D' || k[j]=='Z' || k[j]=='K') {
					if (k[j]=='Z' || k[j]=='K') {
						for (int m=j+1; m<k.length(); m++)
							if (k[m]!=' ') { greska=KodoviGresaka::SuvisanParametar; return false; }
						if (k[j]=='Z') { komanda=Komande::ZavrsiIgru; return true; }
						if (k[j]=='K') { komanda=Komande::KreirajIgru; return true; }
					}
					else if (k[j]=='B' || k[j]=='D') {
						for (int m=j+1; m<k.length(); m++) {
							if (k[m]!=' ' && br==0){
								for (int n=m; n<k.length() && k[n]!=' '; n++,m++){
									if (k[n]<'0' || k[n]>'9') { greska=KodoviGresaka::NeispravanParametar; return false; }
									else vel1+=k[n];
								} br=1;
							}
							if (k[m]!=' ' && br==1){
								for (int n=m; n<k.length() && k[n]!=' '; n++,m++){
									if (k[n]<'0' || k[n]>'9') { greska=KodoviGresaka::NeispravanParametar; return false; }
									else vel2+=k[n];
								} br=2;
							}
							if (br==2)
								for (int n=m; n<k.length(); n++)
									if (k[n]!=' ') { greska=KodoviGresaka::SuvisanParametar; return false; }
						}
						if (vel1.length()==0 || vel2.length()==0) { greska=KodoviGresaka::NedostajeParametar; return false; }
						br1<<vel1;
						br1>>x;
						br2<<vel2;
						br2>>y;
						if (k[j]=='B') { komanda=Komande::Blokiraj; return true; }
						if (k[j]=='D') { komanda=Komande::Deblokiraj; return true; }
					}
					else if (k[j]=='P') {
						j++;
						if (k[j]=='O') {
							for (int o=j+1; o<k.length(); o++)
								if (k[o]!=' ') { greska=KodoviGresaka::SuvisanParametar; return false; }
							komanda=Komande::PrikaziOkolinu; return true;
						}
						else if (k[j]=='>'){
							for (int m=j+1; m<k.length(); m++) {
								if (k[m]!=' ' && broj==0) {
									for (int n=m; n<k.length() && k[n]!=' '; n++,m++) {
										if (k[n]<'0' || k[n]>'9') { greska=KodoviGresaka::NeispravanParametar; return false; }
										else vel1+=k[n];
									} broj=1;
								}
								if (k[m]!=' ' && broj==1) {
									for (int n=m; n<k.length() && k[n]!=' '; n++,m++){
										if (k[n]<'0' || k[n]>'9') { greska=KodoviGresaka::NeispravanParametar; return false; }
										else vel2+=k[n];
									}broj=2;
								}
								if (broj==2)
									for (int n=m; n<k.length(); n++)
										if (k[n]!=' ') { greska=KodoviGresaka::SuvisanParametar; return false; }
							}
							if (vel1.length()==0 || vel2.length()==0) { greska=KodoviGresaka::NedostajeParametar; return false; }
							broj1<<vel1;
							broj1>>x;
							broj2<<vel2;
							broj2>>y;
							komanda=Komande::PomjeriDalje; return true;
						}
						else if (k[j]=='1'){
							for (int r=j+1; r<k.length(); r++) {
								if (k[r]!=' ' && pomocni==0) {
									for (int s=r; s<k.length() && k[s]!=' '; s++,r++){
										if (k[s]!='G' && k[s]!='L' && k[s]!='D' && k[s]!='o') { greska=KodoviGresaka::NeispravanParametar; return false; }
										else pom+=k[s];
									}pomocni=1;
								}
								if (pomocni==1) 
									for (int s=r; s<k.length(); s++)
										if (k[s]!=' ') { greska=KodoviGresaka::SuvisanParametar; return false; }
							}
							if (pom.length()==0) { greska=KodoviGresaka::NedostajeParametar; return false; }
							if (pom=="GL") smjer=Smjerovi::GoreLijevo;
							else if (pom=="G") smjer=Smjerovi::Gore;
							else if (pom=="GD") smjer=Smjerovi::GoreDesno;
							else if (pom=="D") smjer=Smjerovi::Desno;
							else if (pom=="DoD") smjer=Smjerovi::DoljeDesno;
							else if (pom=="Do") smjer=Smjerovi::Dolje;
							else if (pom=="DoL") smjer=Smjerovi::DoljeLijevo;
							else if (pom=="L") smjer=Smjerovi::Lijevo;
							else { greska=KodoviGresaka::NeispravanParametar; return false; }
							komanda=Komande::PomjeriJednoMjesto; return true;
						}
					}
				//	else { greska=KodoviGresaka::PogresnaKomanda; return false; }
				}
				else { greska=KodoviGresaka::PogresnaKomanda; return false; }
			}
	}
}

//ispis matrice prikazi okolinu
void Ispis (std::vector<std::vector<int>> m) {
	for (int i=0; i<3; i++){
		for (int j=0; j<3; j++)
			std::cout<<m[i][j]<<" ";
		std::cout<<std::endl;
	}
}

//GLAVNA FUNKCIJA KOJA POZIVA SVE OSTALE
void IzvrsiKomandu (Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer=Smjerovi::Gore, int p_x=0, int p_y=0) {
	Status s=Status::NijeKraj;
	int br_polja=0; 
	std::vector<std::vector<int>> mine;
	if (komanda==Komande::KreirajIgru) {
		std::cout<<"Unesite broj polja: ";
		do {
			std::cin>>br_polja;
			if (br_polja<0) {
				std::cin.clear();
				std::cin.ignore(10000,'\n');
				std::cout<<"Greska, unesite ponovo!\n";
			}
		} while (br_polja<0);
		std::cout<<"Unesite pozicije mina: ";
		char a,b,c;
		int re,im,i=0;
		for (;;) {
			std::cin>>a;
			if (a=='.') {
				std::cin.clear();
				std::cin.ignore(10000,'\n');
				break;
			}
			if (a!='(') {
				std::cin.clear();
				std::cin.ignore(10000,'\n');
				std::cout<<"Greska, unesite ponovo!\n";
			}
			else {
				std::cin>>re;
				std::cin>>b;
				if (re>=0 && re<br_polja && b==')'){
					mine.resize(i+1);
					mine[i].push_back(re);
					i++;
				}
				else if (re<0 || re>=br_polja || (b!=')' && b!=',')){
					std::cin.clear();
					std::cin.ignore(10000,'\n');
					std::cout<<"Greska, unesite ponovo!\n";
				} 
				else {
					std::cin>>im;
					std::cin>>c;
					if (re>=br_polja || im>=br_polja || a!='(' || b!=',' || c!=')') {
						std::cin.clear();
						std::cin.ignore(10000,'\n');
						std::cout<<"Greska, unesite ponovo!\n";
					}
					else { mine.resize(i+1); mine[i].push_back(re); mine[i].push_back(im); i++; }
				}
			}
		}
		try { 
			polja=KreirajIgru(br_polja,mine);
		}	
			catch (std::domain_error prvi) { 
				std::cout<<prvi.what(); 
			}
	}
	if (komanda==Komande::Blokiraj) try { BlokirajPolje(polja,x,y); }  
		catch (std::domain_error drugi) { 
			std::cout<<drugi.what()<<"\n"; 
		}
	if (komanda==Komande::Deblokiraj) try { DeblokirajPolje(polja,x,y); }  
		catch (std::domain_error treci) { 
			std::cout<<treci.what()<<"\n"; 
		}
	if (komanda==Komande::PomjeriJednoMjesto) try {
		s=Idi(polja, x,y,p_smjer);
		std::cout<<"Tekuca pozicija igraca je ("<<x<<","<<y<<")\n";
	}
		catch (std::out_of_range cetvrti) {
			std::cout<<cetvrti.what();
		} 
		catch (std::logic_error peti) {
			std::cout<<peti.what();
		}
	if (komanda==Komande::PomjeriDalje) try {
		s=Idi(polja,p_x,p_y,x,y);
		std::cout<<"Tekuca pozicija igraca je ("<<x<<","<<y<<")\n";
	}
		catch(std::out_of_range sesti) {
			std::cout<<sesti.what();
		}
		catch (std::logic_error sedmi) {
			std::cout<<sedmi.what();
		}
	if (s==Status::KrajPobjeda) {
		std::cout<<"Bravo, obisli ste sva sigurna polja\n";
		Ocisti(polja);
		throw std::runtime_error ("Igra zavrsena\n");
	}
	if (s==Status::KrajPoraz) {
		std::cout<<"Nagazili ste na minu\n";
		Ocisti(polja);
		throw std::runtime_error ("Igra zavrsena\n");
	}
	if (komanda==Komande::PrikaziOkolinu) try {
		auto matrica=PrikaziOkolinu(polja,x,y);
		Ispis(matrica);
	}
		catch (std::domain_error osmi) {
			std::cout<<osmi.what()<<"\n";
		}
	if (komanda==Komande::ZavrsiIgru) {
		Ocisti(polja);
		throw std::runtime_error ("Igra zavrsena\n");
	}
}

int main ()
{
	try {
		Tabla polja;
		Komande komanda;
		Smjerovi smjer;
		int x=0, y=0;
		KodoviGresaka greska;
		for (;;) {
			std::cout<<"Unesite komandu: ";
			if (UnosKomande(komanda,smjer,x,y,greska)) IzvrsiKomandu(komanda,polja,x,y,smjer);
			else PrijaviGresku(greska);
		}
	}
	catch (std::runtime_error kraj) {
		std::cout<<"Dovidjenja!"<<std::endl;
	}
	return 0;
}