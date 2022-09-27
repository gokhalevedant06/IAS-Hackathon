#include <bits/stdc++.h>
using namespace std;



int main()
{
	ifstream fout("TextFiles/sample20.txt");
	string filecontent;

	// fout.open("sample20.txt",ios::in);


	// if(fout.is_open()){
	// 	cout<<"HERE";
	// 	while(getline(cin,filecontent)){
	// 	cout<<filecontent<<endl;
	// 	}

	// }

	while(getline(fout,filecontent)){
		cout<<filecontent<<endl;
	}

	fout.close();

	return 0;
}