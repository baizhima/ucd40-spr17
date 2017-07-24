#ifndef CATALOG_H
#define CATALOG_H

#include "Collection.h"
#include "Library.h"
#include "Record.h"

#include <map>

class Catalog
{
public:
	Catalog(Library *lib): lib_(lib) {}
	void addCollection(std::string&  name);
	void deleteCollection(std::string& name);

	void clear();

	Collection & getCollection(std::string& name);

	bool hasRecordReferred() const;
	
	bool contains(std::string &name) 			const { return collections_.find(name) != collections_.end(); }
	bool recordIsReferred(int recordID)		 	const ;
	int getNumOfCollections() 		 			const { return collections_.size(); }

	friend std::istream & operator>>(std::istream&, Catalog &);
	friend std::ostream & operator<<(std::ostream&, const Catalog &);
	friend std::ofstream & operator<<(std::ofstream&, const Catalog &);

private:
	Library *lib_;
	std::map<std::string, Collection> collections_;
	
};

#endif