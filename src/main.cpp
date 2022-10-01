#include <bits/stdc++.h>

using namespace std;

int batchSize = 12800;
struct Node{
	int key=-1;
	string val;
	Node* next;
	Node(string Oldkey,string OldVal){
		key = stoi(Oldkey);
		val = OldVal;	
		// cout<<key<<" "<<val<<endl;
	}
};

int hashing(int key){
    if(key<=12800){
        return key;
    }
    return hashing(key%12800);
}

vector<Node*> batch(12800,NULL);

bool writeToFile(fstream myFile, string str){
	bool flag;
	myFile.open("database.txt");

	if(myFile){
		myFile << str;
		return true;
	}
	else{
		return false;
	}
}

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

Node* parseKeyValue(string rawString){
	if(rawString.find(',')==std::string::npos) return NULL;
	int delimiter =rawString.find(',');
	string key = rawString.substr(0,5);
	string val = rawString.substr(delimiter+1,rawString.size());
	Node* temp = new Node(key,val);
	return temp;
}



void chainingprobing(int hash,Node* node){
	Node* head = batch[hash];
	Node* prevhead=head;
	while(true){
		if(head==NULL){
		batch[hash] = node;
		break;
	}else{
			head=head->next;
		}
	}

	// cout<<"\nprinting";
	// Node * head2=batch[hash];
	// while(head2!=NULL){
	// 	cout<<head2->key<<" "<<head2->val;
	// 	head2=head2->next;
	// }
}


void put(string key,string value){
	int hash=hashing(stoi(key));
	Node* newnode=new Node(key,value);
	newnode->next=NULL;
	chainingprobing(hash,newnode);
}



void loadBatches(int startIndex,string path){

	ifstream fileip("TextFiles/"+path);
	string fileLine;

	if(fileip.is_open()){
		cout<<"FILE FOUND"<<endl;
		int counter = 0;
		int size = 0;
		while(size < batchSize && getline(fileip,fileLine)){
		if(counter < startIndex) counter++;
		else{
			parseKeyValue(fileLine);
			if(fileLine.find(',')==std::string::npos){
				break;
			}
			else{
			}
			Node* element = parseKeyValue(fileLine);
			if(element)
			put(to_string(element->key),element->val);
		
		}
		
	}

	}else{
		cout<<"FILE DOES NOT EXIST"<<endl;
	}
	fileip.close();

	
	
}

string get(int key){
	int hash = hashing(key);
	Node* head = batch[hash];
	
	 while(true){
		if(head==NULL) return NULL;
		if(head->key==key) return head->val;
		else head = head->next;
	 }	
}

// void put2(string key,string value){
// 	int a=10;
// 	int *p=&a;
// 	int *q;
	// q=p+key
	//
// }

// int scanmax(int key1,int key2){
// ifstream fileip("TextFiles/"+path);
// 	string fileLine;

// 	if(fileip.is_open()){
// 		cout<<"FILE FOUND"<<endl;
// 		int counter = 0;
// 		int size = 0;
// 		while(size < batchSize && getline(fileip,fileLine)){
// 		if(counter < startIndex) counter++;
// 		else{
// 			parseKeyValue(fileLine);
// 			Node* element = parseKeyValue(fileLine);
// 			int hash = hashing(element->key);
// 			
		
// 		}
		
// 	}

// 	}else{
// 		cout<<"FILE DOES NOT EXIST"<<endl;
// 	}
// 	fileip.close();
// }


void showMenu(){
	cout<<"Turing Machine DB\n";
	cout<<"Enter the number for the operation to perform:\n";
	cout<<"1 - Load the database from filename\n2 - Put an entry to database\n3 - Get a value from database\n4 -  Scan the database\n5 - Quit\n\n";
}

int main()
{


	loadBatches(5,"sample20.txt");

	
	// put("10","abcdve");
	// put("128000","AFSDFDG");
	

	bool flag = true;


	while(flag){
		showMenu();
		int op;
		cin >> op;
		string name;
		long int key;
		string value;
		int start,end;

		switch(op){
			case 1:
				cout<<"Enter the filename:";
				cin>>name;
				load(name);
				break;
			case 2:
				cout<<"Enter the key:";
				cin>>key;
				cout<<"Enter the value:";
				cin>>value;
				put(to_string(key),value);
				break;
			case 3:
				cout<<"Enter the key:";
				cin>>key;
				cout<<get(key);
				break;
			case 4:
				cout<<"Enter the start:";
				cin>>start;
				cout<<"Enter the end:";
				cin>>end;
				// scanmax(start,end);
				break;
			case 5:
				flag = false;
				break;
		}
	}


	return 0;
}






