################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/GPIO/gpioUtil.cpp 

OBJS += \
./src/GPIO/gpioUtil.o 

CPP_DEPS += \
./src/GPIO/gpioUtil.d 


# Each subdirectory must supply rules for building sources it contributes
src/GPIO/%.o: ../src/GPIO/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	arm-unknown-linux-gnueabi-g++ -IC:/cygwin/opt/cross/x-tools/arm-unknown-linux-gnueabi/arm-unknown-linux-gnueabi/sysroot/usr/include -IC:/Users/Jendrik/Desktop/boost -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


