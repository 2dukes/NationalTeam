#include <iostream>
#include <string>

#include "Staff.h"
#include "OtherWorker.h"
#include <fstream>

using namespace std;

OtherWorker::OtherWorker(unsigned int id, string role, string name, Date birth, int sal): Staff (id, role, name, birth)
{
    salary = sal;
}

int OtherWorker::getSalary()
{
    return salary;
}

void OtherWorker::info(ostream &os) const
{
    Staff::info(os);
    os << "Salary: " << salary << "\n";
}

