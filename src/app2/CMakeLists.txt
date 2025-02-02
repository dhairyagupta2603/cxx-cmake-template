add_library(app2_static STATIC tui.cpp)

target_include_directories(app2_static PUBLIC include)

target_precompile_headers(app2_static PUBLIC <string>)

include(GetFTXUI)
target_link_libraries(app2_static PUBLIC app1_shared
                      ftxui::screen ftxui::dom ftxui::component)

include(BuildInfo)
BuildInfo(app2_static)

InstrumentForCoverage(app2_static)
CleanCoverage(app2_static)

Format(app2_static .)

AddCppCheck(app2_static)

Doxygen(app2 src/app2)

add_executable(app2 bootstrap.cpp)
target_link_libraries(app2 app2_static)

# Installation
include(GNUInstallDirs)
install(TARGETS app2
  RUNTIME COMPONENT runtime
)
