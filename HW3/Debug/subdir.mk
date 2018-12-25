################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Base.cpp \
../D1.cpp \
../D1a.cpp \
../D2.cpp \
../main.cpp 

OBJS += \
./Base.o \
./D1.o \
./D1a.o \
./D2.o \
./main.o 

CPP_DEPS += \
./Base.d \
./D1.d \
./D1a.d \
./D2.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


