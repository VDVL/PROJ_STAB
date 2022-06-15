################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../mikrosdk_v2/api/vtft/lib_vtft/src/vtft.c \
../mikrosdk_v2/api/vtft/lib_vtft/src/vtft_drawing.c \
../mikrosdk_v2/api/vtft/lib_vtft/src/vtft_touch.c 

OBJS += \
./mikrosdk_v2/api/vtft/lib_vtft/src/vtft.o \
./mikrosdk_v2/api/vtft/lib_vtft/src/vtft_drawing.o \
./mikrosdk_v2/api/vtft/lib_vtft/src/vtft_touch.o 

C_DEPS += \
./mikrosdk_v2/api/vtft/lib_vtft/src/vtft.d \
./mikrosdk_v2/api/vtft/lib_vtft/src/vtft_drawing.d \
./mikrosdk_v2/api/vtft/lib_vtft/src/vtft_touch.d 


# Each subdirectory must supply rules for building sources it contributes
mikrosdk_v2/api/vtft/lib_vtft/src/%.o mikrosdk_v2/api/vtft/lib_vtft/src/%.su: ../mikrosdk_v2/api/vtft/lib_vtft/src/%.c mikrosdk_v2/api/vtft/lib_vtft/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I"C:/Users/be06.BREIZELEC/Desktop/PROJ_STAB/Proj_stab/mikrosdk_v2" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-mikrosdk_v2-2f-api-2f-vtft-2f-lib_vtft-2f-src

clean-mikrosdk_v2-2f-api-2f-vtft-2f-lib_vtft-2f-src:
	-$(RM) ./mikrosdk_v2/api/vtft/lib_vtft/src/vtft.d ./mikrosdk_v2/api/vtft/lib_vtft/src/vtft.o ./mikrosdk_v2/api/vtft/lib_vtft/src/vtft.su ./mikrosdk_v2/api/vtft/lib_vtft/src/vtft_drawing.d ./mikrosdk_v2/api/vtft/lib_vtft/src/vtft_drawing.o ./mikrosdk_v2/api/vtft/lib_vtft/src/vtft_drawing.su ./mikrosdk_v2/api/vtft/lib_vtft/src/vtft_touch.d ./mikrosdk_v2/api/vtft/lib_vtft/src/vtft_touch.o ./mikrosdk_v2/api/vtft/lib_vtft/src/vtft_touch.su

.PHONY: clean-mikrosdk_v2-2f-api-2f-vtft-2f-lib_vtft-2f-src

