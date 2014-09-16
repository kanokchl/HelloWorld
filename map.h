#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

template <class keyType, class valueType>
struct MapItem
{
  keyType key;
  valueType value;
  MapItem<keyType, valueType> *prev, *next;
};


template <class keyType, class valueType>
class Map
{
  public:
    Map ();  // constructor for a new empty map

    ~Map (); // destructor

    int size () const; // returns the number of key-value pairs

    void add (keyType key, valueType value); 
      /* Adds a new association between the given key and the given value.
         If the key already has an association, it should do nothing.
      */

    void remove (keyType key);
     /* Removes the association for the given key.
        If the key has no association, it should do nothing. */

    valueType get (keyType key, bool & success) const;
     /* Returns the value associated with the given key.
        If the key existed in the map, success should be set to true.
        If the key has no association, it should set success to false. */

    void merge (const Map<keyType, valueType> & other);
     /* Adds all the key-value associations of other to the current map.
        If both maps (this and other) contain an association for the same
        key, then the one of this is used. */

  private:
     /* The head and tail of the linked list you're using to store
        all the associations. */

     MapItem <keyType, valueType> *head, *tail, *clear;

     /* If you like, you can add further data fields and private
        helper methods. */
};

template <class keyType, class valueType>
Map<keyType, valueType>::Map(){
	cout << "New Map Created" << endl;
	head = NULL;
	tail = NULL;
};

template <class keyType, class valueType>
Map<keyType, valueType>::~Map(){
	/*
	if (head->next==NULL){
		delete head;
		delete tail;
	} else {
		tail = head;
		while(tail!=NULL){
			clear = tail ;
			tail = tail->next;
			delete clear;
		}
		delete tail;
	}
	cout << "Map Deleted" << endl;
	*/
} 

template <class keyType, class valueType>
void Map<keyType, valueType>::add(keyType key, valueType value){
	
	MapItem<keyType, valueType>* n = new MapItem<keyType, valueType>;
	//cout << key << endl;
	//cout << value << endl;

	cout << n << endl;
	cerr << n->key << endl;
	cerr << n->value <<endl;
	n->key = key;
	n->value = value;
	
	if (head->prev==NULL){
		head = n;
		tail = n;
	} else {
		n->prev = tail;
    	tail->next = n;
	    tail = n;
	}
	cout << "point3" << endl;
	cout << n->key << endl;
	cout << n->value << endl;
	cout << "point4" << endl;
};

template <class keyType, class valueType>
void Map<keyType, valueType>::remove (keyType key){
	
};

template <class keyType, class valueType>
valueType Map<keyType, valueType>::get (keyType key, bool & success) const{

};


template <class keyType, class valueType>
void Map<keyType, valueType>::merge (const Map<keyType, valueType> & other){
	
};

#endif
