################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/control.cpp \
../src/converttobin.cpp \
../src/initilizer.cpp \
../src/main.cpp \
../src/pin.cpp \
../src/time.cpp 

OBJS += \
./src/control.o \
./src/converttobin.o \
./src/initilizer.o \
./src/main.o \
./src/pin.o \
./src/time.o 

CPP_DEPS += \
./src/control.d \
./src/converttobin.d \
./src/initilizer.d \
./src/main.d \
./src/pin.d \
./src/time.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	arm-unknown-linux-gnueabi-g++ -IC:/cygwin/opt/cross/x-tools/arm-unknown-linux-gnueabi/arm-unknown-linux-gnueabi/sysroot/usr/include -IC:/Users/Jendrik/Desktop/boost -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


