//Author: Junjie Liang
//Date: 4/29/2018
//Description: This is the client code. It will read the given file name in line 35 and output the simulation result for various caches.
#include"Cache.h"
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<sstream>
#include <iomanip>  

using namespace std;
struct Instruction
{
	string ins;
	unsigned long int address;
	Instruction(string inputins, unsigned long int inputaddress)
	{
		ins = inputins;
		address = inputaddress;
	}
};
int ReadInstruction(vector<Instruction>&tempVector, const string filename);
void Process(int CacheSize, int BlockSize, int WaySize, vector<Instruction> TempVector, string filename);




int main()
{
	int CacheSize = 1024;
	int BlockSize = 8;
	int WaySize = 1;
	vector<Instruction> InstructionVector;
	string filename = "test1.trace";
	int InstructionCount = ReadInstruction(InstructionVector, filename);
	bool finished = false;


	Cache WT(CacheSize, BlockSize, WaySize);
	Cache WB(CacheSize, BlockSize, WaySize);
	while (!finished)
	{

		switch (CacheSize)
		{
		case 1024:

			switch (BlockSize)
			{
			case 8:

				switch (WaySize)
				{
				case 1:
					Process(CacheSize, BlockSize, WaySize, InstructionVector, filename);
					WaySize = 2;
					break;
				case 2:
					Process(CacheSize, BlockSize, WaySize, InstructionVector, filename);
					WaySize = 4;
					break;
				case 4:
					Process(CacheSize, BlockSize, WaySize, InstructionVector, filename);
					WaySize = 8;
					break;
				case 8:
					Process(CacheSize, BlockSize, WaySize, InstructionVector, filename);
					WaySize = 1;
					BlockSize = 16;
					break;
				}
				break;
			case 16:

				switch (WaySize)
				{
				case 1:
					Process(CacheSize, BlockSize, WaySize, InstructionVector, filename);
					WaySize = 2;
					break;
				case 2:
					Process(CacheSize, BlockSize, WaySize, InstructionVector, filename);
					WaySize = 4;
					break;
				case 4:
					Process(CacheSize, BlockSize, WaySize, InstructionVector, filename);
					WaySize = 8;
					break;
				case 8:
					Process(CacheSize, BlockSize, WaySize, InstructionVector, filename);
					WaySize = 1;
					BlockSize = 32;
					break;
				}
				break;
			case 32:

				switch (WaySize)
				{
				case 1:
					Process(CacheSize, BlockSize, WaySize, InstructionVector, filename);
					WaySize = 2;
					break;
				case 2:
					Process(CacheSize, BlockSize, WaySize, InstructionVector, filename);
					WaySize = 4;
					break;
				case 4:
					Process(CacheSize, BlockSize, WaySize, InstructionVector, filename);
					WaySize = 8;
					break;
				case 8:
					Process(CacheSize, BlockSize, WaySize, InstructionVector, filename);
					WaySize = 1;
					BlockSize = 128;
					break;
				}
				break;
			case 128:

				switch (WaySize)
				{
				case 1:
					Process(CacheSize, BlockSize, WaySize, InstructionVector, filename);
					WaySize = 2;
					break;
				case 2:
					Process(CacheSize, BlockSize, WaySize, InstructionVector, filename);
					WaySize = 4;
					break;
				case 4:
					Process(CacheSize, BlockSize, WaySize, InstructionVector, filename);
					WaySize = 8;
					break;
				case 8:
					Process(CacheSize, BlockSize, WaySize, InstructionVector, filename);
					WaySize = 1;
					BlockSize = 8;
					CacheSize = 4096;
					break;
				}
				break;
			}
			break;

		case 4096:

			switch (BlockSize)
			{
			case 8:

				switch (WaySize)
				{
				case 1:
					Process(CacheSize, BlockSize, WaySize, InstructionVector, filename);
					WaySize = 2;
					break;
				case 2:
					Process(CacheSize, BlockSize, WaySize, InstructionVector, filename);
					WaySize = 4;
					break;
				case 4:
					Process(CacheSize, BlockSize, WaySize, InstructionVector, filename);
					WaySize = 8;
					break;
				case 8:
					Process(CacheSize, BlockSize, WaySize, InstructionVector, filename);
					WaySize = 1;
					BlockSize = 16;
					break;
				}
				break;
			case 16:

				switch (WaySize)
				{
				case 1:
					Process(CacheSize, BlockSize, WaySize, InstructionVector, filename);
					WaySize = 2;
					break;
				case 2:
					Process(CacheSize, BlockSize, WaySize, InstructionVector, filename);
					WaySize = 4;
					break;
				case 4:
					Process(CacheSize, BlockSize, WaySize, InstructionVector, filename);
					WaySize = 8;
					break;
				case 8:
					Process(CacheSize, BlockSize, WaySize, InstructionVector, filename);
					WaySize = 1;
					BlockSize = 32;
					break;
				}
				break;
			case 32:

				switch (WaySize)
				{
				case 1:
					Process(CacheSize, BlockSize, WaySize, InstructionVector, filename);
					WaySize = 2;
					break;
				case 2:
					Process(CacheSize, BlockSize, WaySize, InstructionVector, filename);
					WaySize = 4;
					break;
				case 4:
					Process(CacheSize, BlockSize, WaySize, InstructionVector, filename);
					WaySize = 8;
					break;
				case 8:
					Process(CacheSize, BlockSize, WaySize, InstructionVector, filename);
					WaySize = 1;
					BlockSize = 128;
					break;
				}
				break;
			case 128:

				switch (WaySize)
				{
				case 1:
					Process(CacheSize, BlockSize, WaySize, InstructionVector, filename);
					WaySize = 2;
					break;
				case 2:
					Process(CacheSize, BlockSize, WaySize, InstructionVector, filename);
					WaySize = 4;
					break;
				case 4:
					Process(CacheSize, BlockSize, WaySize, InstructionVector, filename);
					WaySize = 8;
					break;
				case 8:
					Process(CacheSize, BlockSize, WaySize, InstructionVector, filename);
					WaySize = 1;
					BlockSize = 8;
					CacheSize = 65536;
					break;
				}
				break;
			}
			break;

		case 65536:

			switch (BlockSize)
			{
			case 8:

				switch (WaySize)
				{
				case 1:
					Process(CacheSize, BlockSize, WaySize, InstructionVector, filename);
					WaySize = 2;
					break;
				case 2:
					Process(CacheSize, BlockSize, WaySize, InstructionVector, filename);
					WaySize = 4;
					break;
				case 4:
					Process(CacheSize, BlockSize, WaySize, InstructionVector, filename);
					WaySize = 8;
					break;
				case 8:
					Process(CacheSize, BlockSize, WaySize, InstructionVector, filename);
					WaySize = 1;
					BlockSize = 16;
					break;
				}
				break;
			case 16:

				switch (WaySize)
				{
				case 1:
					Process(CacheSize, BlockSize, WaySize, InstructionVector, filename);
					WaySize = 2;
					break;
				case 2:
					Process(CacheSize, BlockSize, WaySize, InstructionVector, filename);
					WaySize = 4;
					break;
				case 4:
					Process(CacheSize, BlockSize, WaySize, InstructionVector, filename);
					WaySize = 8;
					break;
				case 8:
					Process(CacheSize, BlockSize, WaySize, InstructionVector, filename);
					WaySize = 1;
					BlockSize = 32;
					break;
				}
				break;
			case 32:

				switch (WaySize)
				{
				case 1:
					Process(CacheSize, BlockSize, WaySize, InstructionVector, filename);
					WaySize = 2;
					break;
				case 2:
					Process(CacheSize, BlockSize, WaySize, InstructionVector, filename);
					WaySize = 4;
					break;
				case 4:
					Process(CacheSize, BlockSize, WaySize, InstructionVector, filename);
					WaySize = 8;
					break;
				case 8:
					Process(CacheSize, BlockSize, WaySize, InstructionVector, filename);
					WaySize = 1;
					BlockSize = 128;
					break;
				}
				break;
			case 128:

				switch (WaySize)
				{
				case 1:
					Process(CacheSize, BlockSize, WaySize, InstructionVector, filename);
					WaySize = 2;
					break;
				case 2:
					Process(CacheSize, BlockSize, WaySize, InstructionVector, filename);
					WaySize = 4;
					break;
				case 4:
					Process(CacheSize, BlockSize, WaySize, InstructionVector, filename);
					WaySize = 8;
					break;
				case 8:
					Process(CacheSize, BlockSize, WaySize, InstructionVector, filename);
					WaySize = 1;
					BlockSize = 8;
					CacheSize = 131072;
					break;
				}
				break;
			}
			break;

		case 131072:

			switch (BlockSize)
			{
			case 8:

				switch (WaySize)
				{
				case 1:
					Process(CacheSize, BlockSize, WaySize, InstructionVector, filename);
					WaySize = 2;
					break;
				case 2:
					Process(CacheSize, BlockSize, WaySize, InstructionVector, filename);
					WaySize = 4;
					break;
				case 4:
					Process(CacheSize, BlockSize, WaySize, InstructionVector, filename);
					WaySize = 8;
					break;
				case 8:
					Process(CacheSize, BlockSize, WaySize, InstructionVector, filename);
					WaySize = 1;
					BlockSize = 16;
					break;
				}
				break;
			case 16:

				switch (WaySize)
				{
				case 1:
					Process(CacheSize, BlockSize, WaySize, InstructionVector, filename);
					WaySize = 2;
					break;
				case 2:
					Process(CacheSize, BlockSize, WaySize, InstructionVector, filename);
					WaySize = 4;
					break;
				case 4:
					Process(CacheSize, BlockSize, WaySize, InstructionVector, filename);
					WaySize = 8;
					break;
				case 8:
					Process(CacheSize, BlockSize, WaySize, InstructionVector, filename);
					WaySize = 1;
					BlockSize = 32;
					break;
				}
				break;
			case 32:

				switch (WaySize)
				{
				case 1:
					Process(CacheSize, BlockSize, WaySize, InstructionVector, filename);
					WaySize = 2;
					break;
				case 2:
					Process(CacheSize, BlockSize, WaySize, InstructionVector, filename);
					WaySize = 4;
					break;
				case 4:
					Process(CacheSize, BlockSize, WaySize, InstructionVector, filename);
					WaySize = 8;
					break;
				case 8:
					Process(CacheSize, BlockSize, WaySize, InstructionVector, filename);
					WaySize = 1;
					BlockSize = 128;
					break;
				}
				break;
			case 128:

				switch (WaySize)
				{
				case 1:
					Process(CacheSize, BlockSize, WaySize, InstructionVector, filename);
					WaySize = 2;
					break;
				case 2:
					Process(CacheSize, BlockSize, WaySize, InstructionVector, filename);
					WaySize = 4;
					break;
				case 4:
					Process(CacheSize, BlockSize, WaySize, InstructionVector, filename);
					WaySize = 8;
					break;
				case 8:
					Process(CacheSize, BlockSize, WaySize, InstructionVector, filename);
					WaySize = 1;
					BlockSize = 8;
					CacheSize = 1024;
					finished = true;
					break;
				}
				break;
			}
			break;
		}
	}
	return 0;
}

void Process(int CacheSize, int BlockSize, int WaySize, vector<Instruction> TempVector, string filename)
{
	vector<Instruction>::iterator it;
	Cache WT(CacheSize, BlockSize, WaySize);
	Cache WB(CacheSize, BlockSize, WaySize);
	int bytes_per_way = CacheSize / WaySize;
	int blocks_per_way = bytes_per_way / BlockSize;
	int instructioncount = 0;
	for (it = TempVector.begin(); it != TempVector.end(); it++)
	{
		instructioncount++;
		int tag = it->address / bytes_per_way;
		int index = int(it->address / BlockSize) % blocks_per_way;
		WT.addIndex(index);
		WB.addIndex(index);
		if (it->ins == "read")
		{
			WB.Read(index, tag);
			WT.Read(index, tag);
		}
		if (it->ins == "write")
		{
			WB.WriteBack(index, tag);
			WT.WriteThrough(index, tag);
		}
	}
	WB.CheckWriteBack();

	stringstream ss(filename);
	string prefilename;
	getline(ss, prefilename, '.');
	string postfilename = prefilename + ".result";
	fstream out(postfilename, ios::app);

	out << CacheSize << '\t' << BlockSize << '\t';
	if (WaySize == 1)
		out << "DM" << '\t';
	if (WaySize == 2)
		out << "2W" << '\t';
	if (WaySize == 4)
		out << "4W" << '\t';
	if (WaySize == 8)
		out << "FA" << '\t';
	out << "WB" << '\t' << fixed << setprecision(2) << (WB.getHitTime()) / (instructioncount) << '\t' << WB.getByte_M_C() << '\t' << WB.getByte_C_M()<< endl;
	out << CacheSize << '\t' << BlockSize << '\t';
	if (WaySize == 1)
		out << "DM" << '\t';
	if (WaySize == 2)
		out << "2W" << '\t';
	if (WaySize == 4)
		out << "4W" << '\t';
	if (WaySize == 8)
		out << "FA" << '\t';
	out << "WT" << '\t' << fixed << setprecision(2) << (WT.getHitTime()) / (instructioncount) << '\t' << WT.getByte_M_C() << '\t' << WT.getByte_C_M() << endl;

}

int ReadInstruction(vector<Instruction>&tempVector, const string filename)
{
	ifstream in(filename);
	tempVector.clear();
	int TepmInstructionCount = 0;
	string command;
	unsigned long int address;
	in >> command >> hex >> address;
	while (!in.fail())
	{
		TepmInstructionCount++;
		tempVector.push_back(Instruction(command, address));
		in >> command >> hex >> address;
	}
	return TepmInstructionCount;
}

