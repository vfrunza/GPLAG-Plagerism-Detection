/*B 2016/2017, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

std::string obrni(std::string a){
	int n=a.size();
	std::string b=std::string{};
	for(int i=n-1;i>=0;i--){
		b.push_back(a[i]);
	}
	return b;
}

bool comp(std::string a, int poz, std::string b){
	int m=b.size();
	for(int i=poz;i<poz+m;i++){
		if(a[i]!=b[i-poz])return false;
	}
	return true;
}

std::string zamjeni(std::string a, int poz, std::string b){
	int m=b.size();
	for(int i=poz;i<poz+m;i++){
		a[i]=b[i-poz];
	}
	return a;
}

std::string ObrniFraze(std::string a, std::vector<std::string> v){
	int n=a.size();
	for(auto i:v){
		int m=i.size();
		if(m==0)continue;
		for(int j=0;j<=n-m;j++){
			if(comp(a, j, i)){
				std::string obrnuti=obrni(i);
				a=zamjeni(a, j, obrnuti);
				j=j+m-1;
			}
		}
	}
	return a;
}

std::string pigy(std::string a){
	if(a.size()==0)return a;
	char c;
	c=a[0];
	int n=a.size();
	for(int i=0;i<n-1;i++){
		a[i]=a[i+1];
	}
	a[n-1]=c;
	a=a+"ay";
	return a;
}

std::string IzmijeniUPigLatin(std::string a, std::vector<std::string> v){
	bool trebalsve=false;
	if(v.size()==0){
		trebalsve=true;
	}
	for(auto i:v){
		for(int j=0;j<i.size();j++){
			if(!(i[j]>='a' && i[j]<='z') && !(i[j]>='A' && i[j]<='Z'))throw std::domain_error("Nekorektan izbor rijeci");
		}
	}
	int n=a.size();
	std::string rjes=std::string{};
	std::string temp=std::string{};
	for(int i=0;i<n;){
		while(!(a[i]>='a' && a[i]<='z') && !(a[i]>='A' && a[i]<='Z')){
			rjes.push_back(a[i]);
			i++;
			if(i==n)break;
		}
		if(i==n)break;
		temp=std::string{};
		while((a[i]>='a' && a[i]<='z') || (a[i]>='A' && a[i]<='Z')){
			temp.push_back(a[i]);
			i++;
			if(i==n)break;
		}
		bool ima=false;
		if(trebalsve){
			temp=pigy(temp);
			rjes=rjes+temp;
		} else {
			for(auto j:v){
				if(temp==j){
					temp=pigy(temp);
					rjes=rjes+temp;
					ima=true;
					break;
				}
			}
			if(ima==false){
				rjes=rjes+temp;
			}
		}
		if(i==n)break;
	}
	return rjes;
}

int main ()
{
	std::cout<<"Unesite recenicu: ";
	std::string a;
	std::getline(std::cin, a);
	std::vector<std::string> v;
	std::string b;
	std::cout<<"Unesite fraze: ";
	do{
		std::getline(std::cin, b);
		if(b!=std::string{}){
			v.push_back(b);
		} else break;
	}while(true);
	try{
		b=IzmijeniUPigLatin(a, v);
		std::cout<<"Recenica nakon PigLatin transformacije: ";
		std::cout<<b<<"\n";
	}
	catch(std::domain_error gg){
		 std::cout<<"Izuzetak: "<<gg.what()<<"\n";
	}
	std::cout<<"Recenica nakon obrtanja fraza: ";
	b=ObrniFraze(a, v);
	std::cout<<b;
	return 0;
}