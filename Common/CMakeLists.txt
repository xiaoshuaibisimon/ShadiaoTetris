aux_source_directory(. DIR_COMMON_SRCS)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
add_library(Common ${DIR_COMMON_SRCS})
link_directories(${PROJECT_SOURCE_DIR}/lib)
target_link_libraries(Common
        Welcome
        MainWindow
        )