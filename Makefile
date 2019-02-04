ODIR = obj
SDIR = src
BDIR = bin
IDIR = include

OBJ_PLINGUA = y.tab.o lex.yy.o node_value.o scope.o syntax_tree.o system.o init.o parser.o pattern.o formats.o cplusplus.o 

OBJ_PSIM = psim.o command_line.o
      
BIN_PLINGUA = plingua

BIN_PSIM = psim

CFlags=-c -O3 -Wall -std=gnu++11 
LDFlags=-lfl -lboost_system -lboost_filesystem -lboost_program_options
CC=g++
RM=rm
FLEX=flex
BISON=bison

all: compiler simulator

compiler: y.tab.c lex.yy.c $(OBJ_PLINGUA) $(BIN_PLINGUA) 

simulator: $(OBJ_PSIM) $(BIN_PSIM)

$(BIN_PLINGUA): $(patsubst %,$(ODIR)/%,$(OBJ_PLINGUA))
	@mkdir -p $(BDIR)
	$(CC) $^ $(LDFlags) -o $(BDIR)/$@ 
	
$(BIN_PSIM): $(patsubst %,$(ODIR)/%,$(OBJ_PSIM))
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

%.o: $(SDIR)/simulator/%.cpp	
	@mkdir -p $(ODIR)
	$(CC) $(CFlags) -I$(IDIR) -o $(ODIR)/$@ $<


%.o: $(SDIR)/simulator/psim/%.cpp	
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
	$(RM) $(patsubst %,$(ODIR)/%,$(OBJ_PLINGUA)) $(patsubst %,$(ODIR)/%,$(OBJ_PSIM)) $(BDIR)/$(BIN_PLINGUA)  $(BDIR)/$(BIN_PSIM)
	
install:
	@mkdir -p /usr/local/PLingua/$(BIN_PLINGUA)/
	@mkdir -p /usr/local/PLingua/$(BIN_PSIM)/
	@cp $(BDIR)/$(BIN_PLINGUA) /usr/local/PLingua/$(BIN_PLINGUA)/
	@cp $(BDIR)/$(BIN_PSIM) /usr/local/PLingua/$(BIN_PSIM)/
	@cp LICENSE /usr/local/PLingua/
	@ln -sf /usr/local/PLingua/$(BIN_PLINGUA)/$(BIN_PLINGUA) /usr/local/bin/
	@ln -sf /usr/local/PLingua/$(BIN_PSIM)/$(BIN_PSIM) /usr/local/bin/
	@cp -rf $(IDIR)/cereal/ /usr/local/include/
	@mkdir -p /usr/local/include/plingua/
	@cp -f $(IDIR)/serialization.* /usr/local/include/plingua/
	
