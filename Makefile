# C++ Compiler
CXX = g++
CXXFLAGS = -c -Wall -std=c++11
LDFLAGS = $(addprefix -l,$(LIBS))

SOURCES := $(wildcard src/*.cpp)

VPATH := src

OBJDIR := obj
OBJECTS := $(addprefix $(OBJDIR)/,$(notdir $(SOURCES:.cpp=.o)))

BUILDDIR := build
EXENAME := VSGE
EXECUTABLE := $(addsuffix .out,$(addprefix $(BUILDDIR)/,$(EXENAME)))

LIBS := SDL2

debug: CXX += -DDEBUG
debug: $(SOURCES) $(EXECUTABLE)
release: CXX += -DSDL_ASSERT_LEVEL=1
release: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) | $(BUILDDIR)
	$(CXX) $^ $(LDFLAGS) -o $@

$(OBJECTS): | obj

.PHONY: $(BUILDDIR)
$(BUILDDIR):
	@mkdir -p $@

.PHONY: $(OBJDIR)
$(OBJDIR):
	@mkdir -p $@

$(OBJDIR)/%.o: %.cpp
	$(CXX) $< $(CXXFLAGS) -o $@

.PHONY: clean
clean:
	@- $(RM) -R $(OBJDIR) $(BUILDDIR)

rebuild:
	@make clean --no-print-directory
	@make --no-print-directory
