// -----------------------------------------------
// класс Печати Дерева
// -----------------------------------------------
template <class T> class PrintTree{
	void Print(TreeItem<T>* root, int printDeep, int position){
		if(root)
		{
			string space(printDeep, ' ');
			cout << space<< root->data() << endl;

			if( position < root->Size() ) 
				Print(root->GetAt(position), printDeep + 1, 0);		
			position++;
		
			while( position < root->Size() )
			{
			  TreeItem<T> *item = root->GetAt(position);
			  if( item )
				Print( item , printDeep + 1, 0);
			  position++;
			}
		}	
	}
public:
	void PrintTreeItems(TreeItem<T>* root){
			int printDeep = 0;
			int position = 0;
			Print(root, printDeep, position);	
	}
};