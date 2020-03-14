
OS:=$(shell uname -s | cut -f1 -d_ )

main:
ifeq ($(OS),CYGWIN)
	run "C:\Program Files (x86)\Microsoft Visual Studio\2017\Professional\VC\Auxiliary\Build\vcvars32.bat"
endif
	cd sorce/shlisp && $(MAKE)
	-@cd sorce/justints && $(MAKE)
	cd sorce/justintstoo && $(MAKE)
	-@cd sorce/matrix && $(MAKE) shtar
	-@cd sorce/matrix && $(MAKE) shnth
	$(MAKE) clean
clean:
	-rm -rf *.app *.*~ makefile~ *.o *.exe 
	-find . -name .\* -delete
	chmod -R 777 *
	cd .. && zip -r -q shbobo.zip shbobo
