add_library (list list.c)
add_executable (e07-a3 a3.c a2/sum-iterative.c a2/dub-copy.c a3/insert.c a3/removeEvens.c)
target_link_libraries (e07-a3 list)
