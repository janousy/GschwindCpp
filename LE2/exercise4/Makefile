CXXFLAGS=... 
CXXFLAGS+=-Wall -Wextra -Werror
OBJS=main.cpp	# "main" file
OBJS+=human.cpp   # others…

all: main

clean:
	rm -f main *.o

distclean: clean
	rm -f .depend/*.d
	rm -f *~

-include $(addprefix .depend/,$(OBJS:.o=.d))
%.o: %.cc
	g++ $(CXXFLAGS) -c -o $@ $*.cc
	@g++ -MM $(CXXFLAGS) -c $*.cc >.depend/$*.d

main: $(OBJS)
	g++ $(LDFLAGS) -o $@ $(OBJS)