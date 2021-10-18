/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <iomanip>


using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::setw;



typedef vector<vector<double>> MATRICA;

MATRICA horizontalna_matrica(MATRICA matrica_pocetna){
	double temp;
	
	int n=matrica_pocetna[0].size();//duzina kolona matrice_pocetne
	int m=matrica_pocetna.size();//duzina redova matrice_pocetne
    for(int i=0; i<m; i++){
        for(int j=0; j<n/2; j++){
            temp=matrica_pocetna[i][j];
            matrica_pocetna[i][j]=matrica_pocetna[i][n-j-1];
            matrica_pocetna[i][n-j-1]=temp;
            
        }
    }
	return matrica_pocetna;	
}

MATRICA vertikalna_matrica(MATRICA matrica_pocetna){
	double temp;
	int n=matrica_pocetna[0].size();//duzina kolona matrice_pocetne
	int m=matrica_pocetna.size();//duzina redova matrice_pocetne
	for(int i=0; i<m/2; i++){
        for(int j=0; j<n; j++){
            temp=matrica_pocetna[i][j];
            matrica_pocetna[i][j]=matrica_pocetna[m-1-i][j];
            matrica_pocetna[m-1-i][j]=temp;
            
        }
    }
    
    return matrica_pocetna;
}

MATRICA hor_ver_matrica(MATRICA matrica_pocetna){
	int n=matrica_pocetna[0].size();//duzina kolona matrice_pocetne
	int m=matrica_pocetna.size();//duzina redova matrice_pocetne
	double temp;
	for(int i=0; i<m; i++){
        for(int j=0; j<n/2; j++){
            temp=matrica_pocetna[i][j];
            matrica_pocetna[i][j]=matrica_pocetna[i][n-j-1];
            matrica_pocetna[i][n-j-1]=temp;
            
        }
    }
    for(int i=0; i<m/2; i++){
        for(int j=0; j<n; j++){
            temp=matrica_pocetna[i][j];
            matrica_pocetna[i][j]=matrica_pocetna[m-1-i][j];
            matrica_pocetna[m-1-i][j]=temp;
            
        }
    }
	
	return matrica_pocetna;
}

MATRICA OgledaloMatrica(MATRICA matrica_pocetna){

	MATRICA h_matrica(horizontalna_matrica(matrica_pocetna));
	MATRICA v_matrica(vertikalna_matrica(matrica_pocetna));
	MATRICA hv_matrica(hor_ver_matrica(matrica_pocetna));
	
	int n=matrica_pocetna[0].size();//duzina kolona matrice_pocetne
	int m=matrica_pocetna.size();//duzina redova matrice_pocetne
	
	MATRICA monstrum;
	monstrum.resize(3*m);
	for (int i=0; i<3*m; i++) monstrum[i].resize(3*n);
	/*---------UNOS HV MATRICE U MONSTRUMA------*/
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(i<m && j<n) monstrum[i][j]=hv_matrica[i][j];
		}
	}
	for(int i=2*m;i<3*m;i++){
		for(int j=0;j<n;j++){
			int k=abs(3*m-i-m);
			if(i<3*m && j<n) monstrum[i][j]=hv_matrica[k][j];
		}
	}
	for(int i=0;i<m;i++){
		for(int j=2*n;j<3*n;j++){
			int l=abs(3*n-j-n);
			if(i<m && j<3*n) monstrum[i][j]=hv_matrica[i][l];
		}
	}
	for(int i=2*m;i<3*m;i++){
		for(int j=2*n;j<3*n;j++){
			int k=abs(3*m-i-m);
			int l=abs(3*n-j-n);
			if(i<3*m && j<3*n) monstrum[i][j]=hv_matrica[k][l];
		}
	}
	/*---------UNOS V MATRICE U MONSTRUMA--------*/
	for(int i=0;i<m;i++){
		for(int j=n;j<2*n;j++){
			int l=abs(2*n-j-n);
			if(i<m && j>=n) monstrum[i][j]=v_matrica[i][l];
		}
	}
	for(int i=2*m;i<3*m;i++){
		for(int j=n;j<2*n;j++){
			int k=abs(3*m-i-m);
			int l=abs(2*n-j-n);
			if(i>=2*m && j<2*n) monstrum[i][j]=v_matrica[k][l];
		}
	}
	for(int i=m;i<2*m;i++){
		for(int j=0;j<n;j++){
			int k=abs(2*m-i-m);
			if(i>=m && j<n) monstrum[i][j]=h_matrica[k][j];
		}
	}
	for(int i=m;i<2*m;i++){
		for(int j=2*n;j<3*n;j++){
			int k=abs(2*m-i-m);
			int l=abs(3*n-j-n);
			if(i>=m && j>=2*n) monstrum[i][j]=h_matrica[k][l];
		}
	}
	for(int i=m;i<2*m;i++){
		for(int j=n;j<2*n;j++){
			int k=abs(2*m-i-m);
			int l=abs(2*n-j-n);
			if(i>=m && j>=n) monstrum[i][j]=matrica_pocetna[k][l];
		}
	}
	
	return monstrum;
	
}

int main ()
{
	
	cout<<"Unesite dimenzije matrice (m n): ";
	int m, n;
	cin>>m>>n;
	if(m<0 || n<0){
		cout<<"Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	
	cout<<"Unesite elemente matrice: "<<endl;
	if(m==0 || n==0){
		MATRICA matrica_pocetna;
		if(n==0){ matrica_pocetna.resize(m);
		for(int i = 0; i < n; i++) matrica_pocetna[i].resize(n);}
		if(m==0) {matrica_pocetna.resize(n);
		for(int i = 0; i < n; i++) matrica_pocetna[i].resize(n);}
		cout<<"Rezultantna matrica:"<<endl;
	}
	else{
	MATRICA matrica_pocetna;
	matrica_pocetna.resize(m);
	for (int i=0; i<m; i++) matrica_pocetna[i].resize(n);
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin>>matrica_pocetna[i][j];
		}
	}
	
	MATRICA finalna_matrica(3*m, vector<double>(3*n));
	finalna_matrica=(OgledaloMatrica(matrica_pocetna));
	cout<<"Rezultantna matrica: "<<endl;
	for(int i(0);i<3*m;i++){
		for(int j(0);j<n*3;j++){
			cout<<setw(4)<<finalna_matrica[i][j];
		}
		cout<<endl;
	}
	}
	

	return 0;
}