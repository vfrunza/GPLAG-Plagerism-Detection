	int brojrecenica;
	std::cout<<"Koliko zelite recenica: ";
	std::cin>>brojrecenica;
	std::cin.ignore(10000, '\n');
	std::cout<<"Unesite recenice:";
	char **recenice(nullptr);
	try{
		try{
		recenice=new char*[brojrecenica];
		}
		catch(...){
			std::cout<<"\nProblemi s memorijom!";
			delete recenice;
			return 0;
		}
		for(int i=0;i<brojrecenica;i++){
			char radniprostor[1000];
			std::cin.getline(radniprostor,sizeof radniprostor);
			recenice[i]=new char[std::strlen(radniprostor)+1];
			std::strcpy(recenice[i],radniprostor);
		}
		char *temp(nullptr);
		for(int i=0;i<brojrecenica-1;i++){
			for(int j=i+1;j<brojrecenica;j++){
				if(std::strcmp(recenice[i],recenice[j])>0){
					temp=recenice[i];
					recenice[i]=recenice[j];
					recenice[j]=temp;
				}
			}
		}
		std::cout<<"\nSortirane recenice:\n";
		for(int i=0;i<brojrecenica;i++){
				std::cout<<recenice[i]<<"\n";
			}
			
	}
	catch(std::bad_alloc){
		std::cout<<"\nProblemi s memorijom!";
		for(int i=0;i<brojrecenica;i++) delete [] recenice[i];
		delete [] recenice;
		return 0;
	}
for(int i=0;i<brojrecenica;i++) delete [] recenice[i];
delete [] recenice;
	return 0;
//	}
}