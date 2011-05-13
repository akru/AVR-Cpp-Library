#ifndef LIST
#define LIST_H

template<class T>
class ListItem
{
public:
  ListItem( T data )
      : data( data ), next( 0 )
  {}
  T data;
  ListItem *next;
};

template<class T>
class List
{
public:
  List();
  bool empty();
  void push( T item );
  inline ListItem<T> * getBegin()
  {
    return begin;
  }
private:
  ListItem<T> *begin;
  ListItem<T> *end;
};

template<class T>
List<T>::List()
    : begin( 0 ), end( 0 )
{
}

template<class T>
bool List<T>::empty()
{
  if ( !begin )
    return 1;
  else
    return 0;
}

template<class T>
void List<T>::push( T item )
{
  if ( begin )
  {
    end->next = new ListItem<T>( item );
    end = end->next;
  }
  else
  {
    begin = new ListItem<T>( item );
    end = begin;
  }
}

#endif // LIST_H
