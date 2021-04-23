################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/BF700.c \
../src/adau1977.c \
../src/can.c \
../src/port.c \
../src/sport.c \
../src/twi.c \
../src/uart.c 

SRC_OBJS += \
./src/BF700.doj \
./src/adau1977.doj \
./src/can.doj \
./src/port.doj \
./src/sport.doj \
./src/twi.doj \
./src/uart.doj 

C_DEPS += \
./src/BF700.d \
./src/adau1977.d \
./src/can.d \
./src/port.d \
./src/sport.d \
./src/twi.d \
./src/uart.d 


# Each subdirectory must supply rules for building sources it contributes
src/BF700.doj: ../src/BF700.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore Blackfin C/C++ Compiler'
	ccblkfn -c -file-attr ProjectName="BF700" -proc ADSP-BF700 -flags-compiler --no_wrap_diagnostics -si-revision 1.1 -g -DCORE0 -D_DEBUG @includes-5b7a169a0513eec86090caaee2b0d36a.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -decls-strong -cplbs -gnu-style-dependencies -MD -Mo "src/BF700.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/adau1977.doj: ../src/adau1977.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore Blackfin C/C++ Compiler'
	ccblkfn -c -file-attr ProjectName="BF700" -proc ADSP-BF700 -flags-compiler --no_wrap_diagnostics -si-revision 1.1 -g -DCORE0 -D_DEBUG @includes-5b7a169a0513eec86090caaee2b0d36a.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -decls-strong -cplbs -gnu-style-dependencies -MD -Mo "src/adau1977.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/can.doj: ../src/can.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore Blackfin C/C++ Compiler'
	ccblkfn -c -file-attr ProjectName="BF700" -proc ADSP-BF700 -flags-compiler --no_wrap_diagnostics -si-revision 1.1 -g -DCORE0 -D_DEBUG @includes-5b7a169a0513eec86090caaee2b0d36a.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -decls-strong -cplbs -gnu-style-dependencies -MD -Mo "src/can.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/port.doj: ../src/port.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore Blackfin C/C++ Compiler'
	ccblkfn -c -file-attr ProjectName="BF700" -proc ADSP-BF700 -flags-compiler --no_wrap_diagnostics -si-revision 1.1 -g -DCORE0 -D_DEBUG @includes-5b7a169a0513eec86090caaee2b0d36a.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -decls-strong -cplbs -gnu-style-dependencies -MD -Mo "src/port.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/sport.doj: ../src/sport.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore Blackfin C/C++ Compiler'
	ccblkfn -c -file-attr ProjectName="BF700" -proc ADSP-BF700 -flags-compiler --no_wrap_diagnostics -si-revision 1.1 -g -DCORE0 -D_DEBUG @includes-5b7a169a0513eec86090caaee2b0d36a.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -decls-strong -cplbs -gnu-style-dependencies -MD -Mo "src/sport.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/twi.doj: ../src/twi.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore Blackfin C/C++ Compiler'
	ccblkfn -c -file-attr ProjectName="BF700" -proc ADSP-BF700 -flags-compiler --no_wrap_diagnostics -si-revision 1.1 -g -DCORE0 -D_DEBUG @includes-5b7a169a0513eec86090caaee2b0d36a.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -decls-strong -cplbs -gnu-style-dependencies -MD -Mo "src/twi.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/uart.doj: ../src/uart.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore Blackfin C/C++ Compiler'
	ccblkfn -c -file-attr ProjectName="BF700" -proc ADSP-BF700 -flags-compiler --no_wrap_diagnostics -si-revision 1.1 -g -DCORE0 -D_DEBUG @includes-5b7a169a0513eec86090caaee2b0d36a.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -decls-strong -cplbs -gnu-style-dependencies -MD -Mo "src/uart.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


