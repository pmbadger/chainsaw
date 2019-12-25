# Directories
SOURCE_DIR=src
INCLUDE_DIR=include
BUILD_DIR=bin
TEST_DIR=test
LOG_DIR=log

# Program name
COMPONENT=chain

# Shortcuts
LOG_COMPONENT=$(LOG_DIR)/$(COMPONENT)

# Files
TEST=$(TEST_DIR)/$(COMPONENT).test.c
SOURCES=$(SOURCE_DIR)/**/*.c
BUILD=$(BUILD_DIR)/$(COMPONENT).test
LOG=$(LOG_COMPONENT)/$(shell date +%Y-%m-%d_%H:%M:%S).log


run: $(BUILD) $(LOG_COMPONENT)
	$(BUILD) | tee $(LOG)

$(BUILD): $(TEST) $(SOURCE) $(BUILD_DIR)
	gcc $(TEST) $(SOURCES) -I $(INCLUDE_DIR) -o $(BUILD) -Wall

$(BUILD_DIR):
	@mkdir $(BUILD_DIR);

$(LOG_COMPONENT):
	@mkdir -p $(LOG_COMPONENT);

clear: 
	@if [ -d $(LOG_DIR) ]; then du -h -a $(LOG_DIR); fi
	@rm -rf $(LOG_DIR);

	@if [ -d $(BUILD_DIR) ]; then du -h -a $(BUILD_DIR); fi
	@rm -rf $(BUILD_DIR);

	@echo Cleaned.

