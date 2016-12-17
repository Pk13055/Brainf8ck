/**
 *  	Version 0.2
 *  	- Uses arrays for both the instruction set and bit set.
 *  	- Bit set and instrc size both statically set
 *  	- Loops are functional 
 *	- Mem optmized in terms of instr. set
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

	instrset.clear();
	for(int i=0;i<ARR_SIZE; arrmain[i++]=0);
}

void Manager::printer() {

	for(int i=0;i<=mainptr;cout<<arrmain[i++]);
	cout<<endl;
}

void Manager::printinstr() {

	for(vector<char>::iterator i=instrset.begin(); i!=instrset.end(); cout<<*i++<<" ");
	cout<<endl;
}

void Manager::load_instrset() {

	fin.seekg(0,ios::end);
	long long int  i = fin.tellg(); //for debugging
	char ch='y';
	if(i>INST_SIZE) {
		cout<<"\n Instruction set exceedes instrc. mem. size."
			<<"\n Partially Load \? (y/n) : ";
		cin>>ch;
	}
	if(ch!='n') {
		int i=0;
		fin.seekg(0,ios::beg);
		while(fin>>ch&&i<1000) instrset.push_back(ch);
		cout<<"\n Instruction set loaded successfully.";
	}	
}	

void Manager::begin_exec() {

	vector<char>::iterator i=instrset.begin();
	while(i!=instrset.end()) 
		switch(*i++) {
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

