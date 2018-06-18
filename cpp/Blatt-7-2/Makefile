#O2 for optimization, g for debugging
CFLAGS=-std=c++11 -Wall -O2 -g #-I. $(shell root-config --cflags)
#LFLAGS=$(shell root-config --libs)
LFLAGS=
CC=g++
LD=g++

#Alle Klassen cc-Dateien. Fuege hier weitere Klassen hinzu
SRCS=Vektor.cc Zylindermantel.cc Vollzylinder.cc #Vollzylinder.cc

OBJS = $(SRCS:.cc=.o)

.PHONY: clean all

all: traegheit vektortest

clean:
	@rm -f *~ *.o *# *.d main

traegheit: $(OBJS) traegheit.o
	$(LD) $(LFLAGS) -o traegheit $^

vektortest: $(OBJS) vektortest.o
	$(LD) $(LFLAGS) -o vektortest $^

#rules
%.o : %.cc
	$(CC) $(CFLAGS) -MMD -c -o $@ $<
	@sed -e 's/#.*//' -e 's/^[^:]*: *//' -e 's/ *\\$$//' \
             -e '/^$$/ d' -e 's/$$/ :/' < $*.d >> $*.d

-include $(SRCS:%.cc=%.d)

