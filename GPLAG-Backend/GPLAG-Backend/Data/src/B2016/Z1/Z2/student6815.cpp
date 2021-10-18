/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/

/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>


std::vector<std::vector<int>> Horizontalna (std::vector<std::vector<int>> Matrica) {
		int pom;
		for(int i=0; i<Matrica.size(); i++) {
			for(int j=0; j<Matrica[i].size()/2; j++) {
				pom=Matrica[i][j];
				Matrica[i][j]=Matrica[i][Matrica[i].size()-j-1];
				Matrica[i][Matrica[i].size()-j-1]=pom;
			}
		}
		return Matrica;
}


std::vector<std::vector<int>> Vertikalna (std::vector<std::vector<int>> Matrica) {
	
		std::vector<int> temp;
	
	for(int i=0; i<Matrica.size()/2; i++) {
		temp=Matrica[i];
		Matrica[i]=Matrica[Matrica.size()-i-1];
		Matrica[Matrica.size()-i-1]=temp;
	}
	
	
	return Matrica;
}


std::vector<std::vector<int>> Kombinovana (std::vector<std::vector<int>> Matrica) {
	std::vector<std::vector<int>> Matrica2;
	Matrica2=Horizontalna(Vertikalna(Matrica));
	
	return Matrica2;
}

std::vector<std::vector<int>> OgledaloMatrica (std::vector<std::vector<int>> Matrica) {

	std::vector<std::vector<int>> horizontalna=Horizontalna(Matrica);
	std::vector<std::vector<int>> vertikalna=Vertikalna(Matrica);
	std::vector<std::vector<int>> kombinovana=Kombinovana(Matrica);
	std::vector<std::vector<int>> m(Matrica.size()*3);
	for(int i = 0; i < m.size(); i++) m[i].resize(Matrica[0].size()*3);
	for(int i = 0; i < Matrica.size(); i++)
	    for(int j = 0; j <3; j++) {
	    	  for(int k = 0; k < Matrica[0].size(); k++) {
	    	  	if(j == 0) {
	    	  	 m[i][k] = kombinovana[i][k];
	    	  	}
	    	   if(j == 1)
	    	  	  m[i][k + Matrica[0].size()] = vertikalna[i][k];
	    	  	 if(j == 2) {
	    	  	  m[i][k + 2*Matrica[0].size()] = kombinovana[i][k];
	    	  	}
	    	  }
	    }
	  for(int i = Matrica.size(); i < 2*Matrica.size(); i++)
	    for(int j = 0; j <3; j++) {
	    	  for(int k = 0; k < Matrica[0].size(); k++) {
	    	  	if(j == 0) 
	    	  	  m[i][k] = horizontalna[i - Matrica.size()][k];
	    	  if(j == 1)
	    	  	  m[i][k + Matrica[0].size()] = Matrica[i  - Matrica.size()][k];
	    	  if(j == 2)
	    	  	  m[i][k + 2*Matrica[0].size()] = horizontalna[i- Matrica.size()][k];
	    	  }
	    }
	    for(int i = 2*Matrica.size(); i < 3*Matrica.size(); i++)
	    for(int j = 0; j <3; j++) {
	    	  for(int k = 0; k < Matrica[0].size(); k++) {
	    	  	if(j == 0) 
	    	  	  m[i][k] = kombinovana[i- 2*Matrica.size()][k];
	    	   if(j == 1)
	    	  	  m[i][k + Matrica[0].size()] = vertikalna[i- 2*Matrica.size()][k];
	    	   if(j == 2)
	    	  	  m[i][k + 2*Matrica[0].size()] = kombinovana[i- 2*Matrica.size()][k];
	    	  }
	    }  
	    return m;
}

int main ()
{
	std::vector<std::vector<int>> mat = {{1,2,3} ,{4,5,6}};
	std::vector<std::vector<int>> m;
	m = OgledaloMatrica(mat);
	
	for(int i = 0; i <m.size(); i++) {
	   for(int j = 0; j <m[0].size();j++) std::cout << m[i][j] << " ";
	   std::cout << std::endl;
	}
	
	return 0;
}
