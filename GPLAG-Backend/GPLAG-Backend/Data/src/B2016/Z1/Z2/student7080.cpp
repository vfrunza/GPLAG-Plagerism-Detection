#include <iostream>
#include <vector>
#include <iomanip>


typedef std::vector<std::vector<double>> Matrica;

std::vector<std::vector<double>> OgledaloMatrica(const Matrica &M) {
    std::vector<std::vector<double>> O(3*M.size(),std::vector<double>(3*M[0].size()));
	int k=M.size()-1,l=M[0].size()-1;
    for (int i=0;i<M.size();i++) {
    for (int j=0;j<M[0].size();j++) {
        O[i][j]=M[k][l];
        l--;
    }
    l=M[0].size()-1;
    k--;
    }
    k=M.size()-1,l=M[0].size()-1;
    for (int i=0;i<O.size()/3;i++) {
        for (int j=(2*O[0].size())/3;j<O[0].size();j++) {
            O[i][j]=M[k][l];
            l--;
        }
        l=M[0].size()-1;
        k--;
    }
    k=M.size()-1,l=M[0].size()-1;
    for (int i=2*M.size();i<3*M.size();i++) {
    for (int j=0;j<M[0].size();j++) {
        O[i][j]=M[k][l];
        l--;
    }
    l=M[0].size()-1;
    k--;
    }
    k=M.size()-1,l=M[0].size()-1;
    for (int i=(2*O.size())/3;i<O.size();i++) {
        for (int j=(2*O[0].size())/3;j<O[0].size();j++) {
            O[i][j]=M[k][l];
            l--;
        }
        l=M[0].size()-1;
        k--;
    }



int o=0,p=M[0].size()-1;
for (int i=M.size();i<2*M.size();i++) {
    for (int j=0;j<M[0].size();j++) {
        O[i][j]=M[o][p];
        p--;
    }
    p=M[0].size()-1;
    o++;
}
o=0,p=M[0].size()-1;
for (int i=O.size()/3;i<(2*O.size())/3;i++) {
    for (int j=(2*O[0].size())/3;j<O[0].size();j++) {
        O[i][j]=M[o][p];
        p--;
    }
    p=M[0].size()-1;
    o++;
}



int a=0,b=0;
for (int i=O.size()/3;i<2*O.size()/3;i++) {
    for (int j=O[0].size()/3;j<2*O[0].size()/3;j++) {
        O[i][j]=M[a][b];
        b++;
    }
    b=0;
    a++;
}




int r=M.size()-1,s=0;
for (int i=0;i<M.size();i++) {
    for (int j=M[0].size();j<2*M[0].size();j++) {
        O[i][j]=M[r][s];
        s++;
    }
    s=0;
    r--;
}
r=M.size()-1,s=0;
for (int i=2*M.size();i<3*M.size();i++) {
    for (int j=M[0].size();j<2*M[0].size();j++) {
        O[i][j]=M[r][s];
        s++;
    }
    s=0;
    r--;
}
return O;
}


int main () {
	int m,n;
	std::cout<<"Unesite dimenzije matrice (m n): ";
	std::cin>>m>>n;
	if (m<0 || n<0)  { std::cout<<"Dimenzije matrice moraju biti nenegativne!"; return 0; }
	if (m==0 || n==0) { std::cout<<"Unesite elemente matrice: \nRezultantna matrica: "; 
	for (int i=0;i<3*m;i++) std::cout<<"\n";
	return 0; 
	}
	std::cout<<"Unesite elemente matrice: ";
	std::vector<std::vector<double>> M(m,std::vector<double>(n));
	for (int i=0;i<m;i++) {
		for (int j=0;j<n;j++) {
			std::cin>>M[i][j];
		}
	}
	std::vector<std::vector<double>> O=OgledaloMatrica(M);
	std::cout<<"\nRezultantna matrica: \n";
	for (int i=0;i<O.size();i++) {
		for (int j=0;j<O[0].size();j++) {
			std::cout<<std::right<<std::setw(4)<<O[i][j];
		}
		std::cout<<std::endl;
	}
	return 0;
}