# Directories
SOURCE_DIR=src
INCLUDE_DIR=include
BUILD_DIR=build
TEST_DIR=test
LOG_DIR=log

# Program name
COMPONENT=chain

# Shortcuts
LOG_COMPONENT=$(LOG_DIR)/$(COMPONENT)

# Files
TEST=$(TEST_DIR)/$(COMPONENT).test.c
SOURCE=$(SOURCE_DIR)/$(COMPONENT)/*.c
BUILD=$(BUILD_DIR)/$(COMPONENT).test
UNITTEST=$(SOURCE_DIR)/unittest/*.c
LOG=$(LOG_COMPONENT)/$(shell date +%Y-%m-%d_%H:%M:%S).log


test: $(BUILD) $(LOG_COMPONENT)
	$(BUILD) | tee $(LOG)

$(BUILD): $(SOURCE) $(UNITTEST) $(BUILD_DIR)
	gcc $(TEST) $(SOURCE) $(UNITTEST) -o $(BUILD) -I$(INCLUDE_DIR) -Wall

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

