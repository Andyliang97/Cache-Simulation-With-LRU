
#include "Cache.h"


bool compareByPriority(const TagElement &a, const TagElement &b)
{
	return a.priority > b.priority;
}

Cache::Cache()
{
}


Cache::~Cache()
{
	cache.~vector();
}

Cache::Cache(int in_Cache_size, int in_Block_size, int in_set_count)
{
	Cache_size = in_Cache_size;
	Block_size = in_Block_size;
	set_count = in_set_count;
	set_size = in_Cache_size / in_Block_size / set_count;
	hittime = 0;
	Byte_M_C = 0;
	Byte_C_M = 0;

}

void Cache::Read(int InputIndex, int InputTag)
{
	vector<TagStorage>::iterator it;
	bool hit = false;
	for (it = cache.begin(); it != cache.end(); it++)
	{
		if (it->index == InputIndex)
		{
			vector<TagElement>::iterator block_it;
			if (it->tagstore.empty())
				break;
			sort(it->tagstore.begin(), it->tagstore.end(), compareByPriority);
			int i = 0;
			for(block_it=it->tagstore.begin();block_it!=it->tagstore.end();block_it++)
			{
				
				if (it->tagstore.at(i).tag == InputTag)
				{
					vector<TagElement>::iterator second_block_it;
					int j = 0;
					for (second_block_it = it->tagstore.begin(); second_block_it != it->tagstore.end(); second_block_it++)
					{
						it->tagstore[j].priority++;
						j++;
					}
					it->tagstore[i].priority = 0;
					hittime++;
					hit = true;
					break;
				}
				i++;
			}
			break;
		}
	}

	if (!hit)
	{
		Byte_M_C += Block_size;
		for (it = cache.begin(); it != cache.end(); it++)
		{
			if (it->index == InputIndex)
			{
				if ((it->tagstore.size()) == set_count)
				{
					sort(it->tagstore.begin(), it->tagstore.end(), compareByPriority);
					if (it->tagstore[0].DirtyBit == 1)
					{
						it->tagstore[0].DirtyBit = 0;
						Byte_C_M += Block_size;
					}
					it->tagstore[0].tag = InputTag;
					it->tagstore[0].priority = 0;
					it->tagstore[0].DirtyBit = 0;
					int i = 1;
					vector<TagElement>::iterator third_block_it;
					if (it->tagstore.size() != 1)
					{
						for (third_block_it = it->tagstore.end() - 1; third_block_it != it->tagstore.begin(); third_block_it--)
						{
							third_block_it->priority = i;
							i++;
						}
					}
					break;
				}
				else
				{
					it->tagstore.push_back(TagElement(0, InputTag, 0));
					break;
				}
			}
		}
	}
	//cout << cache[0].tagstore[0] << '\t' << cache[0].tagstore[1] << endl;
}

void Cache::WriteThrough(int InputIndex, int InputTag)
{
	Byte_C_M += 4;
	Read(InputIndex, InputTag);
}

void Cache::WriteBack(int InputIndex, int InputTag)
{
	vector<TagStorage>::iterator it;
	bool hit = false;
	for (it = cache.begin(); it != cache.end(); it++)
	{
		if (it->index == InputIndex)
		{
			if (it->tagstore.empty())
				break;
			sort(it->tagstore.begin(), it->tagstore.end(), compareByPriority);
			vector<TagElement>::iterator block_it;
			
			int i = 0;
			for (block_it = it->tagstore.begin(); block_it != it->tagstore.end(); block_it++)
			{
				if (it->tagstore.at(i).tag == InputTag)
				{
					vector<TagElement>::iterator second_block_it;
					int j = 0;
					for (second_block_it = it->tagstore.begin(); second_block_it != it->tagstore.end(); second_block_it++)
					{
						it->tagstore[j].priority++;
						j++;
					}
					it->tagstore[i].priority = 0;
					it->tagstore[i].DirtyBit = 1;
					hittime++;
					hit = true;
					break;
				}
				i++;
			}
			break;
		}
	}

	if (!hit)
	{
		Byte_M_C += Block_size;
		for (it = cache.begin(); it != cache.end(); it++)
		{
			if (it->index == InputIndex)
			{
				if ((it->tagstore.size()) == set_count)
				{
					sort(it->tagstore.begin(), it->tagstore.end(), compareByPriority);
					if (it->tagstore[0].DirtyBit == 1)
					{
						Byte_C_M += Block_size;
					}
					it->tagstore[0].tag = InputTag;
					it->tagstore[0].priority = 0;
					it->tagstore[0].DirtyBit = 1;
					int i = 1;
					vector<TagElement>::iterator third_block_it;
					if (it->tagstore.size() != 1)
					{
						for (third_block_it = it->tagstore.end() - 1; third_block_it != it->tagstore.begin(); third_block_it--)
						{
							third_block_it->priority = i;
							i++;
						}
					}
					break;
				}
				else
				{
					it->tagstore.push_back(TagElement(1, InputTag, 0));
					break;
				}
			}
		}
	}

}

void Cache::CheckWriteBack()
{
	vector<TagStorage>::iterator it;
	vector<TagElement>::iterator block_it;
	for (it=cache.begin();it!=cache.end();it++)
	{
		for (block_it=it->tagstore.begin(); block_it != it->tagstore.end();block_it++)
		{
			if (block_it->DirtyBit == 1)
			{
				Byte_C_M += Block_size;
				block_it->DirtyBit = 0;
			}
		}
	}
}

int Cache::getByte_M_C()
{
	return Byte_M_C;
}

int Cache::getByte_C_M()
{
	return Byte_C_M;
}

double Cache::getHitTime()
{
	return hittime;
}

void Cache::addIndex(int inputIndex)
{
		cache.push_back(TagStorage(inputIndex));
}






