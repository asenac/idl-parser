file(GLOB CMAKES "${CMAKE_CURRENT_SOURCE_DIR}/*.cmake")

foreach(cmake ${CMAKES})
  include(${cmake})
endforeach(cmake)

