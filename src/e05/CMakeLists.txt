add_executable (e05-a2 a2.c)
target_link_libraries (e05-a2 m)

add_executable (e05-a3 a3.c)

add_executable (e05-a4-iterative a4.c a4a.c)
add_executable (e05-a4-recursive-naive a4.c a4b-naive.c)
add_executable (e05-a4-recursive-efficient a4.c a4b-efficient.c)

add_executable (e05-s3 s3.c)

