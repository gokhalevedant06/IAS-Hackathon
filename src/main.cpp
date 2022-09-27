#include <bits/stdc++.h>
using namespace std;

// loading a file
bool load(string path){
	ifstream fileip("TextFiles/"+path);
	string fileLine;

	if(fileip.is_open()){
		cout<<"FILE FOUND"<<endl;
		while(getline(fileip,fileLine)){
		cout<<fileLine<<endl;
	}
		return true;
	}else{
		cout<<"FILE DOES NOT EXIST"<<endl;
	}
	fileip.close();

	return false;
}

int main()
{
	bool loaded = load("sample20.txt");
	return 0;
}