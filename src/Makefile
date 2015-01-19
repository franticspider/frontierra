# Generated automatically from Makefile.in by configure.
# Tierra makefile

# integer value
PLOIDY=1

# bgl/basic/stdio
FRONTEND=stdio

# yes/no
DEBUG=no

# yes/no
NET=no

# tcp/udp
#NETTYPE=udp

# yes/no
TIEAUDIO=no

# ********** no changes below this line **********

MAKEFILE=Makefile
CC=gcc

RPCGENFLAGS=-DHAVE_TDT_FST_LST_OFSTTYP
ifeq ($(NET),yes)
RPCGENFLAGS+=-DNET -DUSE_PORT
endif # NET

OSFLAGS=$(strip -DPLOIDY=$(PLOIDY) $(RPCGENFLAGS))

ifneq ($(findstring linux-gnu,linux-gnu),)
OSFLAGS+=-DTSysV
endif # linux-gnu

ifneq ($(findstring sunos,linux-gnu),)
OSFLAGS+=-DTBSD -DNEED_CRYPT_PROTO -DNEED_STRERROR
endif # sunos

ifneq ($(findstring osf,linux-gnu),)
OSFLAGS+=-DTSysV -DNEED_CRYPT_PROTO
endif # osf

ifneq ($(findstring irix,linux-gnu),)
OSFLAGS+=-DTSysV
endif # irix

ifneq ($(findstring solaris,linux-gnu),)
OSFLAGS+=-DTSysV -DNEED_CRYPT_PROTO
endif # solaris

ifeq ($(TIEAUDIO),yes)
OSFLAGS+=-DTIEAUDIO
endif # TIEAUDIO

ifeq ($(DEBUG),yes)
OPTIMIZ=-g
else
OPTIMIZ=-O3
endif # DEBUG

LDFLAGS=$(OPTIMIZ)

COMBASNAM=genebank_xdr port_xdr tiexdrcom_xdr
COMSRCS=$(addsuffix .c,$(COMBASNAM))
COMOBJS=$(COMSRCS:.c=.o)
COMCFLAGS=$(strip $(OPTIMIZ) -I. $(OSFLAGS)  -DHAVE_LIBTERMCAP=1 -DHAVE_LIBCURSES=1 -DHAVE_LIBCRYPT=1 -DHAVE_LIBM=1 -DHAVE_LIBNSL=1 -DHAVE_LIBM=1 -DHAVE_LIBNSL=1 -DHAVE_LIBCRYPT=1 -DHAVE_LIBNSL=1 -DHAVE_LIBXMU=1 -DHAVE_LIBX11=1 -DHAVE_LIBXT=1 -DHAVE_LIBXAW=1 -DHAVE_LIBM=1 -DHAVE_LIBNSL=1 -DHAVE_LIBNSL=1 -DHAVE_LIBM=1 -DHAVE_LIBNSL=1 -DHAVE_LIBM=1 -DHAVE_LIBNSL=1 -DHAVE_LIBNSL=1 -DHAVE_LIBNSL=1 -DHAVE_LIBNSL=1 -DHAVE_DIRENT_H=1 -DHAVE_SYS_WAIT_H=1 -DHAVE_FCNTL_H=1 -DHAVE_LIMITS_H=1 -DHAVE_SGTTY_H=1 -DHAVE_SYS_FILE_H=1 -DHAVE_SYS_IOCTL_H=1 -DHAVE_SYS_TIME_H=1 -DHAVE_TERMIO_H=1 -DHAVE_CRYPT_H=1 -DHAVE_STDARG_H=1 -DHAVE_UNISTD_H=1 -DSTDC_HEADERS=1 -DTIME_WITH_SYS_TIME=1 )

ifneq ($(findstring gcc,$(CC)),)
ifneq ($(findstring linux-gnu,linux-gnu),)
COMCFLAGS+=-I/usr/include/bsd -Wall -Wstrict-prototypes -Wno-unused
endif # linux-gnu
endif # gcc

ifeq ($(NET),yes)
NETXDRBASNAM=mesg_xdr
ifeq ($(NETTYPE),udp)
NETXDRBASNAM+=datpkt_xdr
endif # NETTYPE
NETXDRSRCS=$(addsuffix .c,$(NETXDRBASNAM))
NETXDROBJS=$(NETXDRSRCS:.c=.o)
NETXDRCFLAGS=$(COMCFLAGS)
endif # NET


TIEEXE=tierra
TIEBASNAM1=$(strip $(TIEEXE) popdy bookeep diskbank rambank \
    tie_inc decode frontend instruct memalloc memtree slicers trand \
    tsetup ttools micromon operator tieaudsrv)
ifeq ($(NET),yes)
TIEBASNAM1+=netfunc tiecomm
ifeq ($(NETTYPE),udp)
TIEBASNAM1+=tiecommudpasm
else # NETTYPE
TIEBASNAM1+=tiecommtcp
endif # NETTYPE
endif # NET
ifeq ($(FRONTEND),bgl)
BGLHOME = ../
BGLCOMHOME = $(BGLHOME)Bglcom/
BGLSERVHOME = $(BGLHOME)Bglserv/
TIEBASNAM1+=$(strip $(BGLSERVHOME)tbgl_com $(BGLSERVHOME)tbgl_dat \
    $(BGLSERVHOME)tbgl_proc $(BGLCOMHOME)bgl_dat_xdr \
    $(BGLCOMHOME)bglcode $(BGLCOMHOME)bglnet \
    $(BGLCOMHOME)bglprint $(BGLCOMHOME)bgltcp)
endif # FRONTEND
TIEBASNAM=$(TIEBASNAM1) $(COMBASNAM)
ifeq ($(NET),yes)
TIEBASNAM+=$(NETXDRBASNAM)
endif # NET
TIESRCS=$(addsuffix .c,$(TIEBASNAM))
TIEOBJS=$(TIESRCS:.c=.o)
TIECFLAGS=$(COMCFLAGS) -DTIERRA
ifeq ($(NET),yes)
ifeq ($(NETTYPE),tcp)
TIECFLAGS+=-DNETTYPE=2
else # NETTYPE
TIECFLAGS+=-DNETTYPE=1
endif # NETTYPE
endif # NET
ifeq ($(FRONTEND),basic)
TIECFLAGS+=-DFRONTEND=1
else # FRONTEND
ifeq ($(FRONTEND),bgl)
TIECFLAGS+=-I$(BGLSERVHOME) -I$(BGLCOMHOME) -DBGL -DBGL_SERV
else # FRONTEND
TIECFLAGS+=-DFRONTEND=0
endif # FRONTEND
endif # FRONTEND
TIEOBJS1=$(addsuffix .o,$(TIEBASNAM1))


ARGEXE=arg
ARGBASNAM1=$(ARGEXE) $(ARGEXE)_inc
ARGBASNAM=$(ARGBASNAM1) $(COMBASNAM)
ARGSRCS=$(addsuffix .c,$(ARGBASNAM))
ARGOBJS=$(ARGSRCS:.c=.o)
ARGCFLAGS=$(COMCFLAGS) -DARGTIE
ARGOBJS1=$(addsuffix .o,$(ARGBASNAM1))

ifeq ($(FRONTEND),bgl)
TBGLPASSWDEXE = tbglpasswd
TBGLPASSWDSRCS=$(addsuffix .c,$(TBGLPASSWDEXE))
TBGLPASSWDOBJS=$(TBGLPASSWDSRCS:.c=.o)
TBGLPASSWDCFLAGS=$(COMCFLAGS) -DTBGLPASSWD
endif # FRONTEND

DIFFSCANEXE = diffscan
DIFFSCANSRCS=$(addsuffix .c,$(DIFFSCANEXE))
DIFFSCANOBJS=$(DIFFSCANSRCS:.c=.o)
DIFFSCANCFLAGS=$(COMCFLAGS) -DDIFFSCAN
ifeq ($(findstring sunos,linux-gnu),)
ifneq ($(CC),cc)
DIFFSCANCFLAGS+=-DANSI
endif # cc
endif # sunos

RESEQEXE = reseq
RESEQSRCS=$(addsuffix .c,$(RESEQEXE))
RESEQOBJS=$(RESEQSRCS:.c=.o)
RESEQCFLAGS=$(COMCFLAGS) -DRESEQ
ifeq ($(findstring sunos,linux-gnu),)
ifneq ($(CC),cc)
RESEQCFLAGS+=-DANSI
endif # cc
endif # sunos

GENALIGNEXE=genalign
GENALIGNBASNAM1=$(GENALIGNEXE) $(GENALIGNEXE)_inc stralign
GENALIGNBASNAM=$(GENALIGNBASNAM1) $(COMBASNAM)
GENALIGNSRCS=$(addsuffix .c,$(GENALIGNBASNAM))
GENALIGNOBJS=$(GENALIGNSRCS:.c=.o)
GENALIGNCFLAGS=$(COMCFLAGS) -DGENALIGN
GENALIGNOBJS1=$(addsuffix .o,$(GENALIGNBASNAM1))

THREADTREEEXE=threadtree
THREADTREEBASNAM1=$(THREADTREEEXE) $(THREADTREEEXE)_inc
THREADTREEBASNAM=$(THREADTREEBASNAM1) $(COMBASNAM)
THREADTREESRCS=$(addsuffix .c,$(THREADTREEBASNAM))
THREADTREEOBJS=$(THREADTREESRCS:.c=.o)
THREADTREECFLAGS=$(COMCFLAGS) -DTHREADTREE
THREADTREEOBJS1=$(addsuffix .o,$(THREADTREEBASNAM1))

PROBEEXE=probe
PROBEBASNAM1=$(PROBEEXE) $(PROBEEXE)_inc
PROBEBASNAM=$(PROBEBASNAM1) $(COMBASNAM)
PROBESRCS=$(addsuffix .c,$(PROBEBASNAM))
PROBEOBJS=$(PROBESRCS:.c=.o)
PROBECFLAGS=$(COMCFLAGS) -DPROBE
PROBEOBJS1=$(addsuffix .o,$(PROBEBASNAM1))

SOUPUPDTRCEXE=soupupdtrc
SOUPUPDTRCBASNAM1=$(SOUPUPDTRCEXE) $(SOUPUPDTRCEXE)_inc
SOUPUPDTRCBASNAM=$(SOUPUPDTRCBASNAM1) $(COMBASNAM)
SOUPUPDTRCSRCS=$(addsuffix .c,$(SOUPUPDTRCBASNAM))
SOUPUPDTRCOBJS=$(SOUPUPDTRCSRCS:.c=.o)
SOUPUPDTRCCFLAGS=$(COMCFLAGS) -DSOUPUPDTRC
SOUPUPDTRCOBJS1=$(addsuffix .o,$(SOUPUPDTRCBASNAM1))

ifeq ($(TIEAUDIO),yes)

TIEAUDCLEXE=tieaudcl
TIEAUDCLBASNAM1=$(TIEAUDCLEXE)
TIEAUDCLBASNAM=$(TIEAUDCLBASNAM1)
TIEAUDCLSRCS=$(addsuffix .c,$(TIEAUDCLBASNAM))
TIEAUDCLOBJS=$(TIEAUDCLSRCS:.c=.o)
TIEAUDCLCFLAGS=$(COMCFLAGS) -DTIEAUDCL
TIEAUDCLOBJS1=$(addsuffix .o,$(TIEAUDCLBASNAM1))

TIE2PDEXE=tie2pd
TIE2PDBASNAM1=$(TIE2PDEXE)
TIE2PDBASNAM=$(TIE2PDBASNAM1)
TIE2PDSRCS=$(addsuffix .c,$(TIE2PDBASNAM))
TIE2PDOBJS=$(TIE2PDSRCS:.c=.o)
TIE2PDCFLAGS=$(COMCFLAGS) -DTIE2PD
TIE2PDOBJS1=$(addsuffix .o,$(TIE2PDBASNAM1))

endif # TIEAUDIO

ifeq ($(NET),yes)

LOG2IPMAPEXE=log2ipmap
LOG2IPMAPBASNAM=$(LOG2IPMAPEXE)
LOG2IPMAPSRCS=$(addsuffix .c,$(LOG2IPMAPBASNAM))
LOG2IPMAPOBJS=$(LOG2IPMAPSRCS:.c=.o)
LOG2IPMAPCFLAGS=$(COMCFLAGS) -DLOG2IPMAP

ifeq ($(NETTYPE),udp)

OPNSOCKBASNAM=opnsock
OPNSOCKSRCS=$(addsuffix .c,$(OPNSOCKBASNAM))
OPNSOCKOBJS=$(OPNSOCKSRCS:.c=.o)
OPNSOCKCFLAGS=$(COMCFLAGS)
ifeq ($(findstring sunos,linux-gnu),)
ifneq ($(CC),cc)
OPNSOCKCFLAGS+=-DANSI
endif # cc
endif # sunos
OPNSOCKOBJS=$(addsuffix .o,$(OPNSOCKBASNAM))

TIEUDPTNLEXE=tieudptnl
TIEUDPTNLBASNAM1=$(TIEUDPTNLEXE)
TIEUDPTNLBASNAM=$(TIEUDPTNLBASNAM1) $(OPNSOCKBASNAM)
TIEUDPTNLSRCS=$(addsuffix .c,$(TIEUDPTNLBASNAM))
TIEUDPTNLOBJS=$(TIEUDPTNLSRCS:.c=.o)
TIEUDPTNLCFLAGS=$(COMCFLAGS) -DTIEUDPTNL
ifeq ($(findstring sunos,linux-gnu),)
ifneq ($(CC),cc)
TIEUDPTNLCFLAGS+=-DANSI
endif # cc
endif # sunos
TIEUDPTNLOBJS1=$(addsuffix .o,$(TIEUDPTNLBASNAM1))

TIEUDPTNLCEXE=tieudptnlc
TIEUDPTNLCBASNAM1=$(TIEUDPTNLCEXE)
TIEUDPTNLCBASNAM=$(TIEUDPTNLCBASNAM1) $(OPNSOCKBASNAM)
TIEUDPTNLCSRCS=$(addsuffix .c,$(TIEUDPTNLCBASNAM))
TIEUDPTNLCOBJS=$(TIEUDPTNLCSRCS:.c=.o)
TIEUDPTNLCCFLAGS=$(COMCFLAGS) -DTIEUDPTNLC
ifeq ($(findstring sunos,linux-gnu),)
ifneq ($(CC),cc)
TIEUDPTNLCCFLAGS+=-DANSI
endif # cc
endif # sunos
TIEUDPTNLCOBJS1=$(addsuffix .o,$(TIEUDPTNLCBASNAM1))

endif # NETTYPE
endif # NET

.PHONY: programs clean

%_xdr.c: %.x
	-$(RM) $@
	rpcgen $(RPCGENFLAGS) -c -o $@ $<
%.h: %.x
	-$(RM) $@
	rpcgen $(RPCGENFLAGS) -h -o $@ $<


programs: $(strip $(TIEEXE) $(ARGEXE) $(DIFFSCANEXE) $(RESEQEXE) \
          $(GENALIGNEXE) $(THREADTREEEXE) $(PROBEEXE) \
          $(SOUPUPDTRCEXE))

ifeq ($(FRONTEND),bgl)
programs: $(TBGLPASSWDEXE)
endif # FRONTEND

ifeq ($(NET),yes)
programs: $(LOG2IPMAPEXE)
ifeq ($(NETTYPE),udp)
programs: $(TIEUDPTNLEXE) $(TIEUDPTNLCEXE)
endif # NETTYPE
endif # NET

ifeq ($(TIEAUDIO),yes)
programs: $(TIEAUDCLEXE) $(TIE2PDEXE)
endif # TIEAUDIO

TIELDLIBS=-lnsl -lm -lcrypt 
ifeq ($(FRONTEND),basic)
TIELDLIBS+=-lcurses -ltermcap 
endif # FRONTEND

$(TIEEXE): $(TIEOBJS)
	$(CC) $(LDFLAGS) $^ $(TIELDLIBS) -o $@

$(ARGEXE): $(ARGOBJS)
	$(CC) $(LDFLAGS) $^ -lnsl -lm  -o $@

ifeq ($(FRONTEND),bgl)
$(TBGLPASSWDEXE): $(TBGLPASSWDOBJS)
	$(CC) $(LDFLAGS) $^ -lcrypt  -o $@
endif # FRONTEND

$(DIFFSCANEXE): $(DIFFSCANOBJS)
	$(CC) $(LDFLAGS) $^ -o $@

$(RESEQEXE): $(RESEQOBJS)
	$(CC) $(LDFLAGS) $^ -o $@

$(GENALIGNEXE): $(GENALIGNOBJS)
	$(CC) $(LDFLAGS) $^ -lnsl  -o $@

$(THREADTREEEXE): $(THREADTREEOBJS)
	$(CC) $(LDFLAGS) $^ -lnsl -lm -lXaw -lXt -lX11 -lXmu  -o $@

$(PROBEEXE): $(PROBEOBJS)
	$(CC) $(LDFLAGS) $^ -lnsl  -o $@

$(SOUPUPDTRCEXE): $(SOUPUPDTRCOBJS)
	$(CC) $(LDFLAGS) $^ -lnsl  -o $@

ifeq ($(TIEAUDIO),yes)

$(TIEAUDCLEXE): $(TIEAUDCLOBJS)
	$(CC) $(LDFLAGS) $^ -lnsl -lm  -o $@

$(TIE2PDEXE): $(TIE2PDOBJS)
	$(CC) $(LDFLAGS) $^ -lnsl -lm  -o $@

endif # TIEAUDIO

ifeq ($(NET),yes)

$(LOG2IPMAPEXE): $(LOG2IPMAPOBJS)
	$(CC) $(LDFLAGS) $^  -o $@

ifeq ($(NETTYPE),udp)

$(TIEUDPTNLEXE): $(TIEUDPTNLOBJS)
	$(CC) $(LDFLAGS) $^ -lnsl  -o $@

$(TIEUDPTNLCEXE): $(TIEUDPTNLCOBJS)
	$(CC) $(LDFLAGS) $^ -lnsl  -o $@

endif # NETTYPE
endif # NET

clean:
	-$(RM) $(strip \
               $(TIEEXE) $(TIEOBJS) $(MAKEFILE)_$(TIEEXE).d \
               $(ARGEXE) $(ARGOBJS) $(MAKEFILE)_$(ARGEXE).d \
               $(DIFFSCANEXE) $(DIFFSCANOBJS) $(MAKEFILE)_$(DIFFSCANEXE).d \
               $(RESEQEXE) $(RESEQOBJS) $(MAKEFILE)_$(RESEQEXE).d \
               $(GENALIGNEXE) $(GENALIGNOBJS) $(MAKEFILE)_$(GENALIGNEXE).d \
               $(THREADTREEEXE) $(THREADTREEOBJS) \
               $(MAKEFILE)_$(THREADTREEEXE).d \
               $(SOUPUPDTRCEXE) $(SOUPUPDTRCOBJS) \
               $(MAKEFILE)_$(SOUPUPDTRCEXE).d \
               $(PROBEEXE) $(PROBEOBJS) $(MAKEFILE)_$(PROBEEXE).d )               
# don't delete: genebank.h genebank_xdr.c tiexdrcom.h tiexdrcom_xdr.c)
ifeq ($(NET),yes)
	-$(RM) $(strip mesg.h $(NETXDRSRCS) \
               $(LOG2IPMAPEXE) $(LOG2IPMAPOBJS) \
               $(MAKEFILE)_$(LOG2IPMAPEXE).d)
ifeq ($(NETTYPE),udp)
	-$(RM) $(strip datpkt.h $(TIEUDPTNLEXE) $(TIEUDPTNLOBJS) \
               $(MAKEFILE)_$(TIEUDPTNLEXE).d \
               $(TIEUDPTNLCEXE) $(TIEUDPTNLCOBJS) \
               $(MAKEFILE)_$(TIEUDPTNLCEXE).d)
endif # NETTYPE
endif # NET
ifeq ($(FRONTEND),bgl)
	-$(RM) $(strip $(TBGLPASSWDEXE) $(TBGLPASSWDOBJS) \
               $(MAKEFILE)_$(TBGLPASSWDEXE).d \
               $(BGLCOMHOME)bgl_dat_xdr.c $(BGLCOMHOME)bgl_dat_xdr.h)
endif # FRONTEND
ifeq ($(TIEAUDIO),yes)

	-$(RM) $(strip $(TIEAUDCLEXE) $(TIEAUDCLOBJS) \
               $(MAKEFILE)_$(TIEAUDCLEXE).d)

	-$(RM) $(strip $(TIE2PDEXE) $(TIE2PDOBJS) \
               $(MAKEFILE)_$(TIE2PDEXE).d)

endif # TIEAUDIO

$(MAKEFILE)_$(TIEEXE).d: $(TIESRCS) genebank.h tiexdrcom.h
ifeq ($(NET),yes)
$(MAKEFILE)_$(TIEEXE).d: mesg.h
ifeq ($(NETTYPE),udp)
$(MAKEFILE)_$(TIEEXE).d: datpkt.h
endif # NETTYPE
endif # NET
ifeq ($(FRONTEND),bgl)
$(MAKEFILE)_$(TIEEXE).d: $(BGLCOMHOME)bgl_dat_xdr.h
endif # FRONTEND
	$(CC) -M $(TIECFLAGS) -c $(TIESRCS) > $@

$(MAKEFILE)_$(ARGEXE).d: $(ARGSRCS) genebank.h tiexdrcom.h
ifeq ($(NET),yes)
$(MAKEFILE)_$(ARGEXE).d: mesg.h
endif # NET
	$(CC) -M $(ARGCFLAGS) -c $(ARGSRCS) > $@

ifeq ($(FRONTEND),bgl)
$(MAKEFILE)_$(TBGLPASSWDEXE).d: $(TBGLPASSWDSRCS)
	$(CC) -M $(COMCFLAGS) -c $(TBGLPASSWDSRCS) > $@
$(TBGLPASSWDOBJS):
	$(CC) -c $(TBGLPASSWDCFLAGS) $(subst .o,.c,$@)
$(BGLCOMHOME)bgl_dat_xdr.c: $(BGLCOMHOME)bgl_dat_xdr.x
	-$(RM) $(BGLCOMHOME)$@
	rpcgen $(RPCGENFLAGS) -c -o $(BGLCOMHOME)$@ $<
$(BGLCOMHOME)bgl_dat_xdr.h: $(BGLCOMHOME)bgl_dat_xdr.x
	-$(RM) $(BGLCOMHOME)$@
	rpcgen $(RPCGENFLAGS) -h -o $(BGLCOMHOME)$@ $<
endif # FRONTEND

$(MAKEFILE)_$(DIFFSCANEXE).d: $(DIFFSCANSRCS)
	$(CC) -M $(COMCFLAGS) -c $(DIFFSCANSRCS) > $@
$(MAKEFILE)_$(RESEQEXE).d: $(RESEQSRCS)
	$(CC) -M $(COMCFLAGS) -c $(RESEQSRCS) > $@
$(MAKEFILE)_$(GENALIGNEXE).d: $(GENALIGNSRCS) genebank.h tiexdrcom.h
	$(CC) -M $(GENALIGNCFLAGS) -c $(GENALIGNSRCS) > $@
$(MAKEFILE)_$(THREADTREEEXE).d: $(THREADTREESRCS) genebank.h tiexdrcom.h
	$(CC) -M $(THREADTREECFLAGS) -c $(THREADTREESRCS) > $@
$(MAKEFILE)_$(SOUPUPDTRCEXE).d: $(SOUPUPDTRCSRCS) genebank.h tiexdrcom.h
	$(CC) -M $(SOUPUPDTRCCFLAGS) -c $(SOUPUPDTRCSRCS) > $@

$(MAKEFILE)_$(PROBEEXE).d: $(PROBESRCS) genebank.h tiexdrcom.h
	$(CC) -M $(PROBECFLAGS) -c $(PROBESRCS) > $@
$(COMOBJS):
	$(CC) -c $(COMCFLAGS) $(subst .o,.c,$@) -o $@
$(TIEOBJS1):
	$(CC) -c $(TIECFLAGS) $(subst .o,.c,$@) -o $@
$(ARGOBJS1):
	$(CC) -c $(ARGCFLAGS) $(subst .o,.c,$@) -o $@
$(DIFFSCANOBJS):
	$(CC) -c $(DIFFSCANCFLAGS) $(subst .o,.c,$@) -o $@
$(RESEQOBJS):
	$(CC) -c $(RESEQCFLAGS) $(subst .o,.c,$@) -o $@
$(GENALIGNOBJS1):
	$(CC) -c $(GENALIGNCFLAGS) $(subst .o,.c,$@) -o $@
$(THREADTREEOBJS1):
	$(CC) -c $(THREADTREECFLAGS) $(subst .o,.c,$@) -o $@
$(SOUPUPDTRCOBJS1):
	$(CC) -c $(SOUPUPDTRCCFLAGS) $(subst .o,.c,$@) -o $@

ifeq ($(TIEAUDIO),yes)

$(TIEAUDCLOBJS1):
	$(CC) -c $(TIEAUDCLCFLAGS) $(subst .o,.c,$@) -o $@

$(TIE2PDOBJS1):
	$(CC) -c $(TIE2PDCFLAGS) $(subst .o,.c,$@) -o $@

endif # TIEAUDIO

$(PROBEOBJS1):
	$(CC) -c $(PROBECFLAGS) $(subst .o,.c,$@) -o $@
$(OPNSOCKOBJS):
	$(CC) -c $(OPNSOCKCFLAGS) $(subst .o,.c,$@) -o $@
$(TIEUDPTNLOBJS1):
	$(CC) -c $(TIEUDPTNLCFLAGS) $(subst .o,.c,$@) -o $@
$(TIEUDPTNLCOBJS1):
	$(CC) -c $(TIEUDPTNLCCFLAGS) $(subst .o,.c,$@) -o $@

ifeq ($(NET),yes)
$(MAKEFILE)_$(LOG2IPMAPEXE).d: $(LOG2IPMAPSRCS) mesg.h tiexdrcom.h
	$(CC) -M $(LOG2IPMAPCFLAGS) -c $(LOG2IPMAPSRCS) > $@
$(LOG2IPMAPOBJS):
	$(CC) -c $(LOG2IPMAPCFLAGS) $(subst .o,.c,$@) -o $@
$(NETXDROBJS):
	$(CC) -c $(NETXDRCFLAGS) $(subst .o,.c,$@)
ifeq ($(NETTYPE),udp)
$(MAKEFILE)_$(TIEUDPTNLEXE).d: $(TIEUDPTNLSRCS)
	$(CC) -M $(TIEUDPTNLCFLAGS) -c $(TIEUDPTNLSRCS) > $@
$(MAKEFILE)_$(TIEUDPTNLCEXE).d: $(TIEUDPTNLCSRCS)
	$(CC) -M $(TIEUDPTNLCCFLAGS) -c $(TIEUDPTNLCSRCS) > $@
endif # NETTYPE
endif # NET

ifeq ($(TIEAUDIO),yes)

$(MAKEFILE)_$(TIEAUDCLEXE).d: $(TIEAUDCLSRCS)
	$(CC) -M $(TIEAUDCLCFLAGS) -c $(TIEAUDCLSRCS) > $@

$(MAKEFILE)_$(TIE2PDEXE).d: $(TIE2PDSRCS)
	$(CC) -M $(TIE2PDCFLAGS) -c $(TIE2PDSRCS) > $@

endif # TIEAUDIO

ifneq ($(MAKECMDGOALS),clean)
-include $(strip \
    $(MAKEFILE)_$(TIEEXE).d \
    $(MAKEFILE)_$(ARGEXE).d \
    $(MAKEFILE)_$(DIFFSCANEXE).d \
    $(MAKEFILE)_$(RESEQEXE).d \
    $(MAKEFILE)_$(GENALIGNEXE).d \
    $(MAKEFILE)_$(THREADTREEEXE).d \
    $(MAKEFILE)_$(SOUPUPDTRCEXE).d \
    $(MAKEFILE)_$(PROBEEXE).d)

ifeq ($(FRONTEND),bgl)
-include $(MAKEFILE)_$(TBGLPASSWDEXE).d
endif # FRONTEND

ifeq ($(NET),yes)
-include $(MAKEFILE)_$(LOG2IPMAPEXE).d
ifeq ($(NETTYPE),udp)
-include $(strip $(MAKEFILE)_$(TIEUDPTNLEXE).d \
         $(MAKEFILE)_$(TIEUDPTNLCEXE).d)
endif # NETTYPE
endif # NET

ifeq ($(TIEAUDIO),yes)
-include $(MAKEFILE)_$(TIEAUDCLEXE).d
-include $(MAKEFILE)_$(TIE2PDEXE).d
endif # TIEAUDIO

endif # MAKECMDGOALS
