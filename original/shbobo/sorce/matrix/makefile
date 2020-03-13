
ST32MAP = -Ttext 0x0 -Tbss 0x20000000
OS:=$(shell uname -s | cut -f1 -d_)
assFlags=-W -mthumb-interwork -mapcs-32 -march=armv7 -mcpu=cortex-m3
lnkFlags=-v $(ST32MAP) -e0 -nostartfiles 
objFlags=-O binary
assLinux=arm-none-eabi-as 
lnkLinux=arm-none-eabi-ld
objLinux=arm-none-eabi-objcopy
assDarwin=arm-elf-as
lnkDarwin=arm-elf-ld
objDarwin=arm-elf-objcopy
assCYGWIN=arm-elf-as
lnkCYGWIN=arm-elf-ld
objCYGWIN=arm-elf-objcopy
export ass = $(ass$(OS)) $(assFlags)
export lnk = $(lnk$(OS)) $(lnkFlags)
export obj = $(obj$(OS)) $(objFlags)

shnth: assFlags += --defsym SHBOBO=0 
shnth: oto=shnth
#--defsym SHNTH=1
shnth: main
shtar: assFlags += --defsym SHBOBO=1 
shtar: oto=shtar
#--defsym SHTAR=1
shtar: main

main:
	-$(ass) -o $(oto).o wanilla.s
	-$(lnk) -o $(oto).elf $(oto).o
	-$(obj) $(oto).elf $(oto).bin
	mv $(oto).bin ../..
	rm -f *.lst *.o *.elf *.*~ *.bin *.stackdump a.out makefile~

