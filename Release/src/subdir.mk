################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/converttobin.cpp \
../src/gpio_util.cpp \
../src/initilizer.cpp \
../src/main.cpp \
../src/time.cpp 

OBJS += \
./src/converttobin.o \
./src/gpio_util.o \
./src/initilizer.o \
./src/main.o \
./src/time.o 

CPP_DEPS += \
./src/converttobin.d \
./src/gpio_util.d \
./src/initilizer.d \
./src/main.d \
./src/time.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


