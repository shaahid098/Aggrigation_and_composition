cmake_minimum_required(VERSION 3.29)
project(Aggregation_and_Composition_Lab)

set(CMAKE_CXX_STANDARD 20)

Include(FetchContent)

FetchContent_Declare(
        Catch2

        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG        v3.0.1 # or a later release
)

FetchContent_MakeAvailable(Catch2)

if(NOT "${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    #check the compiler being used, if its not Microsoft Visual C then include files

    file(GLOB_RECURSE file_list "catch_string_manip.hpp" "catch_test_case_info.hpp" "catch_xmlwriter.cpp")
    # find files that are known to be missing include statement

    foreach(file ${file_list}) #iterate through said files

        file(READ ${file} file_contents) #open file

        string(FIND "${file_contents}" "#include <cstdint>" file_has_include) # check if file has include

        if(${file_has_include} EQUAL -1) # if file does not have include

            string(CONCAT new_file_contents "#include <cstdint>\n" "${file_contents}")
            #append file contents to the include

            file(WRITE ${file} "${new_file_contents}") # write to file with new contents
        endif()
    endforeach()
endif()



set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/Farm")
add_executable(FarmManagementSystem Farm/FarmDriver.cpp
        Farm/Animal.cpp
        Farm/Chicken.cpp
        Farm/Cow.cpp
        Farm/Crop.cpp
        Farm/Farm.cpp
        Farm/Field.cpp
        Farm/Pig.cpp
)


add_executable(AnimalTest Farm/tests/test_Animal.cpp Farm/Animal.cpp Farm/Chicken.cpp Farm/Cow.cpp Farm/Pig.cpp)
target_link_libraries(AnimalTest PRIVATE Catch2::Catch2WithMain)

add_executable(CropTest Farm/tests/test_Crop.cpp Farm/Crop.cpp)
target_link_libraries(CropTest PRIVATE Catch2::Catch2WithMain)

add_executable(FarmTest Farm/tests/test_Farm.cpp
        Farm/Farm.cpp
        Farm/Field.cpp
        Farm/Animal.cpp
        Farm/Chicken.cpp
        Farm/Cow.cpp
        Farm/Pig.cpp
        Farm/Crop.cpp
)
target_link_libraries(FarmTest PRIVATE Catch2::Catch2WithMain)

add_executable(FieldTest Farm/tests/test_Field.cpp Farm/Field.cpp Farm/Crop.cpp)
target_link_libraries(FieldTest PRIVATE Catch2::Catch2WithMain)