CC=gcc
CF=clang-format -i
CFLAGS=-Wall -Werror -Wextra -std=c11
FLAG_COV=--coverage
TARGET=s21_matrix

BUILD_DIR=build/
TEST_DIR=tests/

SRC:=$(wildcard *.c)
SRC_TEST:=$(wildcard $(TEST_DIR)*.c)

OBJ:=$(addprefix $(BUILD_DIR), $(SRC:.c=.o))
TEST_OBJ:=$(addprefix $(BUILD_DIR)$(TEST_DIR), $(SRC_TEST:$(TEST_DIR)%.c=%.o))

DISTRO=$(shell uname -s)
LCOV=$(BUILD_DIR)$(TEST_DIR)coverage_report/index.html

ifeq (${DISTRO}, Linux)
	LIBS=-lcheck -lm -lsubunit
else ifeq (${DISTRO}, Darwin)
	LIBS=-lcheck -lm
endif

all: $(TARGET).a

$(TARGET).a: $(OBJ)
	ar rc $(TARGET).a $(OBJ)
	ranlib $(TARGET).a

$(BUILD_DIR)%.o: %.c create_dir
	$(CC) $(CFLAGS) -c $< -o $@

test: clean $(TEST_OBJ)
	@$(CC) $(FLAG_COV) -o $(BUILD_DIR)$(TEST_DIR)/$(TARGET)_test $(TEST_OBJ) $(SRC) $(LIBS)
# valgrind --tool=memcheck --leak-check=yes 
	./$(BUILD_DIR)$(TEST_DIR)$(TARGET)_test

$(BUILD_DIR)$(TEST_DIR)%.o: %.c create_dir
	$(CC) $(CFLAGS) -c $< -o $@

gcov_report: test
	lcov -t "test" -c -d $(BUILD_DIR)$(TEST_DIR) -o $(BUILD_DIR)$(TEST_DIR)coverage.info
ifeq (${DISTRO}, Darwin)
	lcov --remove $(BUILD_DIR)$(TEST_DIR)coverage.info '/usr/*' --output-file $(BUILD_DIR)$(TEST_DIR)coverage.info;
endif
	genhtml $(BUILD_DIR)$(TEST_DIR)coverage.info -o $(BUILD_DIR)$(TEST_DIR)coverage_report
# open $(LCOV)

create_dir:
	@mkdir -p $(BUILD_DIR)
	@mkdir -p $(BUILD_DIR)$(TEST_DIR)

clangF:
	@echo CLANG-FORMAT
	@$(CF) $(SRC) $(SRC_TEST) *.h $(TEST_DIR)*.h

rebuild: clean all

.PHONY: clean
clean:
	@echo CLEAN ALL
	@rm -rf $(BUILD_DIR)
	@rm -rf *.dSYM
	@rm -f *.o
	@rm -f $(TARGET).a
	@rm -f a.out
