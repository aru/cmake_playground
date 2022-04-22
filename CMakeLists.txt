# CMakeList.txt : CMake project for cmake_playground, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.11)

project ("cmake_playground"
		 VERSION 1.0
		 LANGUAGES C
)

include(fetchcontent)
#fetchcontent_declare (eskil_megasource
#			          GIT_REPOSITORY http://august.quelsolaar.com:3000/Felix/eskil_megasource.git
#			          GIT_TAG master
#)
#fetchcontent_makeavailable(eskil_megasource)

# clean up if our organized directory already exists
file(REMOVE_RECURSE ${CMAKE_CURRENT_SOURCE_DIR}/organized)
set(org_dir "${CMAKE_CURRENT_SOURCE_DIR}/organized")
# create a local directory where imported code will live
file(MAKE_DIRECTORY ${org_dir})
file(MAKE_DIRECTORY ${org_dir}/second_exe)

# get the code and make symlinks to it
fetchcontent_declare(cmake_import_test
					 GIT_REPOSITORY https://github.com/aru/cmake_import_test.git
					 GIT_TAG main
)
fetchcontent_makeavailable(cmake_import_test)

# make symlinks to the code, putting them in folders if you want
file(CREATE_LINK "${cmake_import_test_SOURCE_DIR}/smol_library.h" "${org_dir}/smol_library.h")
file(CREATE_LINK "${cmake_import_test_SOURCE_DIR}/big_library.h" "${org_dir}/big_library.h")
file(CREATE_LINK "${cmake_import_test_SOURCE_DIR}/one_executable.c" "${org_dir}/one_executable.c")
file(CREATE_LINK "${cmake_import_test_SOURCE_DIR}/second_executable.c" "${org_dir}/second_exe/second_executable.c")
# todo(aru): test if we can set breakpoints in symlinked files

include_directories(${org_dir})

# Add source to this project's executable.
add_executable (cmake_playground "cmake_playground.c" "cmake_playground.h")

# TODO: Add tests and install targets if needed.
