/*B 16/17, Zadaća 2, Zadatak 4
	NAPOMENA: i javni ATo-vi su dio postavke
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
*/
#include<iostream>
#include<vector>
#include<string>
#include<stdexcept>
int PotencijalniKrivci(char ** &c, std::vector<std::string> vs){
	int br=0,n=vs.size();
	c=nullptr;
	try{
		
		c=new char *[n];
		for(int i=0;i<n;i++){
			c[i]=nullptr;
		}
		int al=0;
		try{
			for(int i=0;i<n;i++){
				c[i]=new char[int(vs[i].size()+1)];
				al++;
			}
		}
		catch(...){
			for(int i=0;i<al;i++){
				delete [] c[i];
			}
			delete [] c;
				throw std::bad_alloc();
		}
	}
	catch(...){
		delete [] c;
		throw std::bad_alloc();
	}
	for(int i=0;i<n;i++){
		std::string pom=vs[i];
		for(int j=0;j<int(vs[i].size()+1);j++){
			if(j==int(vs[i].size())){ c[i][j]='\0'; break;}
			c[i][j]=pom[j];
		}
		br++;
	}
	return br;
}

int OdbaciOptuzbu(char ** &c,int n,std::string s){
	bool ima=true, dalje=true;
	for(int i=0;i<n;i++){
		int j;
		if(c[i]==nullptr) continue;
		if(c[i]!=nullptr){
		  for( j=0;j<int(s.length());j++){
			if(c[i][j]!=s[j] && s[j]!='\0'){
				ima=false;
				break;
			  }
			}
		}
		if(ima && c[i][j]=='\0'){
			delete[] c[i];
			c[i]=nullptr;
			dalje=false;
			break;
		}
		
		ima=true;
	}
	if(dalje){
		throw std::domain_error("Osoba sa imenom "+s+" nije bila optuzena");
	}
	int brnul=0;
	for(int i=0;i<n;i++)
		if(c[i]==nullptr)
			brnul++;
	if(brnul>10){
		int brosoba=0;
		for(int i=0;i<n;i++)
			if(c[i]!=nullptr) brosoba++;
		char **p=nullptr;
		p=new char *[brosoba];
		int b=0;
		for(int i=0;i<n;i++){
			if(c[i]!=nullptr)
				p[b++]=c[i];
		}
		for(int i=0;i<n;i++){
			delete [] c[i];
		//	c[i]=nullptr;
		}
		delete [] c;
	//	c=nullptr;
		c=p;
		return brosoba;
	}
	return n;
	
}
void IzlistajOptuzbu(char ** c,int n){
	for(int i=0;i<n;i++){
		int bro=0,k=0;
		if(c[i]==nullptr) continue;
		while (c[i][k++]!='\0') {
			bro++;
		}
		for(int j=0;j<bro;j++){
			std::cout << c[i][j];
		}
		std::cout<<std::endl;
	}
}
int DodajOptuzbu(char **&c, int n, std::string s){
	char *p=nullptr;
	try{
		p=new char[int(s.length())+1];
	}
	catch(...){
		delete [] p;
		throw std::bad_alloc();
	}
	
	for(int i=0;i<int(s.length());i++){
		p[i]=s[i];
	}
	p[int(s.length())]='\0';
	
	bool imamjesta=true;
	for(int i=0;i<n;i++){
		if(c[i]==nullptr){
			imamjesta=false;
			c[i]=new char [int(s.length()+1)];
			for(int j=0;j<=int(s.length());j++)
			c[i][j]=p[j];
		}
	}
	if(imamjesta){
		char **q=nullptr;
		try{
			q=new char*[n+1];
			for(int i=0;i<n+1;i++)
				q[i]=nullptr;
		}
		catch(...){
			delete [] q;
			delete [] p;
			throw std::bad_alloc();
		}
		try {
			for(int i=0;i<n;i++){
			int bro=0,k=0;
				while (c[i][k++]!='\0')
						bro++;
				
			q[i]=new char[bro+1];
			}
	//		q[n]=new char[int(s.size())+1];
			}
		catch (...) {
			for(int i=0;i<n+1;i++)
			delete [] q[i];
			delete [] q;
			delete [] p;
			throw std::bad_alloc();
			}
		for(int i=0;i<n;i++){
			int bro=0,k=0;
				while (c[i][k++]!='\0')
						bro++;
			for(int j=0;j<=bro;j++){
				q[i][j]=c[i][j];
			}
		}
		for(int i=0; i<n; i++) delete[] c[i];
		delete[] c;
		q[n]=p;
		c=q;
	//	delete[] p;
		return n+1;
	}
	delete[] p;
	return n;
}
int main ()
{
	std::cout << "Koliko potencijalnih krivaca zelite unijeti? "<<std::endl;
	int pk;
	std::cin>>pk;
	std::cin.ignore(10000,'\n');
	std::cout << "Unesite potencijalne krivce: "<<std::endl;
	std::vector<std::string> imena;
	for(int i=0;i<pk;i++){
	std::string pom;
	std::getline(std::cin,pom);
	imena.push_back(pom);
	}
	char **nizPotencijalnih;
try{

	 pk = PotencijalniKrivci( nizPotencijalnih, imena);
	
	int x;
	do{
		std::cout << "Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: "<<std::endl;
		std::cin>>x;
		if(x==1){
			try{
			std::cout << "Unesite ime novog optuzenog: "<<std::endl;
			std::cin.ignore(10000,'\n');
			std::string ubaci;
			std::getline(std::cin,ubaci);
			pk=DodajOptuzbu(nizPotencijalnih,pk,ubaci);
			}
			catch(std::bad_alloc){
			for(int i=0;i<pk;i++)
				delete [] nizPotencijalnih[i];
			delete [] nizPotencijalnih;
			std::cout<<"Alokacija nije uspjela";
			}
		}
		if(x==2){
			try{
			std::cout << "Unesite ime koje zelite izbaciti: " << std::endl;
			std::cin.ignore(10000,'\n');
			std::string izbaci;
			std::getline(std::cin,izbaci);
			pk=OdbaciOptuzbu(nizPotencijalnih,pk,izbaci);
			}
			catch(std::bad_alloc){
			for(int i=0;i<pk;i++)
				delete [] nizPotencijalnih[i];
			delete [] nizPotencijalnih;
				std::cout<<"Alokacija nije uspjela";
			}
			catch(std::domain_error x){
				for(int i=0;i<pk;i++)
					delete [] nizPotencijalnih[i];
				delete [] nizPotencijalnih;
				std::cout << x.what()<<std::endl;
			}
		}
		if(x==3){
			IzlistajOptuzbu(nizPotencijalnih,pk);
		}
		
	}while(x!=0);
	for(int i=0;i<pk;i++){
		delete [] nizPotencijalnih[i];
	}
	delete [] nizPotencijalnih;
}

catch(...){
	for(int i=0;i<pk;i++)
		delete [] nizPotencijalnih[i];
	delete [] nizPotencijalnih;
	std::cout<<"Alokacija nije uspjela";
	}
	return 0;
}