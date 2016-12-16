#include<iostream>
#include"classdef.h"
#define clear() std::cout<<"\033[H\033[J"

main() {

	Manager m;
	short int choice;
	do 
	{
		clear();
		std::cout<<"+----- Main Menu -----+ "<<std::endl
			 <<"| 1. Load Instruction | "<<std::endl
			 <<"| 2. Begin Execution  | "<<std::endl
			 <<"| 3. Show bit array   | "<<std::endl
			 <<"| 4. Exit             | "<<std::endl
			 <<"| 5. Show Instruction | "<<std::endl
			 <<"+---------------------+ "<<std::endl
			 <<"	 Choice : ";
		std::cin>>choice;
		switch(choice) {
			case 1 : m.load_instrset(); 		break;
			case 2 : m.begin_exec(); 		break;
			case 3 : m.printer(); 			break;
			case 4 : break;
			case 5 : m.printinstr();		break; 
			default: std::cout<<"\n Invalid Option";break;
		}
		if(choice!=4) { std::cout<<"\n Press any key to continue. "; char ch; std::cin>>ch; }
	} while(choice!=4);
	return 0;

}
