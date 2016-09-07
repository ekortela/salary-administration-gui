# SALARY ADMINISTRATION GUI
Graphical User Interface that allows user to save and administer personnel salaries with easy and understandable user interface.

# Authors
Aapo Keskimolo      aapokesk@gmail.com          Software design, Unit testing, MVC architecture, Back-end
Elisa Kortela       elisa.kortela@gmail.com     Graphical User Interface, Front-end

# RUN INSTRUCTIONS
- Run SalaryAdministrationGui.exe

# BUILD INSTRUCTIONS
1. Install Git, add it to environment variables and run 
	git clone https://github.com/ekortela/salary-administration-gui.git <destination directory>
2. Install Qt 5.6.1 Desktop from QT-company website (offline-installer with MinGW-MSVC2015 is preferred)
3. Run qmake in project root directory with .pro- file
4. Goto project -> Release run configurations -> Change Build Directory: to the directory as in step 3
5. Run Release
* For Debug, you may repeat steps 4-5 with Debug configuration (run-time logs are saved in target build directory)

# DEVELOPMENT TOOLS
- MINGW GCC version 4.9.3 (C++11)
- QT Creator 5.6.1 Desktop (MSVC2013-32bit / MSVC2015-64bit)
- CMake 3.6.1