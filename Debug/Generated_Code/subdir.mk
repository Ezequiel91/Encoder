################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Generated_Code/AS1.c \
../Generated_Code/ASerialLdd1.c \
../Generated_Code/BitIoLdd1.c \
../Generated_Code/BitIoLdd2.c \
../Generated_Code/BitIoLdd3.c \
../Generated_Code/C11.c \
../Generated_Code/C21.c \
../Generated_Code/CS1.c \
../Generated_Code/Cpu.c \
../Generated_Code/DIR1.c \
../Generated_Code/MAX1.c \
../Generated_Code/PE_LDD.c \
../Generated_Code/PIDI1.c \
../Generated_Code/PWM1.c \
../Generated_Code/PwmLdd1.c \
../Generated_Code/Q4C1.c \
../Generated_Code/TI1.c \
../Generated_Code/TU1.c \
../Generated_Code/TU2.c \
../Generated_Code/Tacho1.c \
../Generated_Code/TimerIntLdd1.c \
../Generated_Code/UTIL1.c \
../Generated_Code/WAIT1.c 

OBJS += \
./Generated_Code/AS1.o \
./Generated_Code/ASerialLdd1.o \
./Generated_Code/BitIoLdd1.o \
./Generated_Code/BitIoLdd2.o \
./Generated_Code/BitIoLdd3.o \
./Generated_Code/C11.o \
./Generated_Code/C21.o \
./Generated_Code/CS1.o \
./Generated_Code/Cpu.o \
./Generated_Code/DIR1.o \
./Generated_Code/MAX1.o \
./Generated_Code/PE_LDD.o \
./Generated_Code/PIDI1.o \
./Generated_Code/PWM1.o \
./Generated_Code/PwmLdd1.o \
./Generated_Code/Q4C1.o \
./Generated_Code/TI1.o \
./Generated_Code/TU1.o \
./Generated_Code/TU2.o \
./Generated_Code/Tacho1.o \
./Generated_Code/TimerIntLdd1.o \
./Generated_Code/UTIL1.o \
./Generated_Code/WAIT1.o 

C_DEPS += \
./Generated_Code/AS1.d \
./Generated_Code/ASerialLdd1.d \
./Generated_Code/BitIoLdd1.d \
./Generated_Code/BitIoLdd2.d \
./Generated_Code/BitIoLdd3.d \
./Generated_Code/C11.d \
./Generated_Code/C21.d \
./Generated_Code/CS1.d \
./Generated_Code/Cpu.d \
./Generated_Code/DIR1.d \
./Generated_Code/MAX1.d \
./Generated_Code/PE_LDD.d \
./Generated_Code/PIDI1.d \
./Generated_Code/PWM1.d \
./Generated_Code/PwmLdd1.d \
./Generated_Code/Q4C1.d \
./Generated_Code/TI1.d \
./Generated_Code/TU1.d \
./Generated_Code/TU2.d \
./Generated_Code/Tacho1.d \
./Generated_Code/TimerIntLdd1.d \
./Generated_Code/UTIL1.d \
./Generated_Code/WAIT1.d 


# Each subdirectory must supply rules for building sources it contributes
Generated_Code/%.o: ../Generated_Code/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"C:\Freescale\KDS_2.0.0\eclipse\ProcessorExpert/lib/Kinetis/pdd/inc" -I"C:\Freescale\KDS_2.0.0\eclipse\ProcessorExpert/lib/Kinetis/iofiles" -I"C:/Users/Ezequiel/Documents/ARM/New_Workspace_2/Encoder/Sources" -I"C:/Users/Ezequiel/Documents/ARM/New_Workspace_2/Encoder/Generated_Code" -I"C:\Freescale\KDS_2.0.0\eclipse\ProcessorExpert/lib/Kinetis/pdd2/MK64FN1M0LL12/system" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


