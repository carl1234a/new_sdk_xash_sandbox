#hlsdk-2.3 client port for android
#Copyright (c) mittorn

LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := client
#ifeq ($(XASH_SDL),1)
#APP_PLATFORM := android-12
#LOCAL_SHARED_LIBRARIES += SDL2 
#LOCAL_CFLAGS += -DXASH_SDL
#else
APP_PLATFORM := android-8
#endif

include $(XASH3D_CONFIG)

ifeq ($(TARGET_ARCH_ABI),armeabi-v7a-hard)
LOCAL_MODULE_FILENAME = libclient_hardfp
endif

LOCAL_CFLAGS += -DCLIENT_DLL=1

SRCS=
SRCS_C=
SRCS+=../dlls/wpn_shared/crossbow.cpp
SRCS+=../dlls/wpn_shared/eagle.cpp
SRCS+=../dlls/wpn_shared/pipewrench.cpp
SRCS+=../dlls/wpn_shared/penguin.cpp
SRCS+=../dlls/wpn_shared/sporelauncher.cpp
SRCS+=../dlls/wpn_shared/ak47.cpp
SRCS+=../dlls/wpn_shared/xm1014.cpp
SRCS+=../dlls/wpn_shared/usp.cpp
SRCS+=../dlls/wpn_shared/crowbar.cpp
SRCS+=../dlls/wpn_shared/egon.cpp
SRCS+=../dlls/wpn_shared/sniperrifle.cpp
SRCS+=./ev_hldm.cpp
SRCS+=../dlls/wpn_shared/physgun.cpp
SRCS+=../dlls/wpn_shared/gauss.cpp
SRCS+=../dlls/wpn_shared/handgrenade.cpp
SRCS+=./hl/hl_baseentity.cpp
SRCS+=./hl/hl_events.cpp
SRCS+=./hl/hl_objects.cpp
SRCS+=./hl/hl_weapons.cpp
SRCS+=../dlls/wpn_shared/hornetgun.cpp
SRCS+=../dlls/wpn_shared/mp5.cpp
SRCS+=../dlls/wpn_shared/python.cpp
SRCS+=../dlls/wpn_shared/rpg.cpp
SRCS+=../dlls/wpn_shared/satchel.cpp
SRCS+=../dlls/wpn_shared/shotgun.cpp
SRCS+=../dlls/wpn_shared/squeakgrenade.cpp
SRCS+=../dlls/wpn_shared/tripmine.cpp
SRCS+=../dlls/wpn_shared/glock.cpp
#SRCS+=../game_shared/voice_banmgr.cpp
#SRCS+=../game_shared/voice_status.cpp
SRCS+=./hud/ammo.cpp
SRCS+=./hud/ammo_secondary.cpp
SRCS+=./hud/ammohistory.cpp
SRCS+=./hud/battery.cpp
SRCS+=./cdll_int.cpp
SRCS+=./com_weapons.cpp
SRCS+=./hud/death.cpp
SRCS+=./demo.cpp
SRCS+=./entity.cpp
SRCS+=./ev_common.cpp
SRCS+=./events.cpp
SRCS+=./hud/flashlight.cpp
SRCS+=./studio/GameStudioModelRenderer.cpp
SRCS+=./hud/geiger.cpp
SRCS+=./hud/health.cpp
SRCS+=./hud/hud.cpp
SRCS+=./hud/hud_msg.cpp
SRCS+=./hud/hud_redraw.cpp
#SRCS+=./hud/hud_servers.cpp
SRCS+=./hud/hud_spectator.cpp
SRCS+=./hud/hud_update.cpp
SRCS+=./in_camera.cpp
SRCS+=./input.cpp
SRCS+=./input_goldsource.cpp
SRCS+=./input_mouse.cpp
#SRCS+=./inputw32.cpp
SRCS+=./menu.cpp
SRCS+=./hud/message.cpp
SRCS+=./overview.cpp
SRCS+=./parsemsg.cpp
SRCS_C+=../pm_shared/pm_debug.c
SRCS_C+=../pm_shared/pm_math.c
SRCS_C+=../pm_shared/pm_shared.c
SRCS+=./hud/saytext.cpp
SRCS+=./hud/status_icons.cpp
SRCS+=./hud/statusbar.cpp
SRCS+=./studio/studio_util.cpp
SRCS+=./studio/StudioModelRenderer.cpp
SRCS+=./hud/text_message.cpp
SRCS+=./hud/train.cpp
SRCS+=./tri.cpp
SRCS+=./util.cpp
SRCS+=./view.cpp
SRCS+=./input_xash3d.cpp
SRCS+=./hud/scoreboard.cpp
SRCS+=./hud/MOTD.cpp
INCLUDES =  -I../common -I. -I../game_shared -I../pm_shared -I../engine -I../dlls -I../utils/false_vgui/include
DEFINES = -Wno-write-strings -DLINUX -D_LINUX -Dstricmp=strcasecmp -Dstrnicmp=strncasecmp -DCLIENT_WEAPONS -DCLIENT_DLL -w -D_snprintf=snprintf

LOCAL_C_INCLUDES := $(LOCAL_PATH)/. \
       $(LOCAL_PATH)/hud \
       $(LOCAL_PATH)/studio \
	   $(LOCAL_PATH)/../common \
	   $(LOCAL_PATH)/../engine \
	   $(LOCAL_PATH)/../game_shared \
	   $(LOCAL_PATH)/../dlls \
       $(LOCAL_PATH)/../dlls/wpn_shared \
	   $(LOCAL_PATH)/../pm_shared \
	   $(LOCAL_PATH)/../utils/false_vgui/include
LOCAL_CFLAGS += $(DEFINES) $(INCLUDES)

ifeq ($(GOLDSOURCE_SUPPORT),1)
	DEFINES += -DGOLDSOURCE_SUPPORT
	ifeq ($(shell uname -s),Linux)
		LOCAL_LDLIBS += -ldl
	endif
endif

LOCAL_SRC_FILES := $(SRCS) $(SRCS_C)

include $(BUILD_SHARED_LIBRARY)
