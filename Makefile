MODULES ?= $(shell find ./* -type d -maxdepth 0)

.DEFAULT_GOAL := submodules

.PHONY: submodules
submodules:
	for module in $(MODULES) ; do \
	  echo "Testing $$module" ; \
	  $(MAKE) -C $$module ; \
	done

.PHONY: clean
clean:
	for module in $(MODULES) ; do \
	  echo "Cleaning $$module" ; \
	  $(MAKE) -C $$module clean ; \
	done

.phony: test
test: submodules
