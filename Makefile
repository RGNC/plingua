ODIR = obj
SDIR = src
BDIR = bin
IDIR = include

OBJ = y.tab.o lex.yy.o node_value.o scope.o syntax_tree.o system.o init.o parser.o pattern.o formats.o cplusplus.o 
      
BIN = plingua

CFlags=-c -O3 -Wall -std=gnu++11 
LDFlags=-lfl -lboost_system -lboost_filesystem -lboost_program_options
CC=g++
RM=rm
FLEX=flex
BISON=bison

all: y.tab.c lex.yy.c $(OBJ) $(BIN)

$(BIN): $(patsubst %,$(ODIR)/%,$(OBJ))
	@mkdir -p $(BDIR)
	$(CC) $^ $(LDFlags) -o $(BDIR)/$@ 

%.o: $(SDIR)/%.cpp	
	@mkdir -p $(ODIR)
	$(CC) $(CFlags) -I$(IDIR) -o $(ODIR)/$@ $<

%.o: $(SDIR)/psystem/%.cpp	
	@mkdir -p $(ODIR)
	$(CC) $(CFlags) -I$(IDIR) -o $(ODIR)/$@ $<

%.o: $(SDIR)/parser/%.cpp	
	@mkdir -p $(ODIR)
	$(CC) $(CFlags) -I$(IDIR) -o $(ODIR)/$@ $<

%.o: $(SDIR)/generators/cplusplus/%.cpp	
	@mkdir -p $(ODIR)
	$(CC) $(CFlags) -I$(IDIR) -o $(ODIR)/$@ $<

%.o: $(SDIR)/parser/%.c	
	@mkdir -p $(ODIR)
	$(CC) $(CFlags) -I$(IDIR) -o $(ODIR)/$@ $<

y.tab.c: $(SDIR)/parser/plingua.y
	$(BISON) -o $(SDIR)/parser/$@ -yd $<

lex.yy.c: $(SDIR)/parser/plingua.l
	$(FLEX) -o $(SDIR)/parser/$@ $<  
	
clean:
	$(RM) $(patsubst %,$(ODIR)/%,$(OBJ)) $(BDIR)/$(BIN)
	
install:
	@mkdir -p /usr/local/PLingua/$(BIN)/
	@cp $(BDIR)/$(BIN) /usr/local/PLingua/$(BIN)/
	@cp LICENSE /usr/local/PLingua/$(BIN)/
	@ln -sf /usr/local/PLingua/$(BIN)/$(BIN) /usr/local/bin/
	@cp -rf $(IDIR)/cereal/ /usr/local/include/
	@mkdir -p /usr/local/include/plingua/
	@cp -f $(IDIR)/serialization.* /usr/local/include/plingua/
	
