#include "Record.h"
#include <iostream>
#include <fstream>
#include <string>

using std::endl;



std::istream & operator>>(std::istream &is, Record &rec)
{
	is >> rec.id_;
	if (is.fail()) {
		return is;
	}
	is >> rec.medium_;
	is >> rec.rating_;
	if (is.fail()) {
		return is;
	}
	std::string line;
	std::getline(is, line);
	rec.title_ = line.substr(1);
	return is;

}

std::ostream & operator<<(std::ostream &os, const Record &rec)
{
	os  << rec.id_ << ": " 
		<< rec.medium_ << " "
		<< ((rec.rating_ == 0) ? "u" : std::to_string(rec.rating_));
	 os << " "
		<< rec.title_ << endl;
	return os;
}

std::ofstream & operator<<(std::ofstream &ofs, const Record &rec)
{
	
	ofs  << rec.id_ << " " 
		<< rec.medium_ << " "
		<< rec.rating_ << " "
		<< rec.title_ << endl;
	return ofs;
}