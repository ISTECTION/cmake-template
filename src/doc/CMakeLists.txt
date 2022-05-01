find_package(Doxygen)
if(DOXYGEN_FOUND)
    if(NOT DOXYGEN_OUTPUT_LANGUAGE)
        set(DOXYGEN_OUTPUT_LANGUAGE Russian)
    endif()

    message(STATUS "Автодокументация включена (--target doc)")
    message(STATUS "Язык генерации документации Doxygen: ${DOXYGEN_OUTPUT_LANGUAGE}")
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.conf.in Doxyfile @ONLY)

    # Таргет:
    # PS C:\...\build>     cmake --build . --target doc
    # или
    # PS C:\...\build\doc> cmake --build . --target doc
    add_custom_target(doc COMMAND ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)
else()
    message(STATUS "Doxygen не найден")
endif()