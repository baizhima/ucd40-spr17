#ifndef COLLECTION_H
#define COLLECTION_H

#include "Record.h"

#include <map>

class Collection {
public:
	Collection(std::string& name): name_(name) {}

	void addMember(Record &rec)     		{ records_.insert(std::pair<std::string, Record &>(rec.title_, rec)); }

	void deleteMember(std::string& title) 	{ records_.erase(title); }
	void clear() 							{ records_.clear(); }

	bool contains(int recordID) const;
	bool contains(std::string& title) const { return records_.find(title) != records_.end(); }
	int getNumOfRecords()			  const { return records_.size(); }

	
	friend std::ostream & operator<<(std::ostream&, const Collection &);
	friend std::ofstream & operator<<(std::ofstream&, const Collection &);

private:
	std::string 					name_;
	std::map<std::string, Record &> records_;	
};


#endif