#ifndef LIBRARY_H
#define LIBRARY_H

#include <map>
#include "Record.h"

class Library {

public:
	Library(): nextId_(1) {}
	void addRecord(const std::string& title, const std::string& medium);
	void loadRecord(Record& rec);
	void deleteRecord(std::string &title);

	Record& getRecord(int id);
	Record& getRecord(const std::string &title);

	void clear();

	bool contains(int id) 			  const { return idRecordsMap_.find(id) != idRecordsMap_.end(); }
	bool contains(std::string& title) const { return records_.find(title) != records_.end(); }

	int getNumOfRecords() const { return records_.size(); }

	friend std::istream & operator>>(std::istream&, Library &);
	friend std::ostream & operator<<(std::ostream&, const Library &);
	friend std::ofstream & operator<<(std::ofstream&, const Library &);

private:
	std::map<std::string, Record> records_;
	std::map<int, Record &> idRecordsMap_;

	int nextId_;
};

#endif