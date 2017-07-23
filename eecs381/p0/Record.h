#ifndef RECORD_H
#define RECORD_H

#include <string>

class Record {
public:
	Record(const std::string& title, const std::string& medium, int id): title_(title), medium_(medium), id_(id), rating_(0) {}
	//Record(int id, std::string& medium, int rating, std::string title): title_(title), medium_(medium), id_(id), rating_(rating) {}
	Record():title_(""), medium_(""), id_(-1), rating_(-1){};
	friend class Collection;
	friend class Library;

	void modifyRating(int rating) { rating_ = rating; }

	int getId() const { return id_; }
	std::string getTitle() const { return title_; }
	friend std::istream & operator>>(std::istream&, Record &);
	friend std::ostream & operator<<(std::ostream&, const Record &);	// for regular cout
	friend std::ofstream & operator<<(std::ofstream&, const Record &);  // for cmd_sA

private:
	std::string title_;
	std::string medium_;
	int id_;
	int rating_;
	
};

#endif