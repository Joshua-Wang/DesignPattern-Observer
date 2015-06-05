#COMAKE2 edit-mode: -*- Makefile -*-
####################64Bit Mode####################
ifeq ($(shell uname -m),x86_64)
CC=gcc
CXX=g++
CXXFLAGS=-g \
  -pipe \
  -W \
  -Wall \
  -fPIC
CFLAGS=-g \
  -pipe \
  -W \
  -Wall \
  -fPIC
CPPFLAGS=-D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\"
INCPATH=-I. \
  -I./include \
  -I./output \
  -I./output/include
DEP_INCPATH=

#============ CCP vars ============
CCHECK=@ccheck.py
CCHECK_FLAGS=
PCLINT=@pclint
PCLINT_FLAGS=
CCP=@ccp.py
CCP_FLAGS=


#COMAKE UUID
COMAKE_MD5=0ad99af537bfe8e475ac2d9513055e92  COMAKE


.PHONY:all
all:comake2_makefile_check observer 
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mall[0m']"
	@echo "make all done"

.PHONY:comake2_makefile_check
comake2_makefile_check:
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mcomake2_makefile_check[0m']"
	#in case of error, update 'Makefile' by 'comake2'
	@echo "$(COMAKE_MD5)">comake2.md5
	@md5sum -c --status comake2.md5
	@rm -f comake2.md5

.PHONY:ccpclean
ccpclean:
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mccpclean[0m']"
	@echo "make ccpclean done"

.PHONY:clean
clean:ccpclean
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mclean[0m']"
	rm -rf observer
	rm -rf ./output/bin/observer
	rm -rf observer_observer.o
	rm -rf observer_blog.o
	rm -rf observer_main.o

.PHONY:dist
dist:
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mdist[0m']"
	tar czvf output.tar.gz output
	@echo "make dist done"

.PHONY:distclean
distclean:clean
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mdistclean[0m']"
	rm -f output.tar.gz
	@echo "make distclean done"

.PHONY:love
love:
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mlove[0m']"
	@echo "make love done"

observer:observer_observer.o \
  observer_blog.o \
  observer_main.o
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mobserver[0m']"
	$(CXX) observer_observer.o \
  observer_blog.o \
  observer_main.o -Xlinker "-("   -lpthread \
  -lcrypto \
  -lrt -Xlinker "-)" -o observer
	mkdir -p ./output/bin
	cp -f --link observer ./output/bin

observer_observer.o:observer.cpp \
  observer.h
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mobserver_observer.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o observer_observer.o observer.cpp

observer_blog.o:blog.cpp \
  blog.h
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mobserver_blog.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o observer_blog.o blog.cpp

observer_main.o:main.cpp \
  blog.h \
  observer.h
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mobserver_main.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o observer_main.o main.cpp

endif #ifeq ($(shell uname -m),x86_64)


