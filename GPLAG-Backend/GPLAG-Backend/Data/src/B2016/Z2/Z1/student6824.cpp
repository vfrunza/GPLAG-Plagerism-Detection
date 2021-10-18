#include <iostream>
#include <iomanip>
#include <vector>
#include <stdexcept>
#include <string>
int UslovK{0}, pok{0}; 
enum class Polje{
	Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina
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
void PrijaviGresku(KodoviGresaka kod){
	if(kod==KodoviGresaka::PogresnaKomanda) std::cout <<"Nerazumljiva komanda!"<<std::endl;
	if(kod==KodoviGresaka::NedostajeParametar) std::cout <<"Komanda trazi parametar koji nije naveden!"<<std::endl;
	if(kod==KodoviGresaka::NeispravanParametar) std::cout <<"Parametar komande nije ispravan!"<<std::endl;
	if(kod==KodoviGresaka::SuvisanParametar) std::cout <<"Zadan je suvisan parametar nakon komande!"<<std::endl;
}
Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer){
  polja[x][y]=Polje::Posjeceno;	
  if(smjer==Smjerovi::GoreLijevo){
  	if(x-1<0 || y-1<0) throw std::out_of_range("Izlazak van igrace table");
  	x=x-1;
  	y=y-1;
    }
  if(smjer==Smjerovi::Gore){
  	if(x-1<0) throw std::out_of_range("Izlazak van igrace table");
  	x=x-1;
  }
  if(smjer==Smjerovi::GoreDesno){
  	if(x-1<0 || y+1>polja[0].size()-1) throw std::out_of_range("Izlazak van igrace table");
  	x=x-1;
  	y=y+1;
  }
  if(smjer==Smjerovi::Desno){
  	if(y+1>polja[0].size()-1) throw std::out_of_range("Izlazak van igrace table");
  	y=y+1;
  }
  if(smjer==Smjerovi::Lijevo){
  	if(y-1<0) throw std::out_of_range("Izlazak van igrace table");
  	y=y-1;
  }
  if(smjer==Smjerovi::DoljeLijevo){
  	if(x+1>polja.size()-1 || y-1<0) throw std::out_of_range("Izlazak van igrace table");
  	x=x+1;
  	y=y-1;
  }
  if(smjer==Smjerovi::Dolje){
  	if(x+1>polja.size()-1) throw std::out_of_range("Izlazak van igrace table");
  	x=x+1;
  }
  if(smjer==Smjerovi::DoljeDesno){
  	if(x+1>polja.size()-1 || y+1>polja[0].size()-1) throw std::out_of_range("Izlazak van igrace table");
  	x=x+1;
  	y=y+1;
  }
  if(polja[x][y]==Polje::BlokiranoPrazno) throw std::logic_error("Blokirano polje");
  if(polja[x][y]==Polje::BlokiranoPosjeceno) throw std::logic_error("Blokirano polje");
  if(polja[x][y]==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
  int brojac{0};
  if(polja[x][y]==Polje::Mina) {
  	for(int i=0; i<polja.size(); i++){
  		for(int j=0; j<polja[0].size(); j++){
  			if(polja[i][j]==Polje::Prazno || polja[i][j]==Polje::Mina) brojac++;
  			polja[i][j]=Polje::Prazno;
  		}
  	}
  	return Status::KrajPoraz;
    }
  if(brojac==polja.size()*polja[0].size()) return Status::KrajPobjeda;
  return Status::NijeKraj;
}
Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y){
	if(polja[x][y]==Polje::Prazno) polja[x][y]=Polje::Posjeceno;
 	if(novi_x>polja.size()-1 || novi_x<0 || novi_y>polja[0].size()-1 || novi_y<0) throw std::out_of_range("Izlazak van igrace table");
 	if(polja[novi_x][novi_y]==Polje::BlokiranoPrazno) throw std::logic_error("Blokirano polje");
 	if(polja[novi_x][novi_y]==Polje::BlokiranoPosjeceno) throw std::logic_error("Blokirano polje");
 	if(polja[novi_x][novi_y]==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
 	x=novi_x;
 	y=novi_y;
 	int brojac{0};
 	if(polja[x][y]==Polje::Mina){
 		for(int i=0; i<polja.size(); i++){
 			for(int j=0; j<polja[0].size(); j++){
 				if(polja[i][j]==Polje::Prazno || polja[i][j]==Polje::Mina) brojac++;
 				polja[i][j]=Polje::Prazno;
 			}
 		}
 		return Status::KrajPoraz;
 	}
 	if(brojac==polja.size()*polja[0].size()) return Status::KrajPobjeda;
 	return Status::NijeKraj;
}
void DeblokirajPolje(Tabla &polja, int x, int y){
	    std::string poruka1{"Polje ("};
	    std::string x1=std::to_string(x);
	    std::string poruka2{","};
	    std::string y1=std::to_string(y);
	    std::string poruka3{") ne postoji"};
	    std::string poruka;
	    poruka=poruka1+x1+poruka2+y1+poruka3;
		if(x>polja.size()-1 || x<0 || y>polja[0].size()-1 || y<0) throw std::domain_error (poruka);
		if(polja[x][y]==Polje::BlokiranoPrazno) polja[x][y]=Polje::Prazno;
		if(polja[x][y]==Polje::BlokiranoPosjeceno) polja[x][y]=Polje::Posjeceno;
		if(polja[x][y]==Polje::BlokiranoMina) polja[x][y]=Polje::Mina;
}
void BlokirajPolje(Tabla &polja, int x, int y){
	std::string poruka1{"Polje ("};
	std::string x1=std::to_string(x);
	std::string poruka2{","};
	std::string y1=std::to_string(y);
	std::string poruka3{") ne postoji"};
	std::string poruka;
	poruka=poruka1+x1+poruka2+y1+poruka3;
 	 if(x>polja.size()-1 || x<0 || y>polja[0].size()-1 || y<0) throw std::domain_error (poruka);
	 if(polja[x][y]==Polje::Prazno) polja[x][y]=Polje::BlokiranoPrazno;
	 if(polja[x][y]==Polje::Posjeceno) polja[x][y]=Polje::BlokiranoPosjeceno;
	 if(polja[x][y]==Polje::Mina) polja[x][y]=Polje::BlokiranoMina;
}
std::vector<std::vector<int>>PrikaziOkolinu(const Tabla &polja, int x, int y){
	std::vector<std::vector<int>>a;
	a.resize(3);
	for(int i=0; i<3; i++) a[i].resize(3);
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			a[i][j]=0;
		}
	}
	int red1{0}, red11{0}, red2{0}, red21{0}, kolona1{0}, kolona11{0}, kolona2{0}, kolona21{0}, brojac{0}, u{0}, v{0};
	    std::string poruka1{"Polje ("};
	    std::string x1=std::to_string(x);
	    std::string poruka2{","};
	    std::string y1=std::to_string(y);
	    std::string poruka3{") ne postoji"};
	    std::string poruka;
	    poruka=poruka1+x1+poruka2+y1+poruka3;
	    if(x>polja.size()-1 || x<0 || y>polja[0].size()-1 || y<0) throw std::domain_error (poruka);
		if(polja.size()==1 && polja[0].size()==1) return a;
        if(x>0){red1=x-1; red2=x+1;}
        else{red1=0; red2=2;}
        if(red2>polja.size()-1) red2=polja.size()-1;
        if(y>0){kolona1=y-1; kolona2=y+1;}
        else{kolona1=0; kolona2=2;}
        if(kolona2>polja[0].size()-1) kolona2=polja[0].size()-1;
        for(int i=red1; i<=red2; i++){
        	for(int j=kolona1; j<=kolona2; j++){
              red11=i-1;
        	 if(red11<0) {red11=0; red21=1;}
             else red21=i+1;
        	 if(red21>polja.size()-1) red21=polja.size()-1;
        	kolona11=j-1;
        	 if(kolona11<0) {kolona11=0; kolona21=1;}
             else kolona21=j+1;
        	 if(kolona21>polja[0].size()-1) kolona21=polja[0].size()-1;
        	 brojac=0;
        	 for(int k=red11; k<=red21; k++){
        	  for(int m=kolona11; m<=kolona21; m++){
               if(k==i && m==j){}
              else if((int)polja[k][m]==2 || (int)polja[k][m]==1){brojac=brojac+((int)polja[k][m]-1);}
               else brojac=brojac+(int)polja[k][m];
        	  }
        	  }
        	 a[u][v]=brojac;
        	 v++;
        	}
        u++;
        v=0;
        }
	return a;
}
Tabla KreirajMatricu(int red, int kolona){
	return Tabla(red,std::vector<Polje>(kolona));
}
Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine){
 Tabla a(KreirajMatricu(n,n));
 int ind1, ind2;
 for(int i=0; i<n; i++){
 	for(int j=0; j<n; j++){
 		a[i][j]=Polje::Prazno;
 	}
 }
 for(int i=0; i<mine.size(); i++){
  	for(int j=0; j<mine[i].size(); j++){
  	 if(mine[i].size()!=2)	throw std::domain_error("Ilegalan format zadavanja mina");
  	 if(mine[i][j]>n-1 || mine[i][j]<0) throw std::domain_error("Ilegalne pozicije mina");
 	 if(j==0) {ind1=mine[i][j];}
 	 else {
 	 	ind2=mine[i][j];
 	    a[ind1][ind2]=Polje::Mina;
 	  }
 	 }
 	}
    return a;
}
void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer=Smjerovi::Gore, int p_x=0, int p_y=0){
	try{
	Status u;
	if(komanda==Komande::PomjeriJednoMjesto){
	 u=Idi(polja,x,y,p_smjer);
	 if(u==Status::NijeKraj) std::cout <<"Tekuca pozicija igraca je ("<<x<<","<<y<<")"<<std::endl;
	 else if(u==Status::KrajPoraz) std::cout <<"Nagazili ste na minu"<<std::endl;
	  else std::cout <<"Bravo, obisli ste sva sigurna polja"<<std::endl;
	}
	if(komanda==Komande::PomjeriDalje){
		u=Idi(polja,x,y,p_x,p_y);
	   if(u==Status::NijeKraj) std::cout <<"Tekuca pozicija igraca je ("<<x<<","<<y<<")"<<std::endl;
	   else if(u==Status::KrajPoraz) std::cout <<"Nagazili ste na minu"<<std::endl;
	    else std::cout <<"Bravo, obisli ste sva sigurna polja"<<std::endl;
	}
	if(komanda==Komande::Blokiraj) BlokirajPolje(polja,x,y);
	if(komanda==Komande::Deblokiraj) DeblokirajPolje(polja,x,y);
	if(komanda==Komande::PrikaziOkolinu){ std::vector<std::vector<int>>m{PrikaziOkolinu(polja,x,y)};
	for(int i=0; i<m.size(); i++){
		for(int j=0; j<m[0].size(); j++){
			std::cout<<m[i][j]<<" ";
		}
		std::cout <<std::endl;
	  }
	}
	if(komanda==Komande::ZavrsiIgru){
		for(int i=0; i<polja.size(); i++){
			for(int j=0; j<polja[0].size(); j++){
				polja[i][j]=Polje::Prazno;
			}
		}
		throw std::runtime_error("Igra zavrsena");
	}
	if(komanda==Komande::KreirajIgru){
		int broj_polja, brojac1{0}, brojac2{0};
		std::cout <<"Unesite broj polja: ";
		std::cin >>broj_polja;
		std::cin.ignore(10000,'\n');
		std::cout <<"Unesite pozicije mina: ";
		std::vector <std::vector<int>> mine;
        std::string s;
        int rezultat1{0}, rezultat2{0}, pokaz{0}, x{0}, i{0};
        int niz1[100], niz2[100];
        for(;;){
        	brojac1=0; brojac2=0;
        	std::getline(std::cin, s);
         	if(s[0]=='.') {
                mine.resize(x);
         		for(int i=0; i<x; i++) mine[i].resize(2);
         		for(int i=0; i<x; i++){
         			mine[i][0]=niz1[i];
         			mine[i][1]=niz2[i];
         		}
         		break;}
        	for(i=0; i<s.size(); i++){
                if(s[0]=='.') {i=s.size(); break;}
        		if(s[i]==' '){}
        		else if(s[i]=='(' || s[i]==',' || s[i]==')'){
        			if(s[i]=='(') pokaz=0;
        			if(s[i]==',') pokaz=1;
        			if(s[i]==')'){
        	         if(rezultat1>broj_polja-1 || rezultat1<0 || rezultat2>broj_polja-1 || rezultat2<0){
        		  	  std::cout<<"Greska, unesite ponovo!"<<std::endl; brojac1=1; brojac2=1;
        	        }	
        		  else{
        		  	   niz1[x]=rezultat1;
        		  	   niz2[x]=rezultat2;
        			   x++;
        			  }
        			 rezultat1=0;
        			 rezultat2=0;
        			}
        		} 
       	        else if(pokaz==0){
        			if(s[i]>='0' && s[i]<='9')
        			 {rezultat1=rezultat1*10+s[i]-48; brojac1=1;}	
        	      }
        		  else if(pokaz==1){
        		  	if(s[i]>='0' && s[i]<='9')
        		  	 {rezultat2=rezultat2*10+s[i]-48; brojac2=1;};
        	       }
         else{
         	std::cout<<"Greska, unesite ponovo!"<<std::endl;
         	std::cin.ignore(100000, '\n');
         } 	       
        }
        if(brojac1==1 && brojac2==1){}
        else std::cout<<"Greska, unesite ponovo!"<<std::endl;
     }
      polja=KreirajIgru(broj_polja,mine);  
	}
   }
   catch(std::out_of_range izuzetak1){
   	std::cout <<izuzetak1.what()<<std::endl;
   }
   catch(std::logic_error izuzetak2){
   	std::cout <<izuzetak2.what()<<std::endl;
   }
   catch(std::domain_error izuzetak3){
       std::cout <<izuzetak3.what()<<std::endl;
   }
   catch(std::runtime_error izuzetak4){
   	std::cout <<izuzetak4.what()<<std::endl;
   }
}
bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska){
 std::string s;
 int ind{0}, pokaz{0}, ind1{0}, poz{0};
 char prvi, drugi;
 std::getline(std::cin, s);
 for(int i=0; i<s.size(); i++){
 	if(s[i]==' ' || s[i]=='P' || s[i]=='1' || s[i]=='>' || s[i]=='B' || s[i]=='D' || s[i]=='O' || s[i]=='Z' || s[i]=='K' || s[i]=='G' || s[i]=='L' || s[i]=='o' || (s[i]>='0' && s[i]<='9')){}
 	else{
 		if(pokaz==0){greska=KodoviGresaka::PogresnaKomanda; ind1=1; i=s.size();}
 		else if(pokaz==1){greska=KodoviGresaka::NeispravanParametar; ind1=1; i=s.size();}
 		 else{}
 	} 
 		 if(s[i]==' '){}
 		 else{
 		 	if(poz==0){
  	         if(i==0 && (s[0]=='P' || s[0]=='B' || s[0]=='D' || s[0]=='Z' || s[0]=='K')) {prvi=s[i]; poz=1; i++;}
  	         else{ greska=KodoviGresaka::PogresnaKomanda; ind1=1; i=s.size();}
 		 	 }
  		 	if(UslovK==0 && prvi!='K') { greska=KodoviGresaka::PogresnaKomanda; ind1=1; i=s.size();}
 		 	if(prvi=='P'){
  		 	   if(s[i]==' ' || s[i]=='\0') { greska=KodoviGresaka::PogresnaKomanda; ind1=1; i=s.size();}
 		 	   else if(s[i]=='1') {komanda=Komande::PomjeriJednoMjesto; pokaz=1; prvi=' ';}
 		 	    else if(s[i]=='>') {komanda=Komande::PomjeriDalje; pokaz=1; prvi=' ';  ind=0; x=0; y=0;} 
 		 	     else if(s[i]=='O') {komanda=Komande::PrikaziOkolinu; pokaz=1; prvi=' ';} 
 		 	      else { greska=KodoviGresaka::PogresnaKomanda; ind1=1; i=s.size();}
 		 	   if(s[i+1]==' '){
 		 	   	if(s[i]=='O' || s[i]=='1' || s[i]=='>'){}
    		 	else { greska=KodoviGresaka::PogresnaKomanda; ind1=1; i=s.size();}
 		 	   }	
 		    }
 		    else if(prvi=='B'){
 		      if(s[i]==' ') {komanda=Komande::Blokiraj; prvi=' '; ind=0; x=0; y=0;}
 		      else {greska=KodoviGresaka::PogresnaKomanda; ind1=1; i=s.size();}
 		     } 
 		     else if(prvi=='D') {
 		       if(s[i]==' ') {komanda=Komande::Deblokiraj; prvi=' '; ind=0; x=0; y=0;} 
 		       else { greska=KodoviGresaka::PogresnaKomanda; ind1=1; i=s.size();}
 		     } 	
 		     else if(prvi=='Z') {
 		   //  if(s[i]==' ' || s[i]=='\0') throw std::runtime_error("Dovidjenja!"); 
 		      if(s[i]==' ' || s[i]=='\0'){std::cout <<"Dovidjenja!";  ind1=2; pok=1; i=s.size();} 
 		      else { greska=KodoviGresaka::PogresnaKomanda; ind1=1; i=s.size();}
 		     }	
 		 	 else if(prvi=='K') {
 		 	  if(s[i]==' ' || s[i]=='\0'){ komanda=Komande::KreirajIgru; UslovK=1;}
 		 	  else { greska=KodoviGresaka::PogresnaKomanda; ind1=1; i=s.size();}
 		 	 }	
 		 	 else if(komanda==Komande::PomjeriJednoMjesto){
 		 		if(s[i]=='G' || s[i]=='D' || s[i]=='L') {if(pokaz==1) {drugi=s[i]; pokaz=2; i++;}}
 		 		else {greska=KodoviGresaka::NeispravanParametar; ind1=1; i=s.size();}
 		 		if(drugi=='G'){
 		 			if(s[i]==' ' || s[i]=='\0') smjer=Smjerovi::Gore;
 		 			else if(s[i]=='L') smjer=Smjerovi::GoreLijevo;
 		 			 else if(s[i]=='D') smjer=Smjerovi::GoreDesno;
 		 			if(s[i+1]==' ' || s[i+1]=='\0') {}
 		 			else { greska=KodoviGresaka::SuvisanParametar; ind1=1; i=s.size();}
 		 		}
 		 		if(drugi=='D'){
 		 			if(s[i]==' ' || s[i]=='\0') smjer=Smjerovi::Desno;
 		 			else if(s[i]=='o'){
 		 			 if(s[i+1]==' ' || s[i+1]=='\0') smjer=Smjerovi::Dolje;
 		 			 else if(s[i+1]=='D') smjer=Smjerovi::DoljeDesno;
 		 			  if(s[i+1]=='L') smjer=Smjerovi::DoljeLijevo;
 		 			 if(s[i+2]==' ' || s[i+2]=='\0'){}
 		 			 else { greska=KodoviGresaka::SuvisanParametar; ind1=1; i=s.size();}
 		 			}
 		 		}
 		 		if(drugi=='L'){
 		 		 if(s[i]==' ' || s[i]=='\0') smjer=Smjerovi::Lijevo;
 		 		 else { greska=KodoviGresaka::SuvisanParametar; ind1=1; i=s.size();}
 		 		}
 		 	}
 		 	else if(komanda==Komande::PomjeriDalje || komanda==Komande::Blokiraj || komanda==Komande::Deblokiraj){
 		 		if(s[i]>='0' && s[i]<='9'){
 		 				if(ind==0) x=x*10+s[i]-48;
 		 				else y=y*10+s[i]-48; 
 		 		}		
 		 		if(s[i+1]==' ' || s[i+1]=='\0'){ind=1;}
 		 		else if(s[i+1]>='0' && s[i+1]<='9'){}
 		 	     else { greska=KodoviGresaka::SuvisanParametar; ind1=1; i=s.size();}
 		 	}
 		 }
 }
 if(ind1==0) return true;
 return false;
}
int main (){
	try{
	int x{0}, y{0}, p_x, p_y;
	 Komande komanda;
	 Smjerovi smjer;
	 KodoviGresaka greska;
	 bool t;
	 Tabla polja;
	 for(;;){
		std::cout <<"Unesite komandu: ";
		t=UnosKomande(komanda,smjer,x,y,greska);
		p_x=x, p_y=y;
		if(t==1) IzvrsiKomandu(komanda,polja,x,y,smjer,p_x,p_y);
		else if(pok==1) break;
		else PrijaviGresku(greska);
     }
	}
	catch(std::runtime_error izuzetak){
		std::cout <<izuzetak.what();
	}
	return 0;
}