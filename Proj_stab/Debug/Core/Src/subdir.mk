################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/datas_fusion.c \
../Core/Src/drv8311.c \
../Core/Src/lsm6dso.c \
../Core/Src/lsm6dso_reg.c \
../Core/Src/lsm9ds1.c \
../Core/Src/main.c \
../Core/Src/motion_di_manager.c \
../Core/Src/pwm_driver.c \
../Core/Src/stm32l4xx_hal_msp.c \
../Core/Src/stm32l4xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32l4xx.c 

OBJS += \
./Core/Src/datas_fusion.o \
./Core/Src/drv8311.o \
./Core/Src/lsm6dso.o \
./Core/Src/lsm6dso_reg.o \
./Core/Src/lsm9ds1.o \
./Core/Src/main.o \
./Core/Src/motion_di_manager.o \
./Core/Src/pwm_driver.o \
./Core/Src/stm32l4xx_hal_msp.o \
./Core/Src/stm32l4xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32l4xx.o 

C_DEPS += \
./Core/Src/datas_fusion.d \
./Core/Src/drv8311.d \
./Core/Src/lsm6dso.d \
./Core/Src/lsm6dso_reg.d \
./Core/Src/lsm9ds1.d \
./Core/Src/main.d \
./Core/Src/motion_di_manager.d \
./Core/Src/pwm_driver.d \
./Core/Src/stm32l4xx_hal_msp.d \
./Core/Src/stm32l4xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32l4xx.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../Drivers/CMSIS/Include -I"C:/Users/be06.BREIZELEC/STM32Cube/Repository/Packs/STMicroelectronics/X-CUBE-MEMS1/9.2.0/Middlewares/ST/STM32_MotionDI_Library/Inc" -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I"C:/Users/be06.BREIZELEC/Desktop/PROJ_STAB/Proj_stab/lib_IMU_LSM9DS1" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/datas_fusion.d ./Core/Src/datas_fusion.o ./Core/Src/datas_fusion.su ./Core/Src/drv8311.d ./Core/Src/drv8311.o ./Core/Src/drv8311.su ./Core/Src/lsm6dso.d ./Core/Src/lsm6dso.o ./Core/Src/lsm6dso.su ./Core/Src/lsm6dso_reg.d ./Core/Src/lsm6dso_reg.o ./Core/Src/lsm6dso_reg.su ./Core/Src/lsm9ds1.d ./Core/Src/lsm9ds1.o ./Core/Src/lsm9ds1.su ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/motion_di_manager.d ./Core/Src/motion_di_manager.o ./Core/Src/motion_di_manager.su ./Core/Src/pwm_driver.d ./Core/Src/pwm_driver.o ./Core/Src/pwm_driver.su ./Core/Src/stm32l4xx_hal_msp.d ./Core/Src/stm32l4xx_hal_msp.o ./Core/Src/stm32l4xx_hal_msp.su ./Core/Src/stm32l4xx_it.d ./Core/Src/stm32l4xx_it.o ./Core/Src/stm32l4xx_it.su ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_stm32l4xx.d ./Core/Src/system_stm32l4xx.o ./Core/Src/system_stm32l4xx.su

.PHONY: clean-Core-2f-Src

