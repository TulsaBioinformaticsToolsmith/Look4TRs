/*
 * Util.h
 *
 *  Created on: Apr 24, 2012
 *      Author: Hani Zakaria Girgis, PhD
 */

#ifndef UTIL_H_
#define UTIL_H_

#include "Location.h"
#include "../exception/FileDoesNotExistException.h"
#include "../exception/InvalidInputException.h"

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iterator>
#include <stdlib.h>
#include <dirent.h>
#include <thread>
#include <sys/types.h>
#include <sys/stat.h>

using namespace std;
using namespace utility;
using namespace exception;
#include "RegionList.h"

namespace utility {
	class Util {
	private:
		Util();
		~Util();

	public:
		static string * emptyString;
		static string fileSeparator;
		static unsigned int CORE_NUM;
		static void readFasta(string, vector<string> *, vector<string> *, bool);
		static void readFasta(string, vector<string> *, vector<string> *);
		static vector<string> tokenize(std::string, char);
		static void readCoordinates(string,
			unordered_map<std::string, vector<Location *> *> *);
		static void readCoordinates(string,
			unordered_map<std::string, deque<Location *> *> *);
		static void readCoordinates(string, vector<Location *> *);
		static void readCoordinates(string, vector<ILocation *> *);
		static void readCoordinates(string, RegionList *);
		static void readChromList(string, vector<string> *, string);
		static void toUpperCase(string*);
		static void toUpperCase(string&);
		static string int2string(int);
		static string double2string(double);
		static string long2string(long);
		static void deleteFile(string);
		static void deleteFilesUnderDirectory(string);
		static void checkFile(string);
		static void checkDir(string);
		static void mkDir(string);
		static bool isOverlapping(int, int, int, int);
		static bool isOverlapping(const ILocation * a, const ILocation * b);
		static bool merge(utility::ILocation*, utility::ILocation*);
		static void merge(std::vector<Location *> *, int gapLen = 0);
		static void merge(std::vector<ILocation *> *, int gapLen = 0);
		static void revCompDig(string *, string *);
		static void revCompDig(const char* sequence, int, int, string *);
		static std::string oneDigitToNuc(const std::string&);
		static std::vector<Location *> * locationIntersect(const std::vector<ILocation *> *, 
			const std::vector<ILocation *> *);
		static std::vector<Location *> * locationIntersect(const std::vector<Location *> *, 
			const std::vector<Location *> *);
		static std::vector<Location *> * wholeLocationSubtract(const std::vector<ILocation *>  *, 
			const std::vector<ILocation *> *);
		static std::vector<Location *> * locationSubtract(const std::vector<ILocation *>  *, 
			const std::vector<ILocation *> *);

		static void writeFasta(const string&, const string&, const string&);

		static int sumTotalLength(const vector<ILocation *> *);
		static int sumTotalLength(const vector<Location *> *);
		static string getLargestFile(const string&);

	/**
	 * Delete the objects pointed to by pointers in a vector.
	 * It does not delete the vector itself.
	 *
	 * Credit: http://stackoverflow.com/questions/594089/does-stdvector-clear-do-delete-free-memory-on-each-element
	 */
	template<class T>
		static void deleteInVector(vector<T*> * deleteMe) {
			while (!deleteMe->empty()) {
				delete deleteMe->back();
				deleteMe->pop_back();
			}

		// Set the size to zero
			deleteMe->clear();

		// Set the capacity to zero
			vector<T*> empty;
			deleteMe->swap(empty);
		}
	};
}

template <typename T>
std::ostream& operator<< (std::ostream& out, const std::vector<T>& v) {
	if ( !v.empty() ) {
		out << '[';
		std::copy (v.begin(), v.end(), std::ostream_iterator<T>(out, ", "));
		out << "\b\b]";
	}
	return out;
}


#endif /* UTIL_H_ */
