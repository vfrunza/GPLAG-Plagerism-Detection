#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <string>
#include <stdexcept>

typedef std::vector<std::vector<double>> Matrica;

Matrica OgledaloMatrica(Matrica m) {
             if(m.size()==0) return Matrica (m.size());
             else {
             	if(m[0].size()==0) return Matrica (3*m.size(),std::vector<double> (m[0].size()));
             	else {
             		if(m.size()==1 && m[0].size()==1) {
             			return Matrica {{m[0][0],m[0][0],m[0][0]},{m[0][0],m[0][0],m[0][0]},{m[0][0],m[0][0],m[0][0]}};
             		}
             	else {
  if(m[0].size()!=m[1].size()) throw std::domain_error("Matrica nije korektna!");
             }
             	}
             }
		Matrica o(3*m.size(),std::vector<double> (3*m[0].size())),h(m.size(),std::vector<double> (m[0].size())), k(m.size(),std::vector<double> (m[0].size())), v(m.size(),std::vector<double> (m[0].size()));
int n(0),c(0);
for(std::vector<double> x: m) {
	for(int i=0;i<x.size();i++) {
		h[n][x.size()-1-i]=x[i];
		v[m.size()-1-c][i]=x[i];
		k[m.size()-1-c][x.size()-1-i]=x[i];
	}
	n++;
c++;
}

for(int i=0;i<o.size();i++) {
	for(int j=0;j<o[0].size();j++) {
		if(j<k[0].size() && i<k.size()) {
			for(int no=0;no<k.size();no++) {
				for(int delta=0;delta<k[0].size();delta++) {
            o[i][j]=k[no][delta];
            j++;
		}
		i++;
		j=0;
			}
		i=0;
		j=k[0].size()-1;
		}
		else {
			if(j>=k[0].size() && j<2*k[0].size() && i<k.size()) {
				for(int f=0;f<v.size();f++) {
					for(int g=0;g<v[0].size();g++) {
						o[i][j]=v[f][g];
						j++;
					}
					i++;
					j=k[0].size();
				}
				i=0;
				j=2*k[0].size()-1;
			}
			else {
			if(j>=2*k[0].size() && j<o[0].size() && i<k.size()) {
			for(int q=0;q<k.size();q++) {
				for(int x=0;x<k[0].size();x++) {
					o[i][j]=k[q][x];
					j++;
			}
			i++;
			j=2*k[0].size();
			}
			i=k.size();
			j=-1;
		  }
				else {
		if(j<k[0].size() && i>=k.size() && i<2*k.size()) {
	    	for(int p=0;p<h.size();p++) {
				for(int u=0;u<h[0].size();u++) {
					o[i][j]=h[p][u];
					j++;
				}
				i++;
				j=0;
			}
			i=k.size();
		   j=k[0].size()-1;	
		}
		else  {
			if(j>=k[0].size() && j<2*k[0].size() &&  i>=k.size() && i<2*k.size()) {
		   for(int mi=0;mi<m.size();mi++) {
		   	for(int b=0;b<m[0].size();b++) {
		   		o[i][j]=m[mi][b];
		   		j++;
		   	}
		   	i++;
		   	j=k[0].size();
		   }
		   i=k.size();
		   j=2*k[0].size()-1;
			}
			else {
	        
				if(j>=2*k[0].size() && j<o[0].size() &&  i>=k.size() && i<2*k.size()) {
					for(int hi=0;hi<m.size();hi++) {
					 for(int pi=0;pi<m[0].size();pi++) {
					o[i][j]=h[hi][pi];
					j++;
				}
				i++;
				j=2*k[0].size();
				}
				i=2*k.size();
				j=-1;
				}
				else {
			if(j<k[0].size() && i>=2*k.size() && i<o.size()) {
				for(int s=0;s<k.size();s++) {
					for(int e=0;e<k[0].size();e++) {
			     o[i][j]=k[s][e];
			     j++;
		       }
		       i++;
		       j=0;
			}
			i=2*k.size();
			j=k[0].size()-1;
			}
		else {
			if(j>=k[0].size() && j<2*k[0].size() &&  i>=2*k.size() && i<o.size()) {
			for(int ro=0;ro<v.size();ro++) {
				for(int fi=0;fi<v[0].size();fi++) {
					o[i][j]=v[ro][fi];
					j++;
				}
				i++;
				j=k[0].size();
			}
			i=2*k.size();
			j=2*k[0].size()-1;
			}
			else {
				if(j>=2*k[0].size() && j<o[0].size() &&  i>=2*k.size() && i<o.size()) {
				for(int omega=0;omega<k.size();omega++) {
					for(int alfa=0;alfa<k[0].size();alfa++) {
						o[i][j]=k[omega][alfa];
						j++;
					}
					i++;
					j=2*k[0].size();
				}
				}
			}
		}
				}
			}
		}
			}
		}
	}
}
}
  	return o;
}
int main () {
	int m,n;
	std::cout<<"Unesite dimenzije matrice (m n): ";
	std::cin>>m>>n;
	if(m<0 || n<0) std::cout<<"Dimenzije matrice moraju biti nenegativne!";
	else {
	Matrica B(m,std::vector<double>(n));
	std::cout <<"Unesite elemente matrice: ";
	for(int a=0;a<m;a++) {
		for(int x=0;x<n;x++) {
			std::cin>>B[a][x];
		}
	}
	try {
	auto w(OgledaloMatrica(B));
		std::cout<<std::endl<<"Rezultantna matrica: "<<std::endl;
		for(std::vector<double> f: w) {
			for(int d=0;d<f.size();d++) {
				std::cout <<std::setw(4)<<f[d];
			}
			std::cout<< std::endl;
		}
	}
	catch(std::domain_error poruka) {
		std::cout<<poruka.what() << std::endl;
	}
	}
		return 0;
	}
