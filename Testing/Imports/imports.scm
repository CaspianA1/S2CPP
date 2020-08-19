; imports.scm

(import-sys "stdio.h"); with this, you can natively call C and C++ functions
(import-cpp "test_2.cpp"); this doesn't work yet
(import-scm "test.scm"); this doesn't work

(printf "%d\n" 5); this works
(testFunc)