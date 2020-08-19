py=python3 scheme-\>cpp.py
t=Testing/
o=Output/
move_generated=mv $t*.cpp Output
cpp_17=g++ -std=c++17

# this isn't as useful anymore
all:
	$(py) $ttest_file.scm 
	$(py) $tstrings.scm
	$(py) $tlists_as_arguments.scm
	$(py) $tfunctions.scm
	$(py) $tdad_example.scm
	$(py) $tsimple_addition.scm
	$(move_generated)

# 1. get this working fully - done
math:
	$(py) $tmath.scm
	$(move_generated)
	$(cpp_17) $omath.cpp && ./a.out

# 2. get this working as well - done
import:
	$(py) $tImports/imports.scm
	mv $tImports/imports.cpp Output
	$(cpp_17) $oimports.cpp && ./a.out

# 3. test this further - done
cond:
	$(py) $tconditional.scm
	$(move_generated)

# 4. test this file - done
bool_ops:
	$(py) $tbool_operators.scm
	$(move_generated)
	$(cpp_17) $obool_operators.cpp && ./a.out

mem_equiv:
	$(py) $tequality_test.scm
	$(move_generated)
	$(cpp_17) $oequality_test.cpp && ./a.out

clean:
	rm Testing/*.cpp
