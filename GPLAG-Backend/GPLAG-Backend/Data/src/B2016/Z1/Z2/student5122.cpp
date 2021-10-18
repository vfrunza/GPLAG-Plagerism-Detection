#include <iostream>
#include <iomanip>
#include <vector>
#include <stdexcept>

typedef std::vector<std::vector<double>> Matrica;

Matrica OgledaloMatrica(Matrica m){
	for(int i=0; i<m.size(); i++){
		if(i!=m.size()-1 && m[i].size()!=m[i+1].size()) throw std::domain_error ("Matrica nije korektna");
	}
	Matrica h,v,k;
	Matrica mat;
	h.resize(m.size());
	for(int i=0; i<m.size(); i++){
		h[i].resize(m[0].size());
	}
	k.resize(m.size());
	for(int i=0; i<m.size(); i++){
		k[i].resize(m[0].size());
	}
	v.resize(m.size());
	for(int i=0; i<m.size(); i++){
		v[i].resize(m[0].size());
	}
	mat.resize(3*m.size());
	for(int i=0; i<3*m.size(); i++){
		mat[i].resize(3*m[0].size());
	}
	for(int i=0; i<m.size(); i++){
		for(int j=0; j<m[0].size(); j++){
			v[i][j]=m[m.size()-1-i][j];
		}
	}
	for(int i=0; i<m.size(); i++){
		for(int j=0; j<m[0].size(); j++){
			h[i][j]=m[i][m[0].size()-1-j];
		}
	}
	for(int i=0; i<m.size(); i++){
		for(int j=0; j<m[0].size(); j++){
			k[i][j]=m[m.size()-1-i][m[0].size()-1-j];
		}
	}
	
	for(int i=0; i<3*m.size(); i++){
		for(int j=0; j<3*m[0].size(); j++){
			if(i<m.size() && j<m[0].size()){
				for(int a=0; a<m.size(); a++){
					for(int b=0; b<m[0].size(); b++){
						mat[i][j]=k[a][b];
						j++;
					}
					i++;
					j=0;
				}
			}
				i=0;
				j=m[0].size();
			if(i<m.size() && (j>=m[0].size() && j<2*m[0].size())){
				for(int c=0; c<m.size(); c++){
					for(int d=0; d<m[0].size(); d++){
						mat[i][j]=v[c][d];
						j++;
					}
					i++;
					j=m[0].size();
				}
			}
				i=0;
				j=2*m[0].size();
			
			if(i<m.size() && (j>=2*m[0].size() && j<3*m[0].size())){
				for(int e=0; e<m.size(); e++){
					for(int f=0; f<m[0].size(); f++){
						mat[i][j]=k[e][f];
						j++;
					}
					i++;
					j=2*m[0].size();
				}
			}
				i=m.size();
				j=0;
			
			if((i>=m.size() && i<2*m.size()) && j<m[0].size()){
				for(int g=0; g<m.size(); g++){
					for(int l=0; l<m[0].size(); l++){
						mat[i][j]=h[g][l];
						j++;
					}
					i++;
					j=0;
				}
			}
				i=m.size();
				j=m[0].size();
			if((i>=m.size() && i<2*m.size()) && (j>=m[0].size() && j<2*m[0].size())){
				for(int o=0; o<m.size(); o++){
					for(int p=0; p<m[0].size(); p++){
						mat[i][j]=m[o][p];
						j++;
					}
					i++;
					j=m[0].size();
				}
			}
				i=m.size();
				j=2*m[0].size();
			
			if((i>=m.size() && i<2*m.size()) && (j>=2*m[0].size() && j<3*m[0].size())){
				for(int q=0; q<m.size(); q++){
					for(int r=0; r<m[0].size(); r++){
						mat[i][j]=h[q][r];
						j++;
					}
					i++;
					j=2*m[0].size();
				}
			}
				i=2*m.size();
				j=0;
	
			if((i>=2*m.size() && i<3*m.size()) && (j<m[0].size())){
				for(int s=0; s<m.size(); s++){
					for(int t=0; t<m[0].size(); t++){
						mat[i][j]=k[s][t];
						j++;
					}
					i++;
					j=0;
				}
			}
				i=2*m.size();
				j=m[0].size();

			if((i>=2*m.size() && i<3*m.size()) && (j>=m[0].size() && j<2*m[0].size())){
				for(int u=0; u<m.size(); u++){
					for(int w=0; w<m[0].size(); w++){
						mat[i][j]=v[u][w];
						j++;
					}
					i++;
					j=m[0].size();
				}
			}
				i=2*m.size();
				j=2*m[0].size();
			if((i>=2*m.size() && i<3*m.size()) && (j>=2*m[0].size() && j<3*m[0].size())){
				for(int x=0; x<m.size(); x++){
					for(int y=0; y<m[0].size(); y++){
						mat[i][j]=k[x][y];
						j++;
					}
					i++;
					j=2*m[0].size();
				}
			}
			return mat;
		}
	}
return mat;
}

int main ()
{
	try{
	std::cout<<"Unesite dimenzije matrice (m n): ";
	int m, n;
	std::cin>>m>>n;
	if(m<0 || n<0){
		std::cout<<"Dimenzije matrice moraju biti nenegativne!"; return 0;
	}
	std::cout<<"Unesite elemente matrice: ";
	Matrica a(m,std::vector<double>(n));
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			std::cin>>a[i][j];
		}
	}std::cout<<std::endl;
	std::cout<<"Rezultantna matrica: "<<std::endl;
	
	Matrica mat;
	mat=OgledaloMatrica(a);
	for(int i=0; i<3*m; i++){
		for(int j=0; j<3*n; j++){
			std::cout<<std::right<<std::setw(4)<<mat[i][j];
		}
		std::cout<<std::endl;
	}
		
	} catch(std::domain_error izuzetak){
		std::cout<<izuzetak.what()<<std::endl;
	}
	
	return 0;
}