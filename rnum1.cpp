#include<iostream>
#include<string>


using namespace std;


inline int getRandNum(int n) { return rand() % n + 1; }


int main(int argc, char** argv)
{
	string arg1 = string(argv[1]);
	
	int num = stoi(arg1);
	
	srand( time(nullptr) );
	
	cout << getRandNum(num) << endl;
	
	return 0;
}
