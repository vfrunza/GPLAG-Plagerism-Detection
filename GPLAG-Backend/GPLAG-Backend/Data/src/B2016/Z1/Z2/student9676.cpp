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
typedef std::vector<double> vec;

vec operator + (vec a, vec b){
	vec c;
	for (int i=0; i<int(a.size()); i++){
		c.push_back(a[i]);
	}
	for (int i=0; i<int(b.size()); i++){
		c.push_back(b[i]);
	}
	return c;
}  

 Matrica hv_v_hv (Matrica hv, Matrica v){
	Matrica m(hv.size());
	for (int i=0; i<int(hv.size()); i++){
		m[i]= operator +((operator + (hv[i],v[i])),hv[i]);
	}
	return m;
}

Matrica h_m_h (Matrica h, Matrica m){
	Matrica n(h.size());
	for (int i=0; i<int(h.size()); i++){
		n[i]= operator +((operator + (h[i],m[i])),h[i]);
	}
	return n;
}

Matrica OgledaloMatrica (Matrica m){
	for (int i=0; i<int(m.size()); i++){
		for (int j=i+1; j<int(m.size()); j++){
			if (m[j].size()!=m[i].size()) throw std::domain_error("Matrica nije korektna");
		}
	}
	Matrica h(m.size()),v(m.size()),hv(m.size());
	int n(m.size()-1);
	for (int i=0; i<int(m.size()); i++){
		for (int j=int(m[0].size())-1; j>=0; j--){         //h dobar     //v dobar   //hv dobar
			h[i].push_back(m[i][j]);
		}
	}
	
	for (int i=0; i<int(m.size()); i++){
		v[n] = m[i];  
		hv[n] = h[i];
		n--;
	}
	
  	Matrica hvvhv(hv_v_hv(hv,v)), hmh(h_m_h(h,m));
  	int vel(m.size());
  	 m.resize(3*vel);
  	for (int i=0; i<vel; i++){
  		m[i] = hvvhv[i];
  	}
  	for (int i=vel; i<2*vel; i++){
  		m[i] = hmh[i-vel];
  	}
  	for (int i=2*vel; i<3*vel; i++){
  		m[i] = hvvhv[i-2*vel];
  	}
  	return m;
}
int main ()
{
	
	 try {
	  std::cout<<"Unesite dimenzije matrice (m n): ";
	int m,n;
	std::cin>>m>>n;
	if (m<0 || n<0){
	 std::cout<<"Dimenzije matrice moraju biti nenegativne!";
	 return 0;
	}
	std::cout<<"Unesite elemente matrice:"<<std::endl;
	Matrica mat(m,std::vector<double>(n));
	for (int i=0; i<m; i++){
		for (int j=0; j<n; j++){
			std::cin>>mat[i][j];
		}
	}
	std::cout<<"Rezultantna matrica:"<<std::endl;
	for (vec x: OgledaloMatrica(mat)){
		for (double y: x) std::cout<<std::setw(4)<<y;
		std::cout<<std::endl;
	}
	
	} catch (std::domain_error greska){
		std::cout<<greska.what();
	
	}
	
	  
	return 0;
}