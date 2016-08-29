#include "stdafx.h"

ServiceManager* ServiceManager::_self = NULL;
TreeItem<string>* ServiceManager::_lockedServices = NULL;
StringUtility* ServiceManager::_stringUtility = NULL;
int ServiceManager::_refcount = 0;

void ServiceManager::FreeInst() { 
	_refcount--;
	if(!_refcount) 
	{
		delete this; 
		_self=NULL;
	}
}

ServiceManager* ServiceManager::Instance(){		
	if(_refcount == 0)
	{
		string root = "root";
		_self = new ServiceManager();
		_lockedServices = new TreeItem<string>(NULL, root);
		_stringUtility = new StringUtility();
	}
	_refcount++;
	return _self;
}

bool ServiceManager::IsServiceAlreadyLocked(string service_name){
	vector<string> listOfservices = _stringUtility->Split(service_name);
	
	TreeItem<string>* item = _lockedServices;	

	vector<string>::reverse_iterator beginIt = listOfservices.rbegin();
	vector<string>::reverse_iterator endIt = listOfservices.rend();				
	while(beginIt != endIt){
		TreeItem<string>* ChildItem = item->FindChild(*beginIt);
		if(ChildItem != NULL)
			if(ChildItem->Size() == 0)
				return true;
			else
				item = ChildItem;
		beginIt++;
	}
	return false;	
}

bool ServiceManager::IsExistsService(string service_name){		
	vector<string> listOfservices = _stringUtility->Split(service_name);
	
	TreeItem<string>* item = _lockedServices;	

	vector<string>::reverse_iterator beginIt = listOfservices.rbegin();
	vector<string>::reverse_iterator endIt = listOfservices.rend();				
	while(beginIt != endIt){
		TreeItem<string>* ChildItem = item->FindChild(*beginIt);
		if(ChildItem != NULL)
			item = ChildItem;
		else 
			return false;

		beginIt++;
	}
	return true;	
}

TreeItem<string>* ServiceManager::InsertService(string service_name){
	vector<string> listOfservices = _stringUtility->Split(service_name);
	
	TreeItem<string>* item = _lockedServices;
	
	vector<string>::reverse_iterator beginIt = listOfservices.rbegin();
	vector<string>::reverse_iterator endIt = listOfservices.rend();
	
	while(beginIt != endIt){
		TreeItem<string>* ChildItem = item->FindChild(*beginIt);
		
		if(ChildItem != NULL)
			item = ChildItem;
		else
			item = item->PushBack(*beginIt);
		beginIt++;
	}
	return item->GetRoot();
}

TreeItem<string>* ServiceManager::DeleteService(string serviceName){
	vector<string> listOfservices = _stringUtility->Split(serviceName);		
	
	TreeItem<string>* item = _lockedServices;

	vector<string>::iterator beginIt = listOfservices.begin();
	vector<string>::iterator endIt = listOfservices.end();	
	
	while(beginIt != endIt){
		TreeItem<string> *findingItem = item->Find(*beginIt);
		if(findingItem == NULL) 
			std::runtime_error("inconsistent data!");
		TreeItem<string> *parentItem = findingItem->GetParent();
		item = parentItem->RemoveChild(*beginIt);
		if(item->Size() == 0){
		}
		else
			break;
		beginIt++;
	}
	return item->GetRoot();
}

void ServiceManager::PrintLockedServices(){
	PrintTree<string>* print = new PrintTree<string>();
	print->PrintTreeItems(_lockedServices);
}
