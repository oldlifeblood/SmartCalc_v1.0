gcc = gcc -Wall -Werror -Wextra -std=c11
HEAD = SmartCalc/polish.h

objectFiles = $(wildcard TEST/*.o)
functionFiles = $(wildcard TEST/*.c)
oF = $(wildcard obj/*.o)
fF = $(wildcard SmartCalc/*.c)

ifeq ($(OS), Linux)
	CHECK_FLAGS = -lcheck_pic -pthread -lrt -lm -lsubunit
else
	CHECK_FLAGS = -lcheck -lm
endif

all: clean install

funcForA: library
	$(gcc) -c $(fF)

test: functions 
	$(gcc) $(oF) -o test_calc $(CHECK_FLAGS)
	./test_calc

functions:
	mkdir -p obj/
	$(gcc) -c $(functionFiles) $(fF)
	mv *.o obj/

install:
	mkdir -p ../build
	cd SmartCalc && qmake && make && make clean && rm -rf Makefile && mv SmartCalc.app ../../build/SmartCalc.app

uninstall:
	rm -rf ../build

dvi_install:
	brew install doxygen

dvi:
	doxygen doxy
	open html/index.html

dist:
	rm -rf SmartCalculator
	mkdir SmartCalculator
	mkdir SmartCalculator/src
	cp Makefile SmartCalc/*.c SmartCalc/*.h SmartCalc/*.cpp SmartCalc/*.ui SmartCalc/*.pro SmartCalc/*.pro.user SmartCalc/*.h SmartCalculator/src/
	tar -cvzf SmartCalculator.tar.gz SmartCalculator
	rm -rf SmartCalculator/

gcov_report: functions 
	gcc --coverage $(functionFiles) $(fF) -o test_calc $(CHECK_FLAGS) 
	./test_calc
	lcov -t "test_calc" -o test_calc.info -c -d .
	lcov --remove test_calc.info '/usr/*' -o test_calc.info
	genhtml -o report test_calc.info
	open ./report/index.html


clang-check:
	cp ../materials/linters/.clang-format .
	clang-format -n SmartCalc/*.c
	clang-format -n SmartCalc/*.h
	clang-format -n SmartCalc/*.cpp 
	rm ./.clang-format

clang-formatting:
	cp ../materials/linters/.clang-format .
	clang-format -i SmartCalc/*.c
	clang-format -i SmartCalc/*.h
	clang-format -i SmartCalc/*.cpp 
	rm ./.clang-format

clean:
	rm -rf obj/ report/ test_calc *.info *.gcda *.gcno s21_test SmartCalculator.tar.gz .qmake.stash
