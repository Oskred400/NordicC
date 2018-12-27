PROJECT_NAME := nrf52840_rx
TARGETS      := nrf52840_rx_id$(MYNODEID)
OUTPUT_DIRECTORY := build
PROJ_DIR := .

NRF_802154_DRIVER := $(NRF_802154_DRIVER)
SDK_ROOT := $(NRF_SDK)

$(OUTPUT_DIRECTORY)/nrf52840_rx_id$(MYNODEID).out: \
  LINKER_SCRIPT  := transmitter_gcc_nrf52.ld

# Source files common to all targets
SRC_FILES += \
  $(SDK_ROOT)/modules/nrfx/mdk/gcc_startup_nrf52840.S \
  $(SDK_ROOT)/components/libraries/log/src/nrf_log_backend_rtt.c \
  $(SDK_ROOT)/components/libraries/log/src/nrf_log_backend_serial.c \
  $(SDK_ROOT)/components/libraries/log/src/nrf_log_backend_uart.c \
  $(SDK_ROOT)/components/libraries/log/src/nrf_log_default_backends.c \
  $(SDK_ROOT)/components/libraries/log/src/nrf_log_frontend.c \
  $(SDK_ROOT)/components/libraries/log/src/nrf_log_str_formatter.c \
  $(SDK_ROOT)/components/boards/boards.c \
  $(SDK_ROOT)/components/libraries/button/app_button.c \
  $(SDK_ROOT)/components/libraries/util/app_error.c \
  $(SDK_ROOT)/components/libraries/util/app_error_handler_gcc.c \
  $(SDK_ROOT)/components/libraries/util/app_error_weak.c \
  $(SDK_ROOT)/components/libraries/fifo/app_fifo.c \
  $(SDK_ROOT)/components/libraries/scheduler/app_scheduler.c \
  $(SDK_ROOT)/components/libraries/timer/app_timer.c \
  $(SDK_ROOT)/components/libraries/uart/app_uart_fifo.c \
  $(SDK_ROOT)/components/libraries/util/app_util_platform.c \
  $(SDK_ROOT)/components/libraries/util/nrf_assert.c \
  $(SDK_ROOT)/components/libraries/atomic/nrf_atomic.c \
  $(SDK_ROOT)/components/libraries/balloc/nrf_balloc.c \
  $(SDK_ROOT)/external/fprintf/nrf_fprintf.c \
  $(SDK_ROOT)/external/fprintf/nrf_fprintf_format.c \
  $(SDK_ROOT)/components/libraries/memobj/nrf_memobj.c \
  $(SDK_ROOT)/components/libraries/ringbuf/nrf_ringbuf.c \
  $(SDK_ROOT)/components/libraries/strerror/nrf_strerror.c \
  $(SDK_ROOT)/components/libraries/uart/retarget.c \
  $(SDK_ROOT)/integration/nrfx/legacy/nrf_drv_uart.c \
  $(SDK_ROOT)/integration/nrfx/legacy/nrf_drv_clock.c \
  $(SDK_ROOT)/modules/nrfx/drivers/src/nrfx_gpiote.c \
  $(SDK_ROOT)/modules/nrfx/drivers/src/prs/nrfx_prs.c \
  $(SDK_ROOT)/modules/nrfx/drivers/src/nrfx_uart.c \
  $(SDK_ROOT)/modules/nrfx/drivers/src/nrfx_uarte.c \
  $(SDK_ROOT)/modules/nrfx/drivers/src/nrfx_clock.c \
  $(SDK_ROOT)/components/drivers_nrf/radio_config/radio_config.c \
  $(SDK_ROOT)/components/libraries/bsp/bsp.c \
  $(PROJ_DIR)/main.c \
  $(SDK_ROOT)/external/segger_rtt/SEGGER_RTT.c \
  $(SDK_ROOT)/external/segger_rtt/SEGGER_RTT_Syscalls_GCC.c \
  $(SDK_ROOT)/external/segger_rtt/SEGGER_RTT_printf.c \
  $(SDK_ROOT)/modules/nrfx/mdk/system_nrf52840.c \


### 802.15.4

SINGLE_PHY += \
  $(NRF_802154_DRIVER)/nrf_802154_notification_direct.c \
  $(NRF_802154_DRIVER)/nrf_802154_priority_drop_direct.c \
  $(NRF_802154_DRIVER)/nrf_802154_request_direct.c \
  $(NRF_802154_DRIVER)/rsch/raal/single_phy/single_phy.c \
  $(NRF_802154_DRIVER)/rsch/nrf_802154_rsch.c \
  $(NRF_802154_DRIVER)/rsch/nrf_802154_rsch_crit_sect.c \
  $(NRF_802154_DRIVER)/platform/temperature/nrf_802154_temperature_none.c \
  $(NRF_802154_DRIVER)/timer_scheduler/nrf_802154_timer_sched.c \
  $(NRF_802154_DRIVER)/nrf_802154_rssi.c \
  $(NRF_802154_DRIVER)/nrf_802154_timer_coord.c \
  $(NRF_802154_DRIVER)/platform/clock/nrf_802154_clock_sdk.c \
  $(NRF_802154_DRIVER)/platform/hp_timer/nrf_802154_hp_timer.c \
  $(NRF_802154_DRIVER)/platform/lp_timer/nrf_802154_lp_timer_nodrv.c \

DRV_FILES += \
  $(NRF_802154_DRIVER)/nrf_802154.c \
  $(NRF_802154_DRIVER)/nrf_802154_ack_pending_bit.c \
  $(NRF_802154_DRIVER)/nrf_802154_core.c \
  $(NRF_802154_DRIVER)/nrf_802154_core_hooks.c \
  $(NRF_802154_DRIVER)/nrf_802154_critical_section.c \
  $(NRF_802154_DRIVER)/nrf_802154_debug.c \
  $(NRF_802154_DRIVER)/nrf_802154_pib.c \
  $(NRF_802154_DRIVER)/nrf_802154_revision.c \
  $(NRF_802154_DRIVER)/nrf_802154_rx_buffer.c \
  $(NRF_802154_DRIVER)/fem/nrf_fem_control.c \
  $(NRF_802154_DRIVER)/mac_features/nrf_802154_ack_timeout.c \
  $(NRF_802154_DRIVER)/mac_features/nrf_802154_csma_ca.c \
  $(NRF_802154_DRIVER)/mac_features/nrf_802154_filter.c \
  $(NRF_802154_DRIVER)/mac_features/nrf_802154_delayed_trx.c \

DRV_INC += \
  $(NRF_802154_DRIVER) \
  $(NRF_802154_DRIVER)/rsch/ \
  $(NRF_802154_DRIVER)/rsch/raal/ \

SRC_FILES += \
    $(DRV_FILES) \
    $(SINGLE_PHY) \

# Include folders common to all targets
INC_FOLDERS += \
  $(SDK_ROOT)/external/fprintf \
  $(PROJ_DIR) \
  $(SDK_ROOT)/components/libraries/experimental_section_vars \
  $(SDK_ROOT)/components/drivers_nrf/radio_config \
  $(SDK_ROOT)/components/libraries/atomic \
  $(SDK_ROOT)/components/libraries/fifo \
  $(SDK_ROOT)/components/libraries/delay \
  $(SDK_ROOT)/components/libraries/uart \
  config \
  $(SDK_ROOT)/components/toolchain/cmsis/include \
  $(SDK_ROOT)/components/libraries/balloc \
  $(SDK_ROOT)/components/libraries/log \
  $(SDK_ROOT)/components/libraries/memobj \
  $(SDK_ROOT)/components \
  $(SDK_ROOT)/modules/nrfx/mdk \
  $(SDK_ROOT)/components/libraries/scheduler \
  $(SDK_ROOT)/components/libraries/strerror \
  $(SDK_ROOT)/integration/nrfx \
  $(SDK_ROOT)/modules/nrfx/drivers/include \
  $(SDK_ROOT)/components/libraries/ringbuf \
  $(SDK_ROOT)/modules/nrfx \
  $(SDK_ROOT)/components/drivers_nrf/nrf_soc_nosd \
  $(SDK_ROOT)/components/libraries/log/src \
  $(SDK_ROOT)/external/segger_rtt \
  $(SDK_ROOT)/modules/nrfx/hal \
  $(SDK_ROOT)/components/libraries/bsp \
  $(SDK_ROOT)/components/boards \
  $(SDK_ROOT)/components/libraries/timer \
  $(SDK_ROOT)/components/libraries/button \
  $(SDK_ROOT)/integration/nrfx/legacy \
  $(SDK_ROOT)/components/libraries/util \
  $(DRV_INC) \

# Libraries common to all targets
LIB_FILES += \

# Optimization flags
OPT = -O3 -g3
# Uncomment the line below to enable link time optimization
#OPT += -flto

# C flags common to all targets
CFLAGS += $(OPT)

# flags specific to 802.15.4
CFLAGS += -DRAAL_SINGLE_PHY=1
CFLAGS += -DNRF_CLOCK_ENABLED

CFLAGS += -DBOARD_PCA10056
CFLAGS += -DNRF52840_XXAA
CFLAGS += -DBSP_UART_SUPPORT
CFLAGS += -DCONFIG_GPIO_AS_PINRESET
CFLAGS += -DFLOAT_ABI_HARD
CFLAGS += -Dnrf52840_rx
CFLAGS += -DSWI_DISABLE0
CFLAGS += -mcpu=cortex-m4
CFLAGS += -mthumb -mabi=aapcs
CFLAGS += -Wall -Werror
CFLAGS += -mfloat-abi=hard -mfpu=fpv4-sp-d16
# keep every function in a separate section, this allows linker to discard unused ones
CFLAGS += -ffunction-sections -fdata-sections -fno-strict-aliasing
CFLAGS += -fno-builtin -fshort-enums

CFLAGS += -D MYNODEID=$(MYNODEID)
# C++ flags common to all targets
CXXFLAGS += $(OPT)

# Assembler flags common to all targets
ASMFLAGS += -g3
ASMFLAGS += -mcpu=cortex-m4
ASMFLAGS += -mthumb -mabi=aapcs
ASMFLAGS += -mfloat-abi=hard -mfpu=fpv4-sp-d16
ASMFLAGS += -DBOARD_PCA10056
ASMFLAGS += -DBSP_UART_SUPPORT
ASMFLAGS += -DCONFIG_GPIO_AS_PINRESET
ASMFLAGS += -DFLOAT_ABI_HARD
ASMFLAGS += -Dnrf52840_rx
ASMFLAGS += -DSWI_DISABLE0

# Linker flags
LDFLAGS += $(OPT)
LDFLAGS += -mthumb -mabi=aapcs -L$(SDK_ROOT)/modules/nrfx/mdk -T$(LINKER_SCRIPT)
LDFLAGS += -mcpu=cortex-m4
LDFLAGS += -mfloat-abi=hard -mfpu=fpv4-sp-d16
# let linker dump unused sections
LDFLAGS += -Wl,--gc-sections
# use newlib in nano version
LDFLAGS += --specs=nano.specs

nrf52840_rx: CFLAGS += -D__HEAP_SIZE=8192
nrf52840_rx: CFLAGS += -D__STACK_SIZE=8192
nrf52840_rx: ASMFLAGS += -D__HEAP_SIZE=8192
nrf52840_rx: ASMFLAGS += -D__STACK_SIZE=8192

# Add standard libraries at the very end of the linker input, after all objects
# that may need symbols provided by these libraries.
LIB_FILES += -lc -lnosys -lm -lstdc++


.PHONY: default help

# Default target - first one defined
default: nrf52840_rx_id$(MYNODEID)

# Print all targets that can be built
help:
	@echo following targets are available:
	@echo		nrf52840_rx
	@echo		sdk_config - starting external tool for editing sdk_config.h
	@echo		flash      - flashing binary

TEMPLATE_PATH := $(SDK_ROOT)/components/toolchain/gcc


include $(TEMPLATE_PATH)/Makefile.common

$(foreach target, $(TARGETS), $(call define_target, $(target)))

.PHONY: flash erase

# Flash the program
flash: default
	@echo Flashing: $(OUTPUT_DIRECTORY)/nrf52840_rx_id$(MYNODEID).hex
	nrfjprog -f nrf52 --program $(OUTPUT_DIRECTORY)/nrf52840_rx_id$(MYNODEID).hex --sectorerase
	nrfjprog -f nrf52 --reset

erase:
	nrfjprog -f nrf52 --eraseall

SDK_CONFIG_FILE := config/sdk_config.h
CMSIS_CONFIG_TOOL := $(SDK_ROOT)/external_tools/cmsisconfig/CMSIS_Configuration_Wizard.jar
sdk_config:
java -jar $(CMSIS_CONFIG_TOOL) $(SDK_CONFIG_FILE)
