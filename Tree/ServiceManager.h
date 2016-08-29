// --------------------------------------------------------
// ������ ��������� ��������� (������ ���������� ��� ��������).
// ���� 2 ������ ��� ���������� ���������: Lock(), UnLock()
// � ������� ������ �������� PrintLockedServices(); (������� � ������ ������ ������������) 
// --------------------------------------------------------
class ServiceManager{

	static ServiceManager* _self;
	static int _refcount;
	static TreeItem<string>* _lockedServices;
	static StringUtility* _stringUtility;

	bool IsExistsService(string service_name);
	bool IsServiceAlreadyLocked(string service_name);
	TreeItem<string>* DeleteService(string serviceName);
	TreeItem<string>* InsertService(string service_name);	
	

protected:
	ServiceManager(){}
	~ServiceManager(){
		FreeInst();
	}

public:

	void FreeInst();
	static ServiceManager* Instance();	
	void PrintLockedServices();	
	

	void Lock(string serviceName){
	
		if(!IsServiceAlreadyLocked(serviceName)){
			_lockedServices = InsertService(serviceName);
			return;		
		}
		throw std::exception (serviceName.c_str());
	}

	void UnLock(string serviceName){
	
		if(IsServiceAlreadyLocked(serviceName)){
			_lockedServices = DeleteService(serviceName);
			return;		
		}
		throw std::exception (serviceName.c_str());
	}	
};
