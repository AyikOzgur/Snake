################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/game.cpp \
../src/main.cpp \
../src/snake.cpp \
../src/window.cpp \
../src/world.cpp 

CPP_DEPS += \
./src/game.d \
./src/main.d \
./src/snake.d \
./src/window.d \
./src/world.d 

OBJS += \
./src/game.o \
./src/main.o \
./src/snake.o \
./src/window.o \
./src/world.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/ozgur/eclipse_cpp_workspace/Snake/includes" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/game.d ./src/game.o ./src/main.d ./src/main.o ./src/snake.d ./src/snake.o ./src/window.d ./src/window.o ./src/world.d ./src/world.o

.PHONY: clean-src

