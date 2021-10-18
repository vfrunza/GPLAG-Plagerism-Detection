#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>

typedef std::vector<std::vector<double>> Matrica;


int BrojRedova(Matrica m){
	return m.size();
}

int BrojKolona(Matrica m){
	return m[0].size();
}

void IspisiMatricu (Matrica m ){
	for(int i=0;i<BrojRedova(m);i++){
		for(int j=0;j<BrojKolona(m);j++)
			std::cout<<std::setw(4)<<m[i][j];
			std::cout<<std::endl;
	}
}


Matrica KreirajMatricu(int br_redova,int br_kolona){
	return Matrica(br_redova,std::vector<double>(br_kolona));
}

Matrica UnesiMatricu(int br_redova, int br_kolona){
	auto m(KreirajMatricu(br_redova,br_kolona));
	for(int i=0;i<br_redova;i++){
		for(int j=0;j<br_kolona;j++){
			std::cin>>m[i][j];
		}
	}
	return m;
	
}


Matrica HorizontalnaMatrica(Matrica m){
	
	
	for(int i=0;i<m.size();i++){
		for(int j=0;j<m[i].size()/2;j++){
			
			int vel=m[i].size();
			
			double poc=m[i][j];
			double kraj=m[i][vel-j-1];
			double temp;
			
			temp=poc;
			poc=kraj;
			kraj=temp;
			
			
			m[i][j]=poc;
			m[i][vel-j-1]=kraj;
		}
	}
	return m;
}


Matrica VertikalnaMatrica(Matrica m){
	
	for(int i=0;i<m.size()/2;i++){
		
		int vel=m.size();
		
		std::vector<double>pomocni;
		
		std::vector<double> poc=m[i];
		std::vector<double> kraj=m[vel-1-i];
		
		pomocni=poc;
		poc=kraj;
		kraj=pomocni;
		
		m[i]=poc;
		m[vel-1-i]=kraj;
		
	}
		
	return m;
	
}

Matrica HorizontalnoVertikalnaMatrica(Matrica m){
	
	m=VertikalnaMatrica(m);
	m=HorizontalnaMatrica(m);
	
	return m;
}



std::vector<std::vector<double>> OgledaloMatrica(std::vector<std::vector<double>> m){
	
	//Matrica m1(3*m.size(),std::vector<double>(3*m[0].size()))
	
	Matrica H,V,HV,m1;
	m1.resize(3*m.size());
	
	
	for(int i=0;i<m1.size();i++) m1[i].resize(m[0].size()*3);
		H=HorizontalnaMatrica(m);
		V=VertikalnaMatrica(m);
		HV=HorizontalnoVertikalnaMatrica(m);
		
		int red(0),kolona(0);
		
		for(int i=0;i<m1.size();i++){
			for(int j=0;j<m1[0].size();j++){
			if((j<m[0].size()&&i<m.size()) || (j>=m[0].size()*2 && i<m.size()) || (j<m[0].size() && i>=m.size()*2) || (j>=m[0].size()*2 && i>=m.size()*2)){
				m1[i][j]=HV[red][kolona];
				kolona++;
				if(kolona==m[0].size()) kolona=0;
			}
			else if((j>=m[0].size()&&j<m[0].size()*2 &&i<m.size()) || (j>=m[0].size() && j<m[0].size()*2 && i>=m.size()*2)){
				m1[i][j]=V[red][kolona];
				kolona++;
				if(kolona==m[0].size()) kolona=0;
			}
			else if((i>=m.size() && i<m.size()*2 && j<m[0].size()) || (i>=m.size() && i<m.size()*2 && j>=m[0].size()*2)){
				m1[i][j]=H[red][kolona];
				kolona++;
				if(kolona==m[0].size()) kolona=0;
			}
			else{
				m1[i][j]=m[red][kolona];
				kolona++;
				if(kolona==m[0].size()) kolona=0;
			}
		}
		red++;
		if(red==m.size()) red=0;
	
	
	
		}
	return m1;
}



int main ()
{
try{
	
	int m1,n1;
	std::cout<<"Unesite dimenzije matrice (m n): ";
	std::cin>>m1>>n1;
	if(m1<0 || n1<0) throw std::domain_error("Dimenzije matrice moraju biti nenegativne!");
	
	
	std::cout<<"Unesite elemente matrice: ";
	
	auto A(UnesiMatricu(m1,n1));
	
	
	
	std::cout<<std::endl;
	
	std::cout<<"Rezultantna matrica: "<<std::endl;
	
	Matrica b;
	b=OgledaloMatrica(A);
	IspisiMatricu(b);
}

catch(std::domain_error izuzetak){
	std::cout<<izuzetak.what();
	
}
	
	return 0;
}