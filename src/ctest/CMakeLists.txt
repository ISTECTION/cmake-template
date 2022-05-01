set(PATH_TO_EXECUTABLE_FILE ${CMAKE_BINARY_DIR}/bin/${META_PROJECT_NAME})

# CTest - тестирование программы через аргументы
add_test(NAME success_test_1 COMMAND ${PATH_TO_EXECUTABLE_FILE} 2   3)
add_test(NAME success_test_2 COMMAND ${PATH_TO_EXECUTABLE_FILE} 25 -4)
