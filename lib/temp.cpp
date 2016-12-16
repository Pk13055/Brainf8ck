#include<iostream>
#include<fstream>
using namespace std;

main() {
	ifstream fin;
	cout<<"\n Enter the filename : ";
	char filename[30];
	cin>>filename;
	fin.open(filename);
	int i=0;
	char ch;
	while(i++<11) fin>>ch; 
	cout<<fin.tellg();
	fin.close();
	return 0;
}
