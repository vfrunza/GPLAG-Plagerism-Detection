#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
bool ProvjeraFraze(string recenica, string F,int j){
	bool fraza=true;
	for(int i=0; i< F.size(); i++){
		if(j==recenica.size()){
			fraza= false;
			break;
		}
		if(F[i]!= recenica[j])
			fraza=false;
		if(j<recenica.size())
			j++;
		if(i==F.size()-1)
			break;
	}
	return fraza;
}
string Obrni(string recenica, string F,int j){
	char P;
	int vel=F.size(),i;
	i=j+vel-1;
	while(j!=i){
		P=recenica[j];
		recenica[j]=recenica[i];
		recenica[i]=P;
		i--;
		if(i==j)
			break;
		j++;
	}
	return recenica;
}
std::string ObrniFraze(std::string recenica, std::vector<std::string> F){
	bool A;
	for(int i=0; i<F.size(); i++){
		for(int j=0; j<recenica.size(); j++){
			if(F[i][0]!= recenica[j])
				continue;
			else {
				A=ProvjeraFraze(recenica,F[i], j);
				if(A){
					recenica=Obrni(recenica,F[i], j);
	
				}
			}

			if(j==recenica.size()-1)
				break;
		}
		if(i==F.size()-1)
			break;
	}
	
	return recenica;
}
string izmijeni(string recenica, string F,int j){

	int vel=F.size();
	char Z{recenica[j]};
	int i{j};
	while(j<(i+vel-1) && j<=recenica.size()-1){
		recenica[j]=recenica[j+1];
		j++;
		if(j==recenica.size()-1)
			break;
	}
	if(recenica.size()==j)
		j--;
	recenica[j]=Z;
	recenica.insert(j+1,"ay");
	return recenica;
}
bool ProvjeraTacnosti(vector<string> F){
	bool T=false;
	for(int i=0; i<F.size(); i++){
		for(int j=0; j<F[i].size(); j++){
			if(F[i][j]<'A' || (F[i][j]>'Z' && F[i][j]<'a') || F[i][j]>'z' )
				T=true;
			if(j==F[i].size()-1)
				break;
		}
		if(i==F.size()-1)
			break;
	}
	return T;
}

bool ProvjeraFraze2(string recenica, string F,int j){
	bool fraza=true;
	for(int i=0; i< F.size(); i++){
		if(j==recenica.size()){
			fraza=false;
			break;
		}
		if(F[i] != recenica[j])
			fraza=false;
		if(j<recenica.size())
			j++;
		if(i==F.size()-1)
			break;
	}
	if(fraza && j!=recenica.size()){
		
		if(!(recenica[j]<'A' || (recenica[j]>'Z' && recenica[j]<'a') || recenica[j]>'z'))
			fraza=false;
		j++;
		
	}
	return fraza;
}
string IzmijeniSve(string recenica,int j){
	int l{j};
	int vel{};
	while(!(recenica[l]<'A' || (recenica[l]>'Z' && recenica[l]<'a') || recenica[l]>'z') && l<recenica.size()){
		l++;
		vel++;
	}
	char Z{recenica[j]};
	int i{j};
	while(j<(i+vel-1) && j<recenica.size()){
		recenica[j]=recenica[j+1];
		j++;
	}
	if(recenica.size()==j)
		j--;
	recenica[j]=Z;
	recenica.insert(j+1,"ay");
	return recenica;		
}
string TrebaIzmijenitiSve(string recenica){
	for(int i=0; i<recenica.size(); i++){
		if(recenica[i]<'A' || (recenica[i]>'Z' && recenica[i]<'a') || recenica[i]>'z')
				continue;
		else {
				int l{i};
				int vel{};
				while(!(recenica[l]<'A' || (recenica[l]>'Z' && recenica[l]<'a') || recenica[l]>'z') && l<recenica.size()){
					l++;
					vel++;
				}
				recenica=IzmijeniSve(recenica,i);
				
				i=i+vel+2;
		}
		if(i==recenica.size()-1)
			break;
	}
	return recenica;
}
std::string IzmijeniUPigLatin(std::string recenica, std::vector<std::string> F){
	bool A;
	bool Izuzetak;
	Izuzetak=ProvjeraTacnosti(F);
	if(Izuzetak) throw std::domain_error ("Nekorektan izbor rijeci");
	if(F.size()==0){
		recenica=TrebaIzmijenitiSve(recenica);
		return recenica;
	}
	for(int i=0; i<F.size(); i++){
		for(int j=0; j<recenica.size(); j++){
			if(recenica[j]<'A' || (recenica[j]>'Z' && recenica[j]<'a') || recenica[j]>'z')
				continue;
			else if(F[i][0]!= recenica[j]){
				while(!(recenica[j]<'A' || (recenica[j]>'Z' && recenica[j]<'a') || recenica[j]>'z') && j<recenica.size())
					j++;
			}
			else {
				A=ProvjeraFraze2(recenica,F[i], j);
				if(A){
					recenica=izmijeni(recenica,F[i], j);
				}
				if(!A)
					while(!(recenica[j]<'A' || (recenica[j]>'Z' && recenica[j]<'a') || recenica[j]>'z') && j<recenica.size())
						j++;
			}
			if(j==recenica.size()-1)
				break;
		}
		if(i==F.size()-1)
			break;
	}
	
	return recenica;
}
int main (){
	string recenica;
	vector<string> F;
	cout<<"Unesite recenicu: ";
	std::getline(std::cin, recenica);
	cout<<"Unesite fraze: ";
	int i=0;
	std::cin >>std::ws;
	for(;;){
		F.resize(i+1);
		std::getline(std::cin, F[i]);
		int c = std::cin.peek();
		if(c=='\n')
			break;
		i++;
	}
   	string pig;
   	string obrnuta;
   	try{
   		obrnuta=ObrniFraze(recenica, F);
   		pig=IzmijeniUPigLatin(recenica, F);
   		cout<<"Recenica nakon PigLatin transformacije: "<<pig<<endl;
   	}
   	catch(std::domain_error izuzetak) {
      std::cout <<"Izuzetak: "<< izuzetak.what() << std::endl;
   	}
	cout<<"Recenica nakon obrtanja fraza: "<<obrnuta;
	return 0;
}