################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Application.c \
../Timer0.c \
../adc.c \
../dc_motor.c \
../external_int.c \
../lcd.c 

OBJS += \
./Application.o \
./Timer0.o \
./adc.o \
./dc_motor.o \
./external_int.o \
./lcd.o 

C_DEPS += \
./Application.d \
./Timer0.d \
./adc.d \
./dc_motor.d \
./external_int.d \
./lcd.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


