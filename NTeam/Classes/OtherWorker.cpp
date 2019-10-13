#include <iostream>
#include <string>

#include "Staff.h"
#include "OtherWorker.h"

using namespace std;

OtherWorker::OtherWorker(string r, string n, Date d, int sal): Staff (r, n, d, sal) {}


//int OtherWorker::info(ostream &o) const
////{
////    o << "Other Worker" << endl;
////    int infoS = Staff::info();
////    o << endl;
////    return infoS;
////}
////
////int OtherWorker::info() const {
////    return OtherWorker::info(cout);
////}
