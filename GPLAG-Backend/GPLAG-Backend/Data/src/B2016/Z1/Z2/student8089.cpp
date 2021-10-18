#include <iostream>
#include <vector>
#include <iomanip>

typedef std::vector<std::vector<double>> mat;
typedef std::vector<double> vektor;

mat sabiranje(vektor v1,vektor v2,vektor v3){
	vektor x;
	for(int i=0; i<v1.size(); i++) {x.push_back(v1[i])};
	for(int i=0; i<v1.size(); i++) {x.push_back(v2[i])};
	for(int i=0; i<v1.size(); i++) {x.push_back(v3[i])};
	
	
}
mat OgledaloMatrica(mat m){
	mat mat1;
	if(m.size()==0) return m;
	if (m[0].size()==0 && m.size()!=0) {
		mat1.resize(3 * m.size());
		return mat1;
	}
mat horizontalna(m.size(),vektor (m[0].size()));
	mat ve;
	vektor n;
	int k(0);
	for(int i=m.size()-1; i>=0; i--){
		for(int j=0; j<m[0].size(); j++){
			ve[k][j]=m[i][j];
		}
		k++;
	}
	int k1(0);
  for (int i=0; i<m.size()-1; i++){
  	for(int j=m[0].size()-1; j>=0; j--){
  		mat hor[i][k1]=m[i][j];
  	}
  	k1++;
  }
  for(int i=m.size()-1; i>=0; i--){
  	horve.push_back(hor[i]);
  }
  for(int i=0; i<m.size();i++){
  	n=operator +(hor[i][k1]+ve[k][j]+horve[i]);
  	mat1.push_back(n);
  }
  for(int i=0; i<m.size();i++){
  	n=o(hor[i][k1]+m[i][j]+hor[i][k1]);
  	mat1.push_back(n);
  	}
  	  for(int i=0; i<m.size();i++){
  	n=(horve[i]+ve[k][j]+horve[i]);
  	mat1.push_back(n);
  	}
  	return mat1;

}

int main ()
{
	int a,b;
	std::cin>>a>>b;
    mat mat1(m,vektor (b);
    for(int i=0; i<a; i++){
    	for(int j=0; j<b; j++){
    		std::cin>>mat1[i][j];
    	}
    }
    mat nova=OgledaloMatrica(mat1);
    std::cout<<"Kombinovana: ";
    if(nova.size()!=0){
    	for(int i=0; i<nova.size(); i++){
    		std::cout<<" ";
    		for(int j=0; j<nova[0].size(); j++){
    			std::cout<<std::right<<std::setw(3)<<nova[i][j]<<" ";
    		}
    		std::cout<<std::endl;
    	}
    }
	
	return 0;
}