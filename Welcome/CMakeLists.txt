aux_source_directory(. DIR_WELCOME_SRCS)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
add_library(Welcome ${DIR_WELCOME_SRCS})
link_directories(${PROJECT_SOURCE_DIR}/lib)
target_link_libraries(Welcome
        Common
        MainWindow
)
