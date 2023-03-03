# Autores: Andrei Vlasceanu [839756] & Andres Yubero [842236]

PROG:=main
SRCS:=instruccion.cc instruccionAdd.cc instruccionDup.cc instruccionJumpif.cc instruccionMul.cc instruccionOver.cc instruccionPush.cc instruccionRead.cc instruccionSwap.cc instruccionWrite.cc programa.cc programaSuma.cc programaCuentaAtras.cc programaFactorial.cc main.cc

CXX:= g++ -march=native -O3

DEPS:=$(SRCS:.cc=.d)
OBJS:=$(SRCS:.cc=.o)

all: $(PROG)

$(PROG): $(OBJS)
	$(CXX) -o $@ $(OBJS)

.cc.o:
	$(CXX) -c -MMD $<

edit:
	geany -s *.h *.cc &

clean:
	@rm -f $(PROG) $(DEPS) $(OBJS) core *.s

# Dependencias
-include $(DEPS)