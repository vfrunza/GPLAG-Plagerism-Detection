/*B 2017/2018, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.	
*/
#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>
#include <limits>
//testira vrijednosti okolo elementa koji je najveci
double TestirajOkolo(std::vector<std::vector<double>> matrica, int y, int x, int broj, double suma1)
{
	//testira slucajeve kada ce koordinate elementa izaci iz opsega ranga matrice 
	if(x==0||y==0||matrica.size()==y+1||matrica.at(0).size()==x+1) {/*std::cout<<"pozvana prva"<<std::endl;*/ return 0;}
	if(x-broj/2<0||x+broj/2>matrica.at(0).size()-1||y-broj/2<0||y+broj/2>matrica.size()-1) {/*std::cout<<"pozvana druga"<<std::endl;*/ return 0;}
	double suma(0),temp(0);
	//postavlja brojac na negativnu vrijednost u zavisnosti od broja,
	//za 3 (testira 2^3 elemenata okolo), i = -1 (cijelobrojna vrijednost 3/2) i ide do 2
	//tako da testira 3 elementa iz jednog reda
	for(int i = -broj/2; i < broj/2+1; i++)
	{
		for(int j = -broj/2; j < broj/2+1; j++)
		{
			//uzima samo vrijednosti koje se nalaze na rubu "kvadrata" koji ima obim elemenata 2^broj
			if(j == -broj/2||j==broj/2||i==-broj/2||i==broj/2)
			{
				temp+=matrica.at(y+i).at(x+j);
			}
		}
		//sabira elemente ruba podmatrice za testiranje vrha
		suma+=temp;
		temp=0;
	}
	if(suma<suma1) {/*std::cout<<"proso test!"<< std::endl;*/ return suma;}
	return 0;
}

bool TestGrbavosti(std::vector<std::vector<double>> matrica)
{
	//kad je m i n matrice 0, matrica nije grbava
	if(matrica.size()==0) return false;
	int m(matrica.size()),n(matrica.at(0).size());
	//u slucaju grbave matrice baca izuzetak
	for(int i = 0; i < matrica.size(); i++)
	{
		for(int j = 0; j < matrica.at(i).size(); j++)
		{
			if(m==matrica.size()) break;
			else throw std::domain_error("Matrica nije korektna");
		}
		if(!(n==matrica.at(i).size())) throw std::domain_error("Matrica nije korektna");
	}
	return false;
}
//dodaje podmatricu koja zadovoljava uslov da je planina
std::vector<std::vector<double>> SaljiUMatricu(std::vector<std::vector<double>> matrica, int y, int x, int broj)
{
	std::vector<std::vector<double>> nova;
	std::vector<double> pomocna;
	for(int i = -broj/2; i < broj/2+1; i++)
	{
		for(int j = -broj/2; j < broj/2+1; j++)
		{
			pomocna.push_back(matrica.at(y+i).at(x+j));
		}
		nova.push_back(pomocna);
		pomocna.clear();
	}
	return nova;
}

std::vector<std::vector<double>> NajvecaPlaninaMatrice(std::vector<std::vector<double>> matrica)
{
	bool postoji(false);
	postoji=TestGrbavosti(matrica);
	std::vector<std::vector<double>> nova;
	std::vector<double> pomocni;
	double vrh(0),suma(0),zbfp(0),jednodimenzionalnivrh(0);
	int broj(3),max(0),x(0),y(0),mini = std::numeric_limits<int>::min();
	//std::cout<<"min je: "<< mini<<std::endl;
	for(auto i : matrica)
    {
        for(auto j : i)
	    {
	        //ako nadje da je element matrice najveci onda ga dalje salje u funkcije iznad
	        if(j > mini)
	        {
	        	vrh=j;
	            //jednodimenzionalni vrh je koristan u slucaju matrica 2x2 i vektora
	            //bitan je za to sto ce kasnije dodati element u krajnju matricu
	            //jer nece moci proci gornje funkcije
	            jednodimenzionalnivrh=vrh;
	            //suma je nula ako nije ispunjen uslov u TestirajOkolo
	            suma=TestirajOkolo(matrica,y,x,broj,vrh);
	            if(suma!=0)
	            {
	            	//vrsi dalje testiranje matrice, ako moze proci i veci opseg okolo
	            	for(;;)
	            	{
	            		//testira da li najveca podmatrica zadovoljava uslove da bude najveca planina
	            		if(postoji==false&&max<broj/2){ nova=SaljiUMatricu(matrica,y,x,broj); postoji=true; max++;}
	            		broj+=2;
	            		zbfp=TestirajOkolo(matrica,y,x,broj,suma);
	            		//posalje vrijednost planine u matricu i uzima veci broj
	            		//ako ne prodje TestirajOkolo prekida matricu
	            		//a a ko prodje testira za veci broj
	            		if(zbfp!=0) 
	            		{
	            			postoji=false;
	            			suma=zbfp;
	            		}
	            		if(postoji==true) break;
	            	}
	            }
			    broj=3;
			    suma=0;
	        }
	        x++;
	    }
	    x=0;
	    y++;
    }
    //u slucaju da je matrica koja nece ispuniti uslove funkcija navedenih iznad onda je
    //vrh najveci element te nove matrice
	if(nova.size()==0&&matrica.size()!=0)
	{
		pomocni.push_back(jednodimenzionalnivrh);
		nova.push_back(pomocni);
	}
	
	return nova;
}


int main ()
{
	try
	{
		int m(0),n(0);
		double testunosa(0);
		std::vector<double> pomocna;
		std::vector<std::vector<double>> pomocna1;
		std::vector<std::vector<double>> pomocna2;
		
		std::cout<< "Unesite dimenzije matrice (m i n): ";
		for(;;)
		{
			std::cin>>testunosa;
			if(int(testunosa)/testunosa==1){m=testunosa; break;}
			std::cout<<"Dimenzije moraju biti cijeli brojevi!!!";
			std::cin.clear();
			std::cin.ignore(1000,'\n');
		}
		for(;;)
		{
			std::cin>>testunosa;
			if(int(testunosa)/testunosa==1){n=testunosa; break;}
			std::cout<<"Dimenzije moraju biti cijeli brojevi!!!";
			std::cin.clear();
			std::cin.ignore(1000,'\n');
		}
		if(m<0||n<0)
		{
			std::cout<<"Dimenzije matrice moraju biti nenegativne!";
			return 0;
		}
		std::cout<< "Unesite elemente matrice:";
		for(int i=0; i < m; i++)
		{
			for(int j=0; j < n; j++)
			{
				for(;;)
				{
					if(!(std::cin>>testunosa))
					{
						std::cout<<"To nije broj!!!";
						std::cin.clear();
						std::cin.ignore(1000,'\n');
					}
					else {pomocna.push_back(testunosa); break;}
				}
			}
			pomocna1.push_back(pomocna);
			pomocna.clear();
		}
		pomocna2=NajvecaPlaninaMatrice(pomocna1);
		std::cout<<std::endl<<"Najveca planina unesene matrice je:"<<std::endl;
		for(auto i : pomocna2)
	        {for(auto j : i)
	        {
	            //std::cout.width(temp);
	            //std::cout.width(3);
	            std::cout<<std::setw(6)<< j;
	        }
	        std::cout<<std::endl;
	        }
	}
	catch (std::domain_error izuzetak)
	{
		std::cout << izuzetak.what() << std::endl;
	}
	return 0;
}