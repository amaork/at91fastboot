CPPFLAGS += \
	-DIMG_ADDRESS=$(IMG_ADDRESS)		\
	-DIMG_SIZE=$(IMG_SIZE)			\
	-DJUMP_ADDR=$(JUMP_ADDR)		\
	-DOS_MEM_BANK=$(OS_MEM_BANK) \
	-DOS_MEM_SIZE=$(OS_MEM_SIZE) \
	-DOS_IMG_SIZE=$(OS_IMG_SIZE) \
	-DOS_IMAGE_NAME="\"$(OS_IMAGE_NAME)\"" \
	-DLINUX_IMG_NAND_OFFSET=$(LINUX_IMG_NAND_OFFSET) \
	-DLINUX_KERNEL_ARG_STRING="\"$(LINUX_KERNEL_ARG_STRING)\"" \
	-DGLBDRV_ADDR=$(GLBDRV_ADDR)		\
	-DSETTING_ADDRESS=$(SETTING_ADDRESS)		\
	-DSETTING_SIZE=$(SETTING_SIZE)		\
    -DTOP_OF_MEMORY=$(TOP_OF_MEMORY)	\
	-DMACH_TYPE=$(MACH_TYPE)		\

ASFLAGS += -DJUMP_ADDR=$(JUMP_ADDR)		\
	-DTOP_OF_MEMORY=$(TOP_OF_MEMORY)	\
	-DMACH_TYPE=$(MACH_TYPE)		\

ifeq ($(CONFIG_LONG_TEST),y)
CPPFLAGS += -DCONFIG_LONG_TEST
endif

ifeq ($(CONFIG_DEBUG),y)
CPPFLAGS += -DCONFIG_DEBUG
endif

ifeq ($(CONFIG_VERBOSE),y)
CPPFLAGS += -DCONFIG_VERBOSE
endif

ifeq ($(CONFIG_HW_INIT),y)
CPPFLAGS += -DCONFIG_HW_INIT
endif

ifeq ($(CONFIG_USER_HW_INIT),y)
CPPFLAGS += -DCONFIG_USER_HW_INIT
endif

