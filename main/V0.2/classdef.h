
#include<fstream>
#include<vector>

//control size of instruction set 
#define INST_SIZE 10000

//control size of main bit array 
#define ARR_SIZE 1000


class Manager {

	std::ifstream fin;
	char filename[256];
	void flush();
	std::vector<int> beginstack;
	std::vector<int> endstack;	
	
	public:
	
	void printinstr();

	protected:

	short int arrmain[ARR_SIZE];
	std::vector<char> instrset;
	int mainptr,errorflag;

	public:

	void printer();
	Manager();
	~Manager();
	void load_instrset();
	void begin_exec();
};

