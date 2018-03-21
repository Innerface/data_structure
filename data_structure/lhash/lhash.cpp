
#include "lhash.h"




lx::lhash::lhash(int l) :len(l){
	try{
		data = new hashObject[len];
	}
	catch (std::bad_alloc &e){
		std::cout << "bad_alloc" << e.what() << std::endl;
	}
	memset(data, 0, len);
}


lx::lhash::~lhash(){
	if (data){
		delete[]data;
	}
}


void lx::lhash::add(int key, int value){
	int index = hash(key);
	data[index].setKey(key);
	data[index].setValue(value);
}


bool lx::lhash::exists(int key){

}





int lx::lhash::hash(int key){
	return key%len;
}