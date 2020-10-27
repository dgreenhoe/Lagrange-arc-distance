#-----------------------------------------------------------------------------
# Project Makefile
# Daniel J. Greenhoe
#-----------------------------------------------------------------------------
#--------------------------------------
# TARGET
#--------------------------------------
TARGET = larc

#--------------------------------------
# Files
#--------------------------------------
FILES_OBJ = main.obj c1.obj euclid.obj lab2015larc.obj larc.obj print.obj r1.obj r2.obj r3.obj r4.obj r6.obj r1op.obj r2op.obj r3op.obj r4op.obj r6op.obj testlarc.obj
FILES_H   = main.h   c1.h   euclid.h   lab2015larc.h   larc.h   print.h   r1.h   r2.h   r3.h   r4.h   r6.h   r1op.h   r2op.h   r3op.h   r4op.h   r6op.h   testlarc.h  

#--------------------------------------
# directories
#--------------------------------------
DIR_BIN = c:\p\bcc\bin      # binaries (execuatables) directory
DIR_INC = c:\p\bcc\Include  # include files directory
DIR_LIB = c:\p\bcc\Lib      # libraries directory

#--------------------------------------
# Programs
#--------------------------------------
PRG_COMPILE = $(DIR_BIN)\bcc32
PRG_LINK    = $(DIR_BIN)\bcc32

#--------------------------------------
# master build control
#--------------------------------------
$(TARGET).exe: $(FILES_OBJ) $(FILES_H) makefile
  time /T
  $(PRG_LINK)  -I$(DIR_INC) -I. -L$(DIR_LIB) -e$(TARGET).exe $(FILES_OBJ)
  dir $(TARGET).exe

#--------------------------------------
# implicit build control
#--------------------------------------
.cpp.obj:
	$(PRG_COMPILE) -I$(DIR_INC) -I. -L$(DIR_LIB) -c -w-ncf $&.cpp

#--------------------------------------
# commands
#--------------------------------------
clean:
  del *.obj
  del *.tds

scrub:
  make clean
  del *.exe
  del /Q data\*

new:
  del *.obj
  make

zip:
  zip -o -9 -r $(TARGET).zip * -x *.obj *.tds *.exe *.dat
  unzip -l $(TARGET).zip
  dir *.zip
  