py=python3 scheme-\>cpp.py
move_generated=mv Testing/*.cpp Output
t=Testing/

all:
	$(py) $ttest_file.scm 
	$(py) $tstrings.scm
	$(py) $tlists_as_arguments.scm
	$(py) $tfunctions.scm
	$(py) $tdad_example.scm
	$(py) $tsimple_addition.scm
	$(move_generated)

math:
	$(py) $tmath.scm
	$(move_generated)
	g++ -std=c++14 Output/math.cpp && ./a.out

cond:
	$(py) $tconditional.scm
	$(move_generated)

clean:
	rm Testing/*.cpp
