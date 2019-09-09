CC := g++
MYDIR := $(dir $(realpath $(firstword $(MAKEFILE_LIST))))
SRCDIR := src
BIN := bin
BUILDDIR := build
TARGET := tp1

SRCEXT := cpp
CFLAGS := --coverage -g -Wall -Wno-unknown-pragmas -O3 -std=c++11
T_CFLAGS := --coverage -g -Wall -O3
INC := -I include -I third-party


MODULES = DFS grafo operacoes
SOURCES = $(addsuffix .cpp,$(MODULES))
OBJECTS = $(patsubst %.cpp, %.o, $(SOURCES))
TESTS = $(addprefix test_,$(SOURCES))
TESTSEXE = $(addsuffix .exe,$(TESTS))
TESTSEXEDIR = $(addprefix bin/,$(TESTSEXE))
COVER = $(addsuffix .gcov,$(SOURCES))

SOURCEDIR = $(addprefix $(MYDIR)/,$(SOURCES))
OBJDIR = $(addprefix build/,$(OBJECTS))
TSTDIR = $(addprefix tests/test_,$(SOURCES))
TGTDIR = $(MYDIR)

all: $(TGTDIR)

$(OBJDIR): build/%.o : %.cpp
	@echo ""
	@echo OBJETO: $@
	$(shell mkdir -p build)
	#@mkdir -p ../build
	$(CC) $(INC) $(CFLAGS) -c $(patsubst build/%.o,%.cpp,$@) -o $@

$(TGTDIR): $(OBJDIR)
	@echo ""
	@echo COMPILANDO MAIN
	@mkdir -p bin
	$(CC) $(INC) $(CFLAGS) $(OBJDIR) $(TARGET).cpp -o $(TARGET)


tester: $(TESTS)
$(TESTS): tests/test_%.o : tests/test_%.cpp
	$(shell mkdir -p tests)
	@echo ""
	@echo TESTE: $@
	$(CC) $(INC) -I.. $(T_CFLAGS) tests/$@ $(OBJDIR) -o bin/$@.exe
	bin/$@.exe
	$(RM) test_*.gcno

comp: $(TGTDIR)
	$(CC) $(INC) $(CFLAGS) $(OBJDIR) $(TARGET).cpp -o $(TARGET)

#Use o comando do make: 'make run TXT=nome'
run:
	@./tp1 $(TXT)
	$(RM) tp1.gcno
	$(RM) tp1.gcda

exrun:
	@./tp1 exemplo.txt
	$(RM) tp1.gcno
	$(RM) tp1.gcda

debug:
	@gdb tp1

coverage: $(COVER)
$(COVER): build/%.gcov : %.cpp
	@echo ""
	@echo POSIÇAO: $@
	@gcov $(patsubst %.cpp.gcov,%.cpp,$@) -l -p -o build
	
	$(RM) src#$(patsubst %.cpp.gcov,%.cpp,$@)#*.gcov
	$(RM) #usr#lib*.gcov
	$(RM) *.cpp###*
	$(RM) *.gcda *.gcno

clean:
	$(RM) -r build/* coverage/* *.gcda *.gcno *.gcov *.exe *.o bin/* tp1

.PHONY: clean coverage
