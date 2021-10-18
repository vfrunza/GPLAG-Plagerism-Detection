/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/

#include<iostream>
#include<vector>

typedef std::vector<std::vector<double>> matrica;

int BrojRedova(matrica m){
	return m.size();
}
int BrojKolona(matrica m,int red){
	
	if(m.size()==0) return 0;
	
	return m[red].size();
}



matrica RastuciPodnizovi(std::vector<double> a){

	int k(1);
	bool p(false);
	
	matrica m(0);
	
	for(int i=0;i<int(a.size())-1;){
		if(a[i]<=a[i+1]){
			
			if(m.size()==0){
				m.resize(1);
			}
			
			if(p){
				k++;
				m.resize(k);
				
				p=false;
				
			}
			
	
			m[k-1].push_back(a[i]);
			
	
			
			i++;
			if(i==int(a.size())-1){
				m[k-1].push_back(a[i]);
				
				break;
			}
			
			
		}
		else{
			
			if(m.size()==0) {
				i++;
				continue;
			}
			if(m[k-1].size()!=0 && a[i-1]<=a[i]){
				m[k-1].push_back(a[i]);
			
				p=true;
				i++;
		
				
			}
			else i++;
		}
		
		
		if(i==int(a.size())-1) break;
		
			

		}
	
	

return m;

	
}

matrica OpadajuciPodnizovi(std::vector<double> a){
	int k(1);
	bool p(false);
	
	matrica m(0);
	
	for(int i=0;i<int(a.size())-1;){
		if(a[i]>=a[i+1]){
			
			if(m.size()==0){
				m.resize(1);
			}
			if(p){
				k++;
				m.resize(k);
				p=false;
			}
			
			m[k-1].push_back(a[i]);
			i++;
			
			if(i==int(a.size())-1){
				m[k-1].push_back(a[i]);
				break;
			}	
		
			
			
			
		}
		else{
			if(m.size()==0) {
				i++;
				continue;
			}
				
			if(m[k-1].size()!=0 && a[i-1]>=a[i]){
				m[k-1].push_back(a[i]);
				p=true;
				i++;
			}
			else i++;
		}
		if(i==int(a.size())-1) break;
		
	}
	return m;
	
	
}


int main ()
{
	std::cout<<"Unesite broj elemenata vektora: ";
	int n;
	std::cin>>n;
	
	std::vector<double> vec(n);
	
	
	
	std::cout<<"Unesite elemente vektora: ";
	for(int i=0;i<n;i++){
		std::cin>>vec[i];
		
	}
	
	
	
	
	std::cout<<"Maksimalni rastuci podnizovi: ";
	matrica mr(RastuciPodnizovi(vec));
	
	int r1(BrojRedova(mr));
	
	
	std::cout<<std::endl;
	for(int i=0;i<r1;i++){
		
		int k1(BrojKolona(mr,i));
		
		for(int j=0;j<k1;j++){
			std::cout<<mr[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	

//	std::cout<<mr.size();
	
	
	std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
	
	matrica mo(OpadajuciPodnizovi(vec));
	
	int r2(BrojRedova(mo));
	
	for(int i=0;i<r2;i++){
		int k2(BrojKolona(mo,i));
		
		for(int j=0;j<k2;j++){
			std::cout<<mo[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
//std::cout<<mo.size();
	return 0;
}
