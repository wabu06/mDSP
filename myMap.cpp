#include<iostream>
#include<string>
#include<map>


using namespace std;


inline double getNum(int n)
{ 
	 double P{static_cast<double>( rand() ) / static_cast<double>(RAND_MAX)};
	 
	 return static_cast<double>(n) * P;
}


int main(int argc, char** argv)
{
	auto numMap = map<int, double>{};
	
	string arg1 = string(argv[1]);
	
	int num = stoi(arg1);
	
	srand( time(nullptr) );
	
	for(auto& N: {1, 2, 3, 4, 5, 6, 7, 8, 9, 10})
	{
		if (numMap[N] == 0.0)
			numMap[N] += getNum(num);	
	}
	
	for(auto& N: {1, 2, 3, 4, 5, 6, 7, 8, 9, 10})
		cout << numMap[N] << '\t';
	
	cout << endl; 
	
	return 0;
}
