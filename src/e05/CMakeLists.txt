add_executable (a2 a2.c)
target_link_libraries (a2 m)

add_executable (a3 a3.c)

add_executable (a4-iterative a4.c a4a.c)
add_executable (a4-recursive-naive a4.c a4b-naive.c)
add_executable (a4-recursive-efficient a4.c a4b-efficient.c)

add_executable (s3 s3.c)

