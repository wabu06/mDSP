#include<iostream>
#include<string>


using namespace std;


inline int getDistance(int drange)
{ 
	 double P{static_cast<double>( rand() ) / static_cast<double>(RAND_MAX)};
	 
	 return static_cast<int>( static_cast<double>(drange) * P );
}


int main(int argc, char** argv)
{
	string arg1 = string(argv[1]);
	
	int num = stoi(arg1);
	
	srand( time(nullptr) );
	
	cout << getDistance(num) << endl;
	
	return 0;
}
