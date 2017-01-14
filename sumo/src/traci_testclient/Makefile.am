if CHECK_MEMORY_LEAKS
MEM_LIBS  = ../foreign/nvwa/libnvwa.la
endif

if TRACI
bin_PROGRAMS = TraCITestClient

TraCITestClient_SOURCES = tracitestclient_main.cpp TraCITestClient.cpp TraCITestClient.h

TraCITestClient_LDADD = ../utils/common/libcommon.la \
../utils/traci/libtraci.la ../foreign/tcpip/libtcpip.la \
$(MEM_LIBS)
endif
