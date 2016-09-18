//============================================================================
// Name        : EmployeeControllerException.h
// Author      : Aapo Keskimolo
// Description : Contains user defined exceptions for EmployeeController class
//============================================================================

#ifndef EMPLOYEECONTROLLEREXCEPTION_H
#define EMPLOYEECONTROLLEREXCEPTION_H

#include <exception>


namespace ec {

    class EmployeeControllerException : public std::exception
    {
        const std::string m_reason;

    public:

        EmployeeControllerException(const std::string &r) throw() :
            m_reason(r) { }

        virtual const char* what() const throw()
        {
            return m_reason.c_str();
        }

    };

    class SsnDoesNotExistException : public EmployeeControllerException
    {
    public:

        SsnDoesNotExistException(const std::string &reason) :
            EmployeeControllerException(reason) { }

    };

    class EmployeeTypeInvalidException : public EmployeeControllerException
    {
    public:

        EmployeeTypeInvalidException(const std::string &reason) :
            EmployeeControllerException(reason) { }

    };

    class EmployeeAlreadyExistsException : public EmployeeControllerException
    {
    public:

        EmployeeAlreadyExistsException(const std::string &reason) :
            EmployeeControllerException(reason) { }

    };

    class NullPointerException : public EmployeeControllerException
    {
    public:

        NullPointerException(const std::string &reason) :
            EmployeeControllerException(reason) { }

    };

    class InvalidModelData : public EmployeeControllerException
    {
    public:

        InvalidModelData(const std::string &reason) :
            EmployeeControllerException(reason) { }

    };
}

#endif // EMPLOYEECONTROLLEREXCEPTION_H
