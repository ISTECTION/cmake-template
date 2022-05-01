message(STATUS "Генерация файла `report/Tectonic.toml` и файла `report/code/_abspath.tex`")
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Tectonic.toml.in ${CMAKE_SOURCE_DIR}/report/Tectonic.toml @ONLY)