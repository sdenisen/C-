#include "stdafx.h"

vector<string>* TestFunction();

//TreeItem<string>* InsertService(vector<string> listOfServices, TreeItem<string> *tree){
//	vector<string>::iterator it = listOfServices.end();
//	TreeItem<string>* item = tree;
//	for(; it != listOfServices.begin();)
//	{it--;
//		TreeItem<string>* ChildItem = item->FindChild(*it);
//		if(ChildItem != NULL){
//			item = ChildItem;
//			continue;
//		}
//		item = item->PushBack(*it);
//	}
//	return item->GetRoot();
//}

//bool ExistsService(vector<string> listOfServices, TreeItem<string> *tree){
//	vector<string>::iterator it  = listOfServices.end();	
//	TreeItem<string>* item = tree;
//	for(; it != listOfServices.begin(); )
//	{
//		it--;
//		TreeItem<string>* ChildItem = item->FindChild(*it);
//		if(ChildItem != NULL){
//			item = ChildItem;
//			continue;
//		}
//		return false;
//	}
//	return true;
//}

//void TestInsertTree(){
//	PrintTree* print = new PrintTree();
//	
//	// add service;
//	StringUtility *util = new StringUtility();	
//	string service_name = "test1.test2.test3";
//	vector<string> listOfservices = util->Split(service_name, '.');
//	string str = "root";
//	TreeItem<string> *root = new TreeItem<string>(NULL, str);
//	root = InsertService(listOfservices, root);
//
//
//	// add anotherservice:
//	service_name = "test0.test1.test2.test3";
//	listOfservices = util->Split(service_name, '.');
//
//	if(!ExistsService(listOfservices, root)){
//		root = InsertService(listOfservices, root);
//	}
//	print->PrintTreeItems(root);	
//
//	// add anotherservice:
//	service_name = "test22.test3";
//	listOfservices = util->Split(service_name, '.');
//
//	if(!ExistsService(listOfservices, root)){
//		root = InsertService(listOfservices, root);
//	}
//
//	print->PrintTreeItems(root);
//
//	// add anotherservice:
//	service_name = "test11.test22.test3";
//	listOfservices = util->Split(service_name, '.');
//
//	if(!ExistsService(listOfservices, root)){
//		root = InsertService(listOfservices, root);
//	}
//	print->PrintTreeItems(root);
//}
//
//
class TestCases{
	TreeItem<string> *root;
	PrintTree<string>* print;
public:

	TestCases(){		
		print = new PrintTree<string>();
		root = NULL;
		PrepareData();
	}

	void EraseItems(){
		delete(root);
		root = NULL;
	}


	void PrepareData(){
		if(root != NULL)
			delete(root);
		root = NULL;
		string str = "root";
		root = new TreeItem<string>(NULL, str);
		TreeItem<string> *p;		
		root->PushBack((string)"test1");
		root->PushBack((string)"test2");
		p = root->PushBack((string)"test4");

		p->PushBack((string)"test41");
		p->PushBack((string)"test43");
		cout << "Size of children Items: " << p->Size() << endl;        
	}

	void Print(){
		print->PrintTreeItems(root);
		cout << "Size of root items: " << root->Size()<< endl;
	}


	void TestDeleteTreeItems(){
		cout<<"before remove \"test1\" item:"<<endl;
		print->PrintTreeItems(root);
		root->RemoveChild((string)"test1");
		cout<<"after \"test1\" was removed"<<endl;
		print->PrintTreeItems(root);

		cout<<"counldn't remove others children \"test43\": "<<endl;
		print->PrintTreeItems(root);
		root->RemoveChild((string)"test43");		
		print->PrintTreeItems(root);
	}	
};

