# SALARY ADMINISTRATION GUI
Graphical User Interface that allows user to save and administer personnel salaries with easy and understandable user interface.

# TOOLS USED FOR THE DEVELOPMENT
- MINGW GCC version 4.9.3 (with C++11 standard library)
- QT Creator 5.6.1 Desktop (MSVC2013-32bit / MSVC2015-64bit)
- CMake 3.6.1

# MINIMAL REQUIREMENTS
- GCC
- Cmake
- Qt 5.6.1 (MSVC2015-64bit)

# SOFTWARE DESCRIPTION
PERSONNELL MANAGEMENT APPLICATION

Your task is to design and implement a company personnel management
application. Design your application so that the UI part can be replaced easily. You
should make a simple graphical user interface without graphical user interface builders. 

User interface should contain only basic functionality to set and get relevant information 
(see tables below). You should also make a simple information structure, where employees can 
be added and stored. In the following section there is a description of the employee 
information that your application should be able to contain.

The company has different kinds of workers. The following table tells you what kind
of information you should save of each worker so that you would then be able to
print out all this information of all the saved workers at the same time (e.g. in the
form of a list).

Monthly paid employee 			Hourly paid employee 			Salesman
Name                            Name                            Name
Social security number          Social security number 			Social security number
Monthly compensation            Hourly Compensation 			Monthly compensation
                                Done hours                      Bonus % 
                                                                Realized outcome
                                                                Outcome claim

The workers clearly differ from each other in the salary formation.

Employee                        Salary Formation
Monthly paid employee           Monthly compensation
Hourly paid employee            Done hours*hourly compensation
Salesman                        Monthly compensation raised by the bonus % if the 
                                outcome claim comes true

Based on this information you should make a class hierarchy or a data structures
for your company personnel management application. If you include extra
functionality in your application you should document them also.
You can fill up all relevant information that is missing with reasonable assumption.

# BUILD INSTRUCTIONS
- tbd


- TODO MOVED TO TODO.TXT
