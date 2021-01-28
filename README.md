[![Work in Repl.it](https://classroom.github.com/assets/work-in-replit-14baed9a392b3a25080506f3b7b6d57f295ec2978f6f33ec97e36a161684cbe9.svg)](https://classroom.github.com/online_ide?assignment_repo_id=3990709&assignment_repo_type=AssignmentRepo)
# acc-cosc-1337-starter
C++ starter code with CMake 
# If you use the Replit C++ Compiler, open the .replit file and add the following command below the language="cpp" line.
run="export CC=clang; export CXX=clang++; mkdir -p ../build; cd ../build; cmake ../acc-cosc-1337-spring-2021-yourusername/; make; cd src/examples/01_module/01_hello_world; ./ex_01_01_exe" 
The above-listed run command runs the Hello World Example in the src/examples/01_module.

# Replit file HOW-TO
The src folder contains different C++ programs - examples, assignments, and homeworks.
To run different programs, update the last two statements in the run= command, in this case they are:
cd src/examples/01_module/01_hello_world; <-- this statement tells the operating system to change to the 01_module folder
./ex_01_01_exe  <--- in the 01_module folder find the CMakeLists.txt file find the add_executable command and you'll find the name ex_01_01_exe.

To run other programs determine which folder example or homework to run and follow the procedure above to modify the run command.

