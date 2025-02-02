add_executable(app1_test basic_test.cpp)
target_link_libraries(app1_test PRIVATE app1_static)
AddTests(app1_test)