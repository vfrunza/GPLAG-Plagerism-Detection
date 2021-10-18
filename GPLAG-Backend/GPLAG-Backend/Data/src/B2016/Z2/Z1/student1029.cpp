/*B 16/17, Zadaća 2, Zadatak 1
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
	
*/
#include <iostream>
#include <vector>
#include <stdexcept>


enum class Polje {
	Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina
};
enum class Smjerovi {
	GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo
};
enum class Status {
	NijeKraj, KrajPoraz, KrajPobjeda
};
typedef std::vector<std::vector<Polje>> Tabla;

Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine)
{
	Tabla Igra(n, std::vector<Polje> (n,Polje::Prazno));
	
	for(int i = 0; i < (mine.size() - 1); i++)
	    for(int j = i + 1; j < mine.size(); j++)
	        if((mine.at(i).size() != mine.at(j).size()) || mine.at(j).size() != 2)
	           throw std::domain_error("Ilegalan format zadavanja mina");
	try
	{
		for(int i = 0; i < n; i++)
		    for(int j = 0; j < n; j++)
		        for(int k = 0; k < mine.size(); k++)
		            for(int l = 0; l < 2; l++)
		                if(Igra.at(i).at(j) == mine.at(k).at(l))
		                   Igra.at(i).at(j) = Polje::Mina;
	}
	catch (std::out_of_range) {
		throw std::domain_error("Ilegalne pozicije mina");
	}
	
	return Igra;           
}

std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y)
{
	if(x > polja.size() || y > polja.size())
	   throw std::domain_error("Polje (x,y) ne postoji");
	   
	std::vector<std::vector<int>> Matrica(3, std::vector<int> (3));
	
	for(int i = 0; i < 3; i++)
	 {
	    for(int j = 0; j < 3; j++)
	       {
	       	  int br_mina(0);
	          for(int k)//DODATI JOS USLOVE ZA OKOLINU TACKE ILI NAPRAVITI POMOCNU FJU KOJA
	          {         //CE PREDSTAVLJATI PETLJE KOJE PRISTUPAJU OKOLINI OKOLNE TACKE ZA (X,Y)
	              for(int l)
	                  if(polja.at().at() == Polje::Mina)
	                 	 br_mina++;
	          }
	          Matrica.at(i).at(j) = br_mina;
	       }
	 }
	   
	 return Matrica;        
}

void BlokirajPolje(Tabla &polja, int x, int y)
{
	if(x > polja.size() || y > polja.size())
	   throw std::domain_error("Polje (x,y) ne postoji");
	   
	for(int i = 0; i < polja.size(); i++)
	    for(int j = 0; j < polja(i).size(); j++)
	        if(i == x && j == y)
	        {
	           if(polja.at(i).at(j) == Polje::BlokiranoPrazno || polja.at(i).at(j) == Polje::BlokiranoPosjeceno || polja.at(i).at(j) == Polje::BlokiranoMina)
	        	   break;
	           static_cast<int>(polja.at(i).at(j)) += 3;
	        }
	        
}

void DeblokirajPolje(Tabla &polja, int x, int y)
{
	if(x > polja.size() || y > polja.size())
	   throw std::domain_error("Polje (x,y) ne postoji");
	   
	for(int i = 0; i < polja.size(); i++)   
	    for(int j = 0; j < polja.size(); j++)
	        if(i == x && j == y)
	        {
	           if(polja.at(i).at(j) == Polje::Prazno || polja.at(i).at(j) == Polje::Posjeceno || polja.at(i).at(j) == Polje::Mina)
	             break;
	           static_cast<int>(polja.at(i).at(j)) -= 3;
	        }
}






int main ()
{
	return 0;
}