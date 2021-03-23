SRC   = ./src/complex_t.c 
MAIN  = ./main.c 
UNITY = ./unity/unity.c
TEST_SRC = ./test/unit_test.c

main.exe: complex_t.o main.o
	gcc ./obj/complex_t.o ./obj/main.o -o main.exe

complex_t.o: $(SRC)
	gcc -c $(SRC) -o ./obj/complex_t.o

main.o: $(MAIN)
	gcc -c $(MAIN) -o ./obj/main.o

test.exe: complex_t.o unity.o unit_test.o
	gcc ./obj/complex_t.o ./obj/unity.o ./obj/unit_test.o -o test.exe

unity.o: $(UNITY)
	gcc -c $(UNITY) -o ./obj/unity.o

unit_test.o: $(TEST_SRC)
	gcc -c $(TEST_SRC) -o ./obj/unit_test.o

run: main.exe
	./main.exe

runtest: test.exe
	./test.exe

clean:
	del /q *.exe
	del /q .\obj\*.o

buildDocs: Doxyfile
	Doxygen Doxyfile

cleanDocs:
	rmdir /Q /S .\docs\html