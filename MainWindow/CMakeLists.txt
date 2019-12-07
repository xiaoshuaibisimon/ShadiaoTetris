aux_source_directory(. MAIN_WINDOW)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
add_library(MainWindow ${MAIN_WINDOW})
link_directories(${PROJECT_SOURCE_DIR}/lib)
target_link_libraries(MainWindow
        Common
)