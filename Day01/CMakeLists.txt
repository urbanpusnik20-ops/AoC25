cmake_minimum_required(VERSION 3.10)

project(Day01)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Day01 main.cpp)

#copilot edit da mi zagrab input
# Ensure input.txt is copied to the binary/runtime directory so the program
# can open it using a relative path at runtime.
add_custom_command(TARGET Day01 POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_if_different
		"${CMAKE_CURRENT_SOURCE_DIR}/input.txt"
		"$<TARGET_FILE_DIR:Day01>/input.txt"
)
