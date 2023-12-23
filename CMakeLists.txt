cmake_minimum_required(VERSION 3.11)
project(ExampleProject LANGUAGES CXX)

set(CMAKE_C_COMPILER "g++-8")
# set(CMAKE_CXX_COMPILER "/usr/bin/g++-8")
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(
    libs/brainbitsdk
    libs/includes
    libs/scanner
    # libs/dependencies
    )

link_directories(
    libs/brainbitsdk
    libs/includes
    libs/scanner
    # libs/dependencies
    )

set(
	HEADERS
	libs/includes/main_scanner.h
	libs/includes/main_brainbit.h
	libs/includes/common_api.h
    libs/includes/log.h
    libs/includes/mathLib.h
    libs/includes/spectrumLib.h
    libs/brainbitsdk/brainbit.h
    libs/brainbitsdk/cmn_type.h
    libs/brainbitsdk/signalCallback.h
	libs/brainbitsdk/filtersLib.h
	libs/brainbitsdk/main_brainbit_em_st_artifacts.h
	# libs/brainbitsdk/em_st_artifacts_common_api.h
    libs/scanner/scanner.h
    libs/scanner/sensorsCallback.h
	libs/includes/signalCallback_filters.h
)


set(
	SOURCES
	main_scanner.cpp
	main_brainbit.cpp
	main_brainbit_filters.cpp
    libs/brainbitsdk/brainbit.cpp
    libs/includes/mathLib.cpp
    libs/brainbitsdk/filtersLib.cpp
    libs/brainbitsdk/brainbit_info.cpp
    libs/brainbitsdk/brainbit_filters.cpp
	libs/brainbitsdk/brainbit_supported_functional.cpp
    libs/brainbitsdk/brainbit_callback.cpp
	libs/brainbitsdk/brainbit_em_st_artifacts.cpp
    libs/brainbitsdk/brainbit_settings.cpp
    libs/brainbitsdk/brainbit_spectrum.cpp
    libs/includes/log.cpp
    libs/scanner/scanner.cpp
)

include(FetchContent)

# FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.2/json.tar.xz)
# FetchContent_MakeAvailable(json)


# include(FetchContent) # If not included already
# 
# FetchContent_Declare(sciplot_content
#       GIT_REPOSITORY https://github.com/sciplot/sciplot.git
#         GIT_TAG master)
# 
# FetchContent_GetProperties(sciplot_content)
# if(NOT sciplot_content_POPULATED)
#       FetchContent_Populate(sciplot_content)
#   endif()
# 
# include_directories(${sciplot_content_SOURCE_DIR})
add_executable(example main.cc)
# add_executable(example main_plot.cc)
#target_link_libraries(example PRIVATE nlohmann_json::nlohmann_json /home/sah4ez/hdd-backups/work/git//example/libs/brainbitsdk/libneurosdk2.so /home/sah4ez/git/brainbit/example/libs/includes/em_st_artifacts-x64.lib)
# target_link_directories( example PRIVATE /usr/lib/x86_64-linux-gnu/ )
#target_compile_features(example PRIVATE cxx_std_17)
target_link_libraries(
	example PRIVATE 
	/home/sah4ez/hdd-backups/work/git/brainbit/example/libs/brainbitsdk/libneurosdk2.so 
	/home/sah4ez/hdd-backups/work/git/brainbit/example/libs/includes/libem_st_artifacts.so
	/home/sah4ez/hdd-backups/work/git/brainbit/example/libs/dependencies/libc++abi.so.1
	# /usr/lib/x86_64-linux-gnu/libc++abi.so.1
	# /usr/lib/x86_64-linux-gnu/libc++.so.1
	# # /lib64/ld-linux-x86-64.so.2
	# /lib/x86_64-linux-gnu/libblkid.so.1
    /lib/x86_64-linux-gnu/libc.so.6
	# /lib/x86_64-linux-gnu/libdl.so.2
	# /usr/lib/x86_64-linux-gnu/libffi.so.6
	# /lib/x86_64-linux-gnu/libgcc_s.so.1
	# /usr/lib/x86_64-linux-gnu/libgio-2.0.so.0
	# /usr/lib/x86_64-linux-gnu/libgmodule-2.0.so.0
	# /usr/lib/x86_64-linux-gnu/libgobject-2.0.so.0
	# /lib/x86_64-linux-gnu/libmount.so.1
	# /lib/x86_64-linux-gnu/libm.so.6
	# /lib/x86_64-linux-gnu/libpcre.so.3
    /lib/x86_64-linux-gnu/libpthread.so.0
	# /lib/x86_64-linux-gnu/libresolv.so.2
	/lib/x86_64-linux-gnu/librt.so.1
	# /lib/x86_64-linux-gnu/libselinux.so.1
	# /usr/lib/x86_64-linux-gnu/libstdc++.so.6
	# /lib/x86_64-linux-gnu/libudev.so.1
	# /lib/x86_64-linux-gnu/libuuid.so.1
	# /lib/x86_64-linux-gnu/libz.so.1
	)
# target_link_libraries(example PRIVATE nlohmann_json::nlohmann_json)

target_sources(example PRIVATE ${SOURCES} ${HEADERS})
