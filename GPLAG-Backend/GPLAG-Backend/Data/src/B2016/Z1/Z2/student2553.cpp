#include <vector>
#include <iostream>
#include <stdexcept>
std::vector<std::vector<double>> OgledaloMatrica(std::vector<std::vector<double>> matrica){
	int brojkolona(-1);
	for(int i=0; i<matrica.size();i++){
		if(i==0)brojkolona=matrica[i].size();
		else if(brojkolona!=matrica[i].size()){
			brojkolona=-7; break;
		}
	}
	if(brojkolona==-7){
		throw std::domain_error("Matrica nije korektna");
	}else if(brojkolona!=-1){
		std::vector<std::vector<double>> velika_matrica(3*matrica.size());
		int pi,pj;
		for(int i=0;i<3*matrica.size();i++){
			if (i<matrica.size())pi=i;
			else if(i<2*matrica.size())pi=i-matrica.size();
			else pi=i-2*matrica.size();
			velika_matrica[i].resize(3*matrica[pi].size());
		}
		//napravljena prazna matrica;
		
	//	std::cout<<matrica.size()<<std::endl;
	//	std::cout<<matrica.size()<<" "<<matrica[0].size()<<std::endl;
	//	std::cout<<velika_matrica.size()<<" "<<velika_matrica[0].size()<<std::endl;
		for(int i=0; i<3*matrica.size();i++){
			if (i<matrica.size())pi=i;
			else if(i<2*matrica.size())pi=i-matrica.size();
			else pi=i-2*matrica.size();
			
			for(int j=0; j<3*matrica[pi].size();j++){
	
				if (j<matrica[pi].size())pj=j;
				else if(j<2*matrica[pi].size()) pj=j-matrica[pi].size();
				else pj=j-2*matrica[pi].size();
			//	std::cout<<i<<" "<<j<<" "<<pi<<" "<<pj<<std::endl;
				if(i<matrica.size()){
					if(j<matrica[0].size())velika_matrica[i][j]=matrica[matrica.size()-1-pi][matrica[0].size()-1-pj];
					else if(j<2*matrica[0].size())velika_matrica[i][j]=matrica[matrica.size()-1-pi][pj];
					else if(j<3*matrica[0].size())velika_matrica[i][j]=matrica[matrica.size()-1-pi][matrica[0].size()-1-pj];
				}
				else if(i<2*matrica.size()){
					if(j<matrica[0].size())velika_matrica[i][j]=matrica[pi][matrica[0].size()-1-pj];
					else if(j<2*matrica[0].size())velika_matrica[i][j]=matrica[pi][pj];
					else if(j<3*matrica[0].size())velika_matrica[i][j]=matrica[pi][matrica[0].size()-1-pj];
				}
				else{
					if(j<matrica[0].size())velika_matrica[i][j]=matrica[matrica.size()-1-pi][matrica[0].size()-1-pj];
					else if(j<2*matrica[0].size())velika_matrica[i][j]=matrica[matrica.size()-1-pi][pj];
					else if(j<3*matrica[0].size())velika_matrica[i][j]=matrica[matrica.size()-1-pi][matrica[0].size()-1-pj];
				}
			}
		}
		return velika_matrica;
	}
	return matrica;
}

int main ()
{
	
	
	std::vector<std::vector<double>> a;
	int m,n;
	std::cout<<"Unesite dimenzije matrice (m n): ";
	std::cin>>m>>n;
	std::cin.ignore(100000,'\n');
	if(n<0 || m<0)std::cout<<"Dimenzije matrice moraju biti nenegativne!";
	else{
		double x;
		std::cout<<"Unesite elemente matrice:";
		std::vector<std::vector<double>> mat(m);
		for(int i=0;i<m;i++){
			mat[i].resize(n);
		}
		for(int i=0; i<m;i++){
			for(int j=0; j<n;j++){
				std::cin>>x;
				mat[i][j]=x;
			}
		}
		try{
			a=OgledaloMatrica(mat);
			std::cout<<std::endl<<"Rezultantna matrica:"<<std::endl;
			for(int i=0; i<a.size();i++){
				for(int j=0; j<a[i].size();j++){
					std::cout.width(4);
					std::cout<<a[i][j];
				}
				std::cout<<std::endl;
			}
		}//
		catch(std::domain_error greska){
			std::cout<<greska.what();
		}
	
	}
	
	return 0;
}