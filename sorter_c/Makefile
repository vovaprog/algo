OBJDIR := obj
DEPDIR := dep
$(shell mkdir -p $(OBJDIR) >/dev/null)
$(shell mkdir -p $(DEPDIR) >/dev/null)
DEPFLAGS = -MT $@ -MMD -MP -MF $(DEPDIR)/$*.Td

SRCS := $(shell ls *.cpp 2>/dev/null) $(shell ls *.c 2>/dev/null) 

CXXFLAGS += -std=c++11 -I. -I../algo -O3

COMPILE.c = $(CC) $(DEPFLAGS) $(CFLAGS) $(CPPFLAGS) $(TARGET_ARCH) -c
COMPILE.cc = $(CXX) $(DEPFLAGS) $(CXXFLAGS) $(CPPFLAGS) $(TARGET_ARCH) -c
POSTCOMPILE = mv -f $(DEPDIR)/$*.Td $(DEPDIR)/$*.d

sorter: $(patsubst %.cpp,$(OBJDIR)/%.o,$(wildcard *.cpp))
	$(CXX) -o ./sorter $(OBJDIR)/*.o

$(OBJDIR)/%.o : %.c $(DEPDIR)/%.d
	$(COMPILE.c) $(OUTPUT_OPTION) $<
	$(POSTCOMPILE)

$(OBJDIR)/%.o : %.cpp $(DEPDIR)/%.d
	$(COMPILE.cc) $(OUTPUT_OPTION) $<	
	$(POSTCOMPILE)

$(DEPDIR)/%.d: ;

include $(patsubst %,$(DEPDIR)/%.d,$(basename $(SRCS)))

.PHONY : clean
clean:
	-rm -r $(DEPDIR)	
	-rm -r $(OBJDIR)
	-rm ./sorter
