OUT = bin

SEARCHPATH += src
SEARCHPATHHEADERS += src/headers
vpath %.c $(SEARCHPATH)
vpath %.h $(SEARCHPATHHEADERS)

DEPS += defs.h structs.h

_OBJS += camera.o
_OBJS += draw.o
_OBJS += entities.o
_OBJS += init.o input.o io.o
_OBJS += main.o map.o
_OBJS += player.o
_OBJS += stage.o
_OBJS += textures.o

OBJS = $(patsubst %,$(OUT)/%,$(_OBJS))

# top-level rule to create the program.
all: $(PROG)

# compiling other source files.
$(OUT)/%.o: %.c %.h $(DEPS)
	@mkdir -p $(OUT)
	$(CC) $(CFLAGS) $(CXXFLAGS) -c -o $@ $<
	
# cleaning everything that can be automatically recreated with "make".
clean:
	$(RM) -rf $(OUT) $(PROG)
