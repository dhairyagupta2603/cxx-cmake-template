add_executable(app2_test tui_test.cpp)
target_link_libraries(app2_test
                      PRIVATE app2_static)
AddTests(app2_test)
