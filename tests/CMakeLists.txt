cmake_minimum_required(VERSION 3.0)

add_executable(pricetest pricetest.cpp)
add_executable(uniqueidtest uniqueidtest.cpp)
add_executable(countrychecktest countrychecktest.cpp)
add_executable(emptyinputtest emptyinputtest.cpp)

target_include_directories(pricetest PRIVATE ${INCLUDE_DIR})
target_include_directories(uniqueidtest PRIVATE ${INCLUDE_DIR})
target_include_directories(countrychecktest PRIVATE ${INCLUDE_DIR})
target_include_directories(emptyinputtest PRIVATE ${INCLUDE_DIR})

target_link_libraries(pricetest auction)
target_link_libraries(uniqueidtest auction)
target_link_libraries(countrychecktest auction)
target_link_libraries(emptyinputtest auction)


add_test(NAME pricetest COMMAND $<TARGET_FILE:pricetest>)
add_test(NAME uniqueidtest COMMAND $<TARGET_FILE:uniqueidtest>)
add_test(NAME countrychecktest COMMAND $<TARGET_FILE:countrychecktest>)
add_test(NAME emptyinputtest COMMAND $<TARGET_FILE:emptyinputtest>)
