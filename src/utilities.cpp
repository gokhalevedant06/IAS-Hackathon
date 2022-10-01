#include <bits/stdc++.h>

using namespace std;

int batchSize = 12800;

struct Node{
	int key;
	string val;
	Node* next;
	Node(string Oldkey,string OldVal){
		key = stoi(Oldkey);
		val = OldVal;	
		// cout<<key<<" "<<val<<endl;
	}
};

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

void loadBatches(int startIndex,string path){


	ifstream fileip("TextFiles/"+path);
	string fileLine;

	if(fileip.is_open()){
		cout<<"FILE FOUND"<<endl;
		int counter = 0;
		while(getline(fileip,fileLine)){
		if(counter < startIndex) counter++;
		for(int i=0;i<batchSize;i++){
			cout<<fileLine<<endl;
		}
	}
	}else{
		cout<<"FILE DOES NOT EXIST"<<endl;
	}
	fileip.close();

	
	
}


Node* parseKeyValue(string rawString){
	int delimiter = rawString.find(',');
	string key = rawString.substr(0,5);
	string val = rawString.substr(delimiter+1,rawString.size());
	Node* temp = new Node(key,val);
	return temp;
}


Node a[12800];

int hashing(int key){
    if(key<12800){
        return key;
    }
    return hashing(key%12800);
}

void chainingprobing(int hash,Node node){
	Node* head;
	Node* prevhead=head;
	head = Node[hash];
	while(true){
		if((head->key)==NULL){
prevnode->next=node;
break;
}
else{
	head=head->next;
	prevhead=head;
}
	}
	cout<<"\nprinting";
	Node * head2=Node[hash];
	while(head2!=NULL){
		cout<<head2->key<<" "<<head2->value;
		head2=head2->next;
	}
}

void put(int key,string value){
	int hash=hasing(key);
	Node newnode=new Node();
	newnode->key=key;
	newnode->value=value;
	newnode->next=NULL;
	chainingprobing(hash,newnode);
}

int main()
{
	// bool loaded = load("sample20.txt");
	Node* temp = parseKeyValue("937409,g,svxn");
	cout<<temp->key; 
	
	put(10,"rew");
	put(128000,"rew2");
	return 0;
}






