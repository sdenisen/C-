#include "stdafx.h"
#include "TreeTestCases.h"

void PrintCornerMessage(string msg){
	cout<<"--------------------------------------------------"<<endl;
	cout<<"|                                                |"<<endl;
	cout<<msg<<endl;
	cout<<"|                                                |"<<endl;
	cout<<"--------------------------------------------------"<<endl;
}

void VerifyService(){
	ServiceManager* _serviceManager = ServiceManager::Instance();
	
	cout<<"----------------------------------------------------"<<endl;
	string service_name = "test3";	
	cout<<"locked service \"" + service_name + "\": "<<endl;
	
	_serviceManager->Lock(service_name);
	_serviceManager->PrintLockedServices();
	service_name = "test2.test3";	
	cout<<"try to lock child service: \""+service_name+"\" and get exception: "<<endl;	
	try{
		_serviceManager->Lock(service_name);
	}
	catch(exception &e){
		cout<<"get exception...: "<<e.what()<<endl;
	}
	service_name = "test3";
	_serviceManager->UnLock(service_name);
	cout<<"----------------------------------------------------"<<endl;	
	service_name = "test4.test3";	
	cout<<"lock service \"" + service_name + "\": "<<endl;
	
	_serviceManager->Lock(service_name);
	_serviceManager->PrintLockedServices();
	service_name = "test2.test3";	
	cout<<"lock service: \""+service_name+"\": "<<endl;	
	_serviceManager->Lock(service_name);
	_serviceManager->PrintLockedServices();
	cout<<"unlock only test2.test3 service"<<endl;	
	_serviceManager->UnLock(service_name);
	_serviceManager->PrintLockedServices();
	cout<<"----------------------------------------------------"<<endl;	
	service_name = "test4.test3";	
	cout<<"locked the save service: \""+service_name+"\" and get exception: "<<endl;
	try{
		_serviceManager->Lock(service_name);
	}
	catch(exception &e){
		cout<<"get exception...: "<<e.what()<<endl;
	}

	_serviceManager->PrintLockedServices();
	cout<<endl<<"unlock \""+service_name+"\""<<endl;
	_serviceManager->UnLock(service_name);
	_serviceManager->PrintLockedServices();

	service_name = "unavailable.test3";
	
	cout<<endl<<"unlock service which doesn't exists \"" + service_name + "\", and get exception:"<<endl;		
	try{
		_serviceManager->UnLock(service_name);
	}
	catch(exception &e){
		cout<<"get exception: "<<e.what()<<endl;
	}
	_serviceManager->PrintLockedServices();
}

int _tmain(int argc, _TCHAR* argv[])
{
	PrintCornerMessage("       TEST CASE: VERIFY SERVICE MANAGER:        ");
	VerifyService();	
	getch();
	return 1;
}
