#include "Collection.h"
#include <algorithm>
#include <vector>
#include <iostream>
#include <fstream>
using std::cout;
using std::endl;

bool Collection::contains(int recordID) const
{
	for (auto& it: records_) {
		if (it.second.getId() == recordID) {
			return true;
		}
	}
	return false;
}




std::ostream & operator<<(std::ostream &os, const Collection &col)
{
	os << "Collection " << col.name_ << " contains:";
	int cnt = col.getNumOfRecords();
	if (cnt == 0) {
		os << " None\n";
	} else {
		os << "\n";
		for (auto &it: col.records_) {
			os << it.second;
		}
	}
	return os;
}

std::ofstream & operator<<(std::ofstream &ofs, const Collection &col)
{
	ofs << col.name_ << " " << col.getNumOfRecords() << "\n";
	for (auto& it: col.records_) {
		ofs << it.first << endl;
	}

	return ofs;
}