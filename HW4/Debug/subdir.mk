################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Base.cpp \
../PrivDerived.cpp \
../ProtDerived.cpp \
../PublicDerived.cpp \
../dPriv.cpp \
../dProt.cpp \
../dPublic.cpp \
../main.cpp 

OBJS += \
./Base.o \
./PrivDerived.o \
./ProtDerived.o \
./PublicDerived.o \
./dPriv.o \
./dProt.o \
./dPublic.o \
./main.o 

CPP_DEPS += \
./Base.d \
./PrivDerived.d \
./ProtDerived.d \
./PublicDerived.d \
./dPriv.d \
./dProt.d \
./dPublic.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


