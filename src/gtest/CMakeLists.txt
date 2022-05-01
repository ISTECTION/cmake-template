project(gtest_run)

include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        609281088cfefc76f9d0ce82e1ff6c30cc3591e5)

set(gtest_force_shared_crt ON  CACHE BOOL "" FORCE)
set(BUILD_GMOCK            OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Глобальная переменная всех тестов из рабочей дирректории
file(GLOB TEST_SRC_FILES ${PROJECT_SOURCE_DIR}/src/*.cc)

foreach(_test_file ${TEST_SRC_FILES})
    get_filename_component(_test_name ${_test_file} NAME_WE)        # test_name.cpp -> test_name
    add_executable(${_test_name} ${_test_file})
    # Устанавливаем стандарт С++, с которым будут запускаться тесты
    set_target_properties(${_test_name}        PROPERTIES
        CXX_STANDARD ${${META_PROJECT_NAME}_CXX_STANDARD}
        CXX_STANDARD_REQUIRED                         ON)
    target_link_libraries(${_test_name} gtest gtest_main)
    add_test(NAME ${_test_name} COMMAND ${_test_name})              # добавить тест в CTest
    set_tests_properties(${_test_name} PROPERTIES TIMEOUT 5)
endforeach()
