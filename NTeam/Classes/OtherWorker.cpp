#include <iostream>
#include <string>

#include "Staff.h"
#include "OtherWorker.h"
#include <fstream>

using namespace std;

OtherWorker::OtherWorker(unsigned int id, string role, string name, Date birth, float sal): Staff (id, role, name, birth)
{
    salary = sal;
}

/* Gets */

float OtherWorker::getSalary() const
{
    return salary;
}

/* Sets */

void OtherWorker::setSalary(float salary) {
    this->salary = salary;
}


/* OtherMethods */

void OtherWorker::info(ostream &os) const
{
    Staff::info(os);
    os << "Salary: " << salary << "\n";
}

bool OtherWorker::operator==(const OtherWorker &oW) const {
    return id == oW.getId();
}
