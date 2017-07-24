#include <iostream>
#include <fstream>
#include <regex>
#include <string>


#include "Record.h"
#include "Collection.h"
#include "Catalog.h"
#include "Library.h"

#define FUNC_TO_DO cout << std::string(__func__) << " not impl" << endl;

using std::cout;
using std::endl;

inline bool getInt(std::istream &is, int &res)
{
	is >> res;
	if (is.fail()) {
		is.clear();
		is.ignore(INT_MAX, '\n');
		cout << "Could not read an integer value!" << endl;
		return false;
	}
	return true;
	
}

inline bool getTitle(std::istream &is, std::string &res)
{
	std::getline(is, res);
	res = std::regex_replace(res, std::regex("^ +| +$"), "");
	res = std::regex_replace(res, std::regex("( ) +"), "$1");
	if (res.size() == 0)
	{
		is.clear();
		is.ignore(INT_MAX, '\n');
		cout << "Could not read a title!" << endl;
		return false;
	}
	return true;
}

// find record
void cmd_fr(std::istream& is, Library &lib)
{
	std::string title;
	if (not getTitle(is, title)) {
		return;
	}
	if (not lib.contains(title)) {
		cout << "No record with that title!" << endl;
		return;
	}
	Record& rec = lib.getRecord(title);
	cout << rec;
}

// print record
void cmd_pr(std::istream& is, Library &lib)
{
	int recordID;
	if (not getInt(is, recordID)) {
		return;
	}
	if (not lib.contains(recordID)) {
		cout << "No record with that ID!" << endl;
		return;
	}
	Record& rec = lib.getRecord(recordID);
	cout << rec;
}

// print collection
void cmd_pc(std::istream &is, Catalog &cat)
{
	std::string name;
	is >> name;

	if (not cat.contains(name)) {
		cout << "No collection with that name!" << endl;
		return;
	}
	Collection& col = cat.getCollection(name);
	cout << col;
}

// print Library
void cmd_pL(Library &lib)
{

	cout << lib;
}

// print Catalog
void cmd_pC(Catalog &cat)
{
	cout << cat;
}

// print memory allocation
void cmd_pa(Library &lib, Catalog &cat)
{
	cout << "Memory allocations:" << "\n"
	 	<< "Records: " << lib.getNumOfRecords() << "\n"
		<< "Collections: " << cat.getNumOfCollections() << endl;
}

// add a record to the library
void cmd_ar(std::istream &is, Library &lib)
{
	std::string medium, title;
	is >> medium;
	if (not getTitle(is, title)) {
		return;
	}
	if (lib.contains(title)) {
		cout << "Library already has a record with this title!" << endl;
		return;
	}
	lib.addRecord(title, medium);
}

// add a collection with name
void cmd_ac(std::istream& is, Catalog& cat)
{
	std::string name;
	is >> name;
	if (cat.contains(name)) {
		cout << "Catalog already has a collection with this name!" << endl;
		return;
	}
	cat.addCollection(name);
	cout << "Collection " << name << " added" << endl;
}

// add record as member to a collection
void cmd_am(std::istream& is, Library &lib, Catalog &cat)
{
	std::string name;
	int recordID;

	is >> name;
	if (not getInt(is, recordID)) {
		return;
	}
	if (not cat.contains(name)) {
		cout << "No record with that ID!" << endl;
		return;
	}
	if (not lib.contains(recordID)) {
		cout << "Record is already a member in the collection!" << endl;
		return;
	}
	Record& rec = lib.getRecord(recordID);
	Collection& col = cat.getCollection(name);
	if (col.contains(recordID)) {
		cout << "Record is already a member in the collection!" << endl;
		return;
	}

	col.addMember(rec);
	cout << "Member " << rec.getId() << " " << rec.getTitle() << " added" << endl;

}

// modify rating
void cmd_mr(std::istream &is, Library &lib)
{
	int recordID, rating;
	if (not getInt(is, recordID)) {
		return;
	}
	if (not getInt(is, rating)) {
		return;
	}
	if (rating < 1 || rating > 5) {
		cout << "Rating is out of range!" << endl;
		return;
	}
	if (not lib.contains(recordID)) {
		cout << "Record is already a member in the collection!" << endl;
		return;
	}
	Record &rec = lib.getRecord(recordID);
	rec.modifyRating(rating);
	cout << "Rating for record " << recordID << " changed to " << rating << endl; 
}

// delete record
void cmd_dr(std::istream &is, Library &lib, Catalog &cat)
{
	std::string title;
	if (not getTitle(is, title)) {
		return;
	}

	if (not lib.contains(title)) {
		
		cout << "No record with that title!" << endl;
		return;
	}

	Record& rec = lib.getRecord(title);

	if (cat.recordIsReferred(rec.getId())) {
		cout << "Cannot delete a record that is a member of a collection!" << endl;
		return;
	}

	lib.deleteRecord(title);
}

// delete collection
void cmd_dc(std::istream &is, Catalog &cat)
{
	std::string name;
	is >> name;

	if (not cat.contains(name)) {
		cout << "No collection with that name!" << endl;
		return;
	}

	cat.deleteCollection(name);
	cout << "Collection " << name << " deleted" << endl;
}

void cmd_dm(std::istream &is, Library &lib, Catalog &cat)
{
	std::string name;
	int recordID;
	is >> name;

	if (not getInt(is, recordID)) {
		return;
	}

	if (not lib.contains(recordID)) {
		cout << "No record with that ID!" << endl;
		return;
	}

	if (not cat.contains(name)) {
		cout << "Record is not a member in the collection!" << endl;
		return;
	}
	Record& rec = lib.getRecord(recordID);
	Collection& col = cat.getCollection(name);
	if (not col.contains(name)) {
		cout << "Record is not a member in the collection!" << endl;
		return;
	}
	std::string title = rec.getTitle();
	col.deleteMember(title);

	cout << "Member " << recordID << " " << title << " deleted" << endl;
}

void cmd_cL(Library &lib, Catalog &cat)
{

	if (cat.hasRecordReferred()) {
		cout << "Cannot clear all records unless all collections are empty!" << endl;
		return;
	}
	lib.clear();
	cout << "All records deleted" << endl;
}

void cmd_cC(Catalog &cat)
{
	cat.clear();
	cout << "All collections deleted" << endl;
}

void cmd_cA(Library &lib, Catalog &cat)
{
	cat.clear();
	lib.clear();
	cout << "All data deleted" << endl;
}

void cmd_sA(std::istream& is, Library &lib, Catalog &cat)
{
	std::string filename;
	is >> filename;
	std::ofstream ofs(filename);
	if (not ofs.is_open()) {
		is.clear();
		is.ignore(INT_MAX, '\n');
		cout << "Could not open file!" << endl;
		return;
	}
	ofs << lib;
	ofs << cat;
	ofs.close();
	cout << "Data saved" << endl;
}

void cmd_rA(std::istream& is, Library &lib, Catalog &cat)
{
	std::string filename;
	is >> filename;
	std::ifstream ifs(filename);
	if (not ifs.is_open()) {
		cout << "Could not open file!" << endl;
		is.clear();
		is.ignore(INT_MAX, '\n');
		return;
	}
	ifs >> lib;
	if (ifs.fail()) {
		cout << "Invalid data found in file!" << endl;
		return;
	}
	ifs >> cat;
	if (ifs.fail()) {
		cout << "Invalid data found in file!" << endl;
		return;
	}
	ifs.close();
	cout << "Data loaded" << endl;
}

int main()
{
	Library library;
	Catalog catalog(&library);
	std::string cmd;

	while (true)
	{
		cout << "\nEnter command: ";
		std::cin >> cmd;
		if (cmd == "fr") {
			cmd_fr(std::cin, library);
		} else if (cmd == "cA") {
			cmd_cA(library, catalog);
		} else if (cmd == "cC") {
			cmd_cC(catalog);
		} else if (cmd == "cL") {
			cmd_cL(library, catalog);
		} else if (cmd == "dr") {
			cmd_dr(std::cin, library, catalog);
		} else if (cmd == "dc") {
			cmd_dc(std::cin, catalog);
		} else if (cmd == "dm") {
			cmd_dm(std::cin, library, catalog);
		} else if (cmd == "pa") {
			cmd_pa(library, catalog);
		} else if (cmd == "pL") {
			cmd_pL(library);
		} else if (cmd == "pC") {
			cmd_pC(catalog);
		} else if (cmd == "pc") {
			cmd_pc(std::cin, catalog);
		} else if (cmd == "pr") {
			cmd_pr(std::cin, library);
		} else if (cmd == "ar") {
			cmd_ar(std::cin, library);
		} else if (cmd == "am") {
			cmd_am(std::cin, library, catalog);
		} else if (cmd == "ac") {
			cmd_ac(std::cin, catalog);
		} else if (cmd == "mr") {
			cmd_mr(std::cin, library);
		} else if (cmd == "sA") {
			cmd_sA(std::cin, library, catalog);
		} else if (cmd == "rA") {
			cmd_rA(std::cin, library, catalog);
		}
		else if (cmd == "qq") {
			cmd_cA(library, catalog);
			cout << "Done" << endl;
			break;
		}
		 else {
		 	
			std::cin.ignore(INT_MAX, '\n');
			cout << "Unrecognized command!" << endl;
		}
	}


}