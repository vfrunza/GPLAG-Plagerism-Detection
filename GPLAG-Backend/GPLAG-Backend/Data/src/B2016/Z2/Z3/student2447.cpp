#include <iostream>
#include <deque>
#include <stdexcept>
#include <type_traits>
#include <vector>
#include <iomanip>
#include <algorithm>


bool Fun(std::deque<int> dek, int broj){
	for(int i=0;i<dek.size();i++){
		if(dek[i]==broj){
			return false;
		}
	}
	return true;
}



int SumaCifara(long long int n){
	int a(0);
	while(n!=0){
		int cifra(n%10);
		a+=cifra;
		n/=10;
	}
	return a;
}

int SumaDjelilaca(long long int n){
	int suma(0);
	for(int i=1;i<=std::abs(n);i++){
		if(std::abs(n)%i==0)
		suma+=i;
	}
	return suma;
}


int BrojProstihFaktora(long long int n){
	int brojac(0);
	for(int i=2;i<=n;i++){
		while(n%i==0){
			brojac++;
			n/=i;
		}
	}
	return brojac;
}

int BrojSavrsenihDjelilaca(long long int n){
	int brojac(0);
	for(int i=1;i<=std::abs(n);i++){
		if(n%i==0){
			if(SumaDjelilaca(i)-i==i) brojac++;
		}
	}
	return brojac;
}





template<typename tip1,typename tip2,typename tip3,typename tip4>
auto UvrnutiPresjek(tip1 it1,tip1 it2,tip2 it3,tip2 it4,tip3 fun(tip4))->std::vector<std::vector<typename std::remove_reference<decltype(*it1)>::type>>{
	
	
	tip1 p1(it1);
	tip1 p2(it2);
	tip2 p3(it3);
	tip2 p4(it4);
	
	typedef std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>> Matrica;
	Matrica mat;
	
	int i=1;
	while(p1!=p2){
	
		while(p3!=p4){
		
			auto a(fun(*p1));
			auto b(fun(*p3));
		
			a=fun(*p1);
			b=fun(*p3);
			
			if(a==b){
			mat.resize(i);
			mat[i-1].push_back(*p1);
			mat[i-1].push_back(*p3);
			mat[i-1].push_back(a);
			i++	;
			} 
			p3++;
		}
		p1++;
		p3=it3;
	}
	
	
	
	std::sort(mat.begin(),mat.end(), [] (std::vector<typename std::remove_reference<decltype(*it1)>::type> v1,std::vector<typename std::remove_reference<decltype(*it1)>::type> v2){
		
		/*if(v1[0]!=v2[0]) return v1[0]<v2[0];
		else if(v1[0]==v2[0]) return v1[1]<v2[1];
		else if(v1[1]!=v2[1]) return v1[1]<v2[1];*/
		
		if(v1[int (v1.size()-1)]!= v2[int (v2.size()-1)]) return v1[int (v1.size()-1)]< v2[int (v2.size()-1)];
		else if( v1[int (v1.size()-1)]==v2[int (v2.size()-1)] && v1[0]!=v2[0]) return v1[0]<v2[0];
		if(v1[0]==v2[0]) return v1[1]<v2[1];
		
		
	
	});
	
return mat;

}


template<typename tip1,typename tip2,typename tip3,typename tip4>
auto UvrnutaRazlika(tip1 it1,tip1 it2,tip2 it3,tip2 it4,tip3 fun(tip4))->std::vector<std::vector<typename std::remove_reference<decltype(*it1)>::type>>{
	
	
	tip1 p1(it1);
	tip1 p2(it2);
	tip2 p3(it3);
	tip2 p4(it4);
	
	typedef std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>> Matrica;
	Matrica mat;
	int i=1;
	while(p1!=p2){
		bool cad(false);
		while(p3!=p4){
		
			auto a(fun(*p1));
			auto b(fun(*p3));
			a=fun(*p1);
			b=fun(*p3);
			if(a==b){
			cad=true;
			break;
			} 
			p3++;
		}
			if(cad==false){
			mat.resize(i);
			mat[i-1].push_back(*p1);
			mat[i-1].push_back(fun(*p1));
			i++	;
			}
		p1++;
		p3=it3;
		
	}
	
	tip1 p11(it1);
	tip1 p22(it2);
	tip2 p33(it3);
	tip2 p44(it4);
	
	
	while(p33!=p44){
		bool cad(false);
		while(p11!=p22){
		
			auto a(fun(*p33));
			auto b(fun(*p11));
			a=fun(*p33);
			b=fun(*p11);
			if(a==b){
			cad=true;
			break;
			} 
			p11++;
			}
			if(cad==false){
			mat.resize(i);
			mat[i-1].push_back(*p33);
			mat[i-1].push_back(fun(*p33));
			i++	;
			}
		p33++;
		p11=it1;
		
	}
	
std::sort(mat.begin(),mat.end(), [] (std::vector<typename std::remove_reference<decltype(*it1)>::type> v1,std::vector<typename std::remove_reference<decltype(*it1)>::type> v2){
		
		if(v1[0]!=v2[0]) return v1[0]>v2[0];
		else if(v1[0]==v2[0]) return v1[int(v1.size()-1)]>v2[int(v2.size()-1)];
	
	});
	
return mat;

}









template<typename tip1,typename tip2>
auto UvrnutaRazlika(tip1 it1,tip1 it2,tip2 it3,tip2 it4)->std::vector<std::vector<typename std::remove_reference<decltype(*it1)>::type>>{
	
	
	tip1 p1(it1);
	tip1 p2(it2);
	tip2 p3(it3);
	tip2 p4(it4);
	
	typedef std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>> Matrica;
	Matrica mat;
	int i=1;
	while(p1!=p2){
		bool cad(false);
		while(p3!=p4){
		
			auto a=*p1;
			auto b=*p3;
			
			if(a==b){
			cad=true;
			break;
			} 
			p3++;
		}
			if(cad==false){
			mat.resize(i);
			mat[i-1].push_back(*p1);
			mat[i-1].push_back(0);
			i++	;
			}
		p1++;
		p3=it3;
		
	}
	
	tip1 p11(it1);
	tip1 p22(it2);
	tip2 p33(it3);
	tip2 p44(it4);
	
	
	while(p33!=p44){
		bool cad(false);
		while(p11!=p22){
		
			auto a=*p33;
			auto b=*p11;
		
			if(a==b){
			cad=true;
			break;
			} 
			p11++;
			}
			if(cad==false){
			mat.resize(i);
			mat[i-1].push_back(*p33);
			mat[i-1].push_back(0);
			i++	;
			}
		p33++;
		p11=it1;
		
		
	}
	

	
	
	
std::sort(mat.begin(),mat.end(), [] (std::vector<typename std::remove_reference<decltype(*it1)>::type> v1,std::vector<typename std::remove_reference<decltype(*it1)>::type> v2){
		
		if(v1[0]!=v2[0]) return v1[0]>v2[0];
		else if(v1[0]==v2[0]) return v1[int(v1.size()-1)]>v2[int(v2.size()-1)];
	
	});
	
return mat;

}








template<typename tip1,typename tip2>
auto UvrnutiPresjek(tip1 it1,tip1 it2,tip2 it3,tip2 it4)->std::vector<std::vector<typename std::remove_reference<decltype(*it1)>::type>>{
	
	
	tip1 p1(it1);
	tip1 p2(it2);
	tip2 p3(it3);
	tip2 p4(it4);
	
	typedef std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>> Matrica;
	Matrica mat;
	
	int i=1;
	while(p1!=p2){
	
		while(p3!=p4){
		
			auto a= *p1;
			auto b= *p3;
		
			if(a==b){
			mat.resize(i);
			mat[i-1].push_back(*p1);
			mat[i-1].push_back(0);
			mat[i-1].push_back(0);
			i++	;
			} 
			p3++;
		}
		p1++;
		p3=it3;
	}
	
	
	
	std::sort(mat.begin(),mat.end(), [] (std::vector<typename std::remove_reference<decltype(*it1)>::type> v1,std::vector<typename std::remove_reference<decltype(*it1)>::type> v2){
		
		/*if(v1[0]!=v2[0]) return v1[0]<v2[0];
		else if(v1[0]==v2[0]) return v1[1]<v2[1];
		else if(v1[1]!=v2[1]) return v1[1]<v2[1];*/
		
		if(v1[int (v1.size()-1)]!= v2[int (v2.size()-1)]) return v1[int (v1.size()-1)]< v2[int (v2.size()-1)];
		else if( v1[int (v1.size()-1)]==v2[int (v2.size()-1)] && v1[0]!=v2[0]) return v1[0]<v2[0];
		if(v1[0]==v2[0]) return v1[1]<v2[1];
		
		
	
	});
	
return mat;

}















int main ()
{
	int n1,n2,x1,x2;
	std::deque<int>d1;
	std::deque<int>d2;
	
	std::cout<<"Unesite broj elemenata prvog kontejnera: ";
	std::cin>>n1;
	std::cout<<"Unesite elemente prvog kontejnera: ";
	for(int i=0;i<n1;i++){
		std::cin>>x1;
		if(Fun(d1,x1)==true){
		d1.push_back(x1);
		}else i--;
	
	}
	std::cout<<"Unesite broj elemenata drugog kontejnera: ";
	std::cin>>n2;
	std::cout<<"Unesite elemente drugog kontejnera: ";
	for(int i=0;i<n2;i++){
		std::cin>>x2;
		if(Fun(d2,x2)==true){
		d2.push_back(x2);
		}
		else i--;
	}
	std::cout<<"Uvrnuti presjek kontejnera: "<<std::endl;
	std::deque<int>::iterator it1(d1.begin());
	std::deque<int>::iterator it2(d1.end());
	std::deque<int>::iterator it3(d2.begin());
	std::deque<int>::iterator it4(d2.end());
	
	typedef std::vector<std::vector<int>> Matrica;
	Matrica mat,mat1;
	
	mat=UvrnutiPresjek(it1,it2,it3,it4,SumaCifara);
	for(int i=0;i<mat.size();i++){
		for(int j=0;j<mat[0].size();j++){
			std::cout<<std::setw(6)<<mat[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	
	std::cout<<"Uvrnuta razlika kontejnera:"<<std::endl;
	std::deque<int>::iterator itt1(d1.begin());
	std::deque<int>::iterator itt2(d1.end());
	std::deque<int>::iterator itt3(d2.begin());
	std::deque<int>::iterator itt4(d2.end());
	
	
	
	mat1=UvrnutaRazlika(itt1,itt2,itt3,itt4,BrojProstihFaktora);
	
	for(int i=0;i<mat1.size();i++){
		for(int j=0;j<mat1[0].size();j++){
			std::cout<<std::setw(6)<<mat1[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	std::cout<<"Dovidjenja!";
	
	return 0;
}