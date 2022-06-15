################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../mikrosdk_v2/tests/clicks/spi/click_bee/bee.c \
../mikrosdk_v2/tests/clicks/spi/click_bee/main.c 

OBJS += \
./mikrosdk_v2/tests/clicks/spi/click_bee/bee.o \
./mikrosdk_v2/tests/clicks/spi/click_bee/main.o 

C_DEPS += \
./mikrosdk_v2/tests/clicks/spi/click_bee/bee.d \
./mikrosdk_v2/tests/clicks/spi/click_bee/main.d 


# Each subdirectory must supply rules for building sources it contributes
mikrosdk_v2/tests/clicks/spi/click_bee/%.o mikrosdk_v2/tests/clicks/spi/click_bee/%.su: ../mikrosdk_v2/tests/clicks/spi/click_bee/%.c mikrosdk_v2/tests/clicks/spi/click_bee/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I"C:/Users/be06.BREIZELEC/Desktop/PROJ_STAB/Proj_stab/mikrosdk_v2" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-mikrosdk_v2-2f-tests-2f-clicks-2f-spi-2f-click_bee

clean-mikrosdk_v2-2f-tests-2f-clicks-2f-spi-2f-click_bee:
	-$(RM) ./mikrosdk_v2/tests/clicks/spi/click_bee/bee.d ./mikrosdk_v2/tests/clicks/spi/click_bee/bee.o ./mikrosdk_v2/tests/clicks/spi/click_bee/bee.su ./mikrosdk_v2/tests/clicks/spi/click_bee/main.d ./mikrosdk_v2/tests/clicks/spi/click_bee/main.o ./mikrosdk_v2/tests/clicks/spi/click_bee/main.su

.PHONY: clean-mikrosdk_v2-2f-tests-2f-clicks-2f-spi-2f-click_bee

