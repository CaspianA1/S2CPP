py=python3 scheme-\>cpp.py
t=Testing/
o=Output/
move_generated=mv $t*.cpp Output
cpp_14=g++ -std=c++14

# this isn't as useful anymore
all:
	$(py) $ttest_file.scm 
	$(py) $tstrings.scm
	$(py) $tlists_as_arguments.scm
	$(py) $tfunctions.scm
	$(py) $tdad_example.scm
	$(py) $tsimple_addition.scm
	$(move_generated)

# 1. get this working fully
math:
	$(py) $tmath.scm
	$(move_generated)
	$(cpp_14) $omath.cpp && ./a.out

# 2. get this working as well
import: math
	$(py) $timports.scm
	$(move_generated)
	$(cpp_14) $oimports.cpp && ./a.out

# 3. test this
cond:
	$(py) $tconditional.scm
	$(move_generated)

clean:
	rm Testing/*.cpp
