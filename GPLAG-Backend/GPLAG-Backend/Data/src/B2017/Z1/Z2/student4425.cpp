/*B 2017/2018, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.	
*/
#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>

typedef std::vector<std::vector<double>> mat;

mat KreirajMatricu(int br_redova, int br_kolona){
	return mat (br_redova, std::vector<double>(br_kolona));
}

mat UnesiMatricu(int m, int n){
	auto k(KreirajMatricu(m, n));
	for(int i=0; i<m; i++){
	for(int j=0; j<n; j++){
	std::cin>>k.at(i).at(j);}}
	return k;
}

void  DaLiJeGrbava(mat d){
	for(int i=0; i<d.size()-1;i++){
		if(d.at(i).size()!=d.at(i+1).size()) throw std::domain_error("Matrica nije korektna");
	}
}

mat NajvecaPlaninaMatrice(mat M){
	mat nula, m;
	if(M.size()==0||M.at(0).size()==0)
	return nula;
	else if(M.size()==1&&M.at(0).size()==1)
	return M;
	DaLiJeGrbava(M);
	if(M.size()<=2||M.at(0).size()<=2){
		double max_br(M.at(0).at(0));
		for(int i=0; i<M.size(); i++)
		{
			for(int j=0; j<M.at(i).size(); j++){
				if(M.at(i).at(j)>max_br)
				max_br=M.at(i).at(j);
			}
		}
			m.resize(1);
			m.at(0).resize(1);
			m.at(0).at(0)=max_br;
			return m;
	}
	mat n;
	double w(0), eps(0.00001);
	std::vector<double> v, v0, v1;
	v1.push_back(0);
	v1.push_back(0);
	for(int i=1; i<M.size(); i++){
		for(int j=1; j<M.at(i).size(); j++){
			int p(1), q(1), x(0), y(0);
			double s(0), s1(M.at(i).at(j));
			while(p<(M.size()-i)&&q<(M.at(0).size()-j)){
				if(i-p<0||j-q<0) break;
				s=M.at(i-p).at(j-q)+M.at(i).at(j-q)+M.at(i-p).at(j)+M.at(i+p).at(j+q)+M.at(i+p).at(j)+M.at(i).at(j+q)+M.at(p+i).at(j-q)+M.at(i-p).at(q+j);
				if(p>1&&q>1){
				while(x<p&&y<q){
						s+=M.at(i-p).at(j-q+y)+M.at(i-x).at(j-q)+M.at(i-p).at(j+y)+M.at(i+p).at(j+q-y)+M.at(i+p).at(j-y)+M.at(i+x).at(j+q)+M.at(p+i-y).at(j-q)+M.at(i-p+x).at(q+j);
						x++;
						y++;
					}
				}
				if(s1>s){
				v.push_back(s1);
				v0.push_back(i);
				v0.push_back(j);}
				else break;
				s1=s;
				p++;
				q++;
				x++;
				y++;
			}
		if(v.size()>0){
			w=v.at(0);
				int q1(q);
				int brojac(0);
				m.resize(p+q-1);
				while(brojac!=m.size()){
						m.at(brojac).resize(p+q-1);
						brojac++;}
							for(int k=0; k<m.size(); k++){ 
						for(int l=0; l<m.size(); l++){
							m.at(k).at(l)=M.at(i-(p-1)).at(j-(q-1));
							q--;
							if(l==m.size()-1) 
								q=q1;
						}
							p--;
							}
							if((n.size()==m.size()&&n.at(n.size()/2).at(n.size()/2)-w<eps)&&v1.at(0)<v0.at(0)&&w<n.at(n.size()/2).at(n.size()/2))
							m=n;
							else if((n.size()==m.size()&&n.at(n.size()/2).at(n.size()/2)-w<eps)&&v1.at(1)<v0.at(1)&&w<n.at(n.size()/2).at(n.size()/2))
							m=n;
							if((n.size()==m.size()&&n.at(n.size()/2).at(n.size()/2)<w)||(n.size()<m.size())){
							n=m;
							v1.at(0)=v0.at(0);
							v1.at(1)=v0.at(1);}
		}
			v.clear();
			v0.clear();
		}
	}
	if(n.size()==0){
		double maxi(M.at(0).at(0));
		for(int i=0; i<M.size(); i++){
			for(int j=0; j<M.at(i).size(); j++){
				if(maxi<M.at(i).at(j))
				maxi=M.at(i).at(j);
			}
		}
		n.resize(1);
		n.at(0).resize(1);
		n.at(0).at(0)=maxi;
	}
	return n;
}


int main ()
{
	try{
	std::cout<<"Unesite dimenzije matrice (m i n): ";
	int m, n;
	std::cin>>m>>n;
	if(m<0||n<0)
	std::cout<<"Dimenzije matrice moraju biti nenegativne!";
	else{
		std::cout<<"Unesite elemente matrice:"<<std::endl;
		mat M(UnesiMatricu(m, n));
		mat z=NajvecaPlaninaMatrice(M);
		std::cout<<"Najveca planina unesene matrice je:"<<std::endl;
		for(int i=0; i<z.size(); i++){
		for(int j=0; j<z.at(i).size(); j++)
		std::cout<<std::setw(6)<<z.at(i).at(j);
		std::cout<<std::endl;}
	}}
	catch(std::domain_error izuzetak){
		std::cout<<izuzetak.what();
	}
	catch(...){
		std::cout<<"Pogresan izuzetak!";
	}
	return 0;
}