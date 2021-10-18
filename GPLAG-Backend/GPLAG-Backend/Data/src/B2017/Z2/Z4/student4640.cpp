int main ()
{
	int n;
	std::cout<<"Koliko zelite recenica: ";
	std::cin>>n;
	std::cin.ignore(10000,'\n');
	std::cout<<"Unesite recenice:";
	string **recenica(nullptr);
	try{
		try{
		recenica=new string *[n];
		}
		catch(...){
			std::cout<<"\nProblemi s memorijom!";
			delete recenica;
			return 0;
		}
		for(int i=0;i<n;i++){
			try{
				recenica[i]=new string;
				getline(cin,*recenica[i]);
			}
			catch(...){
			//	for(int i=0;i<n;i++) delete [] recenica[i];
				delete [] recenica;
				cout<<"\nProblemi s memorijom!";
				return 0;
				}
			}
		std::sort(recenica,recenica+n,[](string *a,string *b){
			return *a<*b;
		});
	
		std::cout<<"\nSortirane recenice:\n";
		for(int i=0;i<n;i++) std::cout<<*recenica[i]<<"\n";
		
	}
	catch(std::bad_alloc){
		std::cout<<"\nProblemi s memorijom!";
		//delete  recenica;
		for(int i=0;i<n;i++) delete  recenica[i];
		//delete [] recenica;
		
		return 0;
	}
/*	for(int i=0;i<n;i++) delete[] recenica[i];*/
	delete [] recenica;
	return 0;
}