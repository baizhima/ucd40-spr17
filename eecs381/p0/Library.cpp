#include "Library.h"
#include "Record.h"
#include <iostream>
#include <exception>
#include <string>
#include <utility>
#include <fstream>

using std::cout;
using std::endl;


void Library::addRecord(const std::string& title, const std::string& medium) {
	Record rec(title, medium, nextId_);
	records_.insert(std::pair<std::string, Record>(title, rec));
	Record &recRef = getRecord(title);
	idRecordsMap_.insert(std::pair<int, Record &>(recRef.id_, recRef));
	cout << "Record " << nextId_++ << " added\n";
}

Record& Library::getRecord(int recordID)
{
	if (idRecordsMap_.find(recordID) == idRecordsMap_.end()) {
		throw std::runtime_error(std::string(__func__) + " id " + std::to_string(recordID) + " does not exist");
	}
	const auto& it = idRecordsMap_.find(recordID);
	return it->second;
}

Record& Library::getRecord(const std::string &title)
{
	if (records_.find(title) == records_.end()) {
		throw std::runtime_error(std::string(__func__) + " title " + title + " does not exist");
	}
	const auto& it = records_.find(title);
	return it->second;
}

void Library::deleteRecord(std::string& title) {
	Record& rec = records_.find(title)->second;
	int recordID = rec.id_;
	records_.erase(title);
	idRecordsMap_.erase(recordID);
	cout << "Record " << recordID << " " << title << " deleted" << endl;
}

void Library::clear() {
	idRecordsMap_.clear();
	records_.clear();
	nextId_ = 1;
}

std::istream & operator>>(std::istream &is, Library &lib)
{
	lib.clear();
	int cnt;
	is >> cnt;
	for (int i = 0; i < cnt; i++) {
		Record rec;
		is >> rec;
		lib.loadRecord(rec);
	}
	return is;
}

std::ostream & operator<<(std::ostream &os, const Library &lib)
{
	int cnt = lib.getNumOfRecords();
	if (cnt == 0) {
		os << "Library is empty"<< endl;
	} else {
		os << "Library contains " << cnt << " records:" << endl;
		for (auto &it: lib.records_) {
			os << it.second;
		}
	}
	return os;
}

std::ofstream & operator<<(std::ofstream &ofs, const Library &lib)
{
	ofs << lib.getNumOfRecords() << "\n";
	for (auto& it: lib.records_) {
		ofs << it.second;
	}
	return ofs;
}

void Library::loadRecord(Record &rec)
{
	std::string title = rec.getTitle();
	records_.insert(std::pair<std::string, Record>(title, rec));

	Record &recRef = getRecord(title);
	idRecordsMap_.insert(std::pair<int, Record &>(recRef.id_, recRef));
	nextId_ = (nextId_ > rec.id_ )? nextId_: rec.id_ + 1;
}