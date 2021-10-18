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

double vrh (std::vector<std::vector<double>> matrica) {

double najvisi=0;
for(int i=0;i<matrica.size();i++) {
for(int j=0;j<matrica.at(i).size();j++) {
	
	if(matrica.at(i).at(j)>najvisi) najvisi=matrica.at(i).at(j);
	
}
}

return najvisi;
}


int koordx(std::vector<std::vector<double>> matrica) {
	
	int x;
	double a=vrh(matrica);
	for(int i=0;i<matrica.size();i++) {
	for(int j=0;j<matrica.at(i).size();j++) {
		
		if(abs(matrica.at(i).at(j)-a)<0.0001) x=i;
		
	}	
	}
	
	return x;
}

int koordy(std::vector<std::vector<double>> matrica) {
	
	int y;
	double a=vrh(matrica);
	for(int i=0;i<matrica.size();i++) {
	for(int j=0;j<matrica.at(i).size();j++) {
		
		if(abs(matrica.at(i).at(j)-a)<0.0001) y=j;
		
	}	
	}
	
	return y;
}



std::vector<std::vector<double>> NajvecaPlaninaMatrice (std::vector<std::vector<double>> matrica)
{
	
std::vector<std::vector<double>> prazna;
if(matrica.size()==0 || matrica.at(0).size()==0) return prazna;

for(int i=0;i<matrica.size();i++) {

for(int j=0;j<matrica.size();j++) {

	if(matrica.at(i).size()!=matrica.at(j).size()) throw std::domain_error("Matrica nije korektna");
	
}
}


	
    std::vector<std::vector<double>> najveca;
    
	for(int i=0; i<matrica.size(); i++)
	{

		for(int j=0; j<matrica.at(i).size(); j++)
		{

			if(i!=0 &&i<matrica.size()-1 && j!=0 && j<matrica.at(i).size()-1)
			{
double suma =matrica.at(i).at(j);


				int k=1;
				while ((i+k)<matrica.size() &&(j+k)<matrica.at(i).size() &&(i-k)>=0&&(j-k)>=0 && (suma>matrica.at(i).at(j-k)+matrica.at(i-k).at(j-k)+matrica.at(i-k).at(j)+matrica.at(i-k).at(j+k)+matrica.at(i).at(j+k)+matrica.at(i+k).at(j+k)+matrica.at(i+k).at(j)+matrica.at(i+k).at(j-k)))
				{

				
					
					suma=matrica.at(i).at(j-k)+matrica.at(i-k).at(j-k)+matrica.at(i-k).at(j)+matrica.at(i-k).at(j+k)+matrica.at(i).at(j+k)+matrica.at(i+k).at(j+k)+matrica.at(i+k).at(j)+matrica.at(i+k).at(j-k);
					k++;
				}
				k--;
	std::vector<std::vector<double>> planina;
					planina.resize(2*k+1); //ukupan broj redova
					                                              
					int o=0;
					for(int l=i-k; l<i-k+2*k+1; l++)                //pomocne varijable jer i,j se koriste za prolazak kroz poslanu matricu
					{

						for(int m=j-k; m<j-k+2*k+1; m++)
						{

							planina.at(o).push_back(matrica.at(l).at(m));
						}
						o++;         //o prebacuje redove u pomocnoj matrici planina
					}
					if(planina.size()>najveca.size()) {
						najveca=planina;
					}
					
					else if (vrh(planina)>vrh(najveca)) {
						najveca=planina;
					}
					
					else if(koordx(planina)>koordx(najveca)) {
						najveca=planina;
					}
					
					else if(koordy(planina)>koordy(najveca)) {
						najveca=planina;
					}
					
			}
		}

	}



if(najveca.size()==0) {                       //ako planina sa vrhom i barem 8 clanova okolo nije pronadjena unutar matrice, nadji vrh 

najveca.resize(1);
najveca.at(0).push_back(0);


for(int i=0;i<matrica.size();i++){
for(int j=0;j<matrica.at(i).size();j++) {


if(matrica.at(i).at(j)>najveca.at(0).at(0)) najveca.at(0).at(0)=matrica.at(i).at(j);

}
}

}

/*

// uporedjivanje velicine planina

for(int i=0;i<vektorplanina.size();i++) {

if(vektorplanina.at(i).size()>najveca.size()) najveca=vektorplanina.at(i);

}

bool nasao=false;
int i;
for(i=0;i<vektorplanina.size();i++)  {

if(vektorplanina.at(i).size()==najveca.size() && nasao==true) break;    //imaju dvije najvece istih dimenzija
if(vektorplanina.at(i).size()==najveca.size()) nasao=true;

}

if(i==vektorplanina.size()) return najveca;   // ako nemaju dvije najvece istih dimenzija, vrati najvecu

//uporedjivanje vrhova

for(i=0;i<vektorplanina.size();i++) {
if(vrh(vektorplanina.at(i))>vrh(najveca)) najveca=vektorplanina.at(i);

}

 nasao=false;

for(i=0;i<vektorplanina.size();i++) {
	
	if(vrh(vektorplanina.at(i))==vrh(najveca) && nasao==true) break;
 	if(vrh(vektorplanina.at(i))==vrh(najveca)) nasao=true;
	
}

if(i==vektorplanina.size()) return najveca;

//uporedjivanje x koordinata vrha


for(i=0;i<vektorplanina.size();i++) {
if(koordx(vektorplanina.at(i))<koordx(najveca)) najveca=vektorplanina.at(i);

}

nasao=false;
for(i=0;i<vektorplanina.size();i++) {
if(koordx(vektorplanina.at(i))==koordx(najveca) && nasao==true) break;
if(koordx(vektorplanina.at(i))==koordx(najveca)) nasao=true;

}
if(i==vektorplanina.size()) return najveca;

// nadji najmanju y koordinatu vrha

for(i=0;i<vektorplanina.size();i++) {
if(koordy(vektorplanina.at(i))<koordy(najveca)) najveca=vektorplanina.at(i);

}

*/


return najveca;
}



int main ()
{
	std::cout<<"Unesite dimenzije matrice (m i n): ";
	int m,n;
	std::cin>>m>>n;
	std::vector<std::vector<double>> matrica;

	if(m<0 || n<0) {
	std::cout<<"Dimenzije matrice moraju biti nenegativne!";
	return 0;
	}
		matrica.resize(m);
	double a;
	std::cout<<"Unesite elemente matrice: ";
	for(int i=0;i<m;i++) {
		
		for(int j=0;j<n;j++) {
			
			std::cin>>a;
			matrica.at(i).push_back(a);
		}
	} 
	
try {
	matrica=NajvecaPlaninaMatrice(matrica);
}
catch(std::domain_error izuzetak) {
	std::cout<<izuzetak.what();
}
		std::cout<<std::endl;
	std::cout<<"Najveca planina unesene matrice je: "<<std::endl;
	
	for(int i=0;i<matrica.size();i++) {
		for(int j=0;j<matrica.size();j++) {
		
		std::cout<<std::setw(6)<<std::right<<matrica.at(i).at(j);
		
		}
		std::cout<<std::endl;
	}
	
	
	
	
	return 0;
}