#ifndef EMPLOYEEFACTORYEXCEPTION_H
#define EMPLOYEEFACTORYEXCEPTION_H

#include <exception>

namespace ef {

    class EmployeeFactoryException : public std::exception
    {
        const std::string m_reason;

    public:

        EmployeeFactoryException(const std::string &r) throw() :
            m_reason(r) { }

        virtual const char* what() const throw()
        {
            return m_reason.c_str();
        }

    };

    class TypeInvalidException : public EmployeeFactoryException
    {
    public:

        TypeInvalidException(const std::string &reason) :
            EmployeeFactoryException(reason) { }

    };

}

#endif // EMPLOYEEFACTORYEXCEPTION_H
