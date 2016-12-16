#include<iostream>
#include<fstream>
using namespace std;

//typedef traits::pos_type pos_type;
ifstream fin;

main() {
	int arrmain[1000];
//	pos_type startstack[500],endstack[500];
//	int startptr=0,endptr=0;
	for(int i=0;i<1000;arrmain[i++]=0);
	int mainptr=0;
	char filename[33];
	cout<<"\n Enter the filename : ";
	cin>>filename;
	fin.open(filename);
	int flag=0;
	while(!fin.eof()) {
		char ch;
		fin>>ch;
		if(ch==' ') continue; 
		switch(ch) {
			case '+' : arrmain[mainptr]++;
				   break;
			case '-' : arrmain[mainptr]--;
				   break;
			case '>' : if(mainptr==999) flag=1;
				   mainptr++;
				   break;
			case '<' : if(!mainptr) flag=1; 
				   mainptr--;
				   break;
			case '.' : cout<<(char)arrmain[mainptr];
				   break;
			case ',' : cout<<"\n Enter your input"<<endl<<"(A-Z / 0-9) : ";
				   char temp;
				   cin>>temp;
				   arrmain[mainptr]=(int)temp;
				   break;
         		default  : continue; 
		      /*
			case '[' : 
				   if(!arrmain[mainptr])  { fin.seekp(endstack[endptr--]+1,ios::beg);  break; }
				   startstack[startptr++]=fin.tellg();

			case ']' : 
		      		   if(arrmain[mainptr])  { fin.seekp(startstack[startptr--]+1,ios::beg); break; }
				   endstack[endptr++]=fin.tellg();
			 		
			*/
		}
		if(flag) { cout<<endl<<"Array out of index"<<endl; break; }
	}
	for(int i=0;i<=mainptr;cout<<arrmain[i++]<<" ");
	fin.close();
	return 0;
}
