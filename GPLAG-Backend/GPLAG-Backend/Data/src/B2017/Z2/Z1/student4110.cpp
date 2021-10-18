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
#include <stdexcept>
#include <vector>
#include <complex>
#include <string>

enum class Polje {Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina};
enum class Smjerovi{GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo};
enum class Status{NijeKraj,KrajPoraz,KrajPobjeda};
enum class KodoviGresaka{PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar};
enum class Komande{PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru};
typedef std::vector<std::vector<Polje>> Tabla;
typedef std::vector<std::vector<int>> Matrica;

Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine){
	if(n<=0) throw std::domain_error("Ilegalna velicina");
	for(int i=0;i<mine.size();i++){
		if(mine[i].size()!=2) throw std::domain_error("Ilegalan format zadavanja mina");
	}
	for(int i=0;i<mine.size();i++){
		for(int j=0;j<2;j++){
			if(!(mine[i][j]>=0&&mine[i][j]<n)) throw std::domain_error("Ilegalne pozicije mina");
		}
	}
	Tabla a(n,std::vector<Polje>(n,Polje::Prazno));
	for(int i=0;i<mine.size();i++){
		a[mine[i][0]][mine[i][1]]=Polje::Mina;
	}
	return a;
}

std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y){
	if(!(x>=0&&x<polja.size())||!(y>=0&&y<polja.size())) throw std::domain_error("Polje ("+std::to_string(x)+","+std::to_string(y)+") ne postoji");
	Matrica a(3,std::vector<int>(3));
	std::vector<int> v;
	Matrica m;
	int prva{0},druga{0};
	for(int i=x-1;i<=x+1;i++){
		for(int j=y-1;j<=y+1;j++){
			int br{0};
			v.push_back(i);
			v.push_back(j+1);
			m.push_back(v);
			v.resize(0);
			
			v.push_back(i);
			v.push_back(j-1);
			m.push_back(v);
			v.resize(0);
			
			v.push_back(i+1);
			v.push_back(j);
			m.push_back(v);
			v.resize(0);
			
			v.push_back(i-1);
			v.push_back(j);
			m.push_back(v);
			v.resize(0);
			
			v.push_back(i-1);
			v.push_back(j-1);
			m.push_back(v);
			v.resize(0);
			
			v.push_back(i+1);
			v.push_back(j+1);
			m.push_back(v);
			v.resize(0);
			
			v.push_back(i-1);
			v.push_back(j+1);
			m.push_back(v);
			v.resize(0);
			
			v.push_back(i+1);
			v.push_back(j-1);
			m.push_back(v);
			v.resize(0);
			
			
			for(int k=0;k<m.size();k++){
				if(!(m[k][0]>=0&&m[k][0]<polja.size())||!(m[k][1]>=0&&m[k][1]<polja.size())) {m.erase(m.begin()+k);k--;}
				
			}
			
			for(int k=0;k<m.size();k++){
				if(polja[m[k][0]][m[k][1]]==Polje::Mina)br++;
			}
			a[prva][druga]=br;
			druga++;
			m.resize(0);
		}
		druga=0;
		prva++;
	}
	return a;
}

void BlokirajPolje(Tabla &polja, int x, int y){
	//std::string string1("Polje ("), string2(","),string3(") ne postoji");
	if(!(x>=0&&x<polja.size())||!(y>=0&&y<polja.size()))  throw std::domain_error("Polje ("+std::to_string(x)+","+std::to_string(y)+") ne postoji");
	if(polja[x][y]==Polje::Prazno)polja[x][y]=Polje::BlokiranoPrazno;
	if(polja[x][y]==Polje::Mina)polja[x][y]=Polje::BlokiranoMina;
	if(polja[x][y]==Polje::Posjeceno)polja[x][y]=Polje::BlokiranoPosjeceno;
}
void DeblokirajPolje(Tabla &polja, int x, int y){
	if(!(x>=0&&x<polja.size())||!(y>=0&&y<polja.size())) throw std::domain_error("Polje ("+std::to_string(x)+","+std::to_string(y)+") ne postoji");
	if(polja[x][y]==Polje::BlokiranoPrazno)polja[x][y]=Polje::Prazno;
	if(polja[x][y]==Polje::BlokiranoMina)polja[x][y]=Polje::Mina;
	if(polja[x][y]==Polje::BlokiranoPosjeceno)polja[x][y]=Polje::Posjeceno;
}

Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer){
	polja[x][y]=Polje::Posjeceno;
	std::vector<std::vector<int>> a{{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1}};
	x+=a[int(smjer)][0];
	y+=a[int(smjer)][1];
	if(!(x>=0&&x<polja.size())||!(y>=0&&y<polja.size())) throw std::out_of_range("Izlazak van igrace table");
	if(int(polja[x][y])>2) throw std::logic_error("Blokirano polje");
	if(polja[x][y]==Polje::Mina) {
		Tabla prazna(polja.size(),std::vector<Polje>(polja.size(),Polje::Prazno));
		polja=prazna;
		return Status::KrajPoraz;
	}
	int br{0};
	for(int i=0;i<polja.size();i++){
		for(int j=0;j<polja.size();j++){
			if(polja[i][j]==Polje::Prazno) br++;
		}
	}
	if(br==0) return Status::KrajPobjeda;
	return Status::NijeKraj;
}
Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y){
	polja[x][y]=Polje::Posjeceno;
	x=novi_x;
	y=novi_y;
	if(!(x>=0&&x<polja.size())||!(y>=0&&y<polja.size())) throw std::out_of_range("Izlazak van igrace table");
	if(int(polja[x][y])>2) throw std::logic_error("Blokirano polje");
	if(polja[x][y]==Polje::Mina) {
		Tabla prazna(polja.size(),std::vector<Polje>(polja.size(),Polje::Prazno));
		polja=prazna;
		return Status::KrajPoraz;
	}
	int br{0};
	for(int i=0;i<polja.size();i++){
		for(int j=0;j<polja.size();j++){
			if(polja[i][j]==Polje::Prazno) br++;
		}
	}
	if(br==0) return Status::KrajPobjeda;
	return Status::NijeKraj;
}
void PrijaviGresku(KodoviGresaka a){
	if(int(a)==0)std::cout<<"Nerazumljiva komanda!"<<std::endl;
	if(int(a)==1)std::cout<<"Komanda trazi parametar koji nije naveden!"<<std::endl;
	if(int(a)==3)std::cout<<"Parametar komande nije ispravan!"<<std::endl;
	if(int(a)==2)std::cout<<"Zadan je suvisan parametar nakon komande!"<<std::endl;
}


bool Cifre(std::string a){
	for(int i=0;i<a.length();i++){
		if(!(a[i]>='0'&&a[i]<='9')) return false;
	}
	return true;
}
int PretvoriString(std::string a){
	int k{1},broj{0};
	for(int i=a.length()-1;i>=0;i--){
		broj+=(int(a[i])-48)*k;
		k*=10;
	}
	return broj;
}

bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska){
	std::string a,z;
	std::vector<std::string>b{"P1","P>","B","D","PO","Z","K"},k;
	std::getline(std::cin,a);
	for(int i=0;i<a.length();i++){
		while(a[i]==' ' && i<a.length())i++;
		while(a[i]!=' ' && i<a.length()){
			z.push_back(a[i]);
			i++;
		}
		k.push_back(z);
		z.resize(0);
		while(a[i]==' '&&i<a.length())i++;
		i--;
}

int br{0},indeks;
for(int i=0;i<k.size();i++){
	for(int j=0;j<b.size();j++){
		if(k[i]==b[j]&&br==0){ komanda=Komande(j);br++;indeks=i;}
	}
}
if(br==0){
	greska=KodoviGresaka::PogresnaKomanda;
	for(int i=0;i<a.length();i++){
		if(a[i]=='B'||a[i]=='K'||a[i]=='Z'){
			if(a[i+1]!=' ') greska=KodoviGresaka::SuvisanParametar;
		}
		if(a[i]=='P'&&a[i+1]=='O'&&a[i+2]!=' ') greska=KodoviGresaka::SuvisanParametar;
	}
}
else{
if(int(komanda)==0){
	int br{0};
	std::vector<std::string>b{"GL","G","GD","D","DoD","Do","DoL","L"};
	if((indeks+1)>k.size()) greska=KodoviGresaka::NedostajeParametar;
	else{
	for(int i=0;i<b.size();i++){
		if(k[indeks+1]==b[i]){ smjer=Smjerovi(i);br++;}
	}}
	if(br==0) greska=KodoviGresaka::SuvisanParametar;
}
if(int(komanda)>0&&int(komanda)<4){
	if((indeks+2)>k.size()) greska=KodoviGresaka::NedostajeParametar;
	else{
	if(Cifre(k[indeks+1])&&Cifre(k[indeks+2])){
		x=PretvoriString(k[indeks+1]);
		y=PretvoriString(k[indeks+2]);
	}
	if(!(Cifre(k[indeks+1])&&Cifre(k[indeks+2]))) greska=KodoviGresaka::SuvisanParametar;
	}
}
}
if(int(greska)>=0&&int(greska)<3) return false;
return true;
}

void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer=Smjerovi::Gore, int p_x=0, int p_y=0){
	if(komanda==Komande::Blokiraj){
	try{ BlokirajPolje(polja,x,y);}
	catch(std::domain_error e) {std::cout<<e.what()<<std::endl;}}
	
	if(komanda==Komande::Deblokiraj){
	try {DeblokirajPolje(polja,x,y);}
	catch(std::domain_error e) {std::cout<<e.what()<<std::endl;}}
	
	if(komanda==Komande::PomjeriJednoMjesto){
		try{
	Status a(Idi(polja,x,y,p_smjer));
	if(a==Status::KrajPobjeda)std::cout<<"Tekuca pozicija igraca je ("<<x<<","<<y<<") "<<"Bravo obisli ste sva sigurna polja"<<std::endl;
	if(a==Status::KrajPoraz)std::cout<<"Tekuca pozicija igraca je ("<<x<<","<<y<<") "<<"Nagazili ste na minu"<<std::endl;
	if(a==Status::NijeKraj)std::cout<<"Tekuca pozicija igraca je ("<<x<<","<<y<<")"<<std::endl;}
	catch(std::out_of_range e) {std::cout<<e.what()<<std::endl;}
	catch(std::logic_error e) {std::cout<<e.what()<<std::endl;}
	}
	if(komanda==Komande::PrikaziOkolinu){
		try{
		Matrica a(PrikaziOkolinu(polja,x,y));
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				std::cout<<a[i][j]<<" ";
			}
			std::cout<<std::endl;
		}
		}
		catch(std::domain_error e) {std::cout<<e.what()<<std::endl;}
	}
	if(komanda==Komande::ZavrsiIgru){
		for(int i=0;i<polja.size();i++){
			for(int j=0;j<polja.size();j++)
			polja[i][j]=Polje::Prazno;
		}
		throw std::runtime_error("Igra zavrsena");
	}
	if(komanda==Komande::KreirajIgru){
		try{
		int n;
		std::cout<<"Unesite broj polja: ";
		std::cin>>n;
		while(!std::cin||n<=0){
			std::cout<<"Greska, unesite ponovo!";
			std::cin.clear();
			std::cin.ignore(10000,'\n');
			std::cout<<"Unesite broj polja: ";
			std::cin>>n;
		}
		std::vector<std::complex<int>> a;
		std::complex<int>b;
		std::cout<<"Unesite pozicije mina: ";
			
		while(!std::cin.peek()=='.'){
			std::cin>>b;
			while(!std::cin){
			std::cout<<"Greska, unesite ponovo!";
			std::cin.clear();
			std::cin.ignore(10000,'\n');
			std::cin>>b;
		}
			a.push_back(b);
		}
		std::vector<std::vector<int>>c(a.size(),std::vector<int>(2));
		
		for(int i=0;i<a.size();i++){
			c[i][0]=std::real(a[i]);
			c[i][1]=std::imag(a[i]);
		}
        polja=KreirajIgru(n,c);
			}
		catch(std::domain_error e){
			std::cout<<e.what();
		}
	}
			
	
	
	
}

int main ()
{
    std::cout<<"Unesite komandu: ";
    Komande komanda;
    Smjerovi smjer;
    int x,y;
    KodoviGresaka greska;
    Tabla polja;
    if(UnosKomande(komanda,smjer,x,y,greska)) IzvrsiKomandu(komanda,polja,x,y,smjer);
    else PrijaviGresku(greska);
    
	return 0;
}