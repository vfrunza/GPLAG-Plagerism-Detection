/*B 16/17, Zadaća 2, Zadatak 1
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
	
*/
#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include <complex>
using namespace std;


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
	PogresnaKomanda, NedostajeParmetar, SuvisanParametar, NeispravanParametar
};

enum class Komande {
 PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu,
 ZavrsiIgru, KreirajIgru
};

typedef vector<vector<Polje>> Tabla;




Tabla KreirajIgru(int n,vector<vector<int>> &mine){
	Tabla matrica(n,vector<Polje>(n,Polje::Prazno));

	for(int i=0;i<mine.size();i++){
		if(mine[i].size()!=2){
			throw domain_error("Ilegalan format zadavanja mina");
		} //izuzetak (ilegaln format zadavanja mina) domain_error
		if(mine[i][0]>=n or mine[i][0]<0 or mine[i][1]>=n or mine[i][1]<0){
			throw domain_error("Ilegalne pozicije mina");
		}// izuzetak (ilegalne pozicije mina) domain_error
		matrica[mine[i][0]][mine[i][1]]=Polje::Mina;
	}
	matrica[0][0]=Polje::Posjeceno;
	
	return matrica;
}



int brojac(const Tabla &Polja,int x,int y){
	
	int broj=0;
	
	for(int i=x-1; i<=x+1;i++){
		for(int j=y-1;j<=y+1;j++){
			if(i<0 or j<0 or i>=Polja.size() or j>=Polja.size())continue;
			if(i==x and j==y) continue;
			if(Polja[i][j]==Polje::Mina)broj++;
		}
		
	}
	return broj;
}



vector<vector<int>>PrikaziOkolinu(const Tabla &Polja, int x, int y){
	vector<vector<int>> matrica(3,vector<int>(3,0));
	if(x<0 or y<0 or x>=Polja.size() or y>=Polja.size()){
		throw domain_error("Polje ("+to_string(x)+","+to_string(y)+") ne postoji");
	} //izuzetak (polje (x,y) ne postoji) domain_error
	int temp=y;
	for(int i=0; i<3;i++){
		for(int j=0;j<3;j++){
		matrica[i][j]=brojac(Polja,x-1,y-1); //saljem element po element i provjeravam okolinu 
		y++;
		}
	y=temp;
	x++;
	}
	return matrica;
}



// Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina
void BlokirajPolje(Tabla &Polja, int x, int y){
	if(x<0 or y<0 or x>=Polja.size() or y>=Polja.size()){
			throw domain_error("Polje ("+to_string(x)+","+to_string(y)+") ne postoji");
	}// baciti izuzetak ()
	if(Polja[x][y]==Polje::Prazno)Polja[x][y]=Polje::BlokiranoPrazno;
	if(Polja[x][y]==Polje::Mina)Polja[x][y]=Polje::BlokiranoMina;
	if(Polja[x][y]==Polje::Posjeceno)Polja[x][y]=Polje::BlokiranoPosjeceno;
}


void DeblokirajPolje(Tabla &Polja, int x, int y){
	if(x<0 or y<0 or x>=Polja.size() or y>=Polja.size()){
			throw domain_error("Polje ("+to_string(x)+","+to_string(y)+") ne postoji");
	}// baciti izuzetak ()
	if(Polja[x][y]==Polje::BlokiranoPrazno)Polja[x][y]=Polje::Prazno;
	if(Polja[x][y]==Polje::BlokiranoMina)Polja[x][y]=Polje::Mina;
	if(Polja[x][y]==Polje::BlokiranoPosjeceno)Polja[x][y]=Polje::Posjeceno;
}



//GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo 
Status Idi(Tabla &Polja,int &x, int &y, Smjerovi smjer){
	Polja[0+x][0+y]=Polje::Posjeceno;
	
	if(smjer==Smjerovi::GoreLijevo){
		if(x-1<0 or y-1<0){
			throw out_of_range("Izlazak van ingrace table");
		}//izuzetak out_of_range
		if(Polja[x-1][y-1]==Polje::BlokiranoPosjeceno or Polja[x-1][y-1]==Polje::BlokiranoMina or Polja[x-1][y-1]==Polje::BlokiranoPrazno){
			throw logic_error("Blokirano polje");
		}//izuzetak
		x--; y--;
		
	}else if(smjer==Smjerovi::Gore){
		if(x-1<0){
			throw out_of_range("Izlazak van ingrace table");
		}//izuzetak out_of_range	
		if(Polja[x-1][y]==Polje::BlokiranoPosjeceno or Polja[x-1][y]==Polje::BlokiranoMina or Polja[x-1][y]==Polje::BlokiranoPrazno){
			throw logic_error("Blokirano polje");
		}//izuzetak
		x--;
		
	}else if(smjer==Smjerovi::GoreDesno){
		if(x-1<0 or y+1>=Polja.size()){
			throw out_of_range("Izlazak van ingrace table");
		}//izuzetak out_of_range
		if(Polja[x-1][y+1]==Polje::BlokiranoPosjeceno or Polja[x-1][y+1]==Polje::BlokiranoMina or Polja[x-1][y+1]==Polje::BlokiranoPrazno){
			throw logic_error("Blokirano polje");
		}//izuzetak
		x--; y++;
		
	}else if(smjer==Smjerovi::Desno){
		if(y+1>=Polja.size()){
			throw out_of_range("Izlazak van ingrace table");
		}//izuzetak out_of_range
		if(Polja[x][y+1]==Polje::BlokiranoPosjeceno or Polja[x][y+1]==Polje::BlokiranoMina or Polja[x][y+1]==Polje::BlokiranoPrazno){
			throw logic_error("Blokirano polje");
		}//izuzetak
		y++;
		
	}else if(smjer==Smjerovi::DoljeDesno){
		if(x+1>=Polja.size() or y+1>=Polja.size()){
			throw out_of_range("Izlazak van ingrace table");
		}//izuzetak out_of_rang
		if(Polja[x+1][y+1]==Polje::BlokiranoPosjeceno or Polja[x+1][y+1]==Polje::BlokiranoMina or Polja[x+1][y+1]==Polje::BlokiranoPrazno){
			throw logic_error("Blokirano polje");
		}//izuzetak
		x++; y++;
		
	}else if(smjer==Smjerovi::Dolje){
		if(x+1>=Polja.size()){
			throw out_of_range("Izlazak van ingrace table");
		}//izuzetak out_of_range88
		if(Polja[x+1][y]==Polje::BlokiranoPosjeceno or Polja[x+1][y]==Polje::BlokiranoMina or Polja[x+1][y]==Polje::BlokiranoPrazno){
			throw logic_error("Blokirano polje");
		}//izuzetak
		x++;
		
	}else if(smjer==Smjerovi::DoljeLijevo){
		if(x+1>=Polja.size() or y-1<0){
			throw out_of_range("Izlazak van ingrace table");
		}//izuzetak out_of_range
		if(Polja[x+1][y-1]==Polje::BlokiranoPosjeceno or Polja[x+1][y-1]==Polje::BlokiranoMina or Polja[x+1][y-1]==Polje::BlokiranoPrazno){
			throw logic_error("Blokirano polje");
		}//izuzetak
		x++; y--;
		
	}else if(smjer==Smjerovi::Lijevo){
		if(y-1<0){
			throw out_of_range("Izlazak van ingrace table");
		}//izuzetak out_of_range
		if(Polja[x][y-1]==Polje::BlokiranoPosjeceno or Polja[x][y-1]==Polje::BlokiranoMina or Polja[x][y-1]==Polje::BlokiranoPrazno){
			throw logic_error("Blokirano polje");
		}//izuzetak
		y--;
		
	}
	if(Polja[x][y]==Polje::Mina){
		vector<vector<int>>mat;
		Polja=KreirajIgru(Polja.size(),mat);
		return Status::KrajPoraz;	
	} 
	
	
	for(int i=0;i<Polja.size();i++){
		for(int j=0;j<Polja.size();j++){
	        if(Polja[x][y]==Polje::Prazno or Polja[x][y]==Polje::BlokiranoPrazno)return Status::NijeKraj;
		}
	}
    return Status::KrajPobjeda;
    
	
}


Status Idi(Tabla &Polja,int &x, int &y, int novi_x, int novi_y){
	Polja[x][y]=Polje::Posjeceno;
	
	
	if(novi_x<0 or novi_y<0 or novi_x>=Polja.size() or novi_y>=Polja.size() ){
			throw out_of_range("Izlazak van ingrace table");
		}//izuzetak out_of_range
	if(Polja[novi_x][novi_y]==Polje::BlokiranoPosjeceno or Polja[novi_x][novi_y]==Polje::BlokiranoMina or Polja[novi_x][novi_y]==Polje::BlokiranoPrazno){
			throw logic_error("Blokirano polje");
		}//izuzetak
	
	x=novi_x;
	y=novi_y;
	
	if(Polja[x][y]==Polje::Mina){
		vector<vector<int>>mat;
		Polja=KreirajIgru(Polja.size(),mat);
		return Status::KrajPoraz;	
	} 
	
	
	for(int i=0;i<Polja.size();i++){
		for(int j=0;j<Polja.size();j++){
	        if(Polja[x][y]==Polje::Prazno or Polja[x][y]==Polje::BlokiranoPrazno)return Status::NijeKraj;
		}
	}
	
    return Status::KrajPobjeda;
 
}


//PogresnaKomanda, NedostajeParmetar, SuvisanParametar, NeispravanParametar
void PrijaviGresku(KodoviGresaka a){
	if(a==KodoviGresaka::PogresnaKomanda)cout<<"Nerazumljiva komanda!"<<endl;
	if(a==KodoviGresaka::NedostajeParmetar)cout<<"Komanda trazi parametar koji nije naveden!"<<endl;
	if(a==KodoviGresaka::SuvisanParametar)cout<<"Parametar komande nije ispravan! "<<endl;
	if(a==KodoviGresaka::NeispravanParametar)cout<<"Zadan je suvisan parametar nakon komande!"<<endl;
}

int extract_number(string s, int i, bool &dobar){
	int temp=i, suma=0,k=1;
	while(s[i]<='9' and s[i]>='0')i++;
	
	if(s[i]!=' ' and s[i]!='\0'){
		dobar=false;
		return 0;
	}
	i--;
	while(i!=temp){
		suma+=(s[i]-'0')*k;
		k*=10;
		i--;
	}
	dobar=true;
	return suma;
	
}



  
bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska){
	string s;
	getline(cin,s);
	if(s.length()==0){
		greska=KodoviGresaka::PogresnaKomanda;
		return false;
	}
	int i=0;
	while(s[i]==' '){
		i++;
	}
	if (s[i]=='P' and s[i+1]=='1') {
		i+=2;
		while(s[i]==' ')i++;
		switch(s[i]){
			
			case 'G':
			    i++;
			    switch(s[i]){
			    	case 'D':
			    	i++;
			    	while(s[i]!='\0'){
			    		if(s[i]!=' ' and s[i]!='\n' and s[i]!='\0'){
			    			greska=KodoviGresaka::SuvisanParametar;
			    			return false;
			    		}
			    	}
			       smjer=Smjerovi::GoreDesno;
			       komanda=Komande::PomjeriJednoMjesto;
			       return true;
			    	
			    	
			    	
			    	case 'L':
			    	i++;
			    	while(s[i]!='\0'){
			    		if(s[i]!=' ' and s[i]!='\n' and s[i]!='\0'){
			    			greska=KodoviGresaka::SuvisanParametar;
			    			return false;
			    		}
			    		i++;
			    	}
			       smjer=Smjerovi::GoreLijevo;
			       komanda=Komande::PomjeriJednoMjesto;
			       return true;
			    	
			    	case ' ':
			    	i++;
			    	while(s[i]!='\0'){
			    		if(s[i]!=' ' and s[i]!='\n' and s[i]!='\0'){
			    			greska=KodoviGresaka::SuvisanParametar;
			    			return false;
			    		}
			    		i++;
			    	}
			       smjer=Smjerovi::Gore;
			       komanda=Komande::PomjeriJednoMjesto;
			       return true;
			       
			       case '\0':
			       smjer=Smjerovi::Gore;
			       komanda=Komande::PomjeriJednoMjesto;
			    	return true;
			       
			       default:
			       greska=KodoviGresaka::SuvisanParametar;
			       return false;
			       
			    }
			    
			case 'L':
			    i++;
			    switch(s[i]){
			    	
			    	case ' ':
			    		i++;
			    	while(s[i]!='\0'){
			    		if(s[i]!=' ' and s[i]!='\n' and s[i]!='\0'){
			    			greska=KodoviGresaka::SuvisanParametar;
			    			return false;
			    		}
			    		i++;
			    	}
			    	case '\0':
			    	smjer=Smjerovi::Gore;
			    	komanda=Komande::PomjeriJednoMjesto;
			    	return true;
			    	
			    	default:
			    	greska=KodoviGresaka::SuvisanParametar;
			    	return false;
			    	
			    }    
			
			case 'D':
			 i++;
			    switch(s[i]){
			    	case 'o':
			    	i++;
			    	switch(s[i]){
			    		case 'D':
			    		i++;
			    		while(s[i]!='\0'){
			    			
			    		if(s[i]!=' ' and s[i]!='\n' and s[i]!='\0'){
			    			greska=KodoviGresaka::SuvisanParametar;
			    			return false;
			    		}
			    		i++;
			    		}
			    		smjer=Smjerovi::DoljeDesno;
			    		komanda=Komande::PomjeriJednoMjesto;
			    		return true;
			    		
			    		
			    		case 'L':
			    		i++;
			    		while(s[i]!='\0'){
			    		if(s[i]!=' ' and s[i]!='\n' and s[i]!='\0'){
			    			greska=KodoviGresaka::SuvisanParametar;
			    			return false;
			    		}
			    		i++;
			    		}
			    		smjer=Smjerovi::DoljeLijevo;
			    		komanda=Komande::PomjeriJednoMjesto;
			    		return true;
			    		
			    		
			    		case ' ':
			    		i++;
			    		while(s[i]!='\0'){
			    		if(s[i]!=' ' and s[i]!='\n' and s[i]!='\0'){
			    			greska=KodoviGresaka::SuvisanParametar;
			    			return false;
			    		}
			    		i++;
			    		}
			    		smjer=Smjerovi::Dolje;
			    		komanda=Komande::PomjeriJednoMjesto;
			    		return true;
			    		
			    		case '\0':
			    		smjer=Smjerovi::Dolje;
			    		komanda=Komande::PomjeriJednoMjesto;
			    		return true;
			    		
			    		default:
			    		greska=KodoviGresaka::SuvisanParametar;
			    		return false;
			    		
			    	}
			    
			    	case ' ':
			    	i++;
			    		while(s[i]!='\0'){
			    		if(s[i]!=' ' and s[i]!='\n' and s[i]!='\0'){
			    			greska=KodoviGresaka::SuvisanParametar;
			    			return false;
			    		}
			    		i++;
			    		}
			    		smjer=Smjerovi::Dolje;
			    		komanda=Komande::PomjeriJednoMjesto;
			    		return true;
			    		
			    	
			        case '\0':
		             smjer=Smjerovi::Desno;
		             komanda=Komande::PomjeriJednoMjesto;
		             return true;
			    	
			    	default:
			    	greska=KodoviGresaka::SuvisanParametar;
			    	return false;
			    	
			    }
			    
			    
			case '\0':
			        greska=KodoviGresaka::NedostajeParmetar;
			    	return false;
			
			default:
			    	greska=KodoviGresaka::NeispravanParametar;
			    	return false;
		
		}
	
		
	}else if(s[i]=='K'){
	        	i++;
			   while(s[i]!='\0'){
			    if(s[i]!=' ' and s[i]!='\n' and s[i]!='\0'){
			    	greska=KodoviGresaka::SuvisanParametar;
			    	return false;
			    	}
			   	i++;
			   	}
			   	komanda=Komande::KreirajIgru;
			   	return true;
			    		
			    	
		
	}else if(s[i]=='Z'){
	        	i++;
			   while(s[i]!='\0'){
			    if(s[i]!=' ' and s[i]!='\n' and s[i]!='\0'){
			    	greska=KodoviGresaka::SuvisanParametar;
			    	return false;
			    	}
			   	i++;
			   	}
			   	komanda=Komande::ZavrsiIgru;
			   	return true;
			    		
			    	
		
	}else if(s[i]=='P' and s[i+1]=='>'){
		i+=2;
		bool valja1,valja2;
		while(s[i]==' '){
			i++;
		}
		
		int x1=extract_number(s,i,valja1);
		while(s[i]==' '){
			i++;
		}
		
		if(s[i]=='\0'){
			greska=KodoviGresaka::NedostajeParmetar;
		}
		
		if((s[i]<'9' or s[i]<'0') and s[i]!=' '){
			greska=KodoviGresaka::NeispravanParametar;
			return false;
		}
		
		int y1=extract_number(s,i,valja2);
		while(s[i]!='\0'){
			if(s[i]!=' ' and s[i]!='\n' and s[i]!='\0'){
				greska=KodoviGresaka::SuvisanParametar;
				return false;
			}
		}
		
		if(valja1 and valja2){
		x=x1;
		y=y1;
		komanda=Komande::Blokiraj;
		return true;
		}else{
			greska=KodoviGresaka::NeispravanParametar;
			return false;
		}
		
		
	}else if(s[i]=='B'){
		i++;
		
		bool valja1,valja2;
		while(s[i]==' '){
			i++;
		}
		
		int x1=extract_number(s,i,valja1);
		while(s[i]==' '){
			i++;
		}
		
		if(s[i]=='\0'){
			greska=KodoviGresaka::NedostajeParmetar;
		}
		
		if((s[i]<'9' or s[i]<'0') and s[i]!=' '){
			greska=KodoviGresaka::NeispravanParametar;
			return false;
		}
		
		int y1=extract_number(s,i,valja2);
		while(s[i]!='\0'){
			if(s[i]!=' ' and s[i]!='\n' and s[i]!='\0'){
				greska=KodoviGresaka::SuvisanParametar;
				return false;
			}
		}
		
		if(valja1 and valja2){
		x=x1;
		y=y1;
		komanda=Komande::Blokiraj;
		return true;
		}else{
			greska=KodoviGresaka::NeispravanParametar;
			return false;
		}
		
	}else if(s[i]=='D'){
		i++;
		
		bool valja1,valja2;
		while(s[i]==' '){
			i++;
		}
		
		int x1=extract_number(s,i,valja1);
		while(s[i]==' '){
			i++;
		}
		
		if(s[i]=='\0'){
			greska=KodoviGresaka::NedostajeParmetar;
		}
		
		if((s[i]<'9' or s[i]<'0') and s[i]!=' '){
			greska=KodoviGresaka::NeispravanParametar;
			return false;
		}
		
		int y1=extract_number(s,i,valja2);
		while(s[i]!='\0'){
			if(s[i]!=' ' and s[i]!='\n' and s[i]!='\0'){
				greska=KodoviGresaka::SuvisanParametar;
				return false;
			}
		}
		
		if(valja1 and valja2){
		x=x1;
		y=y1;
		komanda=Komande::Blokiraj;
		return true;
		}else{
			greska=KodoviGresaka::NeispravanParametar;
			return false;
		}
		
	}else if(s[i]=='P' and s[i+1]=='O'){
		
		i+=2;
		while(s[i]!='\0'){
			if(s[i]!=' '){
				greska=KodoviGresaka::PogresnaKomanda;
				return false;
			}
		}
		komanda=Komande::PrikaziOkolinu;
		return true;
		
	}else{
		greska=KodoviGresaka::PogresnaKomanda;//dodati else za pogresan pocetni parametar pls(done)
		return false;
	}
}
void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer = Smjerovi::Gore, int p_x = 0, int p_y = 0){
	
	switch(komanda){
		
		
		
		case (Komande::PomjeriJednoMjesto):{
		
		Status lel=Idi(polja,x,y,p_smjer);//vraca se status
		cout<<"Tekuca pozicija igraca je ("<<x<<", "<<y<<")"<<endl;
		if(lel==Status::NijeKraj){
			break;
		}
		if(lel==Status::KrajPobjeda){
			cout<<"Bravo, obisli ste sva sigurna polja"<<endl;
			vector<vector<int>>v;
			KreirajIgru(polja.size(),v);
			throw runtime_error("Igra zavrsena");
			
		}
		if(lel==Status::KrajPobjeda){
			cout<<"Nagazili ste na minu"<<endl;
			vector<vector<int>>v;
			KreirajIgru(polja.size(),v);
		}
		break;
		
		}
		
		case (Komande::PomjeriDalje):{
		
		Status lel1=Idi(polja,x,y,p_x,p_y);//vraca se status
		cout<<"Tekuca pozicija igraca je ("<<x<<", "<<y<<")"<<endl;
		
		if(lel1==Status::NijeKraj){
			break;
		}
		if(lel1==Status::KrajPobjeda){
			cout<<"Bravo, obisli ste sva sigurna polja"<<endl;
			vector<vector<int>>v;
			KreirajIgru(polja.size(),v);
			throw runtime_error("Igra zavrsena");
			
		}
		if(lel1==Status::KrajPobjeda){
			cout<<"Nagazili ste na minu"<<endl;
			vector<vector<int>>v;
			KreirajIgru(polja.size(),v);
		}
		break;
		
		}
		
		case (Komande::Deblokiraj):{
	    
		try{
		DeblokirajPolje(polja,p_x,p_y);
		}catch(domain_error Hi){
			cout<<Hi.what();
		} 
		break;
		}
		
		
		
		case (Komande::Blokiraj):{
		try{
		BlokirajPolje(polja,p_x,p_y);
	    }catch(domain_error Hi){
			cout<<Hi.what();
		} 
		break;
		}
		
		
		case (Komande::ZavrsiIgru):{
		
		vector<vector<int>>v;
		KreirajIgru(polja.size(),v);
		throw runtime_error("Igra zavrsena");
		
		break;
		}
		
		
		
		case (Komande::PrikaziOkolinu):{
		try{
		vector<vector<int>> okolina=PrikaziOkolinu(polja,x,y);
		
		for(int i=0;i<okolina.size();i++){
			for(int j=0;j<okolina[i].size();i++){
				cout<<okolina[i][j]<<" ";
			}
			cout<<endl;
		}
		}catch(domain_error Hi){
			cout<<Hi.what();
		}
			break;
		
		}
		
		
		case (Komande::KreirajIgru):{
		
		cout<<"Unesite broj polja: ";
		int n;
		cin>>n;
		complex<int>z(0,0);
		int red=0;
		vector<vector<int>>mines(red,vector<int>(red));
		cout<<"Unesite pozicije mina: ";
		cin>>z;
		while(cin.peek()!='.'){
			cin.clear();
			cin.ignore(1000,'\n');
			
		
		
		if(cin.peek()=='.'){
			cin.clear();
			cin.ignore(1000,'\n');
			break;
			
		}
		if(z.real()<0 or z.real()>=n or z.imag()<0 or z.imag()>=n){
			cout<<"Greska, unesite ponovo!"<<endl;
			
			continue;
		}
		if(cin.fail()){
			cout<<"Greska, unesite ponovo!"<<endl;
			
			cin.clear();
			cin.ignore(1000,'\n');
			
			continue;
		}
		red++;
		
		mines.resize(red);
		mines[red-1].resize(2);
		mines[red-1][0]=z.real();
		mines[red-1][1]=z.imag();
		
        cin>>z;
		}
		KreirajIgru(n,mines);
		
		
		break;
		// kraj kreiraj igru
		
		}
	}
}


int main (){
	Status s(Status::NijeKraj);
	Komande kom;
	Tabla MineSweeper;
	int x=0,novi_x=0,novi_y=0,y=0;
	KodoviGresaka greska;
	Smjerovi smijer;
	while(s!=Status::KrajPoraz or s!=Status::KrajPobjeda){
		cout<<"Unesite komandu: ";
		if (UnosKomande(kom, smijer, novi_x, novi_y, greska)){
			try{
				IzvrsiKomandu(kom, MineSweeper,x,y,smijer,novi_x,novi_y);
			}catch(domain_error Hi){
				cout<<Hi.what();
			}
			catch(logic_error Hi){
				cout<<Hi.what();
			}
			catch(runtime_error Hi){
				cout<<Hi.what();
				break;
			}
		}else{
			PrijaviGresku(greska);
		}
		}
	
	return 0;
}