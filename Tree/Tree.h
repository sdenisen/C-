// -----------------------------------------------------------------------------------------
// шаблонный класс Дерево: контейнер сущностей, в частности стрингов, для использования в 
// ServiceManager классе. 
// здесь есть все необходимые методы для управлением деревом:
//		поиск элемента по всему дереву: Find();
//		поиск только у своих потомков: FindChild();
//		вставка нового элемента PushBack();
//		удаление своего потомка RemoveChild();
//		получение размера потомков Size();
//		методы для получения ссылки на родителя и корень: GetParent(); GetRoot(); 
// -----------------------------------------------------------------------------------------

template <class T> class TreeItem{
  typedef vector<TreeItem*> tagItems; 
  typedef typename tagItems::iterator tagItemsIterator; 
  typedef typename tagItems::const_iterator tagItemsIteratorConst; 
private:
  T _data;
  TreeItem* _parent;
  vector<TreeItem*> _children;
  void Destroy();

public:
	   TreeItem(TreeItem* parent,const T& data) : _data(data), _parent(parent)
	   {}
	    ~TreeItem(){ Destroy(); }
public:

  const typename tagItems::size_type Size() const { return _children.size(); }
  const T data() const { 
	  return _data; 
  }

  TreeItem* PushBack(TreeItem* item);
  TreeItem* PushBack(const T& data) { return PushBack( new TreeItem<T>(this, data) ); }  
  TreeItem* Find(const T &data);  
  TreeItem* FindChild(const T &data);
  TreeItem* GetRoot();
  TreeItem* GetParent();
  TreeItem* RemoveChild(const T& data);  

  TreeItem* GetAt(typename tagItems::size_type index)
  {
    if(index >= _children.size()) 
		throw std::runtime_error("Index out of bounds.");
    return _children[index];
  }  
};

template <class T> TreeItem<T>* TreeItem<T>::GetParent(){
	return _parent;
}

template<class T> void TreeItem<T>::Destroy()
{
  tagItemsIterator begin = _children.begin();
  tagItemsIterator end =_children.end();

  while( begin != end )
  {
    delete (*begin);
    ++begin;
  }
  _children.clear();
}

template <class T> TreeItem<T>* TreeItem<T>::RemoveChild(const T& data)
{
  tagItemsIterator begin = _children.begin();
  tagItemsIterator end =_children.end();

  while( begin != end )
  {
	  if((*begin)->data() == data)
	  {	
		  _children.erase(begin);  
		  return this;
	  }
	  begin++;
  }
  return this;
}


template <class T> TreeItem<T>* TreeItem<T>::PushBack(TreeItem<T>* item)
{
  if( !item ) throw std::runtime_error("[push_back] Cannot insert NULL item.");
  item->_parent = this;
  _children.push_back( item );
  return item;
}

template<class T> TreeItem<T>* TreeItem<T>::Find(const T &data){
	
	if(data == _data)
		return this;

	tagItemsIterator it = _children.begin();
	for(; it!= _children.end(); it++){
		TreeItem<T>* test = (*it);
		TreeItem<T>* result = test->Find(data);

		if(result != NULL)
			return result;
	}

	return NULL;
}

template<class T> TreeItem<T>* TreeItem<T>::FindChild(const T &data){
	if(data == _data)
		return this;

	tagItemsIterator it = _children.begin();
	for(; it!= _children.end(); it++){
		TreeItem<T>* test = (*it);
		string childData = test->data();
		if(childData == data)
			return test;	
	}
	return NULL;
}

template<class T> TreeItem<T>* TreeItem<T>::GetRoot(){

	if(_parent == NULL){
		return this;
	}
	return _parent->GetRoot();
}