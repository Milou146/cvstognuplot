################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Connection.cpp \
../file.cpp \
../main.cpp \
../main1.cpp \
../node.cpp \
../traffic.cpp 

CPP_DEPS += \
./Connection.d \
./file.d \
./main.d \
./main1.d \
./node.d \
./traffic.d 

OBJS += \
./Connection.o \
./file.o \
./main.o \
./main1.o \
./node.o \
./traffic.o 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean--2e-

clean--2e-:
	-$(RM) ./Connection.d ./Connection.o ./file.d ./file.o ./main.d ./main.o ./main1.d ./main1.o ./node.d ./node.o ./traffic.d ./traffic.o

.PHONY: clean--2e-

