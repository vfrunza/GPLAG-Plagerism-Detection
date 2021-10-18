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
typedef std::vector<std::vector<double>> Matrica;
typedef std::vector<double> Vektor;
Matrica OgledaloMatrica(Matrica m){
	if(m.empty())return m;
    Matrica z(m.size()*3,Vektor(m[0].size()*3));
    int x(m.size());
    int y(m[0].size());
    Matrica h(x,Vektor(y)),v(x,Vektor(y)),hv(x,Vektor(y));     //deklaracija matrice
    
    for(int i=0;i<m.size();i++){
    	if(y!=m[i].size() && i!=0)throw std::domain_error("Matrica nije korektna");       //provjera da li je grbava matrica
    }
    
    for(int i=0;i<x;i++){                       // pravimo zadate tri matrice
    	for(int j=0;j<y;j++){
    		h[i][j]=m[i][y-1-j];
    		v[i][j]=m[x-1-i][j];
    		hv[i][j]=m[x-1-i][y-1-j];
    	}
    }
    int a(0),b(0);
    for(int i=0;i<x*3;i++){                          // ispis nasih matrica u glavnu matricu koja nam se trazi
    	if(i==x || i==2*x || i==0)a=0;                  //resetovanje a i b pod posebnim uslovima da bi na pravi nacin prolazili kroz nase 4 matrice
    	for(int j=0;j<y*3;j++){
    		if(j==y || j==2*y || j==0)b=0;
    		if( ( (i>=0 && i<x) && ((j>=0 && j<y) || (j>=y*2 && j<y*3)) ) || ( ( i>=2*x && i<3*x) && ((j>=0 && j<y) || (j>=y*2&& j<y*3) ) ) ){
    			z[i][j]=hv[a][b];
    			b++;
    		}
    		if(((i>=2*x && i<3*x) || (i>=0 && i<x)) && (j>=y && j<2*y)){          
    			z[i][j]=v[a][b];
    			b++;
    		}
    		if((i>=x && i<2*x)&&((j>=0 && j<y) || (j>=y*2&& j<y*3))){
    			z[i][j]=h[a][b];
    			b++;
    		}
    		if((i>=x && i<x*2) && (j>=y && j<y*2)){
    			z[i][j]=m[a][b];
    			b++;
    		}
    	}
    	a++;
    	b=0;
    }
    return z;
}

int main ()
{
	int m,n;
	std::cout << "Unesite dimenzije matrice (m n): ";
	std::cin >> m >> n ;
	    if(m<0 || n<0){
	    	std::cout << "Dimenzije matrice moraju biti nenegativne!";
	    	return 0;
	    }	
	    Matrica a(m,std::vector<double>(n));
	    std::cout << "Unesite elemente matrice:" << std::endl;
	    for(int i=0;i<m;i++){
	    	for(int j=0;j<n;j++){
	    		double x;
	    		std::cin >> x;
	    		a[i][j]=x;
	    	}
	    }
	    try{
	    	Matrica b;
	    	b=OgledaloMatrica(a);
	    	std::cout << "Rezultantna matrica:" << std::endl;
	    	for(int i=0;i<b.size();i++){
	    		for(int j=0;j<b[i].size();j++){
	    			std::cout << std::right << std::setw(4) << b[i][j] ;
	    		}
	    		std::cout << std::endl;
	    	}
	    }
	    catch(std::domain_error izuzetak){
	    	std::cout << izuzetak.what() ;
	    }
	return 0;
}