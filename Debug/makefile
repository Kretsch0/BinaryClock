################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/GPIO/wiringPi/subdir.mk
-include src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: pre-build main-build

# Main-build Target
main-build: BinaryClock.a

# Tool invocations
BinaryClock.a: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: Cygwin C++ Linker'
	arm-unknown-linux-gnueabi-g++ -L"c:\cygwin\opt\cross\x-tools\arm-unknown-linux-gnueabi\arm-unknown-linux-gnueabi\sysroot\usr\lib" -o "BinaryClock.a" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(C++_DEPS)$(OBJS)$(C_DEPS)$(CC_DEPS)$(CPP_DEPS)$(EXECUTABLES)$(CXX_DEPS)$(C_UPPER_DEPS) BinaryClock.a
	-@echo ' '

pre-build:
	-@echo 'Our auto deploy to RPi using putty script'
	-C:/eclipse/deployment_scripts/rpi_deploy_debug.bat $(OutDir)BinaryClock.a "/home/pi/projects/BinaryClock.a"
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: main-build pre-build

-include ../makefile.targets
