# cmake_minimum_required(VERSION 3.10)
# project(MySQLConnection)

# # Specify C++ standard  
# set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_STANDARD_REQUIRED True)

# # Find MySQL libraries
# find_package(MySQL REQUIRED)

# # Add the executable
# add_executable(MySQLConnection main.cpp)

# # Link MySQL libraries
# target_include_directories(MySQLConnection PRIVATE ${MySQL_INCLUDE_DIRS})
# target_link_libraries(MySQLConnection PRIVATE ${MySQL_LIBRARIES})

# # Manually specify MySQL paths
# include_directories("C:/Program Files/MySQL/MySQL Connector C 6.1/include")
# link_directories("C:/Program Files/MySQL/MySQL Connector C 6.1/lib")

# # Link MySQL libraries
# target_link_libraries(MySQLConnection mysqlclient)

# C:\Program Files\MySQL\MySQL Connector C++ 9.2\lib


cmake_minimum_required(VERSION 3.10)
project(Task1)

# # Manually set MySQL paths
set(MySQL_INCLUDE_DIR "C:/Program Files/MySQL/MySQL Connector C++ 9.2/include")
set(MySQL_LIBRARY "C:/Program Files/MySQL/MySQL Connector C++ 9.2/lib
/libmysql.lib")

# Include MySQL headers
include_directories({C:/Program Files/MySQL/MySQL Connector C++ 9.2/include})

# Define executable
add_executable(Task1 23-Register_page_with_MySql.cpp)

# # Link MySQL library
# target_link_libraries(my_program ${MySQL_LIBRARY})

