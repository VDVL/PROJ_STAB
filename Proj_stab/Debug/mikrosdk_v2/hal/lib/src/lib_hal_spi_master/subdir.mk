################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../mikrosdk_v2/hal/lib/src/lib_hal_spi_master/hal_spi_master.c 

OBJS += \
./mikrosdk_v2/hal/lib/src/lib_hal_spi_master/hal_spi_master.o 

C_DEPS += \
./mikrosdk_v2/hal/lib/src/lib_hal_spi_master/hal_spi_master.d 


# Each subdirectory must supply rules for building sources it contributes
mikrosdk_v2/hal/lib/src/lib_hal_spi_master/%.o mikrosdk_v2/hal/lib/src/lib_hal_spi_master/%.su: ../mikrosdk_v2/hal/lib/src/lib_hal_spi_master/%.c mikrosdk_v2/hal/lib/src/lib_hal_spi_master/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I"C:/Users/be06.BREIZELEC/Desktop/PROJ_STAB/Proj_stab/mikrosdk_v2" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-mikrosdk_v2-2f-hal-2f-lib-2f-src-2f-lib_hal_spi_master

clean-mikrosdk_v2-2f-hal-2f-lib-2f-src-2f-lib_hal_spi_master:
	-$(RM) ./mikrosdk_v2/hal/lib/src/lib_hal_spi_master/hal_spi_master.d ./mikrosdk_v2/hal/lib/src/lib_hal_spi_master/hal_spi_master.o ./mikrosdk_v2/hal/lib/src/lib_hal_spi_master/hal_spi_master.su

.PHONY: clean-mikrosdk_v2-2f-hal-2f-lib-2f-src-2f-lib_hal_spi_master
