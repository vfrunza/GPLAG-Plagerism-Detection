#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>

enum class Polje {Prazno,Posjeceno,Mina,BlokiranoPrazno,BlokiranoPosjeceno,BlokiranoMina};
typedef std::vector<std::vector<Polje>>Tabla;
enum class Smjerovi{GoreLijevo,Gore,GoreDesno,Desno,DoljeDesno,Dolje,DoljeLijevo,Lijevo};
enum class Status{NijeKraj,KrajPoraz,KrajPobjeda}; 
enum class KodoviGresaka{PogresnaKomanda,NedostajeParametar,SuvisanParametar,NeispravanParametar};
enum class Komande{PomjeriJednoMjesto,PomjeriDalje,Blokiraj,Deblokiraj,PrikaziOkolinu,ZavrsiIgru,KreirajIgru};

 Tabla KreirajIgru(int n , const std::vector<std::vector<int>> &mine)	{
 	Tabla M ( n, std::vector<Polje>(n,Polje::Prazno));
 	for ( int i = 0 ; i < mine.size(); i++ ) if ( mine[i].size() != 2 ) throw std::domain_error("Ilegalan format zadavanja mina");
 	for ( int i = 0 ; i < mine.size(); i++ ) if (mine[i][0] >= M.size() || mine[i][1] >= M.size() ) throw std::domain_error ( "Ilegalne pozicije mina");
 	for ( int i = 0 ; i < M.size() ; i++)	{
 		for ( int j = 0 ; j < M[i].size(); j++)	{
 		for ( int k = 0 ; k < mine.size(); k++)	{
 		 if ( i == 0 && j == 0 ) continue;
 		 if ( i == mine[k][0] && j == mine[k][1] ) M[i][j] = Polje::Mina;
 		   }
		  }
		}

 	return M;
 }
 
 std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja , int x , int y)	{
 	std::vector<std::vector<int>> Matrica (3,std::vector<int>(3));
    for ( int i = 0; i<polja.size(); i++)	if ( x >= polja.size() || y >= polja[i].size() ) throw std::domain_error("Polje ("+std::to_string(x)+","+std::to_string(y)+") ne postoji"); 

 	int n,m;
 		n = 0;
 	for ( int i = x-1 ; i < x+2; i++)	{
 				m = 0;
 		for ( int j = y-1; j< y+2; j++)	{
 		    	int brojac = 0;
 		    for ( int k = i-1; k < i+2; k++)	{
 		    	for ( int z = j-1; z < j+2; z++ )	{
 		    		if(k>=0 &&  k<polja.size() && z>=0 && z<polja.size()){
 		    		if ( polja[k][z] == Polje::Mina ) brojac++;}
 		    	}
 		    }
 		    if(i>=0 && i < polja.size() && j>=0 && j<polja.size()){
 		    if ( polja[i][j] == Polje::Mina) brojac--;}
 			Matrica[n][m] = brojac;
 			m++;
 		}
 			n++;
 	}
 	return Matrica;
 }
 
 void BlokirajPolje( Tabla &polja , int x , int y)	{
    for ( int i = 0; i<polja.size(); i++)	if ( x >= polja.size() || y >= polja[i].size() ) throw std::domain_error("Polje ("+std::to_string(x)+","+std::to_string(y)+") ne postoji"); 
 	for ( int i = 0 ; i< polja.size(); i++ )	{
 		for ( int j = 0; j < polja[i].size(); j++)	{
 			if ( i == x && j == y)	{
 				if ( polja[i][j] == Polje::Prazno ) polja[i][j] = Polje::BlokiranoPrazno;
 				if ( polja[i][j] == Polje::Posjeceno ) polja[i][j] = Polje::BlokiranoPosjeceno;
				if ( polja[i][j] == Polje::Mina ) polja[i][j] = Polje::BlokiranoMina;
 			}
 		}
 	}
 }
  void DeblokirajPolje( Tabla &polja , int x , int y)	{
  
    for ( int i = 0; i<polja.size(); i++)	if ( x >= polja.size() || y >= polja[i].size() ) throw std::domain_error("Polje ("+std::to_string(x)+","+std::to_string(y)+") ne postoji"); 
 	for ( int i = 0 ; i< polja.size(); i++ )	{
 		for ( int j = 0; j < polja[i].size(); j++)	{
 			if ( i == x && j == y)	{
 				if ( polja[i][j] == Polje::BlokiranoPrazno ) polja[i][j] = Polje::Prazno;
 				if ( polja[i][j] == Polje::BlokiranoPosjeceno ) polja[i][j] = Polje::Posjeceno;
				if ( polja[i][j] == Polje::BlokiranoMina ) polja[i][j] = Polje::Mina;
 			}
 		}
 	}
 }
 
 Status Idi(Tabla &polja, int &x , int &y , Smjerovi smjer)	{
  if(x<0 || x >= polja.size() || y<0 ||  y>=polja.size())throw std::out_of_range("Izlazak van igrace table");
  polja[x][y] = Polje::Posjeceno;
  int x1(x),y1(y);
 	if ( smjer == Smjerovi::GoreLijevo)	{
 		x1--;
 		y1--;
 	 if ( x1 < 0 || y1 < 0 ) throw std::out_of_range("Izlazak van igrace table");
 	 if ( polja[x1][y1] == Polje::BlokiranoPosjeceno || polja[x1][y1] == Polje::BlokiranoPrazno || polja[x1][y1] == Polje::BlokiranoMina ) throw std::logic_error("Blokirano Polje");
 		 x=x1;
 	 y=y1;
 	 
 	}
 	 if ( smjer == Smjerovi::Gore)	{
 		x1--;
 	 if ( x1 < 0 ) throw std::out_of_range("Izlazak van igrace table");
 	 if ( polja[x1][y1] == Polje::BlokiranoPosjeceno || polja[x1][y1] == Polje::BlokiranoPrazno || polja[x1][y1] == Polje::BlokiranoMina ) throw std::logic_error("Blokirano Polje");
   x=x1;
   y=y1;
 	}
 	 if ( smjer == Smjerovi::GoreDesno)	{
 		x1--;
 		y1++;
 	 if ( x1 < 0 || y1 >= polja[0].size() ) throw std::out_of_range("Izlazak van igrace table");
 	 if ( polja[x1][y1] == Polje::BlokiranoPosjeceno || polja[x1][y1] == Polje::BlokiranoPrazno || polja[x1][y1] == Polje::BlokiranoMina ) throw std::logic_error("Blokirano Polje");
   x=x1;
   y=y1;
 	}
 	 if ( smjer == Smjerovi::Desno)	{
 		y1++;
 	 if ( y1 >= polja.size() ) throw std::out_of_range("Izlazak van igrace table");
 	 if ( polja[x1][y1] == Polje::BlokiranoPosjeceno || polja[x1][y1] == Polje::BlokiranoPrazno || polja[x1][y1] == Polje::BlokiranoMina ) throw std::logic_error("Blokirano Polje");
   x=x1;
   y=y1;
 	}
 	 if ( smjer == Smjerovi::DoljeDesno)	{
 		y1++;
 		x1++;
 	 if (x1>=polja.size() || y1 >= polja.size() ) throw std::out_of_range("Izlazak van igrace table");
 	 if ( polja[x1][y1] == Polje::BlokiranoPosjeceno || polja[x1][y1] == Polje::BlokiranoPrazno || polja[x1][y1] == Polje::BlokiranoMina ) throw std::logic_error("Blokirano Polje");
   x=x1;
   y=y1;
 	}
 	 if ( smjer == Smjerovi::Dolje)	{
 		x1++;
 	 if (x1>=polja.size()) throw std::out_of_range("Izlazak van igrace table");
 	 if ( polja[x1][y1] == Polje::BlokiranoPosjeceno || polja[x1][y1] == Polje::BlokiranoPrazno || polja[x1][y1] == Polje::BlokiranoMina ) throw std::logic_error("Blokirano Polje");
 	 x=x1;
 	 y=y1;
 	  
 	 }
 	 if ( smjer == Smjerovi::DoljeLijevo)	{
 		x1++;
 		y1--;
 	 if (x1>=polja.size() || y1 < 0) throw std::out_of_range("Izlazak van igrace table");
 	 if ( polja[x1][y1] == Polje::BlokiranoPosjeceno || polja[x1][y1] == Polje::BlokiranoPrazno || polja[x1][y1] == Polje::BlokiranoMina ) throw std::logic_error("Blokirano Polje");
   x=x1;
   y=y1;
 	}
 	 if ( smjer == Smjerovi::Lijevo)	{
 		y1--;
 	 if (y1 < 0) throw std::out_of_range("Izlazak van igrace table");
 	 if ( polja[x1][y1] == Polje::BlokiranoPosjeceno || polja[x1][y1] == Polje::BlokiranoPrazno || polja[x1][y1] == Polje::BlokiranoMina ) throw std::logic_error("Blokirano Polje");
 	x=x1;
 	y=y1;
 	  
 	 }
 	
 	if ( polja[x][y] == Polje::Mina)	{
 		for ( int i = 0 ; i < polja.size(); i++)	{
 			for ( int j = 0; j < polja[i].size(); j++)		polja[i][j] = Polje::Prazno;
 			}
 		return Status::KrajPoraz;
 	}
 		int brojac=0;
 	for ( int i = 0 ; i < polja.size(); i++)	{
 			for ( int j = 0; j < polja[i].size(); j++)	{
				if ( polja[i][j] == Polje::Prazno) brojac++;
 			}
 		}
 		if ( brojac == 0 ) return Status::KrajPobjeda; 
 	
 		return Status::NijeKraj;
 }
 
 
 Status Idi(Tabla &polja, int &x , int &y , int novi_x , int novi_y)	{

if ( polja[novi_x][novi_y] == Polje::BlokiranoPosjeceno) throw std::logic_error("Blokirano polje");
      if ( polja[novi_x][novi_y] == Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
   if ( polja[novi_x][novi_y] == Polje::BlokiranoPrazno) throw std::logic_error("Blokirano polje");
 	 if ( novi_x < 0 || novi_y < 0 || novi_x >= polja.size() || novi_y >= polja[0].size() ) throw std::out_of_range("Izlazak van igrace table");

 	 polja[x][y] = Polje::Posjeceno;
 	 	x = novi_x;
 	 	y = novi_y;

   

    	if ( polja[x][y] == Polje::Mina)	{
 		for ( int i = 0 ; i < polja.size(); i++)	{
 			for ( int j = 0; j < polja[i].size(); j++)	{
 				polja[i][j] = Polje::Prazno;
 			}
 		}
 		return Status::KrajPoraz;
 	}
 		int brojac=0;
 	for ( int i = 0 ; i < polja.size(); i++)	{
 			for ( int j = 0; j < polja[i].size(); j++)	{
				if ( polja[i][j] == Polje::Prazno) brojac++;
 			}
 		}
 		if ( brojac == 0 ) return Status::KrajPobjeda; 
 	
 		return Status::NijeKraj;
 	}
 	
 void PrijaviGresku(KodoviGresaka greska)	{
 		if ( greska == KodoviGresaka::PogresnaKomanda ) std::cout<<"Nerazumljiva komanda!"<<std::endl;
 		else if ( greska == KodoviGresaka::NedostajeParametar ) std::cout<<"Komanda trazi parametar koji nije naveden!"<<std::endl;
 		else if ( greska == KodoviGresaka::NeispravanParametar ) std::cout<<"Parametar komande nije ispravan!"<<std::endl;
 		else if ( greska == KodoviGresaka::SuvisanParametar ) std::cout<<"Zadan je suvisan parametar nakon komande!"<<std::endl;
	}
	
	
 bool UnosKomande(Komande &komanda , Smjerovi &smjer, int &x, int &y,KodoviGresaka &greska,int &p_x,int &p_y)	{
 	   	std::cout<<"Unesite komandu: ";
      std::string S;
 	 	  std::getline(std::cin,S);
      int k = 0;
      while ( (S[k] == ' ' || S[k] == '\t') && k < S.length()  ) S.erase(S.begin()+k);
 	 	  
 	 	  for ( int l = k ; l < S.length()-1 ; l++) {
 	 	       int broj = 0;
 	 	       int razmak = l;
 	 	       while ( (S[l] == ' ' || S[l] == '\t') && l < S.length()) {
 	 	        broj++;
 	 	        l++;
 	 	       }
 	 	       int z = razmak+1;
 	 	       if ( broj > 1 )  while (   z < l && z < S.length() )  S.erase(S.begin()+z);
 	 	      }
 	 	      if ( S[S.length()-1] == ' ' || S[S.length()-1] == '\t') S.erase(S.begin()+S.length()-1);
     	    if ( S == "K")  {
     	    komanda = Komande::KreirajIgru;
     	    return true;
     	    }  
     	  
     	   if ( S == "P1 DoD") {
     	    komanda = Komande::PomjeriJednoMjesto;
     	    smjer = Smjerovi::DoljeDesno;
     	    return true;
     	   }

     	   if ( S == "P1 GL") {
     	    komanda = Komande::PomjeriJednoMjesto;
     	    smjer = Smjerovi::GoreLijevo;
     	    return true;
     	   }
     	   if ( S == "P1 G") {
     	    komanda = Komande::PomjeriJednoMjesto;
     	    smjer = Smjerovi::Gore;
     	    return true;
     	   }
     	    if ( S == "P1 GD") {
     	    komanda = Komande::PomjeriJednoMjesto;
     	    smjer = Smjerovi::GoreDesno;
     	    return true;
     	   }
     	   
     	    	   if ( S == "P1 D") {
     	    komanda = Komande::PomjeriJednoMjesto;
     	    smjer = Smjerovi::Desno;
     	    return true;
     	   }
     	   	   if ( S == "P1 Do") {
     	    komanda = Komande::PomjeriJednoMjesto;
     	    smjer = Smjerovi::Dolje;
     	    return true;
     	   }
     	   	   if ( S == "P1 DoL") {
     	    komanda = Komande::PomjeriJednoMjesto;
     	    smjer = Smjerovi::DoljeLijevo;
     	    return true;
     	   }
     	   	   if ( S == "P1 L") {
     	    komanda = Komande::PomjeriJednoMjesto;
     	    smjer = Smjerovi::Lijevo;
     	    return true;
     	   }
     	   if ( S == "PO") {
     	    komanda = Komande::PrikaziOkolinu;
     	    return true;
     	   }
     	   
     	   if ( S == "Z") {
     	    komanda = Komande::ZavrsiIgru;
     	    return true;
     	   }
     	   int q(0),r(0);
     	   for ( int i = 0; i < S.size(); i++){
     	     while ( (S[i] >= '0' && S[i] <='9') && i <S.size() ) {
     	      q = q*10+(S[i]-'0');
     	      i++;
     	    }
     	    if ( S[i] == ' ') i++;
     	     while ( (S[i] >= '0' && S[i] <='9') && i <S.size()) {
     	      r = r*10+(S[i]-'0');
     	      i++;
     	     }

     	   }
     	 

     	   if ( S == ("P> "+std::to_string(r)+" "+std::to_string(q))) {
     	    komanda = Komande::PomjeriDalje;
     	    p_x = r;
     	    p_y = q;
     	    return true;
     	   }
     	   
   
     	     if ( S == ("B "+std::to_string(r)+" "+std::to_string(q))) {
     	      x = r;
     	      y = q;
     	    komanda = Komande::Blokiraj;
     	    return true;
     	   }
     	   if ( S == ("D "+std::to_string(r)+" "+std::to_string(q))) {
     	     x = r;
     	     y = q;
     	    komanda = Komande::Deblokiraj;
     	    return true;
     	   }
     	   else {
     	    greska = KodoviGresaka::NeispravanParametar;
     	   }
     	   return false;
     	 
     	
    
 }
 
 void IzvrsiKomandu(Komande komanda, Tabla &polja,int&x,int&y,Smjerovi p_smjer ,int &p_x,int &p_y) {
   if (komanda == Komande::KreirajIgru) {
    std::cout<<"Unesite broj polja: ";
    int n;
 	std::cin>>n;
	 std::cin.clear();
	 std::cin.ignore(10000, '\n');
  	std::cout<<"Unesite pozicije mina: ";
  	std::vector<std::vector<int>>mine;
  	std::vector<int>V;
  	int R = 0;
    	for( ; ;)	{
 	std::string s;
   	std::getline(std::cin,s);
   	if( s[0] == '(' && (s[1] >= '0' && s[1] <='9') && s[2] ==',' && (s[3] >= '0' && s[3] <='9') && s[4] == ')' ) {
		if ( s[1]-'0' > n || s[3]-'0' >n) {
		 std::cout<<"Greska, unesite ponovo!"<<std::endl;
		 continue;
		}
		  R++;
		  mine.resize(R);
		  V.push_back(s[1]-'0');
  		V.push_back(s[3]-'0');
   		if ( s[5] == '.' ) break;
}
 		int a=0;
   	for ( int i = 0 ; i < s.length() ; i++) if ( s[i] == '.') {
   		a=1;
   		break;
   	}
     	if (a==1) break;
   	else if(!(s[0] == '(' && (s[1] >= '0' && s[1] <='9') && s[2] ==',' && (s[3] >= '0' && s[3] <='9') && s[4] == ')')) {
   		std::cout<<"Greska, unesite ponovo!"<<std::endl;
   		continue;
   	}	
 } 
 int h=0;
  for ( int z = 0; z < R; z++) {
    for ( int k = 0 ; k < 2 ; k++) {
    mine[z].push_back(V[h]);
    h++;
    }
  }

   
  	polja = KreirajIgru(n ,mine);

   }  
   if ( komanda == Komande::PomjeriJednoMjesto) {
      Status a;
      a = Idi(polja,x,y,p_smjer);
      std::cout<<"Tekuca pozicija igraca je ("<<x<<","<<y<<")"<<std::endl;
     if ( a == Status::KrajPoraz ) {
      std::cout<<"Nagazili ste na minu"; 
      throw std::runtime_error("Igra zavrsena");
     }
     else if ( a == Status::KrajPobjeda ) {
      std::cout<<"Bravo, obisli ste sva sigurna polja";
      throw std::runtime_error("Igra zavrsena");

     }
   }
   if ( komanda == Komande::PrikaziOkolinu) {
    std::vector<std::vector<int>> Matrica (3,std::vector<int>(3));
     Matrica = PrikaziOkolinu(polja,x,y);
     for ( int i = 0 ; i < Matrica.size(); i++){
      for (int j = 0 ; j < Matrica[i].size(); j++) std::cout<<Matrica[i][j]<<" ";
     
           std::cout<<std::endl;

     }
   }
   
   if ( komanda == Komande::Blokiraj)   {
    BlokirajPolje(polja,x,y);	  }
   if ( komanda == Komande::Deblokiraj)   {
    DeblokirajPolje(polja,x,y);	
   }
   if ( komanda == Komande::PomjeriDalje)   {
     try {
        Status a;
 
     a = Status(Idi(polja, x , y , p_x , p_y));
      std::cout<<"Tekuca pozicija igraca je ("<<x<<","<<y<<")"<<std::endl;
       if ( a == Status::KrajPoraz ) {
      std::cout<<"Nagazili ste na minu"; 
      throw std::runtime_error("Igra zavrsena");
     }
     else if ( a == Status::KrajPobjeda ) {
      std::cout<<"Bravo, obisli ste sva sigurna polja";
      throw std::runtime_error("Igra zavrsena");

     }
      
     }
     catch (std::logic_error izuzetak) {
      std::cout << izuzetak.what() << std::endl;
     }
   
     
   }

   
   if ( komanda == Komande::ZavrsiIgru ) {
    for ( int i = 0 ; i < polja.size(); i++) {
     for ( int j = 0 ; j < polja[i].size(); j++) {
       polja[i][j] = Polje::Prazno;
     }
    }
    throw std::runtime_error("Igra zavrsena");
   }
 }
 

int main ()
{
	bool a ;
	int x=0,y=0;
	int p_x=0,p_y=0;
	Komande komande;
	Smjerovi smjerovi;
	KodoviGresaka greske;
	Tabla polja;
	try {
	for ( ;; ) {
	a = UnosKomande(komande,smjerovi,x,y,greske,p_x,p_y);
	if ( a==true) IzvrsiKomandu(komande,polja,x,y,smjerovi,p_x,p_y);
	else if ( a==false) PrijaviGresku(greske);
	}	}
	catch (std::runtime_error izuzetak) {
	 std::cout<<"Dovidjenja!" << std::endl;
	}
	

	return 0;
}