#include "Catalog.h"
#include <exception>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

void Catalog::addCollection(std::string& name)
{
	Collection col(name);
	collections_.insert(std::pair<std::string, Collection>(name,col));
	
}

void Catalog::deleteCollection(std::string& name)
{
	collections_.erase(name);
}

Collection & Catalog::getCollection(std::string& name)
{
	if (not contains(name)) {
		throw std::runtime_error(std::string(__func__) + " collection " + name + "does not exist");
	}
	const auto& it = collections_.find(name);
	return it->second;
}

void Catalog::clear()
{
	collections_.clear();
}

bool Catalog::recordIsReferred(int recordID) const
{
	for (auto &it: collections_) {
		if (it.second.contains(recordID)) {
			return true;
		}
	}
	return false;
}

bool Catalog::hasRecordReferred() const
{
	for (auto &it: collections_) {
		if (it.second.getNumOfRecords() != 0) {
			return true;
		}
	}
	return false;
}

std::istream & operator>>(std::istream& is, Catalog &cat)
{
	cat.clear();
	int cnt;
	is >> cnt;
	if (is.fail()) {
		return is;
	}
	for (int i = 0; i < cnt; i++) {
		std::string name;
		int numRecs;
		is >> name >> numRecs;
		if (is.fail()) {
			return is;
		}
		is.get(); // '\n'
		cat.addCollection(name);
		Collection &col = cat.getCollection(name);
		for (int j = 0; j < numRecs; j++) {
			std::string title;
			std::getline(is, title);

			Record& rec = cat.lib_->getRecord(title);
			col.addMember(rec);
		}
		
	}
	return is;

}


std::ostream & operator<<(std::ostream& os, const Catalog &cat)
{
	int cnt = cat.getNumOfCollections();
	if (cnt == 0) {
		os << "Catalog is empty" << std::endl;
	} else {
		os << "Catalog contains " << cnt << " collections:" << std::endl;
		for (auto &it: cat.collections_) {
			os << it.second;
		}
	}
	return os;
}

std::ofstream & operator<<(std::ofstream &ofs, const Catalog &cat)
{
	ofs << cat.getNumOfCollections() << "\n";
	
	for (auto &s: cat.collections_) {
		ofs << s.second;;
	}

	return ofs;
}