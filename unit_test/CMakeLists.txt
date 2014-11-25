file (GLOB SOURCE_FILE_LIST src/*.cpp)

add_executable (UnitTest ${SOURCE_FILE_LIST})
include_directories("${PROJECT_SOURCE_DIR}/external/include")
target_link_libraries(UnitTest LINK_PUBLIC TheBigOh)