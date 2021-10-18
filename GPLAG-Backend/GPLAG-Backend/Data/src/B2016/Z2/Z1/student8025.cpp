#include <iostream>
#include <vector>
#include <stdexcept>
#include <complex>
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
	for(int i=0; i<mine.size(); i++){
		if(mine[i].size()!=2) throw std::domain_error("Ilegalan format zadavanja mina");
		for(int j=0; j<mine[i].size(); j++){
			if(mine[i][j]<0 || mine[i][j]>=n) throw std::domain_error("Ilegalne pozicije mina");
		}
	}
	Tabla polje;
	if(n==0) return polje;
	polje.resize(n);
	for(int i=0; i<n; i++){
		polje[i].resize(n);
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			polje[i][j]=Polje::Prazno;
		}
	}
	for(int i=0; i<mine.size(); i++){
			int a(mine[i][0]);
			int b(mine[i][1]);
			if(a==0 && b==0) continue;
			polje[a][b]=Polje::Mina;
			
	}
	return polje;
}
std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y){
	if(x<0 || y<0 || x>polja.size()-1 || y>polja.size()-1) {
		throw std::domain_error("Polje (x,y) ne postoji");
	}
	std::vector<std::vector<int>>povratna(3,std::vector<int>(3));
	if(polja.size()==0) return povratna;
	std::vector<std::vector<int>> m(polja.size(),std::vector<int>(polja.size(),0));
    for(int i=0; i<polja.size(); i++){
    	for(int j=0; j<polja.size(); j++){
    	if(polja[i][j]==Polje::Mina){
    		m[i][j]=1;
    	}else{
    		m[i][j]=0;
    	}
    	}
    }
	std::vector<std::vector<int>> n(polja.size()+4,std::vector<int>(polja.size()+4,0));
for(int i=2; i<polja.size()+2; i++){
	for(int j=2; j<polja.size()+2; j++){
		n[i][j]=m[i-2][j-2];
	}
}
	x=x+2;
	y=y+2;
	int brojac1(-1),brojac2(-1);
	std::vector<int>v[3];
	for(int i=0; i<3; i++){
		v[i].resize(3);
	}
	
	for(int i=x-1; i<=x+1; i++){
		brojac1++;
		if(brojac2==2){
			brojac2=-1;
		}
		for(int j=y-1; j<=y+1; j++){
			brojac2++;
			for(int z=i-1; z<=i+1; z++){
				for(int h=j-1; h<=j+1; h++){
					if(z==i && h==j) continue;
					if(n[z][h]==1){
						(v[brojac1])[brojac2]+=1;
					}
				}
			}
		}
	}
	for(int i=0; i<3; i++){
		povratna[i]=v[i];
	}
	return povratna;
}
void BlokirajPolje(Tabla &polja, int x, int y){
	if(x<0 || y<0 || x>polja.size()-1 || y>polja.size()-1) throw std::domain_error("Polje (x,y) ne postoji");
	if(polja[x][y]==Polje::Prazno){
		polja[x][y]=Polje::BlokiranoPrazno;
	}else if(polja[x][y]==Polje::Mina){
		polja[x][y]=Polje::BlokiranoMina;
	}else if(polja[x][y]==Polje::Posjeceno){
		polja[x][y]=Polje::BlokiranoPosjeceno;
	}
}
void DeblokirajPolje(Tabla &polja, int x, int y){
	if(x<0 || y<0 || x>polja.size()-1 || y>polja.size()-1) throw std::domain_error("Polje (x,y) ne postoji");
if(polja[x][y]==Polje::BlokiranoPrazno){
	polja[x][y]=Polje::Prazno;
}else if(polja[x][y]==Polje::BlokiranoPosjeceno){
	polja[x][y]=Polje::Posjeceno;
}else if(polja[x][y]==Polje::BlokiranoMina){
	polja[x][y]=Polje::Mina;
}
	
}
Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer){
	if(smjer==Smjerovi::GoreLijevo){
		if(x-1<0 || y-1<0) throw std::out_of_range("Izlazak van igrace table");
		if(polja[x-1][y-1]==Polje::BlokiranoPrazno || polja[x-1][y-1]==Polje::BlokiranoPosjeceno || polja[x-1][y-1]==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
	polja[x][y]=Polje::Posjeceno;
	x=x-1;
	y=y-1;
		if(polja[x][y]==Polje::Mina){
			return Status::KrajPoraz;
		}
		for(int i=0; i<polja.size(); i++){
			for(int j=0; j<polja.size(); j++){
				if(i!=x && j!=y && polja[i][j]==Polje::Prazno){
				
				return Status::NijeKraj;
				}
			}
		}
		return Status::KrajPobjeda;
	}else if(smjer==Smjerovi::Gore){
		if(x-1<0) throw std::out_of_range("Izlazak van igrace table");
		if(polja[x-1][y]==Polje::BlokiranoPrazno || polja[x-1][y]==Polje::BlokiranoPosjeceno || polja[x-1][y]==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
polja[x][y]=Polje::Posjeceno;
	x=x-1;
		if(polja[x][y]==Polje::Mina){
		
			return Status::KrajPoraz;
		}
		for(int i=0; i<polja.size(); i++){
			for(int j=0; j<polja.size(); j++){
				if(i!=x && j!=y && polja[i][j]==Polje::Prazno){
					
				return Status::NijeKraj;
				}
			}
		}
		return Status::KrajPobjeda;
		
	}else if(smjer==Smjerovi::GoreDesno){
		
		if(x-1<0 || y+1>polja.size()-1) throw std::out_of_range("Izlazak van igrace table");
		if(polja[x-1][y+1]==Polje::BlokiranoPrazno || polja[x-1][y+1]==Polje::BlokiranoPosjeceno || polja[x-1][y+1]==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");

polja[x][y]=Polje::Posjeceno;
	x=x-1;
	y=y+1;
		if(polja[x][y]==Polje::Mina){
			return Status::KrajPoraz;
		}
		for(int i=0; i<polja.size(); i++){
			for(int j=0; j<polja.size(); j++){
				if(i!=x && j!=y && polja[i][j]==Polje::Prazno){
					
				return Status::NijeKraj;
				}
			}
		}
		return Status::KrajPobjeda;
		
	}else if(smjer==Smjerovi::Desno){
		if(y+1>polja.size()-1) throw std::out_of_range("Izlazak van igrace table");
		if(polja[x][y+1]==Polje::BlokiranoPrazno || polja[x][y+1]==Polje::BlokiranoPosjeceno || polja[x][y+1]==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
	polja[x][y]=Polje::Posjeceno;
	y=y+1;
		if(polja[x][y]==Polje::Mina){
			
			return Status::KrajPoraz;
		}
		for(int i=0; i<polja.size(); i++){
			for(int j=0; j<polja.size(); j++){
				if(i!=x && j!=y && polja[i][j]==Polje::Prazno){
					
				return Status::NijeKraj;
				}
			}
		}
		return Status::KrajPobjeda;
		
	} else if(smjer==Smjerovi::DoljeDesno){
		if((x+1)>polja.size()-1 || (y+1)>polja.size()-1) throw std::out_of_range("Izlazak van igrace table");
		if(polja[x+1][y+1]==Polje::BlokiranoPrazno || polja[x+1][y+1]==Polje::BlokiranoPosjeceno || polja[x+1][y+1]==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
	polja[x][y]=Polje::Posjeceno;
	x+=1;
	y+=1;
		if(polja[x][y]==Polje::Mina){
			return Status::KrajPoraz;
		}
		for(int i=0; i<polja.size(); i++){
			for(int j=0; j<polja.size(); j++){
				if(i!=x && j!=y && polja[i][j]==Polje::Prazno){
			
				return Status::NijeKraj;
				}
			}
		}
		return Status::KrajPobjeda;
		
	} else if(smjer==Smjerovi::Dolje){
		if(x+1>polja.size()-1) throw std::out_of_range("Izlazak van igrace table");
		if(polja[x+1][y]==Polje::BlokiranoPrazno || polja[x+1][y]==Polje::BlokiranoPosjeceno || polja[x+1][y]==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
	polja[x][y]=Polje::Posjeceno;
	x=x+1;
	
		if(polja[x][y]==Polje::Mina){

			return Status::KrajPoraz;
		}
		for(int i=0; i<polja.size(); i++){
			for(int j=0; j<polja.size(); j++){
				if(i!=x && j!=y && polja[i][j]==Polje::Prazno){
					
				return Status::NijeKraj;
				}
			}
		}
		return Status::KrajPobjeda;
	}else if(smjer==Smjerovi::DoljeLijevo){
		if(x+1>polja.size() || y-1<0) throw std::out_of_range("Izlazak van igrace table");
		if(polja[x+1][y-1]==Polje::BlokiranoPrazno || polja[x+1][y-1]==Polje::BlokiranoPosjeceno || polja[x+1][y-1]==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
	polja[x][y]=Polje::Posjeceno;
	x=x+1;
	y=y-1;
		if(polja[x][y]==Polje::Mina){

			return Status::KrajPoraz;
		}
		for(int i=0; i<polja.size(); i++){
			for(int j=0; j<polja.size(); j++){
				if(i!=x && j!=y && polja[i][j]==Polje::Prazno){
				
				return Status::NijeKraj;
				}
			}
		}
		return Status::KrajPobjeda;
	}else if(smjer==Smjerovi::Lijevo){
		if(y-1<0 )throw std::out_of_range("Izlazak van igrace table");
		if(polja[x][y-1]==Polje::BlokiranoPrazno || polja[x][y-1]==Polje::BlokiranoPosjeceno || polja[x][y-1]==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
	polja[x][y]=Polje::Posjeceno;
	y=y-1;
		if(polja[x][y]==Polje::Mina){

			return Status::KrajPoraz;
		}
		for(int i=0; i<polja.size(); i++){
			for(int j=0; j<polja.size(); j++){
				if(i!=x && j!=y && polja[i][j]==Polje::Prazno){
				
				return Status::NijeKraj;
				}
			}
		}
		return Status::KrajPobjeda;
		
	}
	return Status::NijeKraj;
}
Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y){
	if(novi_x<0 || novi_x>polja.size()-1 || novi_y<0 || novi_y>polja.size()-1) throw std::out_of_range("Izlazak van igrace table");
	if(polja[novi_x][novi_y]==Polje::BlokiranoPrazno || polja[novi_x][novi_y]==Polje::BlokiranoPosjeceno || polja[novi_x][novi_y]==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
	x=novi_x;
	y=novi_y;
	polja[x][y]=Polje::Posjeceno;
if(polja[x][y]==Polje::Mina){
			return Status::KrajPoraz;
		}
		for(int i=0; i<polja.size(); i++){
			for(int j=0; j<polja.size(); j++){
				if(i!=x && j!=y && polja[i][j]==Polje::Prazno){

				return Status::NijeKraj;
				}
			}
		}
			return Status::KrajPobjeda;
	}


void PrijaviGresku(KodoviGresaka kod){
	if(kod==KodoviGresaka::PogresnaKomanda){
		std::cout<<"Nerazumljiva komanda!"<<std::endl;
	}else if(kod==KodoviGresaka::NedostajeParametar){
		std::cout<<"Komanda trazi parametar koji nije naveden!"<<std::endl;
	} else if(kod==KodoviGresaka::NeispravanParametar){
		std::cout<<"Parametar komande nije ispravan!"<<std::endl;
	} else if(kod==KodoviGresaka::SuvisanParametar){
		std::cout<<"Zadan je suvisan parametar nakon komande!"<<std::endl;
	}
}
int Provjeri(std::string s,  std::vector<std::string>h, int &x, int &y){
	std::vector<int>v(10);
	for(int i=0; i<10; i++){
		v[i]=-11;
	}
	int n, b, provjera(0),upamti(-1),brojac(-1);
	if(x==0){
	while(y<s.length()){
		while(s[y]==' ') y++;
		if(y==s.length()) break;
		n=y;
			for(int i=0; i<h.size(); i++){
		y=n;
		provjera=0;
		for(int j=0; j<h[i].length(); j++){
			if(s[y]!=(h[i])[j]){
				provjera=1;
				break;
			}
			y++;
		}
		if((provjera==0 && y==s.length()) || (provjera==0 && s[y]==' ')){
			upamti=i;
			while(y!=s.length()){
					if(s[y]!=' '){
						return 10;
					}
				y++;
				
			}
			return upamti;
		}
	
	
	}
	return 9;
	y++;
	}
	return 11; 
	}
	else if(x>0 && x<4){
		while(y<s.length()){
			int predznak(1);
			while(s[y]==' ') y++;
			if(s[y]=='-') predznak=-1;
			else if(s[y]>47 && s[y]<58){
				b=0;
			
			while(s[y]>47 && s[y]<58){
			b=b*10 + s[y]-'0';
					y++;
				}   
				b*=predznak;
				brojac++;
				v[brojac]=b;
			}
			if(y!=s.length() && s[y]!=' ' && s[y]!='-'){
				if(v[0]!=-11 && v[1]!=-11){
					return 10;
				}
				return 9;
			}
				y++;
			}
			if(v[2]!=-11){
				
	return 10;
			}
				 if(v[1]==-11){
					return 11;
				}
				if(v[0]!=-11 && v[1]!=-11){
				x=v[0];
				y=v[1];
				return 12;
				}
		}
	 else if(x>=4){
		while(y!=s.length()){
			if(s[y]!=' '){
				return 10;
			}
			
			y++;
		}
		if(y==s.length()) return 12;
		
	}
	
	
return 10;

}
bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska){
	int i(0),n(0),provjera(0),upamti1(-1),upamti2(-1);
	std::string recenica;
	std::getline(std::cin,recenica);
std::vector<std::string>v{"P1","P>","B", "D", "PO", "Z", "K"};
std::vector<std::string>h{"GL", "G", "GD", "D", "DoD", "Do", "DoL","L"};
while(i<recenica.length()){
	while(recenica[i]==' ') i++;
	 n=i;
	for(int j=0; j<v.size(); j++){
		i=n;
		provjera=0;
		for(int z=0; z<v[j].length(); z++){
			if(recenica[i]!=(v[j])[z]){
				provjera=1;
				break;
			}
			i++;
		}
		if((provjera==0 && i==recenica.length())||(provjera==0 && recenica[i]==' ') ){
			upamti1=j;
			upamti2=i;
			break;
		}
	}
	if(provjera==0) break;
		i++;
		if(provjera==1 && i>n) break;
}
	int nesto=upamti1;
	if(upamti1==-1){
		greska=KodoviGresaka::PogresnaKomanda;
		return false;
	}
	if(upamti1==0){
	int p=Provjeri(recenica,h,upamti1,upamti2);
     if(p>=0 && p<8){
     	komanda=Komande::PomjeriJednoMjesto;
     	if(p==0){
     	smjer=Smjerovi::GoreLijevo;	
     	}else if(p==1){
     		smjer=Smjerovi::Gore;
     	}
     	else if(p==2){
     		smjer=Smjerovi::GoreDesno;
     	}
     	else if(p==3){
     		smjer=Smjerovi::Desno;
     	}
     	else if(p==4){
     		smjer=Smjerovi::DoljeDesno;
     	}
     	else if(p==5){
     		smjer=Smjerovi::Dolje;
     	}
     	else if(p==6){
     		smjer=Smjerovi::DoljeLijevo;
     	}else if(p==7){
     		smjer=Smjerovi::Lijevo;
     	}
     	return true;
     	
     }else if(p==9){
     	greska=KodoviGresaka::NedostajeParametar; 
     return false;
     }else if(p==10){
     	greska=KodoviGresaka::SuvisanParametar;
     	return false;
     }else if(p==11){
     	greska=KodoviGresaka::NeispravanParametar;
     	return false;
     }
	}
	else if(upamti1>0 && upamti1<4){
	int d=Provjeri(recenica,h,upamti1,upamti2);
	if(d==12){
		if(nesto==1){
			komanda=Komande::PomjeriDalje;
		}else if(nesto==2){
			komanda=Komande::Blokiraj;
		}else if(nesto==3){
			komanda=Komande::Deblokiraj;
		}
	x=upamti1;
	y=upamti2;
	return true;
	}
	else if(d==9){
     	greska=KodoviGresaka::NedostajeParametar; 
     return false;
     }else if(d==10){
     	greska=KodoviGresaka::SuvisanParametar;
     	return false;
     }else if(d==11){
     	greska=KodoviGresaka::NeispravanParametar;
     	return false;
     }
	}else if(upamti1>=4){
		int c=Provjeri(recenica,h,upamti1,upamti2);
		if(c==12){
			if(nesto==4){
				komanda=Komande::PrikaziOkolinu;
				return true;
			}else if(nesto==5){
				komanda=Komande::ZavrsiIgru;
				return true;
			}else if(nesto==6){
				komanda=Komande::KreirajIgru;
				return true;
			}
			

		}else if(c==10){
			greska=KodoviGresaka::SuvisanParametar;
     	return false;
		}
	}

return false;
}
void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y,
Smjerovi p_smjer = Smjerovi::Gore, int p_x = 0, int p_y = 0){
	int n,brojac(0);
	Status qvo;
	std::vector<std::vector<int>> v(10,std::vector<int>(2));
	std::complex<int> z;
	if(komanda==Komande::KreirajIgru){
		std::cout<<"Unesite broj polja: ";
		std::cin>>n;
		std::cout<<"Unesite pozicije mina: ";
		while(std::cin.peek()!='.'){
			std::cin>>z;
			if(std::cin.get()=='.'){
			std::cin.clear();
			std::cin.ignore(10000,'\n');
				break;
			} 
		while(!std::cin || z.real()<0 || z.real()>=n || z.imag()<0 || z.imag()>=n){
			std::cout<<"Greska, unesite ponovo!"<<std::endl;
			std::cin.clear();
			std::cin.ignore(10000,'\n');
			std::cin>>z;
		}
		v[brojac][0]=z.real();
		v[brojac][1]=z.imag();
		brojac++;
		}
		std::cin.clear();
		std::cin.ignore(10000,'\n');
		try{
			v.resize(brojac);
		polja=KreirajIgru(n,v);
		}catch(std::domain_error izuzetak){
			std::cout<<izuzetak.what()<<std::endl;
		}
	}
	else if(komanda==Komande::PomjeriJednoMjesto){
		try{
			
		qvo=Idi(polja,x,y,p_smjer);
		}
		catch(std::out_of_range izuzetak){
			std::cout<<izuzetak.what()<<std::endl;
		}catch(std::logic_error izuzetak){
			std::cout<<izuzetak.what()<<std::endl;
		}
	if(qvo==Status::NijeKraj){
		std::cout<<"Tekuca pozicija igraca je ("<<x<<","<<y<<")"<<std::endl;
	}else if(qvo==Status::KrajPoraz){
		std::cout<<"Nagazili ste na minu"<<std::endl;
		for(int i=0; i<polja.size(); i++){
			for(int j=0; j<polja.size(); j++){
				polja[i][j]=Polje::Prazno;
			}
		}
	std::cout<<"Igra zavrsena"<<std::endl;
		throw std::runtime_error("Igra zavrsena");
	}else if(qvo==Status::KrajPobjeda){
		std::cout<<"Bravo, obisli ste sva sigurna polja"<<std::endl;
		for(int i=0; i<polja.size(); i++){
			for(int j=0; j<polja.size(); j++){
				polja[i][j]=Polje::Prazno;
			}
		}
	std::cout<<"Igra zavrsena"<<std::endl;
		throw std::runtime_error("Igra zavrsena");
	}
	
	}else if(komanda==Komande::PomjeriDalje){
		try{
		p_x=x;
		p_y=y;
			qvo=Idi(polja,x,y,p_x,p_y);
		if(qvo==Status::NijeKraj){
		std::cout<<"Tekuca pozicija igraca je ("<<x<<","<<y<<")"<<std::endl;
	}else if(qvo==Status::KrajPoraz){
		std::cout<<"Nagazili ste na minu"<<std::endl;
		for(int i=0; i<polja.size(); i++){
			for(int j=0; j<polja.size(); j++){
				polja[i][j]=Polje::Prazno;
			}
		}
	std::cout<<"Igra zavrsena"<<std::endl;
		throw std::runtime_error("Igra zavrsena");
	}else if(qvo==Status::KrajPobjeda){
		std::cout<<"Bravo, obisli ste sva sigurna polja"<<std::endl;
		for(int i=0; i<polja.size(); i++){
			for(int j=0; j<polja.size(); j++){
				polja[i][j]=Polje::Prazno;
			}
		}
		throw std::runtime_error("Igra zavrsena");
	
	}
		}catch(std::out_of_range izuzetak){
				std::cout<<izuzetak.what()<<std::endl;
		}
		catch(std::logic_error izuzetak){
			std::cout<<izuzetak.what()<<std::endl;
		}
	}else if(komanda==Komande::Blokiraj){
	try{
		BlokirajPolje(polja,x,y);
	}catch(std::domain_error){
		std::cout<<"Polje ("<<x<<","<<y<<") ne postoji"<<std::endl;
	}
	}else if(komanda==Komande::Deblokiraj){
		try{
		DeblokirajPolje(polja,x,y);
		}catch(std::domain_error){
			std::cout<<"Polje ("<<x<<","<<y<<") ne postoji"<<std::endl;
		}
	}else if(komanda==Komande::PrikaziOkolinu){
		std::vector<std::vector<int>> m(3,std::vector<int>(3));
		try{
			m=PrikaziOkolinu(polja,x,y);
          for(int i=0; i<3; i++){
          	for(int j=0; j<3; j++){
          	std::cout<<m[i][j]<<" ";
          	}
          	std::cout<<std::endl;
          }
		}
		catch(std::domain_error){
			std::cout<<"Polje ("<<x<<","<<y<<") ne postoji"<<std::endl;
		}
	} else if(komanda==Komande::ZavrsiIgru){
		for(int i=0; i<polja.size(); i++){
			for(int j=0; j<polja.size(); j++){
				polja[i][j]=Polje::Prazno;
			}
		}
		throw std::runtime_error("Igra zavrsena");
	}
}
int main (){
	Komande komanda; 
	Smjerovi smjer;
	int x(0), y(0),a(0),b(0);
	Tabla polja;
KodoviGresaka greska;
	for(;;){
			std::cout<<"Unesite komandu: ";
			try{
				if(UnosKomande(komanda,smjer,x,y,greska)==true){
				IzvrsiKomandu(komanda,polja,x,y,smjer,a,b);
			}else{
				PrijaviGresku(greska);
			}
		}catch(std::runtime_error){
			std::cout<<"Dovidjenja!";
			break;
		}
		
	}

	return 0;
}