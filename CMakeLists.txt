project(bw-server)
cmake_minimum_required(VERSION 2.8)
aux_source_directory(./src/ SRC_LIST)
add_executable(${PROJECT_NAME} ${SRC_LIST})

# Enable C++11 standard depend
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 11)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)

# link the libraries to the executable
target_link_libraries (${PROJECT_NAME} pthread boost_system)

# Install rules
INSTALL(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION usr/bin)
INSTALL(FILES server.conf.default DESTINATION etc/${PROJECT_NAME} RENAME server.conf)
