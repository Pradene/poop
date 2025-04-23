#ifndef EMPLOYEEMANAGEMENT_HPP
#define EMPLOYEEMANAGEMENT_HPP

#include "Employee.hpp"

class EmployeeManager {
private:
    std::vector<Employee *> _employees;

public:
    void addEmployee() {}
    void removeEmployee(Employee *employee) {}
    void executeWorkday() {}
    void calculatePayroll() {}
}

#endif // EMPLOYEEMANAGEMENT_HPP