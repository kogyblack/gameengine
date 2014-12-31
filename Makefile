# C++ Compiler
CXX=g++
CXXFLAGS=-c -Wall -std=c++11
LDFLAGS = $(addprefix -l,$(LIBS))

SOURCES := $(wildcard src/*.cpp)

VPATH := src

OBJECTS := $(addprefix obj/,$(notdir $(SOURCES:.cpp=.o)))
EXECUTABLE = bin/VSGE.out

LIBS := SDL2

debug: CXX += -DDEBUG
debug: $(SOURCES) $(EXECUTABLE)
release: CXX += -DSDL_ASSERT_LEVEL=1
release: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $^ $(LDFLAGS) -o $@

$(OBJECTS): | obj

.PHONY: obj
obj:
	@mkdir -p $@

obj/%.o: %.cpp
	$(CXX) $< $(CXXFLAGS) -o $@

.PHONY: clean
clean:
	@- $(RM) -R obj $(EXECUTABLE)

rebuild:
	@make clean --no-print-directory
	@make --no-print-directory
