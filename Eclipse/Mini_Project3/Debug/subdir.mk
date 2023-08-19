################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC.c \
../DcMotor.c \
../GPIO.c \
../LCD.c \
../Main.c \
../TIMER.c \
../lM35_TempSensor.c 

OBJS += \
./ADC.o \
./DcMotor.o \
./GPIO.o \
./LCD.o \
./Main.o \
./TIMER.o \
./lM35_TempSensor.o 

C_DEPS += \
./ADC.d \
./DcMotor.d \
./GPIO.d \
./LCD.d \
./Main.d \
./TIMER.d \
./lM35_TempSensor.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


