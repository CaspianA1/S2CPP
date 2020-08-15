; imports.scm

(import-sys "stdio.h"); with this, you can natively call C and C++ functions
(import-cpp "../Output/math.cpp")
(import-scm "math.scm"); this doesn't work

(printf "%d" 5); this works