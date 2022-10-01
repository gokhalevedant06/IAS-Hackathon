#include <bits/stdc++.h>
using namespace std;

#define delimiter ','

// loading a file
fstream load(string path){
	fstream fileip("TextFiles/"+path);
	string fileLine;

	if(fileip.is_open()){
		cout<<"FILE FOUND"<<endl;
		// while(getline(fileip,fileLine)){
		// cout<<fileLine<<endl;
	    // }
	    return fileip;

	}
    else{
		cout<<"Making New File..."<<endl;
	}
	fileip.close();

	return fileip;
}

pair<int, string> separateKeyValue(string line){
    string key = "";
    string str = "";

    int i = 0;
    while(line[i] != delimiter){
        key += line[i];
        i++;
    }
    while(i != line.size()-1){
        str += line[i];
        i++;
    }
    pair<int, string> myPair;
    myPair.first = stoi(key);
    myPair.second = str;
    return myPair;
}



int main()
{
    string fileLine;
    fstream newFile = load("sample20.txt");
    while(getline(newFile,fileLine)){
    // cout<<fileLine<<endl;
    pair<int, string> myPair = separateKeyValue(fileLine);
    cout<< myPair.first << endl;
    }       

    

	return 0;
}