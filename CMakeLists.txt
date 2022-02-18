cmake_minimum_required(VERSION 3.20)
project(spnbox C)

set(CMAKE_C_STANDARD 99)

include_directories("/opt/homebrew/include")
include_directories("inc/")
include_directories("/opt/homebrew/opt/openssl@1.1/include")

set(CMAKE_LIBRARY_FLAGS "-L../lib -lssl -lcrypto -lgmp -lsodium")

set(CMAKE_WARNING_FLAGS "-Wall -Wextra -Wpedantic \
-Wformat=2 -Wno-unused-parameter -Wshadow \
-Wwrite-strings -Wstrict-prototypes -Wold-style-definition \
-Wredundant-decls -Wnested-externs -Wmissing-include-dirs")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${CMAKE_LIBRARY_FLAGS} ${CMAKE_WARNING_FLAGS}")


add_executable(spnbox main.c src/sbox.c src/helper.c inc/sbox.h inc/config.h inc/helper.h inc/types.h inc/tables/tables.h src/spnbox.c inc/spnbox.h src/tableMng.c inc/tableMng.h src/spn/spn16.c inc/spn/spn16.h src/spn/spn8.c src/spn/spn24.c src/spn/spn32.c inc/spn/spn8.h inc/spn/spn24.h inc/spn/spn32.h sss.h)

target_link_libraries(spnbox ${LIBSODIUM_LIBRARY})
