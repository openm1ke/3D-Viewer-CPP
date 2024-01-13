CC=g++
FLAGS=-std=c++17 -Wall -Werror -Wextra -pedantic -g #-fsanitize=address
LIBS=-lstdc++
LIBGTEST=-lgtest -lgtest_main $(LIBS)
OS:=$(shell uname -s)
BIN_NAME=3DViewer
BIN_FILE=$(BIN_NAME)_v2.0
ALL_FILES := main.cpp $(wildcard s21_*.cpp) $(wildcard */s21_*.cpp) $(wildcard s21_*.h) $(wildcard */s21_*.h)
ifeq ($(OS), Darwin)
	FLAGS += -D MACOS
	OPEN:=open
	QMAKE:=qmake
else
	LIBS += -lsubunit -lrt -lm -lpthread
	OPEN:=xdg-open
	QMAKE:=qmake6
endif

rebuild: clean all

all: clean gcov_report dvi install

clean: uninstall
	@rm -rf *.o *.gcda *.gcno gcov_test ./report ./build ./html ./latex CPPLINT.cfg cpplint.py

build: clean
	@mkdir -p ./build
	$(QMAKE) $(BIN_NAME).pro -o ./build/$(BIN_FILE)_makefile
	cd ./build && make -f $(BIN_FILE)_makefile
	rm -rf ./build/moc_* ./build/*.o ./build/*.h ./build/$(BIN_FILE)_makefile ./build/.qmake.stash

install: build
ifeq ($(OS), Darwin)
	open ./build/$(BIN_FILE).app/
else 
	./build/$(BIN_FILE)
endif

uninstall:
ifeq ($(OS), Darwin)
	@rm -rf ./build/$(BIN_FILE).app ./build/$(BIN_FILE).tar.gz
else
	@rm -rf ./build/$(BIN_FILE) ./build/$(BIN_FILE).tar.gz
endif

dist: build
ifeq ($(OS), Darwin)
	cd ./build && tar -czvf $(BIN_FILE).tar.gz $(BIN_FILE).app
else
	cd ./build && tar -czvf $(BIN_FILE).tar.gz $(BIN_FILE)
endif

tests: clean
	@$(CC) $(FLAGS) ./tests/s21_test_model.cpp ./model/s21_model.cpp $(LIBGTEST) -o test
	@./test
	@rm -rf test

gcov_report: clean
	@$(CC) $(FLAGS) ./tests/s21_test_model.cpp ./model/s21_model.cpp --coverage $(LIBGTEST) -o gcov_test
	@./gcov_test
	@mkdir -p report
	@gcovr . -e "tests/*" --html --html-details report/index.html
	@rm -rf *.gcda *.gcno *.info gcov_test
	@sh -c "if grep -iq microsoft /proc/version ; then cd ./report; cmd.exe /c start index.html; else $(OPEN) ./report/index.html; fi"

dvi:
	doxygen Doxyfile
	@sh -c "if grep -iq microsoft /proc/version ; then cd ./html; cmd.exe /c start index.html; else $(OPEN) ./html/index.html; fi"

clf:
	clang-format -n --style=Google ${ALL_FILES}

cpk:
	cppcheck --language=c++ ${ALL_FILES}

cpl:
	@cp ../materials/linters/CPPLINT.cfg ../materials/linters/cpplint.py ./
	@python3 cpplint.py --extensions=cpp,h ${ALL_FILES}
	@rm -rf CPPLINT.cfg cpplint.py

style: clf cpk cpl

fix_style:
	@clang-format -i --style=Google ${ALL_FILES}

localtest:
	@$(CC) $(FLAGS) ./localtest.cpp ./model/s21_model.cpp $(LIBGTEST) -o test
	@./test

leaks:
	@$(CC) $(FLAGS) ./tests/s21_test_model.cpp ./model/s21_model.cpp $(LIBGTEST) -o test
	valgrind --leak-check=full --show-leak-kinds=all ./test
	@rm -rf test

.PHONY: all clean
