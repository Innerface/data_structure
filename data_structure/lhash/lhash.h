
#ifndef _LHASH_H_
#define _LHASH_H_


#include <vector>
#include <iostream>

/*
 *  采用线性探测法实现哈希表
 *  参考：https://github.com/jwasham/practice-cpp/blob/master/hash_table/hash_table.cc
 */

namespace lx{

	class hashObject{
	public:
		hashObject(){}
		hashObject(int k, int v) :key(k), value(v){}
		~hashObject(){}

		void setKey(int k){
			key = k;
		}

		void setValue(int v){
			value = v;
		}

		int getKey(){ return key; }

		int getValue(){ return value; }
	private:
		int key;
		int value;
	};


	class lhash{
	public:
		lhash(int len);
		~lhash();
		/*   add a key-value to hash,if key exists ,update its value   */
		void add(int key,int value);

		/*   if key exists in hash   */
		bool exists(int key);

		/*   get value from hash by key   */
		int get(int key);

		/*   remove key-value from hash by key   */
		bool remove(int key);
	private:
		/*   hash function   */
		int hash(int key);

	private:
		/*   data storage   */
		hashObject *data;
		int len;
	};
}




#endif