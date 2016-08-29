// --------------------------------------------------
// класс работает со строками, 
// единственный метод 
// разделяет строку по разделителю: Split()
// --------------------------------------------------

class StringUtility
{	
private:
	static const char SPLIT_CHAR='.';

	static bool sep(char c){
		return SPLIT_CHAR == c;	
	}
public:
	StringUtility(){}

	vector<string> Split(const string& str){
		vector<string> result;
		
		typedef string::const_iterator iter;
		iter i = str.begin();		
		while(i != str.end()){
			iter j = find_if(i, str.end(), StringUtility::sep);			
			result.push_back(string(i, j));			
			if(j == str.end())
				break;
			i = ++j;
		}
		return result;	
	}	
};

