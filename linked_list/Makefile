MODULE ?= $(notdir $(CURDIR))
LINKER_FLAGS ?= $(TARGET_FLAGS) $(LDFLAGS)
TARGET_FLAGS ?= -stdlib=libc++
WARNINS ?= -Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic
CPPFLAGS ?= $(WARNINGS) -g -std=c++17 $(TARGET_FLAGS)
BUILD_DIR ?= ./build
MKDIR_P ?= mkdir -p
RM ?= rm

.DEFAULT_GOAL := test
.PHONY: test
test: $(BUILD_DIR)/test
	$<

.PHONY: clean
clean:
	$(RM) -r $(BUILD_DIR)

$(BUILD_DIR)/$(MODULE).o: $(MODULE).cpp $(MODULE).hpp $(MODULE).tpp
	$(MKDIR_P) $(dir $@)
	$(CXX) -c $(CPPFLAGS) -c $< -o $@

$(BUILD_DIR)/test.o: test.cpp
	$(MKDIR_P) $(dir $@)
	$(CXX) -c $(CPPFLAGS) -c $< -o $@

$(BUILD_DIR)/test: $(BUILD_DIR)/test.o $(BUILD_DIR)/$(MODULE).o
	$(MKDIR_P) $(dir $@)
	$(CXX) $(LINKER_FLAGS) $^ -o $@
