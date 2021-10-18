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
#include <sstream>

enum class Polje{
	Prazno,Posjeceno,Mina,BlokiranoPrazno,BlokiranoPosjeceno,BlokiranoMina
};
enum class Smjerovi{
	GoreLijevo,Gore,GoreDesno,Desno,DoljeDesno,Dolje,DoljeLijevo,Lijevo
};
enum class Status{
	NijeKraj,KrajPoraz,KrajPobjeda
};
enum class KodoviGresaka{
	PogresnaKomanda,NedostajeParametar,SuvisanParametar,NeispravanParametar
};
enum class Komande{
	PomjeriJednoMjesto,PomjeriDalje,Blokiraj,Deblokiraj,PrikaziOkolinu,ZavrsiIgru,KreirajIgru
};


typedef std::vector<std::vector<Polje>> Tabla;
/*void ispisiTablu(std::vector<std::vector<Polje>> polja){
   for(int i = 0; i < polja.size(); i++) {
          for(int j = 0; j < polja[i].size(); j++) std::cout << int(polja[i][j]) << " ";
          std::cout << std::endl;
        }
}*/


Tabla KreirajIgru(int n,const std::vector<std::vector<int>> &mine){
	Tabla podloga;
/*	std::cout<<"HALOOO"<<std::endl;*/
//	std::cout<<mine.size();
	/*for(int i=0;i<mine.size();i++){
		for(int j=0;j<mine[i].size();j++){
			std::cout<<mine[i][j]<<" ";
		}
		std::cout<<std::endl;
	}*/
	if(n<=0) throw std::domain_error("Ilegalna velicina\n");
	for(int i=0;i<mine.size();i++){
		for(int j=0;j<mine[i].size();j++){
			if(mine[i][j]>n) throw std::domain_error("Ilegalne pozicije mina\n");
			else if(mine[i].size()!=2) throw std::domain_error("Ilegalan format zadavanja mina\n");
		}
	}
	podloga.resize(n);
	for(int i=0;i<n;i++) podloga[i].resize(n);
	for(int i=0;i<mine.size();i++){
			podloga[mine[i][0]][mine[i][1]]=Polje::Mina;
		}
	for(int i=0;i<n;i++){
		for(int j=0;j<podloga[i].size();j++){
			if(podloga[i][j]!=Polje::Mina) podloga[i][j]=Polje::Prazno;
		}
	}
	return podloga;
}
template<typename T> 
std::string PretvoriUString(T x){
	std::ostringstream s; s<<x; 
	return s.str();
}
int PomocnaZa_Okolinu(const Tabla &podloga,int x,int y){
	int br(0);
	int z=x-1;
	int k=y-1;
	if(z<0) z=0;
	if(k<0) k=0;
	int dokle1(x+1),dokle2(y+1);
	if(dokle1>=podloga.size()) dokle1=podloga.size()-1;
	if(dokle2>=podloga[0].size()) dokle2=podloga[0].size()-1;
	for(int i=z;i<=dokle1;i++){
		for(int j=k;j<=dokle2;j++){
			if(podloga[i][j]==Polje::Mina) br++;
		}
	}
	if(podloga[x][y]==Polje::Mina) br--;
	return br;
}

std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polje,int x,int y){
	std::vector<std::vector<int>> matrica;
	matrica.resize(3);
	int m(0);
	std::cout<<"OVDJE JE X :   "<<x<<std::endl;
	if(x>=polje.size() || y>=polje[0].size()){ std::string s="Polje ("+PretvoriUString(x)+","+PretvoriUString(y)+") ne postoji\n"; throw std::domain_error(s); }
				int z(x-1);
				int k(y-1);
				if(k<0) k=0;
				if(z<0) z=0;
				int dokle1(x+1);
				int dokle2(y+1);
				if((x+1)>=polje.size()) dokle1=polje.size()-1;
				if(dokle2>=polje[0].size()) dokle2=polje[0].size()-1;
				for(int n=z;n<=dokle1;n++){
					for(int l=k;l<=dokle2;l++){
				matrica[m].push_back(PomocnaZa_Okolinu(polje,n,l));
			}
			m++;
		}
return matrica;
}
void BlokirajPolje(Tabla &polja,int x,int y){
	
	if(x>=polja.size() || y>=polja[0].size()){std::string s="Polje ("+PretvoriUString(x)+","+PretvoriUString(y)+") ne postoji\n"; throw std::domain_error(s);}
	if(polja[x][y]==Polje::Prazno) polja[x][y]=Polje::BlokiranoPrazno;
	else if(polja[x][y]==Polje::Mina) polja[x][y]=Polje::BlokiranoMina;
	else if(polja[x][y]==Polje::Posjeceno) polja[x][y]=Polje::BlokiranoPosjeceno;
}

void DeblokirajPolje(Tabla &polja,int x,int y){
	if(x>=polja.size() || y>=polja[0].size()){std::string s="Polje ("+PretvoriUString(x)+","+PretvoriUString(y)+") ne postoji"; throw std::domain_error(s);}
	if(polja[x][y]==Polje::BlokiranoPrazno) polja[x][y]=Polje::Prazno;
	else if(polja[x][y]==Polje::BlokiranoMina) polja[x][y]=Polje::Mina;
	else if(polja[x][y]==Polje::BlokiranoPosjeceno) polja[x][y]=Polje::Posjeceno;
}

Status Idi(Tabla &polja,int &x,int &y,Smjerovi smjer){
	int a(0);
	bool b=true;
	if(smjer==Smjerovi::Gore){ if((x-1)<0) throw std::out_of_range("Izlazak van igrace table\n");
	  else if(polja[x-1][y]==Polje::BlokiranoPosjeceno || polja[x-1][y]==Polje::BlokiranoPrazno || polja[x-1][y]==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
	  polja[x][y]=Polje::Posjeceno;
	  if(polja[x-1][y]==Polje::Mina) a=1;
	  x=x-1;
	}
	if(smjer==Smjerovi::GoreLijevo){
	if(((x-1)<0) || ((y-1)<0)) throw std::out_of_range("Izlazak van igrace table\n");
	else if(polja[x-1][y-1]==Polje::BlokiranoPosjeceno || polja[x-1][y-1]==Polje::BlokiranoPrazno || polja[x-1][y-1]==Polje::BlokiranoMina) throw std::logic_error("Blokriano polje\n");
	polja[x][y]=Polje::Posjeceno;
	if(polja[x-1][y-1]==Polje::Mina) a=1;
	x=x-1;
	y=y-1;
	}
	if(smjer==Smjerovi::GoreDesno){
		if(((x-1)<0) || ((y+1)>polja.size())) throw std::out_of_range("Izlazak van igrace table\n");
	else if(polja[x-1][y+1]==Polje::BlokiranoPosjeceno || polja[x-1][y+1]==Polje::BlokiranoPrazno || polja[x-1][y+1]==Polje::BlokiranoMina) throw std::logic_error("Blokriano polje\n");
	polja[x][y]=Polje::Posjeceno;
	if(polja[x-1][y+1]==Polje::Mina) a=1;
	x=x-1;
	y=y+1;
	}
	if(smjer==Smjerovi::Lijevo){
		if((y-1)<0) throw std::out_of_range("Izlazak van igrace table\n");
		else if(polja[x][y-1]==Polje::BlokiranoPosjeceno || polja[x][y-1]==Polje::BlokiranoPrazno || polja[x][y-1]==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
	polja[x][y]=Polje::Posjeceno;
	if(polja[x][y-1]==Polje::Mina) a=1;
	y=y-1;
	}
	if(smjer==Smjerovi::Desno){
		if((y+1)>polja.size()) throw std::out_of_range("Izlazak van igrace table\n");
		else if(polja[x][y+1]==Polje::BlokiranoPosjeceno || polja[x][y+1]==Polje::BlokiranoPrazno || polja[x][y+1]==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje\n");
		polja[x][y]=Polje::Posjeceno;
		if(polja[x][y+1]==Polje::Mina) a=1;
		y=y+1;
	}
	if(smjer==Smjerovi::Dolje){
		if((x+1)>polja.size()){ throw std::out_of_range("Izlazak van igrace table\n");}
		else if (polja[x+1][y]==Polje::BlokiranoPosjeceno || polja[x+1][y]==Polje::BlokiranoPrazno || polja[x+1][y]==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje\n");
	polja[x][y]=Polje::Posjeceno;
	if(polja[x+1][y]==Polje::Mina) a=1;
	x+=1;
	}
	if(smjer==Smjerovi::DoljeLijevo){
		if(((x+1)>polja.size()) || ((y-1)<0)) throw std::out_of_range("Izlazak van igrace table\n");
		else if(polja[x+1][y-1]==Polje::BlokiranoPosjeceno || polja[x+1][y-1]==Polje::BlokiranoPrazno || polja[x+1][y-1]==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje\n");
	polja[x][y]=Polje::Posjeceno;
	if(polja[x+1][y-1]==Polje::Mina) a=1;
	x=x+1;
	y=y-1;
	}
	if(smjer==Smjerovi::DoljeDesno){
		if(((x+1)>polja.size()) ||((y+1)>polja.size())) throw std::out_of_range("Izlazak van igrace table\n");
		else if(polja[x+1][y+1]==Polje::BlokiranoPosjeceno || polja[x+1][y+1]==Polje::BlokiranoPrazno || polja[x+1][y+1]==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje\n");
	polja[x][y]=Polje::Posjeceno;
	if(polja[x+1][y+1]==Polje::Mina) a=1;
	x=x+1;
	y=y+1;
	}
	for(int i=0;i<polja.size();i++){
		for(int j=0;j<polja[i].size();j++){
			if(polja[i][j]==Polje::Prazno) b=false;
		}
	}
	if(a==1){
		for(int i=0;i<polja.size();i++){
			for(int j=0;j<polja[i].size();j++){
				polja[i][j]=Polje::Prazno;
			}
		}
		return Status::KrajPoraz;
	}
	if(b){
		return Status::KrajPobjeda;
	}
	return Status::NijeKraj;
}

Status Idi(Tabla &polja,int &x,int &y,int novi_x,int novi_y){
	int a(0);
	bool b(true);
		
	if((novi_x-x)<0 || (novi_x-x)>polja.size() || (novi_y-y)<0 || (novi_y-y)>polja.size()) throw std::out_of_range("Izlazak van igrace table\n");
	else if(polja[novi_x][novi_y]==Polje::BlokiranoPosjeceno || polja[novi_x][novi_y]==Polje::BlokiranoPrazno || polja[novi_x][novi_y]==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje\n");
	polja[x][y]=Polje::Posjeceno;
	   x=novi_x;
	   y=novi_y;
    if(polja[novi_x][novi_y]==Polje::Mina) a=1;
    for(int i=0;i<polja.size();i++){
    	for(int j=0;j<polja[i].size();j++){
    		if(polja[i][j]==Polje::Prazno) b=false;
    	}
    }
    if(a==1){
    	for(int i=0;i<polja.size();i++){
    		for(int j=0;j<polja[i].size();j++){
    			polja[i][j]=Polje::Prazno;
    		}
    	}
    	return Status::KrajPoraz;
    }
    if(b){
    	return Status::KrajPobjeda;
    }
    return Status::NijeKraj;

}
void PrijaviGresku(KodoviGresaka greska){
	
	if(greska==KodoviGresaka::PogresnaKomanda) std::cout<<"Nerazumljiva komanda!"<<std::endl;
	else if(greska==KodoviGresaka::NedostajeParametar) std::cout<<"Komanda trazi parametar koji nije naveden!"<<std::endl;
	else if(greska==KodoviGresaka::NeispravanParametar) std::cout<<"Parametar komande nije ispravan!"<<std::endl;
	else if(greska==KodoviGresaka::SuvisanParametar) std::cout<<"Zadan je suvisan parametar nakon komande!"<<std::endl;
	
}

int PretvoriuCifre(std::string &s,int pocetak,int kraj){
	int broj(0),k(1);
	pocetak--;
	kraj--;
	while(kraj!=pocetak){
		broj+=(s[kraj]-'0')*k;
		k++;
		kraj--;
	}
	return broj;
}

bool UnosKomande(Komande &komanda,Smjerovi &smjer,int &x,int &y,KodoviGresaka &greska){
	std::string s;
	//bool tacna_komanda=true;
	std::getline(std::cin,s);
	//for(int i=0;i<s.size();i++){ if(s[i]!=' ' && s[i]!='P' && s[i]!='>' && s[i]!='D' && s[i]!='1' && s[i]!='O' && s[i]!='B' && s[i]!='K' && s[i]!='Z' && !(s[i]>='0' && s[i]<='9') && s[i]!='L'){ greska=KodoviGresaka::PogresnaKomanda; return false;}}
	for(int i=0;i<s.length();i++){
		if(s[i]==' '){ while(s[i]==' ' && i<s.length()-1) i++;}
		if(s[i]=='P'){
			if(i<s.size()-1) i++;
			if(s[i]!='1' && s[i]!='>' && s[i]!='O'){ greska=KodoviGresaka::PogresnaKomanda; return false;}
			if(s[i]=='1'){
				if(i<s.size()-1) i++;
				if(s[i]==' ' && i<s.length()-1){ while(s[i]==' ' && i<s.length()-1) i++;}
				if(i==s.length()-1 && (s[i]==' ' || s[i]=='1')){greska=KodoviGresaka::NedostajeParametar; return false;}
				if(s[i]=='G'){
					if(i<s.size()-1) i++;
					if(s[i]!=' ' && s[i]!='L' && s[i]!='D' && s[i]!=s.length()-1 && s[i]!='G'){greska=KodoviGresaka::PogresnaKomanda; return false;}
					if(s[i]==' ' && i<s.length()-1){
						while(s[i]==' ' && i<s.length()-1) i++;}
					if(s[i]=='L'){
						if(i<s.size()-1) i++;
						if(s[i]!=' ' && i<s.length()-1){ greska=KodoviGresaka::SuvisanParametar;return false;}
						if(s[i]==' ' && i<s.length()-1){
							while(s[i]==' ' && i<s.length()-1) i++;}
							if(i==s.length()-1){komanda=Komande::PomjeriJednoMjesto; smjer=Smjerovi::GoreLijevo; return true;}
						
					}
					else if(s[i]=='D'){
						if(i<s.size()-1) i++;
						if(s[i]!=' ') { greska=KodoviGresaka::SuvisanParametar; return false;}
						if(s[i]==' ' && i<s.length()-1){
							while(s[i]==' ' && i<s.length()-1) i++;}
							if(i==s.length()-1){ komanda=Komande::PomjeriJednoMjesto; smjer=Smjerovi::GoreDesno; return true;}
						}
				  if(i==s.length()-1){komanda=Komande::PomjeriJednoMjesto; smjer=Smjerovi::Gore; return true;}
				}
				else if(s[i]=='D'){
					if(i<s.size()-1) i++;
					if(s[i]=='o'){
						if(i<s.size()-1) i++;
						  if(s[i]=='D'){
						  	if(i<s.size()-1) i++;
						  	if(s[i]==' ' && i<s.size()-1){while(s[i]==' ' && i<s.size()-1) i++;}
						  	if(i==s.size()-1) {
						  		komanda=Komande::PomjeriJednoMjesto;
						  		smjer=Smjerovi::DoljeDesno;
						  		return true;
						  	}
						  	else {
						  		greska=KodoviGresaka::SuvisanParametar;
						  	}
						  }
						  if(s[i]=='L'){
						  	if(i<s.size()-1) i++;
						  	if(s[i]==' ' && i<s.size()-1){ while(s[i]==' ' && i<s.size()-1) i++;}
						  	if(i==s.size()-1){
						  		komanda=Komande::PomjeriJednoMjesto;
						  		smjer=Smjerovi::DoljeLijevo;
						  		return true;
						  	}
						  	else {
						  		greska=KodoviGresaka::SuvisanParametar;
						  	}
						  }
						  if(s[i]==' ' && i<s.size()-1){ while(s[i]==' ' && i<s.size()-1) i++;}
						  if(i==s.size()-1) { komanda=Komande::PomjeriJednoMjesto; smjer=Smjerovi::Dolje; return true;}
						  else {
						  	greska=KodoviGresaka::PogresnaKomanda;
						  	return false;
						  }
					}
					if(s[i]==' ' && i<s.size()-1){ while(s[i]==' ' && i<s.size()-1) i++;}
					if(i==s.size()-1){ komanda=Komande::PomjeriJednoMjesto; smjer=Smjerovi::Desno; return true;}
					else {
						greska=KodoviGresaka::PogresnaKomanda; return false;
					}
				}
				else if(s[i]=='L'){
					if(i<s.size()-1) i++;
					if(s[i]==' ' && i<s.size()-1){ while(s[i]==' ' && i<s.size()-1) i++;}
					if(i==s.size()-1){ komanda=Komande::PomjeriJednoMjesto; smjer=Smjerovi::Lijevo; return true;}
					else
					{
						greska=KodoviGresaka::PogresnaKomanda;
						return false;
					}
				}
				else {
					greska=KodoviGresaka::NeispravanParametar; return false;}
				}
				if(s[i]=='>'){
					if(i<s.size()-1) i++;
					if(s[i]==' ' && i<s.length()-1){ while(s[i]==' ' && i<s.length()-1) i++;}
					if(i==s.length()-1){greska=KodoviGresaka::NedostajeParametar; return false;}
					if(s[i]>='0' && s[i]<='9'){
						int k=i;
						//for(int j=i;j<s.size();j++){ if(s[j]!=' ' && !(s[j]>='0' && s[j]<='9')) greska=KodoviGresaka::PogresnaKomanda; return false;}
						while(s[i]>='0' && s[i]<='9') i++;
						x=PretvoriuCifre(s,k,i);
						if(s[i]==' ' && i<s.length()-1){
							while(s[i]==' ' && i<s.length()-1) i++;
						}
						if(s[i]>='0' && s[i]<='9'){
							int k=i;
							while(s[i]>='0' && s[i]<='9') i++;
						   y=PretvoriuCifre(s,k,i);
							for(int z=i;z<s.size();z++) if(s[z]!=' '){ greska=KodoviGresaka::SuvisanParametar; return false ;}
							komanda=Komande::PomjeriDalje;
						}
					}
					else {
						greska=KodoviGresaka::NeispravanParametar;
						return false;
					}
				}	
				//else { greska=KodoviGresaka::PogresnaKomanda; return false;}
				if(s[i]=='O'){

				if(i<s.length()-1) i++;
        if(s[i]==' ' && i<s.length()-1){ while(s[i]==' ' && i<s.length()-1) i++;}
        if(i==s.length()-1) {komanda=Komande::PrikaziOkolinu; return true;}
        else { 
        	greska=KodoviGresaka::PogresnaKomanda;
        	return false;
				}
	    }
	}	
	    else if(s[i]=='B'){
	    	if(i<s.size()-1) i++;
	    	if(s[i]==' ' && i<s.length()-1){ while(s[i]==' ' && i<s.length()-1) i++;}
	    	if(i==s.size()-1){greska=KodoviGresaka::NedostajeParametar; return false;}
	    	if(s[i]>='0' && s[i]<='9'){
	    		int k=i;
	    		while(s[i]>='0' && s[i]<='9') i++;
	    		x=PretvoriuCifre(s,k,i);
	    		if(s[i]==' ' && i<s.length()-1){
	    		while(s[i]==' ' && i<s.length()-1) i++;}
	    		if(s[i]>='0' && s[i]<='9'){
	    			int k=i;
	    			while(s[i]>='0' && s[i]<='9') i++;
	    			y=PretvoriuCifre(s,k,i);
	    			for(int z=i;z<s.size();z++) if(s[z]!=' '){ greska=KodoviGresaka::SuvisanParametar;  return false;} 
	    			komanda=Komande::Blokiraj;
	    		}
	    	}
	    	else{
	    		greska=KodoviGresaka::PogresnaKomanda;
	    		return false;
	    	}
 	    }
 	    else if(s[i]=='D'){
 	    	 if(i<s.size()-1)i++;
 	    	if(s[i]==' ' && i<s.size()-1){while(s[i]==' ' && i<s.size()-1) i++;}
 	    	if(i==s.size()-1){greska=KodoviGresaka::NedostajeParametar; return false;}
 	    	if(s[i]>='0' && s[i]<='9'){
 	    		int k=i;
 	    		while(s[i]>='0' && s[i]<='9') i++;
 	    		x=PretvoriuCifre(s,k,i);
 	    		if(s[i]==' ' && i<s.size()-1) { while(s[i]==' ' && i<s.size()-1) i++;}
 	    		if(s[i]>='0' && s[i]<='9'){int k=i; while(s[i]>='0' && s[i]<='9') i++;
 	    		y=PretvoriuCifre(s,k,i);
 	    		}
 	    		for(int z=i;z<s.size();z++) if(s[z]!=' '){ greska=KodoviGresaka::PogresnaKomanda; return false;}
 	    		komanda=Komande::Deblokiraj;
 	    	}
 	    	else {
 	    		greska=KodoviGresaka::PogresnaKomanda; return false;
 	    	}
 	    }
	    else if(s[i]=='Z'){
	    	if(i<s.size()-1) i++;
	    	if(s[i]==' ' && i<s.size()-1) {while(s[i]==' ' && i<s.size()-1) i++;}
	    	if(i==s.size()-1) komanda=Komande::ZavrsiIgru;
	    	else { greska=KodoviGresaka::PogresnaKomanda; return false;}
	    }
	    else if(s[i]=='K'){
	    	if(i<s.size()-1) i++;
	    	while(s[i]==' ' && i<s.size()-1) i++;
	    	if(i==s.size()-1) komanda=Komande::KreirajIgru;
	    	else { greska=KodoviGresaka::SuvisanParametar; return false;}
	    }
	    else {
	    	greska=KodoviGresaka::PogresnaKomanda;
	    	return false;
	    }
	}
	return true;
	
}

void IzvrsiKomandu(Komande komanda,Tabla &polja,int &x,int &y,Smjerovi p_smjer=Smjerovi::Gore,int p_x=0,int p_y=0){
	std::vector<std::vector<int>> v;
	int k(0),br3(1);
	if(komanda==Komande::KreirajIgru){
		int n(0);
		std::cout<<"Unesite broj polja: ";
		std::cin>>n;
		std::cout<<"Unesite pozicije mina: ";
		std::cin.clear();
		std::cin.ignore(1000,'\n');
        bool a(true);
        for(;;){
        bool b(true);
        std::string s;
        int br(0),br1(0);
        std::getline(std::cin,s);
        if(!a){ break;}
        for(int i=0;i<s.size();i++){
        	if(s[0]=='.') {a=false; break;}
        	if(s.size()<4 || s[0]!='('){std::cout<<"Greska, unesite ponovo!"<<std::endl; break;}
        	if(s[0]=='('){
        		if(i<s.size()-1 && b) i++;
        		if(s[i]==' '){ while(i<s.size()-1 && s[i]==' ')i++;}
        		if(i+2<s.size()){
        		if(s[i]>='0' && s[i]<='9'){
        			if((s[i]=='0' && s[i+2]=='0') || s[i]-'0'>=n){std::cout<<"Greska, unesite ponovo!"<<std::endl;break;}
        			 br=s[i]-'0';
        			if(i<s.size()-1) i++;
        		}
        	}
        	//if(s[i]!=' ' && s[i]!=',') b=false;
        	if(s[i]==',' ) i++;
        	if(s[i]==' '){ while(i<s.size()-1 && s[i]==' ') i++;}
        	if(s[i]>='0' && s[i]<='9'&& b){
        		if(s[i]-'0'>=n){std::cout<<"Greska, unesite ponovo!"<<std::endl;break;}
        		br1=s[i]-'0';
        		if(i<s.size()-1) i++;
        		if(s[i]==' '){ while(i<s.size()-1 && s[i]==' ') i++;}
        		if(s[i]==')'){
        			v.resize(br3);
        		v[k].push_back(br);
        		v[k].push_back(br1);
        		br3++;
        		k++;
        		}
        	}
        }
        //if(!b){std::cout<<"Greska, unesite ponovo!"<<std::endl; std::cin.clear();std::cin.ignore(1000,'\n'); break;}
        }
        if(!a){break;}
        }
        try{
        polja=KreirajIgru(n,v);
        }
        catch(std::domain_error){
        	throw;
        }
	}
	else if(komanda==Komande::Blokiraj){
		try{
		BlokirajPolje(polja,p_x,p_y);
		}
		catch(std::domain_error){
			throw;
		}
	}
	else if(komanda==Komande::Deblokiraj){
		for(int i=0;i<v.size();i++){
        	for(int j=0;j<v[i].size();j++){
        		std::cout<<v[i][j]<<" ";
        	}
        	std::cout<<std::endl;
        }
		try{
		DeblokirajPolje(polja,p_x,p_y);
		}
		catch(std::domain_error){
			throw;
		}
	}
	else if(komanda==Komande::PomjeriJednoMjesto){
		try{
		Status a=Idi(polja,x,y,p_smjer);
		if(a==Status::KrajPoraz){ std::cout<<"Nagazili ste na minu"<<std::endl;
		for(int i=0;i<polja.size();i++){
			for(int j=0;j<polja.size();j++){
				polja[i][j]=Polje::Prazno;
				throw std::runtime_error("Igra zavrsena");
			}
		}
		}
		else if(a==Status::KrajPobjeda){ std::cout<<"Bravo,obisli ste sva sigurna polja"<<std::endl;
		for(int i=0;i<polja.size();i++){
			for(int j=0;j<polja.size();j++){
				polja[i][j]=Polje::Prazno;
				throw std::runtime_error("Igra zavrsena");
			}
		}
		}
		else std::cout<<"Tekuca pozicija igraca je ("<<x<<","<<y<<")"<<std::endl;
		
	}
	catch(std::out_of_range){
		throw;
	}
	catch(std::logic_error){
		throw;
	}
	}
	else if(komanda==Komande::PomjeriDalje){
		try{
		Status a=Idi(polja,x,y,p_x,p_y);
		if(a==Status::KrajPoraz){
			std::cout<<"Nagazili ste na minu"<<std::endl;
			for(int i =0;i<polja.size();i++){
				for(int j=0;j<polja.size();j++){
					polja[i][j]=Polje::Prazno;
			}
		}
		throw std::runtime_error("Igra zavrsena\n");
		}
		else if(a==Status::KrajPobjeda){
			std::cout<<"Bravo obisli ste sva sigurna polja"<<std::endl;
			for(int i=0;i<polja.size();i++){
				for(int j=0;j<polja.size();j++){
					polja[i][j]=Polje::Prazno;
				}
			}
			throw std::runtime_error("Igra zavrsena\n");
		}
		else std::cout<<"Tekuca pozicija igraca je ("<<x<<","<<y<<")"<<std::endl;
	}
	catch(std::out_of_range){
		throw;
	}
	}
	else if(komanda==Komande::PrikaziOkolinu){
		try{
		std::vector<std::vector<int>> mat=PrikaziOkolinu(polja,p_x,p_y);
		for(int i=0;i<=2;i++){
			for(int j=0;j<=2;j++){
				std::cout<<mat[i][j]<<" ";
			}
			std::cout<<std::endl;
		}
	}
	catch(std::domain_error){
		throw;
	}
	}
	else if(komanda==Komande::ZavrsiIgru){
		for(int i=0;i<polja.size();i++){
			for(int j=0;j<polja.size();j++){
				polja[i][j]=Polje::Prazno;
			}
		}
		throw std::runtime_error("Igra zavrsena");
	}
	
}

int main ()
{
	
	 /*std::vector<std::vector<int>> mine = {{0,1}, {0,4}, {1,3}, {1,4}, {2,0}, {2,1}, {2,3}} ;
    Tabla tabla = KreirajIgru(5, mine);
    for(int i=0;i<tabla.size();i++){
    	for(int j=0;j<tabla[0].size();j++){
    		if(tabla[i][j]==Polje::Mina) std::cout<<" 1 ";
    		else std::cout<<" 0 ";
    	}
    	std::cout<<std::endl;
    }
     std::vector<std::vector<int>> okolina = PrikaziOkolinu(tabla, 1, 1);
    for(int i = 0; i < okolina.size(); i++)
    {
      for(int j = 0; j < okolina[i].size(); j++) std::cout << okolina[i][j] << " ";
      std::cout << std::endl;
    }*/
   /* std::vector<std::vector<int>> mine = {{0,1}, {0,2}, {1,0}, {1,1}, {1,2}, {2,0}, {2,1}, {2,2}};
  std::vector<std::vector<Polje>> tabla = KreirajIgru(3, mine);
  try{
    BlokirajPolje(tabla, 3,3);
  }
  catch(std::domain_error e){
    std::cout << e.what() << std::endl;
  }
  try{
    BlokirajPolje(tabla, 2,5);
  }
  catch(std::domain_error e){
    std::cout << e.what() << std::endl;
  }
  try{
    BlokirajPolje(tabla, 5,2);
  }
  catch(std::domain_error e){
    std::cout << e.what() << std::endl;
  }
  try{
    DeblokirajPolje(tabla, 3,3);
  }
  catch(std::domain_error e){
    std::cout << e.what() << std::endl;
  }
  try{
    DeblokirajPolje(tabla, 2,5);
  }
  catch(std::domain_error e){
    std::cout << e.what() << std::endl;
  }
  try{
    DeblokirajPolje(tabla, 5,2);
  }
  catch(std::domain_error e){
    std::cout << e.what() << std::endl;
  }*/
  /*while (true) {
      Komande komanda;
      Smjerovi smjer = Smjerovi::GoreDesno;
      int x = 0, y = 0;
      KodoviGresaka greska = KodoviGresaka::SuvisanParametar;
      UnosKomande(komanda, smjer, x, y, greska);
      if(komanda == Komande::ZavrsiIgru) break;
      std::cout << "Unesena komanda: " << int(komanda);
      std::cout << ", (x,y) = (" << x << "," << y <<")";
      if(smjer != Smjerovi::GoreDesno) std::cout << " azuriran smjer na " << int(smjer);
      std::cout  << std::endl;
    }*/
    /*while (true) {
      Komande komanda  = Komande::PomjeriDalje;
      Smjerovi smjer;
      int x = 0, y = 0;
      KodoviGresaka greska = KodoviGresaka::SuvisanParametar;
      UnosKomande(komanda, smjer, x, y, greska);
      if(komanda == Komande::ZavrsiIgru) break;
      std::cout << int(greska) << " ";
    }*/
   /* while (true) {
      Komande komanda;
      Smjerovi smjer = Smjerovi::GoreDesno;
      int x = 0, y = 0;
      KodoviGresaka greska = KodoviGresaka::SuvisanParametar;
      UnosKomande(komanda, smjer, x, y, greska);
      if(komanda == Komande::ZavrsiIgru) break;
      std::cout << "Unesena komanda: " << int(komanda);
      std::cout << ", (x,y) = (" << x << "," << y <<")";
      if(smjer != Smjerovi::GoreDesno) std::cout << " azuriran smjer na " << int(smjer);
      std::cout  << std::endl;
    }*/
    Tabla polja;
    int x_p(0),y_p(0);
    for(;;){
    std::cout<<"Unesite komandu: ";
    Komande komanda;
    Smjerovi smjer;
    int x(0),y(0);
    KodoviGresaka greska;
    bool a;
    a=UnosKomande(komanda,smjer,x,y,greska);
    if(a){
        if(komanda==Komande::ZavrsiIgru){ std::cout<<"Dovidjenja!"; break;}
        try{
    	IzvrsiKomandu(komanda,polja,x_p,y_p,smjer,x,y);
        }
        catch(std::domain_error izuzetak){
        	std::cout<<izuzetak.what();
        }
        catch(std::out_of_range izuzetak){
        	std::cout<<izuzetak.what();
        }
        catch(std::logic_error izuzetak){
        	std::cout<<izuzetak.what();
        }
    }
    else{
    	PrijaviGresku(greska);
    }
    }
   /* int x = 0, y = 0;
 std::vector<std::vector<Polje>> tabla;
  IzvrsiKomandu(Komande::KreirajIgru, tabla, x, y);
  ispisiTablu(tabla);
  IzvrsiKomandu(Komande::KreirajIgru, tabla, x, y);
  ispisiTablu(tabla);
  IzvrsiKomandu(Komande::KreirajIgru, tabla, x, y);*/
  
	return 0;
}