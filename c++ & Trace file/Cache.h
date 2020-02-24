//Author: Junjie Liang
//Date:4/29/2018
//Description: This class will take the given tag and index and calculate the hit time, total byte transfered from memory to cache and total byte transfered from cache to memory.
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
struct TagElement 
{
	int DirtyBit;
	int tag;
	int priority;
	TagElement() :DirtyBit(0), tag(-1),priority(1) {};
	TagElement(int InputDirtyBit, int InputTag, int InputPriority)
	{
		DirtyBit = InputDirtyBit;
		tag = InputTag;
		priority = InputPriority;
	}
};
struct TagStorage
{
	int index;
	vector<TagElement> tagstore;
	TagStorage(int InputIndex)
	{
		index = InputIndex;
	}
};

class Cache
{
private:
	vector<TagStorage> cache;
	int Cache_size;
	int Block_size;
	int set_count;
	int set_size;
	double hittime;
	int Byte_M_C;
	int Byte_C_M;

public:
	Cache();
	~Cache();
	Cache(int in_Cache_size, int in_Block_size, int in_set_size);
	void Read(int InputIndex, int InputTag);
	void WriteThrough(int InputIndex, int InputTag);
	void WriteBack(int InputIndex, int InputTag);
	void CheckWriteBack();
	int getByte_M_C();
	int getByte_C_M();
	double getHitTime();
	void addIndex(int inputIndex);
};

