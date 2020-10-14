CXXFLAGS=... 
CXXFLAGS+=-Wall -Wextra -Werror
OBJS=main.cpp	# "main" file # others…
OBJS+=rpn.cpp pvector.cpp fraction.cpp

all: main

clean:
	rm -f main *.o

distclean: clean
	rm -f .depend/*.d
	rm -f *~

-include $(addprefix .depend/,$(OBJS:.o=.d))
%.o: %.cc
	g++ -std=c++17 $(CXXFLAGS) -c -o $@ $*.cc
	@g++ -std=c++17 -MM $(CXXFLAGS) -c $*.cc >.depend/$*.d

main: $(OBJS)
	g++ -std=c++17 $(LDFLAGS) -o $@ $(OBJS)