add_library(app1 OBJECT basic.cpp)

target_sources(app1 
               PUBLIC FILE_SET HEADERS
               BASE_DIRS include
               FILES include/app1/basic.hpp
)

set_target_properties(app1 PROPERTIES
    POSITION_INDEPENDENT_CODE 1
)

InstrumentForCoverage(app1)

add_library(app1_shared SHARED)
target_link_libraries(app1_shared app1)

add_library(app1_static STATIC)
target_link_libraries(app1_static app1)

CleanCoverage(app1_static)
Format(app1_static .)
AddCppCheck(app1)
Doxygen(app1 src/app1)

# Installation
include(GNUInstallDirs)
install(TARGETS app1 app1_shared app1_static
  EXPORT App1Library
  ARCHIVE COMPONENT development
  LIBRARY COMPONENT runtime
  FILE_SET HEADERS COMPONENT runtime
)

if (UNIX)
  install(CODE "execute_process(COMMAND ldconfig)"
          COMPONENT runtime
  )
endif()

install(EXPORT App1Library
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/app1/cmake
  NAMESPACE Calc::
  COMPONENT runtime
)

install(FILES "App1Config.cmake"
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/app1/cmake
)
