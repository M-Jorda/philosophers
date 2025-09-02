include build/configs/Colors.mk
include build/configs/Config.mk

# Include different source files based on target
ifeq ($(MAKECMDGOALS),bonus)
include build/configs/Sources_bonus.mk
include build/Bonus.mk
else
include build/configs/Sources.mk
include build/Mandatory.mk
endif

include build/configs/Utils.mk

.PHONY: all