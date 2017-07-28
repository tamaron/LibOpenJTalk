
CC = cl

CFLAGS = /O2 /Ob2 /Oi /Ot /Oy /GT /GL /TC /D CHARSET_UTF_8
LFLAGS = /LTCG

CORES = jpcommon.obj jpcommon_node.obj jpcommon_label.obj

all: jpcommon.lib

jpcommon.lib: $(CORES)
	lib $(LFLAGS) /OUT:$@ $(CORES)

.c.obj:
	$(CC) $(CFLAGS) /c $<

clean:
	del *.lib
	del *.obj
