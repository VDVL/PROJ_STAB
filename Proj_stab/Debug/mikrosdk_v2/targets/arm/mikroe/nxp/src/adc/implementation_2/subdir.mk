################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../mikrosdk_v2/targets/arm/mikroe/nxp/src/adc/implementation_2/hal_ll_adc.c 

OBJS += \
./mikrosdk_v2/targets/arm/mikroe/nxp/src/adc/implementation_2/hal_ll_adc.o 

C_DEPS += \
./mikrosdk_v2/targets/arm/mikroe/nxp/src/adc/implementation_2/hal_ll_adc.d 


# Each subdirectory must supply rules for building sources it contributes
mikrosdk_v2/targets/arm/mikroe/nxp/src/adc/implementation_2/%.o mikrosdk_v2/targets/arm/mikroe/nxp/src/adc/implementation_2/%.su: ../mikrosdk_v2/targets/arm/mikroe/nxp/src/adc/implementation_2/%.c mikrosdk_v2/targets/arm/mikroe/nxp/src/adc/implementation_2/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I"C:/Users/be06.BREIZELEC/Desktop/PROJ_STAB/Proj_stab/mikrosdk_v2" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-mikrosdk_v2-2f-targets-2f-arm-2f-mikroe-2f-nxp-2f-src-2f-adc-2f-implementation_2

clean-mikrosdk_v2-2f-targets-2f-arm-2f-mikroe-2f-nxp-2f-src-2f-adc-2f-implementation_2:
	-$(RM) ./mikrosdk_v2/targets/arm/mikroe/nxp/src/adc/implementation_2/hal_ll_adc.d ./mikrosdk_v2/targets/arm/mikroe/nxp/src/adc/implementation_2/hal_ll_adc.o ./mikrosdk_v2/targets/arm/mikroe/nxp/src/adc/implementation_2/hal_ll_adc.su

.PHONY: clean-mikrosdk_v2-2f-targets-2f-arm-2f-mikroe-2f-nxp-2f-src-2f-adc-2f-implementation_2

