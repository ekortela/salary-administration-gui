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
1. Install Git and run git clone https://github.com/ekortela/salary-administration-gui.git
2. Install Qt 5.6+ from QT-company website
3. Start QtCreator -> Open SalaryAdministrationGui.pro
4. Goto Projects -> Build & Run configurations -> Change "Build Directory" to root directory from Step 1
5. Build & Run project

# TROUBLESHOOTING
- Run-time .log is generated in the target executable directory containing debug messages
- In case Linux libraries are missing (Ubuntu):
    LD_LIBRARY_PATH=/usr/local/lib64/:$LD_LIBRARY_PATH
    export LD_LIBRARY_PATH
    sudo add-apt-repository ppa:ubuntu-toolchain-r/test
    sudo apt-get update
    sudo apt-get install gcc-4.9 g++-4.9