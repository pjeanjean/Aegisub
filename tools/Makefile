include $(dir $(lastword $(MAKEFILE_LIST)))../header.mk

osx-bundle-restart-helper_OBJ := $(d)osx-bundle-restart-helper.o

ifeq (yes, $(BUILD_DARWIN))
PROGRAM += $(d)osx-bundle-restart-helper
endif

repack-thes-dict_OBJ  := $(d)repack-thes-dict.o $(TOP)lib/libaegisub.a
repack-thes-dict_LIBS := $(LIBS_BOOST) $(LIBS_ICU) $(LIBS_PTHREAD)
repack-thes-dict_CPPFLAGS := -I$(TOP) -I$(TOP)libaegisub/include $(CFLAGS_ICU)

PROGRAM += $(d)repack-thes-dict

ifeq (no, $(SYSTEM_LUAJIT))
$(TOP)tools/respack.lua: $(BIN_LUA)
endif

include $(TOP)Makefile.target
