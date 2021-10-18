/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/

#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>

std::vector<std::vector<double>> horizontalno (std::vector<std::vector<double>> matrica) {
std::vector<std::vector<double>>pomatrica=matrica;


for(int i=0;i<matrica.size();i++) {
    int n=0;
for(int j=matrica[0].size()-1;j>=0;j--) {
                                                  
pomatrica[i][n]=matrica[i][j];
n++;
}

}

return pomatrica;
}



std::vector<std::vector<double>> vertikalno (std::vector<std::vector<double>> matrica) {
std::vector<std::vector<double>>pomatrica=matrica;

int n=0;
for(int i=matrica.size()-1;i>=0;i--) {
    
for(int j=0;j<matrica[0].size();j++) {
pomatrica[n][j]=matrica[i][j];

}
n++;
}


return pomatrica;
}


std::vector<std::vector<double>> OgledaloMatrica (std::vector<std::vector<double>> matrica) {


try{ 
for(int i=0;i<matrica.size();i++) {
	if(matrica[i].size() != matrica[0].size() )  
		throw std::domain_error ("Matrica nije korektna");

   }
}

catch (std::domain_error izuzetak) {
	std::cout<<izuzetak.what();
}


std::vector<std::vector<double>> pomatrica=matrica;
std::vector<std::vector<double>> srednjamatrica=matrica;
std::vector<std::vector<double>> velikamatrica;


velikamatrica.resize(3*matrica.size());


int redovi=pomatrica.size();
int kolone=pomatrica[0].size();  //svaki red ima isto kolona pa je svejedno od kojeg vektora uzeti size(), ali najsigurnije od prvog, ne znas koliko ih ima


//upisivanje


pomatrica=vertikalno(horizontalno(pomatrica));

for(int i=0;i<redovi;i++) {

for(int j=0;j<kolone;j++) {                     //gore lijevo

velikamatrica[i].push_back(pomatrica[i][j]);

      } 
} 

pomatrica=srednjamatrica;
pomatrica=vertikalno(pomatrica);

for(int i=0;i<redovi;i++) {
	
for(int j=0;j<kolone;j++) {
	
velikamatrica[i].push_back(pomatrica[i][j]);            //gore

        }
}

pomatrica=srednjamatrica;
pomatrica=vertikalno(horizontalno(pomatrica));

for(int i=0;i<redovi;i++) {
                                               //gore desno
for(int j=0;j<kolone;j++) {

velikamatrica[i].push_back(pomatrica[i][j]);

      } 
}

pomatrica=srednjamatrica;
pomatrica=horizontalno(pomatrica);

for(int i=0;i<redovi;i++) {
                                               //lijevo
for(int j=0;j<kolone;j++) {

velikamatrica[i+redovi].push_back(pomatrica[i][j]);
      } 
}


pomatrica=srednjamatrica;

for(int i=0;i<redovi;i++) {
                                               //sredina
for(int j=0;j<kolone;j++) {

velikamatrica[i+redovi].push_back(pomatrica[i][j]);

      } 
}



pomatrica=srednjamatrica;
pomatrica=horizontalno(pomatrica);

for(int i=0;i<redovi;i++) {
                                               //desno
for(int j=0;j<kolone;j++) {

velikamatrica[redovi+i].push_back(pomatrica[i][j]);

      } 
}


pomatrica=srednjamatrica;
pomatrica=vertikalno(horizontalno(pomatrica));

for(int i=0;i<redovi;i++) {
                                               //dole lijevo
for(int j=0;j<kolone;j++) {

velikamatrica[2*redovi+i].push_back(pomatrica[i][j]);

      } 
}


pomatrica=srednjamatrica;
pomatrica=vertikalno(pomatrica);

for(int i=0;i<redovi;i++) {
                                               //dole 
for(int j=0;j<kolone;j++) {

velikamatrica[2*redovi+i].push_back(pomatrica[i][j]);

      } 
}


pomatrica=srednjamatrica;
pomatrica=vertikalno(horizontalno(pomatrica));

for(int i=0;i<redovi;i++) {
                                               //dole desno
for(int j=0;j<kolone;j++) {

velikamatrica[2*redovi+i].push_back(pomatrica[i][j]);

      } 
}


return velikamatrica;

}

int main ()
{
    
    int m,n,a;
    std::cout<<"Unesite dimenzije matrice (m n): ";
    std::cin>>m>>n;
    if(m<0 || n<0){
        std::cout<<"Dimenzije matrice moraju biti nenegativne!";
        return 0;
    }
    
    
     std::vector<std::vector<double>> matrica;
     matrica.resize(m);                         
     
     
    std::cout<<"Unesite elemente matrice: ";
    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++){
            std::cin>>a;
            matrica[i].push_back(a);
        }
    }
   
    if(m!=0 && n!=0) {
    matrica=OgledaloMatrica(matrica);
    }
    
    std::cout<<"\nRezultantna matrica: ";
   
    for(int i=0;i<matrica.size();i++) {
        std::cout<<std::endl;
        for(int j=0;j<matrica[0].size();j++) {
            std::cout<<std::setw(4)<<std::right<<matrica[i][j];
        }
        
    }
    
    
    
    
	return 0;
}