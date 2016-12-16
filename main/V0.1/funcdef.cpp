/**
 *  	Version 0.1
 *  	- Uses arrays for both the instruction set and bit set.
 *  	- Bit set and instrc size both statically set
 *  	- Loops are functional 
 *	- Not mem optimized
 *	- ASCII mem. blocks
 **/

#include<iostream>
#include"classdef.h"
using namespace std;


Manager::Manager() {

	flush();
	mainptr=errorflag=0;
	cout<<"\n Enter the filename : ";
	cin>>filename;
	fin.open(filename);
	if(fin.good()) cout<<"\n File read successful.";
	else cout<<"\n File failed to load.";
}

Manager::~Manager() { fin.close(); }

void Manager::flush() {

	for(int i=0;i<INST_SIZE;instrset[i++]='\0');
	for(int i=0;i<ARR_SIZE; arrmain[i++]=0);
}

void Manager::printer() {

	for(int i=0;i<=mainptr;cout<<arrmain[i++]);
	cout<<endl;
}

void Manager::printinstr() {

	for(int i=0;instrset[i]!='\0';cout<<instrset[i++]<<" ");
	cout<<endl;
}

void Manager::load_instrset() {

	fin.seekg(0,ios::end);
	cout<<fin.tellg()<<endl; //for debugging
	char ch='y';
	if(fin.tellg()>INST_SIZE) {
		cout<<"\n Instruction set exceedes instrc. mem. size."
			<<"\n Partially Load \? (y/n) : ";
		cin>>ch;
	}
	if(ch!='n') {
		int i=0;
		fin.seekg(0,ios::beg);
		while(!fin.eof()&&i<1000) fin>>instrset[i++];
		cout<<"\n Instruction set loaded successfully.";
	}	
}	

void Manager::begin_exec() {

	int i=0;
	while(instrset[i]) 
		switch(instrset[i++]) {
			case '+' : arrmain[mainptr]++;
				   break;
			case '-' : if(!arrmain[mainptr]) arrmain[mainptr]=256;
					   arrmain[mainptr]--;
				   break;
			case '>' : if(mainptr==ARR_SIZE-1) { errorflag=1; break; }
					   mainptr++;
				   break;
			case '<' : if(!mainptr) { errorflag=-1; break; }
					   mainptr--;
				   break;
			case '.' : cout<<(char)arrmain[mainptr];
				   break;
			case ',' : cout<<"\n Enter your input"<<endl<<"(A-Z / 0-9) : ";
				   char temp;
				   cin>>temp;
				   arrmain[mainptr]=(int)temp;
				   break;
			case '[' : break; 
			case ']' : break;
			default	 : break;
		}
	if(errorflag) cout<<"Array out of index"<<endl;

}

