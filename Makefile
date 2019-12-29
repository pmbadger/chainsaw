SOURCE_DIR=src
INCLUDE_DIR=include
BUILD_DIR=bin
TEST_DIR=test
LOG_DIR=log

SOURCES=$(SOURCE_DIR)/**/*.c
COMPONENTS=chain math
LOGFILE=$(shell date +%Y-%m-%d_%H:%M:%S).log


.PHONY: all clean %
.PRECIOUS: $(BUILD_DIR)/%.test $(LOG_DIR)/%

all: $(COMPONENTS)

%: $(BUILD_DIR)/%.test | $(LOG_DIR)/%
	-@$< > $|/$(LOGFILE)
	@echo "$<:"
	@grep -E "^|FAIL!|.{6}%" $|/$(LOGFILE) --color
	@echo

$(BUILD_DIR)/%.test: $(TEST_DIR)/%.test.c $(SOURCES) | $(BUILD_DIR)
	gcc $< $(SOURCES) -I $(INCLUDE_DIR) -o $@ -Wall

$(BUILD_DIR):
	@mkdir $@

$(LOG_DIR)/%:
	@mkdir -p $@

clean:
	@if [ -d $(LOG_DIR) ]; then du -h -a $(LOG_DIR); fi
	@rm -rf $(LOG_DIR);
	@if [ -d $(BUILD_DIR) ]; then du -h -a $(BUILD_DIR); fi
	@rm -rf $(BUILD_DIR);
	@echo Clean done.

