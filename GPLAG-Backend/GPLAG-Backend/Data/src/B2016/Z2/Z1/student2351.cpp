/*B 16/17, Zadaća 2, Zadatak 1
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
	
*/
#include<iostream>
#include<vector>
#include<stdexcept>
#include<string>

enum  class Polje{
	Prazno=0, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno,BlokiranoMina
};
enum class Smjerovi{
	GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo
};


enum class Status{
	NijeKraj, KrajPoraz, KrajPobjeda
};

enum class KodoviGresaka{
	PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar
};

enum class Komande{
	PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru
};

typedef std::vector<std::vector<Polje>> Tabla;





Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine){

		Tabla t(n,std::vector<Polje>(n,Polje::Prazno));

	for(int i=0;i<mine.size();i++){
		
		if(mine[i].size()!=2) throw std::domain_error("Ilegalan format zadavanja mina");
	}
	
	for(int i=0;i<mine.size();i++){
		
		if(mine[i][0]<0 || mine[i][0]>n || mine[i][1]<0 || mine[i][1]>n) throw std::domain_error("Ilegalne pozicije mina");
		
		t[mine[i][0]][mine[i][1]]=Polje::Mina;
		
		
	}
	return t;
	
	
	
	
	
}

int Prebroji(const Tabla &polja, int x,int y){
	int brojac(0);
	for(int a=x-1;a<=x+1;a++){
		if(a<0 || a>polja.size()-1) continue;
		for(int b=y-1;b<=y+1;b++){
			if(b<0 || b>polja.size()-1) continue;
			
			if(a==x && b==y) continue;
			if(polja[a][b]==Polje::Mina){
				
				brojac++;
			}
			
		}
		
	}
	
	
	
	return brojac;
}


std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y){

if(x<0  || x>polja.size()-1 || y<0 || y>polja.size()-1) {
	std::string s1{"Polje ("},s2{","},s3{") ne postoji"};
char b(static_cast<char>(x+'0'));
char c(static_cast<char>(y+'0'));
std::string s=s1+b+s2+c+s3;


//const char n[]{"Polje"
	throw std::domain_error(s);
}
	
	std::vector<std::vector<int>> okolina(3,std::vector<int>(3));
	int i(0),j(0);
	for(int a=x-1;a<=x+1;a++){
	j=0;
		for(int b=y-1;b<=y+1;b++){
			
			if(a<0 ||  b<0 || a>polja.size()-1 || b>polja.size()) okolina[i][j]=0;
			
			okolina[i][j]=Prebroji(polja,a,b);
			j++;
		}
		i++;
		
	}
	
	return okolina;
	
	
	
}
void BlokirajPolje(Tabla &polja,int x,int y) {
	
	
	if(x<0 || y<0 || x>polja.size()-1 || y>polja.size()-1) {
	std::string s1{"Polje ("},s2{","},s3{") ne postoji"};
char b(static_cast<char>(x+'0'));
char c(static_cast<char>(y+'0'));
std::string s=s1+b+s2+c+s3;


//const char n[]{"Polje"
	throw std::domain_error(s);
	}
	
//	if(polja[x][y]==Polje::BlokiranoPosjeceno || polja[x][y]==Polje::BlokiranoPrazno || polja[x][y]==Polje::BlokiranoMina) throw std::logic_error("Blokirano Polje");
//std::cout<<static_cast<int>(polja[x][y]);
	for(int i=static_cast<int>(Polje::Prazno);i<=static_cast<int>(Polje::Mina);i++){
		
		if(static_cast<int>(polja[x][y])==i) polja[x][y]=static_cast<Polje>(i+3);
	}
	


}

void DeblokirajPolje(Tabla &polja,int x,int y){
	if(x<0 || y<0 || x>polja.size()-1 || y>polja.size()-1) {
			std::string s1{"Polje ("},s2{","},s3{") ne postoji"};
      char b(static_cast<char>(x+'0'));
	char c(static_cast<char>(y+'0'));
	std::string s=s1+b+s2+c+s3;

	throw std::domain_error(s);
	}
	for(int i=static_cast<int>(Polje::BlokiranoPrazno);i<=static_cast<int>(Polje::BlokiranoMina);i++){
		if(static_cast<int>(polja[x][y])==i) polja[x][y]=static_cast<Polje>(i-3);
	}
	
	
}

Status Idi(Tabla &polja, int &x,int &y,Smjerovi smjer){
	
	//	if(x<0 || y<0 || x>polja.size()-1 || y>polja.size()-1) throw std::out_of_range("Izlazak van igrace table");
	
	int a,b;
	
	
	
	for(int i=static_cast<int>(Smjerovi::GoreLijevo);i<=static_cast<int>(Smjerovi::GoreDesno);i++){
		
		if(static_cast<int>(smjer)==i) {
			a=x-1;
			b=y-1+i;
		
		
	  }
	}
	for(int i=static_cast<int>(Smjerovi::DoljeDesno);i<=static_cast<int>(Smjerovi::DoljeLijevo);i++){
		if(static_cast<int>(smjer)==i){
			a=x+1;
			b=y+5-i;
		

		}
	}
	if(smjer==Smjerovi::Desno){
		a=x;
		b=y+1;
	}
	if(smjer==Smjerovi::Lijevo){
		a=x;
		b=y-1;
		
	}
	
	if(a<0 || b<0 || a>polja.size()-1 || b>polja.size()-1) throw std::out_of_range("Izlazak van igrace table");
	
	for(int i=static_cast<int>(Polje::BlokiranoPrazno);i<=static_cast<int>(Polje::BlokiranoMina);i++){
	if(polja[a][b]==static_cast<Polje>(i)){
		throw std::logic_error("Blokirano polje");
	}
	}

	polja[x][y]=Polje::Posjeceno;
	
	x=a;
	y=b;
	
	  if(polja[x][y]==Polje::Mina){ 
	  	for(int i=0;i<polja.size();i++){
	  		for(int j=0;j<polja.size();j++){
	  			
	  			polja[x][y]=Polje::Prazno;
	  		}
	  	}
	  	return Status::KrajPoraz;
	  }
	  bool NemaPrazno(true);
	  
	  for(int i=0;i<polja.size();i++){
	  	for(int j=0;j<polja.size();j++){
	  		if(i==x && j==y) continue;
	  		if(polja[i][j]==Polje::Prazno){
	  			NemaPrazno=false;
	  			break;
	  		}
	  	}
	  }
	  if(NemaPrazno) return Status::KrajPobjeda;
	  else{
	  	return Status::NijeKraj;
	  }
}

Status Idi(Tabla &polja,int &x,int &y,int novi_x,int novi_y){
	
	
	if(novi_x<0 || novi_y<0 || novi_x>polja.size()-1 || novi_y>polja.size()-1) throw std::out_of_range("Izlazak van igrace table");
	
	for(int i=static_cast<int>(Polje::BlokiranoPrazno);i<=static_cast<int>(Polje::BlokiranoMina);i++){
		
		
		if(polja[novi_x][novi_y]==static_cast<Polje>(i)){
			
			
			throw std::logic_error("Blokirano polje");
			return Status::NijeKraj;
		}
	}
	
	polja[x][y]=Polje::Posjeceno;

	
	
	
	
	x=novi_x;
	y=novi_y;

	if(polja[x][y]==Polje::Mina) return Status::KrajPoraz;
	
	bool NemaPrazno(true);
	for(int i=0;i<polja.size();i++){
		for(int j=0;j<polja.size();j++){
			if(x==i && y==j) continue;
			if(polja[i][j]==Polje::Prazno){
				NemaPrazno=false;
				break;
			}
		}
	}
	
	if(NemaPrazno) return Status::KrajPobjeda;
	else{
		return Status::NijeKraj;
	}

}
void PrijaviGresku(KodoviGresaka greska){
	std::vector<std::string> ispis{
	"Nerazumljiva komanda!",
	"Komanda trazi parametar koji nije naveden!",
	"Zadan je suvisan parametar nakon komande!",
	"Parametar komande nije ispravan!"
};
for(int i=static_cast<int>(KodoviGresaka::PogresnaKomanda);i<=static_cast<int>(KodoviGresaka::NeispravanParametar);i++){
	if(static_cast<int>(greska)==i){
		std::cout<<ispis[i]<<std::endl;
	}
	
}

}

bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y,KodoviGresaka &greska){
	
	
	


	char a;
	std::vector<char> k{'P','B','D','Z','K'};
//	std::vector<std::string> s{"GL","GL","GD","D","DoD","Do","DoL","L"};
	while(std::cin.peek()==' ' || std::cin.peek()=='\n') std::cin.get();
//	if(std::cin.peek())

	
	a=std::cin.get();

	
//	for(int i=0;i<=k.size();i++){
//		if(a==k[i]){
		if(a!='P' && a!='B' && a!='D' && a!='Z'&& a!='K'){
			greska=KodoviGresaka::PogresnaKomanda;
			return false;
		}
				
			
			if(a=='P'){
				char a2(std::cin.get());
				if(a2=='O'){
				
					while(std::cin.peek()==' ') std::cin.get();
					if(std::cin.peek()!=' ' &&  std::cin.peek()!='\n') {
						greska=KodoviGresaka::SuvisanParametar;
						std::cin.clear();
						std::cin.ignore(100000,'\n');
						return false;
					}
					
					if(std::cin.peek()=='\n'){
					komanda=Komande::PrikaziOkolinu;
					std::cin.clear();
					std::cin.ignore(10000,'\n');
					
					return true;
					}
				}
				if(a2=='>'){
				//	if(cin.peek()==' ') cin.get();
				int  a5,b;
					std::cin>>a5;
					if(!std::cin){
						std::cin.clear();
						std::cin.ignore(10000,'\n');
						greska=KodoviGresaka::NeispravanParametar;
						return false;
					}
					std::cin>>b;
					if(!std::cin){
						std::cin.clear();
						std::cin.ignore(10000,'\n');
						greska=KodoviGresaka::NeispravanParametar;
						return false;
					}
					
				//	cin.ignore();
				//	cin.ignore(10000,'\n');
					while(std::cin.peek()==' ') std::cin.get();
					if(std::cin.peek()!=' ' && std::cin.peek()!='\n') {
						greska=KodoviGresaka::SuvisanParametar;
						return false;
					}
					if(std::cin.peek()=='\n') {
						x=a5;
						y=b;
						
						komanda=Komande::PomjeriDalje;
						return true;
					}
					
			}
			if(a2=='1'){
			//	std::cout<<"--";
			while(std::cin.peek()==' ') std::cin.get();
			
			std::vector<std::string> pravci{"GL","G","GD","D","DoD","Do","DoL","L"};
			std::string s;
			std::cin>>s;
		
		
			bool ima(false);
			for(int m=0;m<8;m++){
				
				if(s==pravci[m]){
					ima=true;
					
					while(std::cin.peek()==' ') std::cin.get();
					if(std::cin.peek()!=' ' && std::cin.peek()!='\n'){
						
					
						std::cin.clear();
						std::cin.ignore(10000,'\n');
						greska=KodoviGresaka::SuvisanParametar;
						return false;
					}
					if(std::cin.peek()=='\n'){
							
						komanda=Komande::PomjeriJednoMjesto;
						smjer=static_cast<Smjerovi>(m);
						
						
						return true;
					}
					
					
				}
			}
				
				if(ima==false){
					greska=KodoviGresaka::NeispravanParametar;
					std::cin.clear();
					std::cin.ignore(10000,'\n');
					return false;
				}
			
				
			
			
			
				
				
			}
			
			if(a2!='1' && a2!='O' && a2!='>') {
				greska=KodoviGresaka::PogresnaKomanda;
				return false;
			}
			
			
		}
		
		
	
		if(a=='B' || a=='D'){
			
			int a1,b;
			std::cin>>a1;
			
			
			if(!std::cin){
				std::cin.clear();
				std::cin.ignore(10000,'\n');
				greska=KodoviGresaka::NeispravanParametar;
				return false;
				
			}
			std::cin>>b;
			
			if(!std::cin){
				std::cin.clear();
				std::cin.ignore(10000,'\n');
				greska=KodoviGresaka::NeispravanParametar;
				return false;
			}
				while(std::cin.peek()==' ') std::cin.get();
					if(std::cin.peek()!=' ' && std::cin.peek()!='\n') {
						
						greska=KodoviGresaka::SuvisanParametar;
						return false;
					}
					if(std::cin.peek()=='\n') {
						
						x=a1;
						y=b;
						std::cin.clear();
						std::cin.ignore(10000,'\n');
						if(a=='B'){
							komanda=Komande::Blokiraj;
							
						}
						if(a=='D'){
							komanda=Komande::Deblokiraj;
						}
						return true;
					}
			
			
			
			
		}
	
		if(a=='Z' || a=='K'){
			
			while(std::cin.peek()==' ') std::cin.get();
			if(std::cin.peek()!=' ' && std::cin.peek()!='\n'){
				std::cin.clear();
				std::cin.ignore(10000,'\n');
				greska=KodoviGresaka::SuvisanParametar;
				return false;
			}
			if(std::cin.peek()=='\n'){
			//	std::cin.clear();
			//	std::cin.ignore(10000,'\n');
				
				if(a=='Z'){
					komanda=Komande::ZavrsiIgru;
					return true;
				}
				if(a=='K'){
					komanda=Komande::KreirajIgru;
			
					return true;
				}
			}
		}
		
		
	
		
		
//	}
	
}
void ZavrsiIgru(Tabla &polja){
	for(int i=0;i<polja.size();i++){
		for(int j=0;j<polja.size();j++){
			polja[i][j]=Polje::Prazno;
		}
	}
	throw std::runtime_error("Igra zavrsena");
}

void IzvrsiKomandu(Komande komanda,Tabla &polja, int &x, int &y, Smjerovi p_smjer=Smjerovi::Gore, int p_x=0, int p_y=0){
	int pozx(0),pozy(0);
	try{
	
	if(komanda==Komande::Blokiraj){
		
			BlokirajPolje(polja,x,y);
			
		}
	if(komanda==Komande::Deblokiraj){
		DeblokirajPolje(polja,x,y);
	}
	if(komanda==Komande::ZavrsiIgru){
		ZavrsiIgru(polja);
	}
	if(komanda==Komande::PomjeriJednoMjesto || komanda==Komande::PomjeriDalje){
		
	
		Status pr;
	
		if(komanda==Komande::PomjeriJednoMjesto){
			
	      pr=Idi(polja,x,y,p_smjer);
	      pozx=x;
	      pozy=y;
		}
		if(komanda==Komande::PomjeriDalje){
			p_x=x;
			p_y=y;
			x=pozx;
			y=pozy;
		
			pr=Idi(polja,x,y,p_x,p_y);
			
			pozx=x;
			pozy=y;
			
		}
		std::cout<<"Tekuca pozicija igraca je ("<<x<<","<<y<<")"<<std::endl;
		if(pr==Status::KrajPoraz){
			std::cout<<"Nagazili ste na minu"<<std::endl;
			ZavrsiIgru(polja);
		}
		if(pr==Status::KrajPobjeda){
			std::cout<<"Bravo, obisli ste sva sigurna polja"<<std::endl;
			ZavrsiIgru(polja);
		}
	}
	if(komanda==Komande::ZavrsiIgru){
		ZavrsiIgru(polja);
	}
	if(komanda==Komande::PrikaziOkolinu){
		
		std::vector<std::vector<int>> mat(PrikaziOkolinu(polja,x,y));
		for(int i=0;i<mat.size();i++){
			for(int j=0;j<mat.size();j++){
				
				std::cout<<mat[i][j]<<" ";
				
			}
			std::cout<<std::endl;
		}
		
		
	}

	if(komanda==Komande::KreirajIgru){
		x=0;
		y=0;
		pozx=0;
		pozy=0;
		std::cout<<"Unesite broj polja: ";
		int n;
		std::cin>>n;
		
		std::vector<std::vector<int>> v(0);
		
		int dim(0);
		
		//boo provjera(true);
		std::cout<<"Unesite pozicije mina: ";
		std::cin.clear();
		std::cin.ignore(10000,'\n');
		
		for(;;){
			int a,b;
			char z;
			
		//	while(std::cin.peek()==' ') std::cin.get();
			z=std::cin.get();
		
			
			if(z=='.') break;
			if(z!='(' ) {
				gr:
				std::cout<<"Greska, unesite ponovo!"<<std::endl;
				std::cin.clear();
				std::cin.ignore(10000,'\n');
				continue;
			}
			if(z=='('){
				std::cin>>a;
			
				if(a>=n || a<0) goto gr;
				z=std::cin.get();
			//	std::cout<<z<<"}}";
				if(z!=','){
					
		     	goto gr;
				}else{
					std::cin>>b;
					if(b>=n || b<0) goto gr;
					
					z=std::cin.get();
					if(z!=')') goto gr;
					else{
						dim++;
						v.resize(dim);
						v[dim-1].push_back(a);
						v[dim-1].push_back(b);
						
						
						std::cin.clear();
						std::cin.ignore(10000,'\n');
						
						
					}
				}
			}
		}
		
	
			
			polja=KreirajIgru(n,v);
			
		}
		
		
	}
		
		catch(std::logic_error e){
	
			
			std::cout<<e.what()<<std::endl;
		}
		catch(std::domain_error s){
		std::cout<<s.what();
	
			
		}
	
	}
	
	
	


int main ()
{
	
	
	
	
	Tabla polja(0);
	int x(0),y(0);
	
	for(;;){
		try{
		std::cout<<"Unesite komandu: ";
		
		Smjerovi smjer;
		KodoviGresaka greska;
		Komande komanda;
		int p_x(0),p_y(0);
		
			bool a(UnosKomande(komanda,smjer,x,y,greska));
			
		
			
			if(a){
			
				IzvrsiKomandu(komanda,polja, x,y,smjer,p_x,p_y);
			}else{
				
				PrijaviGresku(greska);
			}
		}
		catch(std::runtime_error){
	//	std::cout<<e.what()<<std::endl;
		std::cout<<"Dovidjenja!";
		break;
	}
	}
	

	return 0;
}