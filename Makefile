all:
	python3 scheme-\>cpp.py Testing/test_file.scm 
	python3 scheme-\>cpp.py Testing/strings.scm
	python3 scheme-\>cpp.py Testing/lists_as_arguments.scm
	python3 scheme-\>cpp.py Testing/functions.scm
	python3 scheme-\>cpp.py Testing/dad_example.scm
	python3 scheme-\>cpp.py Testing/simple_addition.scm
	mv Testing/*.cpp Output

math:
	python3 scheme-\>cpp.py Testing/math.scm
	mv Testing/*.cpp Output

clean:
	rm Testing/*.cpp
