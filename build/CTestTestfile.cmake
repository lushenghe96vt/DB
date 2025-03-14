# CMake generated Testfile for 
# Source directory: C:/Users/Bobby Lu/Documents/School/Undergraduate/Junior_Year/Academics/Spring/ECE 3574/DB
# Build directory: C:/Users/Bobby Lu/Documents/School/Undergraduate/Junior_Year/Academics/Spring/ECE 3574/DB/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if(CTEST_CONFIGURATION_TYPE MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(my_test "C:/Users/Bobby Lu/Documents/School/Undergraduate/Junior_Year/Academics/Spring/ECE 3574/DB/build/Debug/my_test.exe")
  set_tests_properties(my_test PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/Bobby Lu/Documents/School/Undergraduate/Junior_Year/Academics/Spring/ECE 3574/DB/CMakeLists.txt;56;add_test;C:/Users/Bobby Lu/Documents/School/Undergraduate/Junior_Year/Academics/Spring/ECE 3574/DB/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(my_test "C:/Users/Bobby Lu/Documents/School/Undergraduate/Junior_Year/Academics/Spring/ECE 3574/DB/build/Release/my_test.exe")
  set_tests_properties(my_test PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/Bobby Lu/Documents/School/Undergraduate/Junior_Year/Academics/Spring/ECE 3574/DB/CMakeLists.txt;56;add_test;C:/Users/Bobby Lu/Documents/School/Undergraduate/Junior_Year/Academics/Spring/ECE 3574/DB/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(my_test "C:/Users/Bobby Lu/Documents/School/Undergraduate/Junior_Year/Academics/Spring/ECE 3574/DB/build/MinSizeRel/my_test.exe")
  set_tests_properties(my_test PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/Bobby Lu/Documents/School/Undergraduate/Junior_Year/Academics/Spring/ECE 3574/DB/CMakeLists.txt;56;add_test;C:/Users/Bobby Lu/Documents/School/Undergraduate/Junior_Year/Academics/Spring/ECE 3574/DB/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(my_test "C:/Users/Bobby Lu/Documents/School/Undergraduate/Junior_Year/Academics/Spring/ECE 3574/DB/build/RelWithDebInfo/my_test.exe")
  set_tests_properties(my_test PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/Bobby Lu/Documents/School/Undergraduate/Junior_Year/Academics/Spring/ECE 3574/DB/CMakeLists.txt;56;add_test;C:/Users/Bobby Lu/Documents/School/Undergraduate/Junior_Year/Academics/Spring/ECE 3574/DB/CMakeLists.txt;0;")
else()
  add_test(my_test NOT_AVAILABLE)
endif()
