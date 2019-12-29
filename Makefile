# Directories
SOURCE_DIR=src
INCLUDE_DIR=include
BUILD_DIR=bin
TEST_DIR=test
LOG_DIR=log

# Component name
TARGET=chain

# Shortcuts
LOG_TARGET=$(LOG_DIR)/$(TARGET)

# Files
TEST=$(TEST_DIR)/$(TARGET).test.c
SOURCES=$(SOURCE_DIR)/**/*.c
BUILD=$(BUILD_DIR)/$(TARGET).test
LOG=$(LOG_TARGET)/$(shell date +%Y-%m-%d_%H:%M:%S).log


run: $(BUILD) $(LOG_TARGET)
	$(BUILD) | tee $(LOG)

$(BUILD): $(TEST) $(SOURCES) $(BUILD_DIR)
	gcc $(TEST) $(SOURCES) -I $(INCLUDE_DIR) -o $(BUILD) -Wall

$(BUILD_DIR):
	@mkdir $(BUILD_DIR);

$(LOG_TARGET):
	@mkdir -p $(LOG_TARGET);

clear: 
	@if [ -d $(LOG_DIR) ]; then du -h -a $(LOG_DIR); fi
	@rm -rf $(LOG_DIR);

	@if [ -d $(BUILD_DIR) ]; then du -h -a $(BUILD_DIR); fi
	@rm -rf $(BUILD_DIR);

	@echo Cleaned.

