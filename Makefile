#
# Project Makefile 
#

all: app tests

app:
	cd src && $(MAKE)
tests:
	cd tests && $(MAKE)
	cd tests && build/test_suite

clean:
	cd src && $(MAKE) clean
	cd tests && $(MAKE) clean
.PHONY: all app tests clean
