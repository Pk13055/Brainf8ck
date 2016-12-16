/**
*  	Version 0.1
*  	- Uses arrays for both the instruction set and bit set.
*  	- Bit set and instrc size both statically set
*  	- Loops are functional 
*	- Not mem optimized
**/

#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

//control size of instruction set 
#define INST_SIZE 10000

//control size of main bit array 
#define ARR_SIZE 1000

#define clear() printf("\033[H\033[J")

class Manager {
	//vector<int> arrmain;
	//vector<char> instrset;
	short int arrmain[ARR_SIZE];
	char instrset[INST_SIZE];
	int mainptr;
	fstream fin;
	char filename[256];
 	void flush();
 public:
	void printer();
	Manager();
	~Manager() { fin.close(); }
	void load_instrset();
	void begin_exec();
};

Manager::Manager() {

	flush();
	mainptr=0;
	cout<<"\n Enter the filename : ";
	cin>>filename;
	fin.open(filename);
	if(fin.good()) cout<<"\n File read successful.";
	else cout<<"\n File failed to load.";
}

void Manager::flush() {
	for(int i=0;i<INST_SIZE;instrset[i++]='\0');
	for(int i=0;i<ARR_SIZE; arrmain[i++]=0);
}

void Manager::printer() {
	for(int i=0;i<=mainptr;cout<<arrmain[i++]);
	cout<<endl;
}
void Manager::load_instrset() {

	fin.seekg(0,ios::end);
	char ch='y';
	if(fin.tellp()>INST_SIZE) {
		cout<<"\n Instruction set exceedes instrc. mem. size."
		    <<"\n Partially Load \? (y/n) : ";
	        cin>>ch;
	}
	if(ch!='n') {
		int i=0;
		fin.seekp(0,ios::beg);
		while(!fin.eof()&&i<1000) fin>>instrset[i++];
		cout<<"\n Instruction set loaded successfully.";
	}	
}	

void Manager::begin_exec() {
	

}


main() {
	
	Manager m;
	short int choice;
	do 
	{
		clear();
		cout	<<"+----- Main Menu -----+ "<<endl
			<<"| 1. Load Instruction | "<<endl
			<<"| 2. Begin Execution  | "<<endl
			<<"| 3. Show bit array   | "<<endl
			<<"| 4. Exit		 | "<<endl
			<<"+---------------------+ "<<endl
			<<"	 Choice : ";
		cin>>choice;
		switch(choice) {
			case 1 : m.load_instrset(); 		break;
			case 2 : m.begin_exec(); 		break;
			case 3 : m.printer(); 			break;
			case 4 : break;
			default: cout<<"\n Invalid Option";	break;
		}
	} while(choice!=4);
	return 0;
}
