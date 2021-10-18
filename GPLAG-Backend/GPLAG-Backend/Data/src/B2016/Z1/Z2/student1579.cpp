/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include<iostream>
#include<vector>
#include<stdexcept>
#include<iomanip>
typedef std::vector<std::vector<double> > matrice ;

matrice kreirajmat(int m, int n){
	return matrice(m,std::vector<double>(n));
}

matrice OgledaloMatrica(matrice m){
	matrice rez;
	if(m.size()==0) return rez;
	int x=m.size(),y=m[0].size();
	for(int i=0;i<x-1;i++){
		for(int j=i+1;j<x;j++){
			if(m[i].size()!=m[j].size()) 
			throw std::domain_error("Matrica nije korektna");
		}
	}
	rez=kreirajmat(3*x,3*y);
	matrice kolone=m,redovi=m,miks;
	double temp;
	for(int i=0;i<x;i++){
		for(int j=0;j<(y/2);j++){
			temp=kolone[i][j];
			kolone[i][j]=kolone[i][y-1-j];
			kolone[i][y-1-j]=temp;
		}
	}
	for(int i=0;i<(x/2);i++){
		for(int j=0;j<y;j++){
			temp=redovi[i][j];
			redovi[i][j]=redovi[x-1-i][j];
			redovi[x-1-i][j]=temp;
		}
	}
	miks=kolone;
	for(int i=0;i<(x/2);i++){
		for(int j=0;j<y;j++){
			temp=miks[i][j];
			miks[i][j]=miks[x-1-i][j];
			miks[x-1-i][j]=temp;
		}
	}
	int a=0,c=0,e=0,g=(-x),k=(-x),lj=(-x),nj=-(2*x),p=-(2*x),s=-(2*x);
	for(int i=0;i<(3*x);i++){
		int	b=0,d=0,f=0,h=0,l=0,n=0,o=0,r=0,t=0;
		for(int j=0;j<(3*y);j++){
			if(i<x && j<y){
				rez[i][j]=miks[a][b];
				b++;
				
			}
			if(i<x && j>=y && j<y*2){
				rez[i][j]=redovi[c][d];
				d++;
				
			}
			if(i<x && j>=2*y && j<y*3){
				rez[i][j]=miks[e][f];
				f++;
				
			}
			if(i>=x && i<2*x && j<y ){
				rez[i][j]=kolone[g][h];
				h++;
			}
			if(i>=x && i<2*x && j>=y && j<2*y){
				rez[i][j]=m[k][l];
				l++;
			}
			if(i>=x && i<2*x && j>=2*y){
				rez[i][j]=kolone[lj][n];
				n++;
			}
			if(i>=2*x && j<y){
				rez[i][j]=miks[nj][o];
				o++;
			}
			if(i>=2*x && j>=y && j<2*y){
				rez[i][j]=redovi[p][r];
				r++;
			}
			if(i>=2*x && j>=2*y){
				rez[i][j]=miks[s][t];
				t++;
			}
		}
		a++;
		c++;
		e++;
		g++;
		k++;
		lj++;
		nj++;
		p++;
		s++;
	}
	
	
	return rez ;
}

int main ()
{
	try{
	std::cout<<"Unesite dimenzije matrice (m n): ";
	int m,n;
	std::cin>>m;
	std::cin>>n;
	if(m<0 || n<0) throw std::domain_error("Dimenzije matrice moraju biti nenegativne!");
	matrice mat=kreirajmat(m,n);
	std::cout<<"Unesite elemente matrice:";
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			std::cin>>mat[i][j];
		}
	}
	std::cout<<std::endl<<"Rezultantna matrica:"<<std::endl;
	matrice rez=OgledaloMatrica(mat);
	for(int i=0;i<rez.size();i++){
		for(int j=0;j<rez[i].size();j++)
		std::cout<<std::setw(4)<<rez[i][j];
	std::cout<<std::endl;
		
	}
	}
	catch (std::domain_error x){
		std::cout<<x.what();
	}
	return 0;
}