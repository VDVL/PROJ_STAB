################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../mikrosdk_v2/drv/lib/src/lib_drv_pwm/drv_pwm.c 

OBJS += \
./mikrosdk_v2/drv/lib/src/lib_drv_pwm/drv_pwm.o 

C_DEPS += \
./mikrosdk_v2/drv/lib/src/lib_drv_pwm/drv_pwm.d 


# Each subdirectory must supply rules for building sources it contributes
mikrosdk_v2/drv/lib/src/lib_drv_pwm/%.o mikrosdk_v2/drv/lib/src/lib_drv_pwm/%.su: ../mikrosdk_v2/drv/lib/src/lib_drv_pwm/%.c mikrosdk_v2/drv/lib/src/lib_drv_pwm/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I"C:/Users/be06.BREIZELEC/Desktop/PROJ_STAB/Proj_stab/mikrosdk_v2" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-mikrosdk_v2-2f-drv-2f-lib-2f-src-2f-lib_drv_pwm

clean-mikrosdk_v2-2f-drv-2f-lib-2f-src-2f-lib_drv_pwm:
	-$(RM) ./mikrosdk_v2/drv/lib/src/lib_drv_pwm/drv_pwm.d ./mikrosdk_v2/drv/lib/src/lib_drv_pwm/drv_pwm.o ./mikrosdk_v2/drv/lib/src/lib_drv_pwm/drv_pwm.su

.PHONY: clean-mikrosdk_v2-2f-drv-2f-lib-2f-src-2f-lib_drv_pwm
