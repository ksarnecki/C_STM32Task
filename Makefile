CC = arm-eabi-gcc -w
OBJCOPY = arm-eabi-objcopy
FLAGS = -mthumb -mcpu=cortex-m4 \
	-mfloat-abi=softfp -mfpu=fpv4-sp-d16
CPPFLAGS = -DSTM32F411xE
CFLAGS = $(FLAGS) -Wall -g -I/opt/arm/stm32/inc \
	 -I/opt/arm/stm32/CMSIS/Include \
	 -I/opt/arm/stm32/CMSIS/Device/ST/STM32F4xx/Include \
	 -O2 -ffunction-sections -fdata-sections
LDFLAGS = $(FLAGS) -Wl,--gc-sections -nostartfiles \
	  -L/opt/arm/stm32/lds -Tstm32f411re.lds
vpath %.c /opt/arm/stm32/src

.PHONY: all clean
	.SECONDARY: leds.elf irc/irc_ll_api.o irc/irc_hl_api.o main.o diods/diods_ll_api.o timer/timer_ll_api.o uart/uart_soft.o uart/uart_hardware.o diods/diods_hl_api.o startup_stm32.o sbrk.o\
		delay.o gpio.o
all: leds.bin

%.elf : main.o irc/irc_ll_api.o irc/irc_hl_api.o diods/diods_ll_api.o diods/diods_hl_api.o timer/timer_ll_api.o uart/uart_soft.o uart/uart_hardware.o startup_stm32.o delay.o gpio.o sbrk.o
	$(CC) $(LDFLAGS) $^ -o $@
%.bin : %.elf
	$(OBJCOPY) $< $@ -O binary
clean :
	rm -f *.bin *.elf *.hex *.d *.o *.bak *~


