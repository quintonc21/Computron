# CMake generated Testfile for 
# Source directory: C:/Users/Admin/OneDrive/Documents/VSCode/Computron
# Build directory: C:/Users/Admin/OneDrive/Documents/VSCode/Computron/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if(CTEST_CONFIGURATION_TYPE MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(my_test "C:/Users/Admin/OneDrive/Documents/VSCode/Computron/build/Debug/my_test.exe")
  set_tests_properties(my_test PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/Admin/OneDrive/Documents/VSCode/Computron/CMakeLists.txt;21;add_test;C:/Users/Admin/OneDrive/Documents/VSCode/Computron/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(my_test "C:/Users/Admin/OneDrive/Documents/VSCode/Computron/build/Release/my_test.exe")
  set_tests_properties(my_test PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/Admin/OneDrive/Documents/VSCode/Computron/CMakeLists.txt;21;add_test;C:/Users/Admin/OneDrive/Documents/VSCode/Computron/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(my_test "C:/Users/Admin/OneDrive/Documents/VSCode/Computron/build/MinSizeRel/my_test.exe")
  set_tests_properties(my_test PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/Admin/OneDrive/Documents/VSCode/Computron/CMakeLists.txt;21;add_test;C:/Users/Admin/OneDrive/Documents/VSCode/Computron/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(my_test "C:/Users/Admin/OneDrive/Documents/VSCode/Computron/build/RelWithDebInfo/my_test.exe")
  set_tests_properties(my_test PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/Admin/OneDrive/Documents/VSCode/Computron/CMakeLists.txt;21;add_test;C:/Users/Admin/OneDrive/Documents/VSCode/Computron/CMakeLists.txt;0;")
else()
  add_test(my_test NOT_AVAILABLE)
endif()
