################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/LPC845_GPIO_Dr.c \
../src/SysTick.c \
../src/adc.c \
../src/cr_startup_lpc84x.c \
../src/crp.c \
../src/ctimer.c \
../src/cucatesla01.c \
../src/hc__sr04.c \
../src/inicializacion.c \
../src/mde_com.c \
../src/mde_mov.c \
../src/mrt.c \
../src/mtb.c \
../src/oscilador.c \
../src/servo.c \
../src/swm.c \
../src/timers.c \
../src/uart0.c 

S_SRCS += \
../src/aeabi_romdiv_patch.s 

C_DEPS += \
./src/LPC845_GPIO_Dr.d \
./src/SysTick.d \
./src/adc.d \
./src/cr_startup_lpc84x.d \
./src/crp.d \
./src/ctimer.d \
./src/cucatesla01.d \
./src/hc__sr04.d \
./src/inicializacion.d \
./src/mde_com.d \
./src/mde_mov.d \
./src/mrt.d \
./src/mtb.d \
./src/oscilador.d \
./src/servo.d \
./src/swm.d \
./src/timers.d \
./src/uart0.d 

OBJS += \
./src/LPC845_GPIO_Dr.o \
./src/SysTick.o \
./src/adc.o \
./src/aeabi_romdiv_patch.o \
./src/cr_startup_lpc84x.o \
./src/crp.o \
./src/ctimer.o \
./src/cucatesla01.o \
./src/hc__sr04.o \
./src/inicializacion.o \
./src/mde_com.o \
./src/mde_mov.o \
./src/mrt.o \
./src/mtb.o \
./src/oscilador.o \
./src/servo.o \
./src/swm.o \
./src/timers.o \
./src/uart0.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -DCORE_M0PLUS -D__MTB_BUFFER_SIZE=256 -D__USE_ROMDIVIDE -D__LPC84X__ -D__REDLIB__ -I"C:\Users\Magdalena\Desktop\cucatesla02.2(ex1.42)\inc" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0 -mthumb -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/%.o: ../src/%.s src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU Assembler'
	arm-none-eabi-gcc -c -x assembler-with-cpp -DDEBUG -D__CODE_RED -DCORE_M0PLUS -D__USE_ROMDIVIDE -D__LPC84X__ -D__REDLIB__ -I"C:\Users\Magdalena\Desktop\cucatesla02.2(ex1.42)\inc" -g3 -mcpu=cortex-m0 -mthumb -specs=redlib.specs -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/LPC845_GPIO_Dr.d ./src/LPC845_GPIO_Dr.o ./src/SysTick.d ./src/SysTick.o ./src/adc.d ./src/adc.o ./src/aeabi_romdiv_patch.o ./src/cr_startup_lpc84x.d ./src/cr_startup_lpc84x.o ./src/crp.d ./src/crp.o ./src/ctimer.d ./src/ctimer.o ./src/cucatesla01.d ./src/cucatesla01.o ./src/hc__sr04.d ./src/hc__sr04.o ./src/inicializacion.d ./src/inicializacion.o ./src/mde_com.d ./src/mde_com.o ./src/mde_mov.d ./src/mde_mov.o ./src/mrt.d ./src/mrt.o ./src/mtb.d ./src/mtb.o ./src/oscilador.d ./src/oscilador.o ./src/servo.d ./src/servo.o ./src/swm.d ./src/swm.o ./src/timers.d ./src/timers.o ./src/uart0.d ./src/uart0.o

.PHONY: clean-src

