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
#include <string>

enum class Polje {
	Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno ,BlokiranoMina 
};

enum class Smjerovi {
	GoreLijevo, Gore, GoreDesno,Desno ,DoljeDesno,Dolje,DoljeLijevo,Lijevo
};
enum class Status {
	NijeKraj,KrajPoraz,KrajPobjeda
};
enum class KodoviGresaka {
	PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar
} ;
enum class Komande{
	PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj,PrikaziOkolinu,ZavrsiIgru,KreirajIgru
};
typedef std::vector<std::vector<Polje>> Tabla ;
Tabla KreirajIgru (int n, const std::vector<std::vector<int>>&mine ){
	if(n<=0) throw std::domain_error("Ilegalna velicina");
	Tabla t1(n,std::vector<Polje>(n,Polje::Prazno));
	for (int i = 0; i < mine.size(); i++) {
		if(mine.at(i).size()!=2)
			throw std::domain_error("Ilegalan format zadavanja mina");
		int a[2]={ mine.at(i).at(0),mine.at(i).at(1)};
		if(a[1]<0 or a[1]>=n or a[0]<0 or a[0]>=n)
			throw std::domain_error("Ilegalne pozicije mina");
		t1.at(a[0]).at(a[1])=Polje::Mina;
	}
	return t1;
}
std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polje,int x,int y){
	if(x<0 or y<0 or x>=polje.size() or y>=polje.size())
		throw std::domain_error("Polje ("+std::to_string(x)+","+std::to_string(y)+ ") ne postoji");
	int matrica [8][2]={{0,1},{1,0},{1,1},{-1,0},{0,-1},{-1,-1},{1,-1},{-1,1}};
	std::vector<std::vector<int >> okolina ;
	for (int  i = x-1; i <x+2; i++) {
		std::vector<int > a;
		for (int j = y-1; j<y+2; j++) {
			if(j<0 or j>=polje.size() or i<0 or i>=polje.size())
				continue;
			int broj(0);
			for (int k = 0; k <8; k++) {
				int red(i),kol(j);
				red+=matrica[k][0];
				kol+=matrica[k][1];
				if(red<0 or red>=polje.size() or kol<0 or kol>=polje.size())
					continue;
				if(polje.at(red).at(kol)==Polje::Mina)
					broj++;
			}
			a.push_back(broj);
		}
		if(a.size()>0)
		okolina.push_back(a);
	}
	return okolina;
}
void BlokirajPolje(Tabla &polje,int x,int y){
	if(x<0 or y<0 or x>=polje.size() or y>=polje.size())
		throw std::domain_error("Polje ("+std::to_string(x)+","+std::to_string(y)+ ") ne postoji");
	int a=int(polje.at(x).at(y));
	if(a<3)
		a+=3;
	polje.at(x).at(y)=Polje(a);
}
void DeblokirajPolje(Tabla &polje,int x,int y){
	if(x<0 or y<0 or x>=polje.size() or y>=polje.size())
		throw std::domain_error("Polje ("+std::to_string(x)+","+std::to_string(y) +") ne postoji");
	int a=int(polje.at(x).at(y));
	if(a>=3)
		a-=3;
	polje.at(x).at(y)=Polje(a);
}
Status Idi(Tabla &polje, int &x , int &y, Smjerovi smjer){
	int pravci[8][2]= {{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1}};
	int a(x+pravci[int(smjer)][0]),b(y+pravci[int(smjer)][1]);
	
	if(a<0 or b<0 or a>=polje.size() or b>=polje.size())
		throw std::out_of_range("Izlazak van igrace table");
	Polje s=polje.at(a).at(b);
	if(s==Polje::Mina){
		polje=Tabla(polje.size(),std::vector<Polje>(polje.size(),Polje::Prazno));
		return Status::KrajPoraz;
	}
	if(s==Polje::BlokiranoPosjeceno or s==Polje::BlokiranoPrazno or s== Polje::BlokiranoMina)
		throw std::logic_error("Blokirano polje");
	polje.at(x).at(y)=Polje::Posjeceno;
	x=a;
	y=b;
	bool pobjeda=true;
	for (int i = 0; i < polje.size(); i++) {
		for (int j = 0; j < polje.size(); j++) {
			if(polje.at(i).at(j)==Polje::Prazno or polje.at(i).at(j)==Polje::BlokiranoPrazno ){
				pobjeda=false;
				break;
			}
		}
	}
	if(pobjeda) return Status::KrajPobjeda;
	else return Status::NijeKraj;
}
Status Idi(Tabla &polje, int &x , int &y, int novi_x,int novi_y){


	if(novi_x<0 or novi_y<0 or novi_x>=polje.size() or novi_y>=polje.size())
		throw std::out_of_range("Izlazak van igrace table");
	Polje s=polje.at(novi_x).at(novi_y);
	if(s==Polje::Mina){
		polje=Tabla(polje.size(),std::vector<Polje>(polje.size(),Polje::Prazno));
		return Status::KrajPoraz;
	}
	if(s==Polje::BlokiranoPosjeceno or s==Polje::BlokiranoPrazno or s==Polje::BlokiranoMina)
		throw std::logic_error("Blokirano polje");
	polje.at(x).at(y)=Polje::Posjeceno;
	x=novi_x;
	y=novi_y;
	bool pobjeda=true;
	for (int i = 0; i < polje.size(); i++) {
		for (int j = 0; j < polje.size(); j++) {
			if(polje.at(i).at(j)==Polje::Prazno or polje.at(i).at(j)==Polje::BlokiranoPrazno ){
				pobjeda=false;
				break;
			}
		}
	}
	if(pobjeda) return Status::KrajPobjeda;
	else return Status::NijeKraj;
}
void PrijaviGresku(KodoviGresaka kod){
	std::vector<std::string> poruke{"Nerazumljiva komanda!","Komanda trazi parametar koji nije naveden!","Zadan je suvisan parametar nakon komande!","Parametar komande nije ispravan!"};
	std::cout << poruke.at(int(kod)) << std::endl;
}
bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska){
	std::vector<std::string> Lista_komandi{"P1","P>","B","D","PO","Z","K"} ;
	std::string s;
	
	std::getline(std::cin,s);
	int komanda_br=-1;
	for (int i = 0; i < 7; i++) {
		if(0==s.find(Lista_komandi.at(i)))
			komanda_br=i;	
	}		
	if(komanda_br==-1){
		greska=KodoviGresaka::PogresnaKomanda;
		return false;
	}
	for (int i = 0; i < Lista_komandi.at(komanda_br).size(); i++) {
		s.erase(s.begin());
	}if(s.size()>0)
	while (s.at(0)==' ') {
		s.erase(s.begin());
	}
	int br_smjer=-1;
	int duzina_komande=0;
	if(komanda_br==0){
		std::vector<std::string> lista_smjerovi={"GL","G","GD","D","DoD","Do","DoL","L"};
		for (int i = 0; i < 8; i++) {
			if(0==s.find(lista_smjerovi.at(i)) && lista_smjerovi.at(i).size()>duzina_komande){
			br_smjer=i;
			duzina_komande=lista_smjerovi.at(i).size();
			}
		}
		if(br_smjer==-1){
			if(s.size()==0){
				greska=KodoviGresaka::NedostajeParametar;
				return false;
			}else{
				greska=KodoviGresaka::NeispravanParametar;
				return false;
			}
		}
		if(s.size()>lista_smjerovi.at(br_smjer).size() && s.at(lista_smjerovi.at(br_smjer).size())!=' '){
			greska=KodoviGresaka::NeispravanParametar;
			return false;
		}
			for (int i = lista_smjerovi.at(br_smjer).size()+1; i < s.size(); i++) {
				if(s.at(i)!=' '){
					greska=KodoviGresaka::SuvisanParametar;
					return false;
				}
			}
			komanda=Komande(komanda_br);
			smjer=Smjerovi(br_smjer);
	}else if(komanda_br==1 or komanda_br==2 or komanda_br==3){
		int a(0),b(0);
		if(s.size()==0){
			greska=KodoviGresaka::NedostajeParametar;
			return false;
		}
		std::string::iterator p(s.begin()),k(s.end());
		if(*p<'0' or *p>'9'){
			greska=KodoviGresaka::NeispravanParametar;
			return false;
		}
		while (*p>='0'&& *p<='9' &&p<k) {
			a=a*10+*p-'0';
			p++;
		}
		if(p==k){
			greska=KodoviGresaka::NedostajeParametar;
			return false;
		}else if(*p!=' '){
			greska=KodoviGresaka::NeispravanParametar;
			return false;
		}
		while ((*p < '0' or *p > '9')&& p<k ) {
			if(*p!=' '){
				greska=KodoviGresaka::NeispravanParametar;
				return false;
			}
			p++;
		}
		if(p==k){
			greska=KodoviGresaka::NedostajeParametar;
			return false;
		}
		while (*p>='0'&& *p<='9' &&p<k) {
			b=b*10+*p-'0';
			p++;
		}
		if(k>p &&*p!=' ' ){
			greska=KodoviGresaka::NeispravanParametar;
			return false;
		}else if(k>p){
			while (p<k) {
				if(*p++!= ' '){
					greska=KodoviGresaka::SuvisanParametar;
					return false;
				}
			}
		}
		x=a;
		y=b;
		komanda=Komande(komanda_br);
	}else{
		if(s.size()>0){
			greska=KodoviGresaka::SuvisanParametar;
			return false;
		}
		komanda=Komande(komanda_br);
	}
	return true;
}
void IzvrsiKomandu(Komande komanda, Tabla &polje, int &x, int&y ,Smjerovi p_smjer=Smjerovi::Gore, int p_x=0, int p_y=0){
	if(komanda==Komande::PomjeriJednoMjesto){
		try{
		Status igra=Idi(polje,x,y,p_smjer);
		std::vector<std:: string> tekst {"Nagazili ste na minu","Bravo, obisli ste sva sigurna polja"} ;
		if(int(igra)>0){
			std::cout<<tekst.at(int(igra)-1)<<std::endl;
			polje=Tabla (polje.size(),std::vector<Polje>(polje.size(),Polje::Prazno));
			throw std::runtime_error("Igra zavrsena");
		}else
		std::cout << "Tekuca pozicija igraca je ("<<x<<","<<y<<")" << std::endl;
		}catch(std::out_of_range izuzetak ){
			std::cout << izuzetak.what() << std::endl;
		}catch(std::logic_error izuzetak){
			std::cout << izuzetak.what() << std::endl;
		}
	}else if( komanda==Komande::PomjeriDalje){
		try{
		Status igra=Idi(polje,x,y,p_x,p_y);
		std::vector<std:: string> tekst {"Nagazili ste na minu","Bravo, obisli ste sva sigurna polja"} ;
		if(int(igra)>0){
			std::cout<<tekst.at(int(igra)-1)<<std::endl;
			polje=Tabla (polje.size(),std::vector<Polje>(polje.size(),Polje::Prazno));
			throw std::runtime_error("Igra zavrsena");
		}
		else
		std::cout << "Tekuca pozicija igraca je ("<<x<<","<<y<<")" << std::endl;
		}catch(std::out_of_range izuzetak ){
			std::cout << izuzetak.what() << std::endl;
		}catch(std::logic_error izuzetak){
			std::cout << izuzetak.what() << std::endl;
		}
	}else if(komanda==Komande::PrikaziOkolinu){
		try{
			std::vector<std::vector<int> > okol=PrikaziOkolinu(polje,x,y) ;
			for (int i = 0; i <okol.size() ; i++) {
				for (int j = 0; j < okol.size(); j++) {
					std::cout << okol.at(i).at(j) << " ";
				}
				std::cout  << std::endl;
			}
		}catch(std::domain_error izuzetak ){
			std::cout << izuzetak.what() << std::endl;
		}
	}
	else if(komanda==Komande::Blokiraj){
		try{
			BlokirajPolje(polje,p_x,p_y);
		}catch(std::domain_error izuzetak ){
			std::cout << izuzetak.what() << std::endl;
		}
	}else if(komanda==Komande::Deblokiraj){
		try{
			DeblokirajPolje(polje,p_x,p_y);
		}catch(std::domain_error izuzetak ){
			std::cout << izuzetak.what() << std::endl;
		}
	}
	else if(komanda==Komande::ZavrsiIgru){
		polje=Tabla (polje.size(),std::vector<Polje>(polje.size(),Polje::Prazno));
		throw std::runtime_error("Igra zavrsena");
	}else{
		std::cout << "Unesite broj polja: ";
		int n;
		while (!(std::cin >> n) or n<=0) {
			std::cout << "Greska, unesite ponovo!" << std::endl;
			std::cin.clear();
			std::cin.ignore(1000,'\n');
			std::cout << "Unesite broj polja: ";
		}
		std::vector<std::vector<int>> minee ;
		std::cout << "Unesite pozicije mina: ";
		while (1) {
			int m1,m2;
			char b[3];
			std::cin>>b[0];
			if(b[0]=='.'){
			std::cin.ignore(100,'\n');
			break;
			}
			std::cin>>std::ws>>m1>>b[1]>>std::ws>>m2>>b[2];
			if(!std::cin or b[0] != '(' or b[1] != ',' or b[2] != ')' or m1 >= n or m2 >= n or m1 < 0 or m2 < 0 or(m1==0 and m2==0) ){
				std::cout << "Greska, unesite ponovo!" << std::endl;
				std::cin.clear();
				std::cin.ignore(1000,'\n');
				continue;
			}
			std::vector<int> v1 {m1,m2};
			minee.push_back(v1);
		}
		x=0;
		y=0;
		try{
		polje=KreirajIgru(n,minee);
		}catch(std::domain_error izuzetak){
			std::cout << izuzetak.what() << std::endl;
		}
	}
}
int main ()
{
	Tabla polje;
	try{
		while (1) {
			int x,y,p_x,p_y;
			Komande komanda;
			Smjerovi smjer;
			KodoviGresaka greska;
			std::cout << "Unesite komandu: " ;
			if(UnosKomande(komanda,smjer,p_x,p_y,greska))
				IzvrsiKomandu(komanda,polje,x,y,smjer,p_x,p_y);
			else
				PrijaviGresku(greska);
			
		}
	}
		catch(std::runtime_error izuzetak){
			std::cout << "Dovidjenja!" << std::endl;
		}
	return 0;
}