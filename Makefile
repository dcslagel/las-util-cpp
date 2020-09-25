# ------------------------------------------------------------------------------
# Clang Compiler
# ------------------------------------------------------------------------------
# CXX    = /Library/Developer/CommandLineTools/usr/bin/clang++
# CXXFLAGS = -std=c++14 -Wall -Wextra -Weverything -Wno-c++98-compat

# ------------------------------------------------------------------------------
# GCC Compiler
# ------------------------------------------------------------------------------
GNU_VER = 9
CXX     := /usr/local/opt/gcc/bin/g++-$(GNU_VER)
# CXX   = /usr/local/opt/gcc/bin/c++-$(GNU_VER)
CXXFLAGS := -std=c++14 -Wall -Wextra -Wpedantic -pedantic-errors
# GCC compiler ------------------------------------------------#

# ------------------------------------------------------------------------------
# Compiler variables
# ------------------------------------------------------------------------------
DEBUG  = -g -O0

# ------------------------------------------------------------------------------
# Tool variables
# ------------------------------------------------------------------------------
# f: force removal, v: verbose (list files removed)
RM     = /bin/rm -fv

# ------------------------------------------------------------------------------
# Project variables
# ------------------------------------------------------------------------------
PRG      = lasUtil
LAS_FILE = sample_2.0.las

SRCS     = \
	las_args.cpp \
	las_header.cpp \
	las_log_param.cpp \
	las_other.cpp \
	las_utils.cpp \
	las_version.cpp \
	las_well.cpp

MAIN_SRCS = $(SRCS) main.cpp
TEST_SRCS = $(SRCS) tests/test_main.cpp

MAIN_OBJS     = $(subst .cpp,.o,($MAIN_SRCS)
TEST_OBJS     = $(subst .cpp,.o,($TEST_SRCS)

# ------------------------------------------------------------------------------
#  Directory variables
# ------------------------------------------------------------------------------
DIR_DATA = examples
DIR_TEST = build/tests
DIR_DEV  = build/dev
DIR_REL  = build/rel
DIR_BIN  = bin

# ------------------------------------------------------------------------------
#  vpaths
# ------------------------------------------------------------------------------
vpath %.cpp src
# vpath %.h include

# ------------------------------------------------------------------------------
# Make release targets
# ------------------------------------------------------------------------------
all: $(PRG)

$(PRG): $(DIR_REL)/$(PRG)

$(DIR_REL)/$(PRG): $(MAIN_SRCS)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $^ -o $(DIR_REL)/$(PRG)

run_rel:
	@echo "#----------------------------------------#"
	@echo "LAS_FILE: [$(LAS_FILE)]"
	@echo "#----------------------------------------#"
	./$(DIR_REL)/$(PRG) -f $(DIR_DATA)/$(LAS_FILE)

clean_rel:
	$(RM) $(DIR_REL)/$(PRG)
# ------------------------------------------------------------------------------
# Make test targets
# ------------------------------------------------------------------------------
test: $(DIR_TEST)/test_main

$(DIR_TEST)/test_main: $(TEST_SRCS)
	@mkdir -p $(@D)
	$(CXX) $(CFLAGS) -I src $^ -o $(DIR_TEST)/test_main

run_test:
	$(DIR_TEST)/test_main

clean_test:
	$(RM) $(OBJS) $(PRG) $(DIR_TEST)/test_main


# ------------------------------------------------------------------------------
# General project maintenance targets
# ------------------------------------------------------------------------------
clean:
	$(RM) -r $(DIR_REL)
	$(RM) -r $(DIR_TEST) $(DIR_DEV) $(DIR_REL) $(DIR_BIN)

# ------------------------------------------------------------------------------
#  PHONEY
# ------------------------------------------------------------------------------
.PHONEY: clean make_depends run runtest


# ------------------------------------------------------------------------------
#  Help
# ------------------------------------------------------------------------------
AWK = /usr/bin/awk
SORT = /usr/bin/sort

.PHONEY: help
help:
	@$(MAKE) --print-data-base --question | \
		$(AWK) '/^[^.%][-A-Za-z0-9_]*:/ {print substr($$1, 1, length($$1)-1)}' | \
		$(SORT)
