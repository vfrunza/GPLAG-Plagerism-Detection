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
#include <vector>
#include <stdexcept>
#include <complex>

enum class Polje {Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina};
enum class Smjerovi {GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo};
enum class Status {NijeKraj, KrajPoraz, KrajPobjeda};
enum class KodoviGresaka {PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar};
enum class Komande {PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru};
typedef std::vector<std::vector<Polje>> Tabla;

Tabla KreirajIgru (int n, const std::vector<std::vector<int>> &mine)
{
	if (n<=0)
		throw std::domain_error ("Ilegalna velicina");
	for (int i=0;i<mine.size();i++)	{
		if (mine.at(i).size()!=2)
			throw std::domain_error ("Ilegalan format zadavanja mina");
	}
	for (int i=0;i<mine.size();i++) {
		for (int j=0;j<mine.at(i).size();j++) {
			if (mine.at(i).at(j)<0 || mine.at(i).at(j)>=n)
				throw std::domain_error ("Ilegalne pozicije mina");
		}
	}
	Tabla vrati(n,std::vector<Polje> (n,Polje::Prazno));
	for (int i=0;i<mine.size();i++)
	{
		for (int j=1;j<mine.at(i).size();j++) {
			vrati.at(mine.at(i).at(j-1)).at(mine.at(i).at(j))=Polje::Mina;
		}
	}
	return vrati;
}
std::vector<std::vector<int>> PrikaziOkolinu (const Tabla &polja, int x, int y) 
{
	auto temp1(std::to_string(x)), temp2(std::to_string(y));
	std::string izuzetak("Polje ("+temp1+","+temp2+") ne postoji");
	if (x<0 || x>=polja.size() || y<0 || y>=polja.at(0).size())
		throw std::domain_error (izuzetak);
	std::vector<std::vector<int>> vrati(3);
	int indeks(0);
	for (int i=x-1;i<=x+1;i++) {
		for (int j=y-1;j<=y+1;j++) {
			int brojac(0);
			for (int k=i-1;k<=i+1;k++) {
				for (int l=j-1;l<=j+1;l++) {
					 if (k>=0 && k<=polja.size()-1 && l>=0 && l<=polja.at(i).size()-1) {
						if (polja.at(k).at(l)==Polje::Mina && (k!=i || l!=j))
							brojac++;
					}
				}
			}
			vrati.at(indeks).push_back(brojac);
		}
		indeks++;
	}
	return vrati;
}
void BlokirajPolje (Tabla &polja, int x, int y) 
{
	auto temp1(std::to_string(x)), temp2(std::to_string(y));
	std::string izuzetak("Polje ("+temp1+","+temp2+") ne postoji");
	if (x<0 || x>=polja.size() )
		throw std::domain_error (izuzetak);
	if (polja.size()>0) {
		if (y<0 || y>=polja.at(0).size())
			throw std::domain_error (izuzetak);
	}
	Polje niz[3]{Polje::BlokiranoPrazno,Polje::BlokiranoPosjeceno,Polje::BlokiranoMina};
	int temp(int(polja.at(x).at(y)));
	if (temp<3)
		polja.at(x).at(y)=niz[temp];
}
void DeblokirajPolje (Tabla &polja, int x, int y)
{
	auto temp1(std::to_string(x)),temp2(std::to_string(y));
	std::string izuzetak("Polje("+temp1+","+temp2+") ne postoji");
	if (x<0 || x>=polja.size())
		throw std::domain_error (izuzetak);
	if (polja.size()>0) {
		if (y<0 || y>=polja.at(0).size())
			throw std::domain_error (izuzetak);
	}
	Polje niz[3]{Polje::Prazno,Polje::Posjeceno,Polje::Mina};
	int temp(int(polja.at(x).at(y)));
	if (temp>=3)
		polja.at(x).at(y)=niz[temp-3];
}
void IgraZavrsena(Tabla &polja)
{
	for (int i=0;i<polja.size();i++) {
		for (int j=0;j<polja.at(i).size();j++)
		polja.at(i).at(j)=Polje::Prazno;
	}
}
Status Idi (Tabla &polja, int &x, int &y, Smjerovi smjer)
{
	int niz1[8]{-1,-1,-1,0,1,1,1,0};
	int niz2[8]{-1,0,1,1,1,0,-1,-1};
	int posx(niz1[int(smjer)]); int posy(niz2[int(smjer)]);
	if (x+posx<0 || x+posx>=polja.size() || y+posy<0 || y+posy>=polja.at(0).size())
		throw std::out_of_range ("Izlazak van igrace table");
	auto pos(polja.at(x+posx).at(y+posy));
	if (pos==Polje::BlokiranoPosjeceno || pos==Polje::BlokiranoPrazno || pos==Polje::BlokiranoMina)
		throw std::logic_error ("Blokirano polje");
	polja.at(x).at(y)=Polje::Posjeceno;
	x+=posx; y+=posy;
	if (polja.at(x).at(x)==Polje::Mina) {
		IgraZavrsena(polja);
		return Status::KrajPoraz;
	}
	bool pobjeda(true);
	for (int i=0;i<polja.size();i++) {
		for (int j=0;j<polja.at(i).size();j++)
			if (polja.at(i).at(j)==Polje::Prazno){
				pobjeda=false;
				break;}
	}
	if (pobjeda) {
	IgraZavrsena(polja);
	return Status::KrajPobjeda;}
	return Status::NijeKraj;
}
Status Idi (Tabla &polja, int &x, int &y, int novi_x, int novi_y)
{
	if (novi_x<0 || novi_x>=polja.size() || novi_y<0 || novi_y>=polja.at(0).size())
		throw std::out_of_range ("Izlazak van igrace table");
	auto pos(polja.at(novi_x).at(novi_y));
	if (pos==Polje::BlokiranoPosjeceno || pos==Polje::BlokiranoPrazno || pos==Polje::BlokiranoMina)
		throw std::logic_error ("Blokirano polje");
	polja.at(x).at(y)=Polje::Posjeceno;
	x=novi_x; y=novi_y;
	if (polja.at(x).at(y)==Polje::Mina) {
		IgraZavrsena(polja);
		return Status::KrajPoraz;
	}
	bool pobjeda(true);
	for (int i=0;i<polja.size();i++) {
		for (int j=0;j<polja.at(i).size();j++) {
			if (polja.at(i).at(j)==Polje::Prazno) {
				pobjeda=false;
				break;
			}
		}
	}
	if (pobjeda) {
	IgraZavrsena(polja);
	return Status::KrajPobjeda; }
	return Status::NijeKraj;
}
void PrijaviGresku (KodoviGresaka greska)
{
	const char *greske[4]{"Nerazumljiva komanda!","Komanda trazi parametar koji nije naveden!","Zadan je suvisan parametar nakon komande!","Parametar komande nije ispravan!"};
	std::cout<<greske[int(greska)]<<std::endl;;
}
void IzbaciRazmake(std::string &s) 
{
	for (int i=0;i<s.size();i++) {
		if (s.at(i)==' ') {
			s.erase(s.begin()+i);
			i--;
		}
	}
}
bool UnosKomande (Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska) 
{
	std::vector<std::string> v{"P1","P>","B","D","PO","Z","K"};
	std::string unos;
	std::getline(std::cin,unos);
	int cuvaj,ind;
	bool flag(false);
	for (int i=0;i<v.size();i++) {
		bool pok(false);
		for (int j=0;j<v.at(i).size();) {
			int indeks(0);
			if (unos.at(indeks)==' ')
			indeks++;
			else if (unos.at(indeks)==v.at(i).at(j)) {
				while (unos.at(indeks)==v.at(i).at(j)) {
					indeks++;
					j++;
					if (j==v.at(i).size()) {
						pok=true;
						flag=true;
						ind=indeks; cuvaj=i;
						break;
					}
					if (indeks==unos.size())
					break;
				}
			}
			else
			break;
		}
		if (pok) {
			if (cuvaj==4 || cuvaj==5 || cuvaj==6) {
				for (int j=ind;j<unos.size();j++) {
					if (unos.at(j)!=' ') {
						greska=KodoviGresaka::SuvisanParametar;
						return false;
					}
				}
				Komande niz[3]{Komande::PrikaziOkolinu,Komande::ZavrsiIgru,Komande::KreirajIgru};
				komanda=niz[cuvaj-4];
				return true;
			}
			else if (cuvaj==1 || cuvaj==2 || cuvaj==3) {
				int broj[2]{0,0};
				bool niz[2]{false,false};
				bool ima(false);
				for (int j=ind;j<unos.size();j++) {
					if (unos.at(j)!=' ') {
						ima=true;
						break;
					}
				}
				if (!ima) {
					greska=KodoviGresaka::NedostajeParametar;
					return false;
				}
				int pomocna(0);
				int pomocna2(0);
				for (int j=ind;j<unos.size();j++) {
					if (unos.at(j)>='0' && unos.at(j)<='9') {
						pomocna++;
						if (pomocna>2) {
							greska=KodoviGresaka::SuvisanParametar;
							return false;
						}
						niz[pomocna-1]=true;
						int temp(0);
						while (unos.at(j)>='0' && unos.at(j)<='9') {
							temp=temp*10+unos.at(j)-'0';
							j++;
							if (j==unos.size())
							break;
						}
						if (j==unos.size() || unos.at(j)==' ') {
							broj[pomocna2]=temp;
							pomocna2++;
						}
					}
				}
				if (niz[1]==true && niz[0]==true) {
					for (int j=ind;j<unos.size();j++) {
						if (unos.at(j)>='0' && unos.at(j)<='9')
						continue;
						if (unos.at(j)!=' ' ) {
							greska=KodoviGresaka::NeispravanParametar;
							return false;
						}
					}
				}
				x=broj[0]; y=broj[1];
				Komande niz2[3]{Komande::PomjeriDalje,Komande::Blokiraj,Komande::Deblokiraj};
				komanda=niz2[cuvaj-1];
				return true;
			}
			else if (cuvaj==0) {
				std::vector<std::string> temp{"P1GL","P1G","P1GD","P1D","P1DoD","P1Do","P1DoL","P1L"};
				Smjerovi niz4[8]{Smjerovi::GoreLijevo,Smjerovi::Gore,Smjerovi::GoreDesno,Smjerovi::Desno,Smjerovi::DoljeDesno,Smjerovi::Dolje,Smjerovi::DoljeLijevo,Smjerovi::Lijevo};
				IzbaciRazmake(unos);
				if (unos=="P1") {
					greska=KodoviGresaka::NedostajeParametar;
					return false;
				}
				for (int j=0;j<temp.size();j++) {
					if (unos==temp.at(j)) {
						smjer=niz4[j];
						komanda=Komande::PomjeriJednoMjesto;
						return true;
					}
				}
				greska=KodoviGresaka::NeispravanParametar;
				return false;
			}
		}
	}
	if (!flag) {
		greska=KodoviGresaka::PogresnaKomanda;
		return false;
	}
	return true;
}
void IzvrsiKomandu (Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer=Smjerovi::Gore, int p_x=0, int p_y=0) 
{
	if (komanda==Komande::Blokiraj) {
		try {
			BlokirajPolje(polja,p_x,p_y);
		}
		catch(std::domain_error izuz) {
			std::cout<<izuz.what()<<std::endl;
		}
	}
	else if (komanda==Komande::Deblokiraj) {
		try {
			DeblokirajPolje(polja,p_x,p_y);
		}
		catch (std::domain_error izuz) {
			std::cout<<izuz.what()<<std::endl;;
		}
	}
	else if (komanda==Komande::PrikaziOkolinu) {
		try {
		auto mat(PrikaziOkolinu(polja,x,y));
		for (int i=0;i<mat.size();i++) {
			for (int j=0;j<mat.at(i).size();j++) 
				std::cout<<mat.at(i).at(j)<<" ";
			std::cout<<"\n";
		}}
		catch (std::domain_error izuz) {
			std::cout<<izuz.what()<<std::endl;
		}
	}
	else if (komanda==Komande::PomjeriDalje) {
		try {
			auto temp(Idi(polja,x,y,p_x,p_y));
			if (temp==Status::KrajPobjeda) {
			std::cout<<"Bravo,obisli ste sva sigurna polja"<<std::endl; 
			throw std::runtime_error ("Igra zavrsena");}
			else if (temp==Status::KrajPoraz) {
			std::cout<<"Nagazili ste minu"<<std::endl;
			throw std::runtime_error ("Igra zavrsena");}
			else 
			std::cout<<"Tekuca pozicija igraca je ("<<x<<","<<y<<")"<<std::endl;
		}
		catch (std::out_of_range izuz) {
			std::cout<<izuz.what()<<std::endl;
		}
		catch (std::logic_error izuz2) {
			std::cout<<izuz2.what()<<std::endl;
		}
	}
	else if (komanda==Komande::PomjeriJednoMjesto) {
		try {
			auto temp(Idi(polja,x,y,p_smjer));
			if (temp==Status::KrajPobjeda) {
			std::cout<<"Bravo, obisli ste sva polja"<<std::endl; 
			throw std::runtime_error ("Igra zavrsena");}
			else if (temp==Status::KrajPoraz) {
			std::cout<<"Nagazili ste minu"<<std::endl;
			throw std::runtime_error ("Igra zavrsena");}
			else
			std::cout<<"Tekuca pozicija igraca je ("<<x<<","<<y<<")"<<std::endl;
		}
		catch (std::out_of_range izuz) {
			std::cout<<izuz.what()<<std::endl;
		}
		catch (std::logic_error izuz2) {
			std::cout<<izuz2.what()<<std::endl;
		}
	}
	else if (komanda==Komande::ZavrsiIgru) {
		IgraZavrsena(polja);
		throw std::runtime_error ("Igra zavrsena");
	}
	else if (komanda==Komande::KreirajIgru) {
		int x;
		for (;;) {
			std::cout<<"Unesite broj polja: ";
			std::cin>>x;
			if (!std::cin || x<=0) {
				std::cout<<"Greska, unesite ponovo!";
			}
			else
			break;
		}
		std::cin.ignore(10000,'\n');
		std::cout<<"Unesite pozicije mina: ";
		std::vector<std::vector<int>> mat;
		std::string temp;
		int indeks(0);
		for (;;) {
			std::getline(std::cin,temp);
			IzbaciRazmake(temp);
			bool ispravno(true);
			if (temp==".")
			break;
			if (temp.at(0)!='(' || temp.at(temp.size()-1)!=')')
			ispravno=false;
			int temp1[2]{0};
			bool zarez(false);
			for (int i=0;i<temp.size();i++) {
				if (temp.at(i)==',') {
					zarez=true;
					if (!(temp.at(i-1)>='0' && temp.at(i-1)<='9') || !(temp.at(i+1)>='0' && temp.at(i+1)<='9'))
					ispravno=false;
				}
			}
			if (!ispravno || !zarez)
			std::cout<<"Greska, unesite ponovo!"<<std::endl;
			else {
				int ind(0);
				for (int i=0;i<temp.size();i++) {
					if (temp.at(i)>='0' && temp.at(i)<='9') {
						while (temp.at(i)>='0' && temp.at(i)<='9') {
							temp1[ind]=temp1[ind]*10+temp.at(i)-'0';
							i++;
						}
						ind++;
					}
				}
				if (temp1[0]>=x || temp1[1]>=x || temp1[0]<0 || temp1[1]<0 || (temp1[0]==0 && temp1[1]==0))
				std::cout<<"Greska, unesite ponovo!"<<std::endl;
				else {
				mat.resize(indeks+1);
				mat.at(indeks).push_back(temp1[0]); mat.at(indeks).push_back(temp1[1]);
				indeks++;}
			}
		}
		polja=KreirajIgru(x,mat);
	}
}
int main ()
{	
	int x(0),y(0);
	Komande komanda;
	Smjerovi smjer;
	KodoviGresaka greska;
	int x_n, y_n;
	Tabla polja;
		try {
		for (;;) {
		std::cout<<"Unesite komandu: ";
		auto temp(UnosKomande(komanda,smjer,x_n,y_n,greska));
		if (temp) {
			IzvrsiKomandu(komanda,polja,x,y,smjer,x_n,y_n);
		}
		else {
			PrijaviGresku(greska);
		}}}
		catch(std::runtime_error izuz) {
			std::cout<<"Dovidjenja!"<<std::endl;
		}
	
	return 0;
}