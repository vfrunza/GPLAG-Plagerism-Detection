#include<iomanip>
#include<iostream> 
#include<vector> 
std::vector<std::vector<double>>HorizontalnaMatrica(std::vector<std::vector<double>> Matrica){
	std::vector<std::vector<double>> HM;
	HM.resize(Matrica.size()); 
	for(int i(0); i<HM.size(); i++) HM[i].resize(Matrica[i].size()); 
	int n; 
	for(int i(0); i<HM.size(); i++){ 
		n=HM[i].size()-1;
		for(int j(0); j<HM[i].size(); j++){
			HM[i][j]=Matrica[i][n]; 
			n--;
		}
	} 
	return HM;
} 
std::vector<std::vector<double>> VertikalnaMatrica(std::vector<std::vector<double>> Matrica){
	std::vector<std::vector<double>> VM;
	VM.resize(Matrica.size());
	for(int i(0); i<VM.size(); i++) VM[i].resize(Matrica[i].size()); 
	int n, m; 
	m=VM[0].size();
	for(int j(0); j<m; j++){
		n=VM.size()-1;
		for(int i(0); i<VM.size(); i++){
			VM[i][j]=Matrica[n][j]; 
			n--;
		}
	} 
	return VM;
} 
std::vector<std::vector<double>> KombinovanaMatrica(std::vector<std::vector<double>> Matrica){
	std::vector<std::vector<double>> KM;
	KM.resize(Matrica.size());
	for(int i(0); i<Matrica.size(); i++) KM[i].resize(Matrica[i].size()); 
	int a, b, c, d;
	a=KM.size();
	b=KM.size()-1;
	c=KM[0].size();
	for(int i(0); i<a; i++){ 
		d=KM[0].size()-1;
		for(int j(0); j<c; j++){
			KM[i][j]=Matrica[b][d]; 
			d--;
		} 
		b--;
	} 
	return KM;
} 
std::vector<std::vector<double>> OgledaloMatrica(std::vector<std::vector<double>> Matrica){ 
	std::vector<std::vector<double>> NovaMatrica;
	std::vector<std::vector<double>> HM;
	HM=HorizontalnaMatrica(Matrica);
	std::vector<std::vector<double>> VM;
	VM=VertikalnaMatrica(Matrica);
	std::vector<std::vector<double>> KM;
	KM=KombinovanaMatrica(Matrica); 
	int a(Matrica.size());
	NovaMatrica.resize(3*a);  
	int b(Matrica[0].size());
	for(int i(0); i<NovaMatrica.size(); i++) NovaMatrica[i].resize(3*b);  
	for(int i(0); i<3*a; i++){
		for(int j(0); j<3*b; j++){
			if(i<a && j<b) NovaMatrica[i][j]=KM[i][j]; 
			else if(i>=a && i<a*2 && j<b) NovaMatrica[i][j]=HM[i-a][j]; 
			else if(i>=2*a && i<3*a && j<b) NovaMatrica[i][j]=KM[i-2*a][j]; 
			else if(i<a && j>=b && j<b*2) NovaMatrica[i][j]=VM[i][j-b]; 
			else if(i>=a && i<a*2 && j>=b && j<b*2) NovaMatrica[i][j]=Matrica[i-a][j-b];  
			else if(i>=a*2 && i<3*a && j>=b && j<b*2) NovaMatrica[i][j]=VM[i-2*a][j-b];
			else if(i<a && j>=2*b && j<3*b) NovaMatrica[i][j]=KM[i][j-2*b];
			else if(i>=a && i<2*a && j>=2*b && j<3*b) NovaMatrica[i][j]=HM[i-a][j-2*b]; 
			else if(i>=2*a && i<3*a && j>=2*b && j<3*b) NovaMatrica[i][j]=KM[i-2*a][j-2*b];
		}
	} 
	return NovaMatrica;
}
int main ()
{ 
	int m, n;
	std::cout << "Unesite dimenzije matrice (m n): "; 
	std::cin >> m >> n;  
	if(m<0 || n<0) std::cout << "Dimenzije matrice moraju biti nenegativne!"; 
	else if(m==0 && n==0) std::cout << "Unesite elemente matrice: " << std::endl << "Rezultantna matrica: ";  
	else 
	{ 
		std::vector<std::vector<double>> Matrica;
	    Matrica.resize(m);
	    for(int i(0); i<Matrica.size(); i++) Matrica[i].resize(n);
	    std::cout << "Unesite elemente matrice: ";
	    for(int i(0); i<m; i++)
		   for(int j(0); j<n; j++) std::cin >> Matrica[i][j];  
	    std::vector<std::vector<double>> Mirror(OgledaloMatrica(Matrica));  
	    std::cout << std::endl;
	    std::cout << "Rezultantna matrica: " << std::endl; 
	    for(int i(0); i<Mirror.size(); i++){
		   for(int j(0); j<Mirror[i].size(); j++){
			std::cout << std::setw(4)<< Mirror[i][j];
		} 
		std::cout << std::endl;
	}
	}
	return 0;
}