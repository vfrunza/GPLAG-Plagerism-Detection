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

std::string ObrniRijec (std::string rijec){
	for(int i=0; i<rijec.length()/2; i++){
	    std::string pomocna;
	    pomocna.resize(1);
	    pomocna[0]=rijec[i];
	    rijec[i]=rijec[rijec.length()-1-i];
	    rijec[rijec.length()-1-i]=pomocna[0];
	}
	return rijec;
}

std::string OvoPigNesto (std::string rijec){
	std::string pomocna;
	pomocna.resize(0);
	pomocna[0]=rijec[0];
	for(int i=0; i<rijec.length()-1; i++){
		rijec[i]=rijec[i+1];
		if(i==rijec.length()-2)rijec[rijec.length()-1]=pomocna[0];
	}
	rijec+="ay";
	return rijec;
}

std::string ObrniFraze(std::string a, std::vector<std::string> b){
	for(int i=0; i<b.size(); i++){ 
	    for(int j=0; j<a.length(); j++){
	    	int z=0;
	    	std::string f(b[i]);
	    	//std::cout << "b[" << i << "]= " << b[i] << " \n";
		    while(a[j]==f[z]){
		    	z++;
		    	j++;
                if(z==b[i].length()){
                	for(int x=0; x<z; x++){
                		std::string obrnuta(ObrniRijec(b[i]));
                	    a[j-z+x]=obrnuta[x];
                	}
                	break;
                }
                if(j>=a.length())break;
		    }
	    }
	}
	return a;
}

std::string IzmijeniUPigLatin(std::string a, std::vector<std::string> b){
	
	for(int i=0; i<b.size(); i++){
		for(int j=0; j<b[i].length(); j++){
			if( (b[i][j]<'A' || b[i][j]>'Z') && (b[i][j]<'a' || b[i][j]>'z') ) throw std::domain_error("Nekorektan izbor rijeci");
		}
	}
	
	for(int i=0; i<b.size(); i++){
		for(int j=0; j<a.length(); j++){
			int z=0;
			std::string f(b[i]);
			while(a[j]==f[z]){
				z++;
				j++;
				//std::cout << " a-j ___" << a[j] << "____ !\n";
				if(z==b[i].length() && ((a[j]<'A' || a[j] >'Z') && (a[j]<'a' || a[j]>'z')) && (j-z==0 || ((a[j-z-1]<'A' || a[j-z-1]>'Z') && (a[j-z-1]<'a' || a[j-z-1]>'z')) )){
					a.resize(a.length()+2);
					for(int x=a.length()-1; x>=j; x--){
						a[x]=a[x-2];
					}
					std::string ObradjenaRijec(OvoPigNesto(b[i]));
					for(int x=0; x<ObradjenaRijec.length(); x++){
						a[j-z+x]=ObradjenaRijec[x];
					}
					break;
				}
				if(j>a.length())break;
			}
		}
	}
	/*if(b.size()==0){ // svaka rijec treba kad se unese prazan vektor ko drugi parametar
		for(int i=0; i<a.length(); i++){
			std::string rijec, slovo;
			slovo.resize(1);
			int z=i, br=1;
			while(((a[i]>'A' && a[i]<'Z') || (a[i]>'a' && a[i]<'z')) && i<a.length()){ // ovaj dio char string nijedobarrr
				slovo[0]=a[i];
				std::cout << "slovo " << slovo << " __";
				rijec.resize(br);
				rijec[br-1]=slovo[0];
				i++;
				br++;
			}
			std::cout << "kkk " << rijec << " kkk \n";
			if(rijec.size()!=0){
				std::string ObradjenaRijec(OvoPigNesto(rijec));
				a.resize(a.length()+2);
				for(int x=a.length()-1; x>=z; x--){
					a[x]=a[x-2];
				}
				for(int x=0; x<ObradjenaRijec.length(); x++){
					a[z+x]=ObradjenaRijec[x];
				}
			}
			
		}
	} */
	return a;
} 

int main(){
	std::vector<std::string> a(0);
	std::string recenica, rijeci;
	std::cout << "Unesite recenicu: ";
	std::getline(std::cin, recenica);
	std::cout << "Unesite fraze: ";
	while(std::cin.peek()!='\n'){
		std::getline(std::cin, rijeci);
		a.push_back(rijeci);
		//std::cout << "Obrnutoo : " << ObrniRijec(rijeci) << "   \n";//
		//std::cout << "PigLatin: " << OvoPigNesto(rijeci) << "  \n";//
	}

	try{
	    std::string x(IzmijeniUPigLatin(recenica, a));
	    std::cout << "Recenica nakon PigLatin transformacije: ";
	    std::cout << x;
	}
	catch(std::domain_error izuzetak){
		std::cout << "Izuzetak: " << izuzetak.what();
	}
	
	std::cout << "\nRecenica nakon obrtanja fraza: ";
	std::string y(ObrniFraze(recenica, a));
	std::cout << y;
	return 0;
}