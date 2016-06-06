#!/bin/bash

# Quick Flash script for STM32F4 NUCLEO-F401RE board

if [ $# -eq 0 ]; then
  file=`ls *.bin`
elif [ $# -eq 1 ]; then
  file=$1
else
  echo "Usage:"
  echo $0 "[the_name_of_the_file_with_the_binary_flash_image]"
  exit
fi

openocd -d0 \
 -f board/st_nucleo_f401re.cfg \
 -c "init" -c "reset halt" \
 -c "flash write_image erase $file 0x8000000" \
 -c "verify_image $file" -c "reset" -c "shutdown"