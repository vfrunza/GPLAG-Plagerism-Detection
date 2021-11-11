


	while (*p!='\0') {
		if(*p=='<'){ 	p++; 
			if(*p!='\0' && *p!='/'){
				char *c=niz[velicina];
				
				while (*p!='\0'&&(*p!=' ' && *p!='>')) {
					(*c++)=tolower(*p++); 	}
				*c='\0';
				velicina++;
			}
			//ako nismo na kraju i ako je 
			else if(*p!='\0' && *p=='/'){
			char *c=niz[velicina-1]; 
			int isti=1; 
			if(*p!='\0')   p++;  //preskacem ovo '/'
			while (*p!='\0' && (*p!=' ' && *p!='>')) {
				 	if(*c!=tolower(*p)) isti=0; 
				 	c++; p++; 
				 	if(*c=='\0')  break;
				 }
			if(isti==1 && (*p==' ' || *p=='>')) velicina--;
			else return 0; 
			}	
		} 
	}
	
	
	
if(velicina==0) return 1; 
	return 0; 
}