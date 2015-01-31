add_library ("list" list.c)
target_link_libraries ("list" readline)
add_library (tree tree.c)
target_link_libraries (tree readline)

add_executable (e07-a2a-iterative a2/test-sum.c a2/sum-iterative.c)
add_executable (e07-a2a-recursive a2/test-sum.c a2/sum-recursive.c)
target_link_libraries (e07-a2a-iterative "list")
target_link_libraries (e07-a2a-recursive "list")

add_executable (e07-a2b-inplace a2/test-dub.c a2/dub-inplace.c)
add_executable (e07-a2b-copy a2/test-dub.c a2/dub-copy.c)
target_link_libraries (e07-a2b-inplace "list")
target_link_libraries (e07-a2b-copy "list")

add_executable (e07-a3a-iterative-dp a3/test-insert-dp.c a3/insert-iterative-dp.c)
add_executable (e07-a3a-iterative-rv a3/test-insert-rv.c a3/insert-iterative-rv.c)
add_executable (e07-a3a-recursive-dp a3/test-insert-dp.c a3/insert-recursive-dp.c)
add_executable (e07-a3a-recursive-rv a3/test-insert-rv.c a3/insert-recursive-rv.c)
target_link_libraries (e07-a3a-iterative-dp "list")
target_link_libraries (e07-a3a-iterative-rv "list")
target_link_libraries (e07-a3a-recursive-dp "list")
target_link_libraries (e07-a3a-recursive-rv "list")

add_executable (e07-a3b-iterative-dp a3/test-removeEvens-dp.c a3/removeEvens-iterative-dp.c)
add_executable (e07-a3b-recursive-rv a3/test-removeEvens-rv.c a3/removeEvens-recursive-rv.c)
target_link_libraries (e07-a3b-iterative-dp "list")
target_link_libraries (e07-a3b-recursive-rv "list")

add_executable (e07-a4a a4/test-baz.c a4/baz.c)
target_link_libraries (e07-a4a tree)

add_executable (e07-a4b a4/test-leafprod.c a4/leafprod.c)
target_link_libraries (e07-a4b tree)

