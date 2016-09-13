# SALARY ADMINISTRATION GUI
Graphical User Interface that allows user to save and administer personnel salaries with easy and understandable user interface.

# Authors
Aapo Keskimolo      aapokesk@gmail.com          Software design, Unit testing, MVC architecture, Back-end
Elisa Kortela       elisa.kortela@gmail.com     Graphical User Interface, Front-end

# PLATFORM SUPPORT
- Linux 64bit Debian/Ubuntu
- Windows XP/7/10 32bit/64bit

# RUN INSTRUCTIONS
Windows(32/64bit): Run static/SalaryAdministrationGui.exe
Linux(64bit): Run static/SalaryAdministrationGui

# TOOLS USER FOR DEVELOPMENT
- MINGW GCC version 4.9.3 (C++11)
- QT Creator 5.6.1 Desktop (MSVC2013-64bit / MinGW 32/64bit)
- CMake 3.6.1
- Windows 32bit/64bit, Linux (Debian Jessie)

# BUILD INSTRUCTIONS
1. Install Git, add it to environment variables and run 
	git clone https://github.com/ekortela/salary-administration-gui.git <destination directory>
2. Install Qt 5.6.1 Desktop from QT-company website (offline-installer with MinGW-MSVC2015 is preferred)
3. Run qmake in project root directory with .pro- file
4. Goto project -> Release run configurations -> Change Build Directory: to the directory as in step 3
5. Run Release
* For Debug, you may repeat steps 4-5 with Debug configuration (run-time logs are saved in target build directory)

# TROUBLESHOOTING
- Run-time .log is generated in the target executable directory containing debug messages
- In case Linux libraries are missing (Ubuntu):
    LD_LIBRARY_PATH=/usr/local/lib64/:$LD_LIBRARY_PATH
    export LD_LIBRARY_PATH
    sudo add-apt-repository ppa:ubuntu-toolchain-r/test
    sudo apt-get update
    sudo apt-get install gcc-4.9 g++-4.9