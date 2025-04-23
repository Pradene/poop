#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP

class Employee {
private:
    int _hourlyValue;

public:
    int executeWorkday() {}
}

class TempEmployee: public Employee {
public:
    int executeWorkday() {}
}

class ContractEmployee: public Employee {
public:
    int executeWorkday() {}
}

class Apprentice: public Employee {
public:
    int executeWorkday() {}
}    

#endif // EMPLOYEE_HPP