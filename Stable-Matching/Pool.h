#include <iostream>
#include "Teacher.h"
#include "Student.h"



template <class T, class S> class Pool{
	private:
		T* elements[10];
	public:
		Pool();
		~Pool();
		void setElemAt(T* element, int index);
		T* getElemAt(int index);
		int getIndexOf(T* element);
		T* getElemByID(int id);
		bool allMatched();
		void resetHighPref();
		void printPool();
		void printMatches(S* match);
};

template <class T, class S> Pool<T,S>::Pool():elements{nullptr}{}

template <class T, class S> Pool<T,S>::~Pool<T,S>(){}

template <class T, class S>
void Pool<T,S>::setElemAt(T* element, int index){
	elements[index] = element;
}


template <class T, class S>
T* Pool<T,S>::getElemAt(int index){ return elements[index]; }

template <class T, class S>
int Pool<T,S>::getIndexOf(T* element){
	for(int i=0;i<10;i++){
		if(element == elements[i]) return i;
	}
	return NULL;
}

template <class T, class S>
T* Pool<T,S>::getElemByID(int id){
	for(T* elem : elements){
		if(elem->getID() == id) return elem;
	}
	return NULL;
}


template <class T, class S>
bool Pool<T,S>::allMatched(){
	for(int i=0;i<10;i++){
		if(!elements[i]) return true; //Array is not filled
		if(!(elements[i]->isMatched())) return false; //Unmatched found
	}
	return true;
}

template <class T, class S>
void Pool<T,S>::resetHighPref(){
	for(T* item : elements){
		if(!item) continue;

	}
}

template <class T, class S>
void Pool<T,S>::printPool(){
	std::cout<<std::endl;
	for(T* item : elements){
		if(!item) break;
		std::cout << *item;
	}
	std::cout<<std::endl;
}

template <class T, class S>
void Pool<T,S>::printMatches(S* match){
	std::cout << "\tMatches:\n" << std::endl;
	for(T* item : elements){
		match = item->getMatched();
		std::cout << "Name:\t\t\t" << item->getName() << "\t" << match->getName() << std::endl;
		std::cout << "ID:\t\t\t" << item->getID() << "\t" << match->getID() << std::endl;
		std::cout << "Preference of Matched:\t" << item->getPrefOf(match) << "\t" << match->getPrefOf(item) << std::endl;
		std::cout << std::endl;
	}
}
