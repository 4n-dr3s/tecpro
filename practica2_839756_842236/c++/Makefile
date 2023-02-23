# Autores: Andrei Vlasceanu [839756] & Andres Yubero [842236]

PROG:=main
SRCS:=instruccionAdd.cc instruccionRead.cc instruccionWrite.cc programaSuma.cc main.cc
CXX:= g++ -O2
OBJS:=$(SRCS:.cc=.o)

all: $(PROG) main.s

$(PROG): $(OBJS)
	$(CXX) -o $@ $(OBJS)

.cc.o:
	$(CXX) -c $<

edit:
	geany -s *.h *.cc &

clean:
	@rm -f $(PROG) $(OBJS) core *.s

#rational.o: rational.cc rational.h
#main.o: main.cc rational.h
#main.s: main.cc rational.h