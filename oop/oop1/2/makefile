include control.mak
ifeq (TRUE, $(F1))
	_F1 = f1.o
	__F1 = -D __F1__
endif
_F1 ?=  #
__F1 ?= #
ifeq (TRUE, $(F2))
	_F2 = f2.o
	__F2 = -D __F2__
endif
_F2 ?= #
__F2 ?= #
ifeq (TRUE, $(F3))
	_F3 = f3.o
	__F3 = -D __F3__
endif
_F3 ?= #
__F3 ?= #
ifeq (TRUE, $(F4))
	_F4 = f4.o
	__F4 = -D __F4__
endif
_F4 ?= #
__F4 ?= #
main : $(_F1) $(_F2) $(_F3) $(_F4) main.o
	g++ $(_F1) $(_F2) $(_F3) $(_F4) main.o -o main
main.o : main.cpp *.h control.mak
	g++ -c main.cpp -o main.o $(__F1) $(__F2) $(__F3) $(__F4)
$(_F1) : f1.cpp f1.h
	g++ -c f1.cpp -o f1.o
$(_F2) : f2.cpp f2.h
	g++ -c f2.cpp -o f2.o
$(_F3) : f3.cpp f3.h
	g++ -c f3.cpp -o f3.o
$(_F4) : f4.cpp f4.h
	g++ -c f4.cpp -o f4.o
clean :
	rm *.o main
