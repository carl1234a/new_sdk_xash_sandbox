#HLSDK server Android port
#Copyright (c) nicknekit

LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := server

include $(XASH3D_CONFIG)

ifeq ($(TARGET_ARCH_ABI),armeabi-v7a-hard)
LOCAL_MODULE_FILENAME = libserver_hardfp
endif

LOCAL_CFLAGS += -D_LINUX -DCLIENT_WEAPONS -Dstricmp=strcasecmp -Dstrnicmp=strncasecmp -D_snprintf=snprintf \
	-fno-exceptions -DNO_VOICEGAMEMGR -Wno-conversion-null -Wno-write-strings -std=gnu++98 -Wno-invalid-offsetof


LOCAL_CPPFLAGS := $(LOCAL_CFLAGS)

LOCAL_C_INCLUDES := $(SDL_PATH)/include \
		    $(LOCAL_PATH)/. \
            $(LOCAL_PATH)/monsters \
		    $(LOCAL_PATH)/wpn_shared \
		    $(LOCAL_PATH)/../common \
		    $(LOCAL_PATH)/../engine/common \
		    $(LOCAL_PATH)/../engine \
		    $(LOCAL_PATH)/../public \
		    $(LOCAL_PATH)/../pm_shared \
		    $(LOCAL_PATH)/../game_shared

LOCAL_SRC_FILES := monsters/agrunt.cpp airtank.cpp \
           monsters/aflock.cpp \
           animating.cpp \
           animation.cpp \
           monsters/apache.cpp \
           monsters/barnacle.cpp \
           monsters/barney.cpp \
           monsters/bigmomma.cpp \
           monsters/bloater.cpp \
           bmodels.cpp \
           monsters/bullsquid.cpp \
           buttons.cpp \
           cbase.cpp \
           client.cpp \
           combat.cpp \
           monsters/controller.cpp \
           wpn_shared/crossbow.cpp \
           wpn_shared/crowbar.cpp \
           defaultai.cpp \
           doors.cpp \
           effects.cpp \
           wpn_shared/egon.cpp \
           explode.cpp \
		   enttools.cpp \
           flyingmonster.cpp \
           func_break.cpp \
           func_mortar.cpp \
           func_tank.cpp \
           game.cpp \
           gamerules.cpp \
           monsters/gargantua.cpp \
           wpn_shared/gauss.cpp \
           genericmonster.cpp \
           ggrenade.cpp \
           globals.cpp \
           wpn_shared/glock.cpp \
           monsters/gman.cpp \
           h_ai.cpp \
           h_battery.cpp \
           h_cycler.cpp \
           h_cine.cpp \
           h_export.cpp \
           wpn_shared/handgrenade.cpp \
           monsters/hassassin.cpp \
           monsters/headcrab.cpp \
           healthkit.cpp \
           monsters/hgrunt.cpp \
           monsters/hornet.cpp \
           wpn_shared/hornetgun.cpp \
           monsters/houndeye.cpp \
           monsters/ichthyosaur.cpp \
           monsters/islave.cpp \
           items.cpp \
           monsters/leech.cpp \
           lights.cpp \
           maprules.cpp \
           monstermaker.cpp \
           monsters.cpp \
           monsterstate.cpp \
           wpn_shared/mp5.cpp \
           multiplay_gamerules.cpp \
           monsters/nihilanth.cpp \
           nodes.cpp \
	   observer.cpp \
           monsters/osprey.cpp \
           monsters/pathcorner.cpp \
           plane.cpp \
           plats.cpp \
           player.cpp \
	   monsters/playermonster.cpp \
           wpn_shared/python.cpp \
           monsters/rat.cpp \
           monsters/roach.cpp \
           wpn_shared/rpg.cpp \
	   wpn_shared/satchel.cpp \
           schedule.cpp \
           monsters/scientist.cpp \
           scripted.cpp \
           wpn_shared/shotgun.cpp \
           singleplay_gamerules.cpp \
           skill.cpp \
           sound.cpp \
           soundent.cpp \
           spectator.cpp \
           squadmonster.cpp \
           wpn_shared/squeakgrenade.cpp \
           subs.cpp \
           talkmonster.cpp \
           teamplay_gamerules.cpp \
           tentacle.cpp \
           tempmonster.cpp \
           triggers.cpp \
           wpn_shared/tripmine.cpp \
           monsters/turret.cpp \
           util.cpp \
           weapons.cpp \
           world.cpp \
           xen.cpp \
           monsters/zombie.cpp \
           prop.cpp \
           wpn_shared/gravgun.cpp \
           wpn_shared/ar2.cpp \
           wpn_shared/big_cock.cpp \
           unpredictedweapon.cpp \
	   ../pm_shared/pm_debug.c \
	   ../pm_shared/pm_math.c \
	   ../pm_shared/pm_shared.c \
	   coop.cpp \
	   wpn_shared/gateofbabylon.cpp \
	   gravgunmod.cpp \
	   shock.cpp \
	   wpn_shared/shockrifle.cpp \
	   wpn_shared/displacer.cpp \
	   wpn_shared/m249.cpp \
	   wpn_shared/knife.cpp \
	   gunmod.cpp \
	   wpn_shared/BMOD_flyingcrowbar.cpp \
	   bottle.cpp \
	   wpn_shared/eagle.cpp \
	   wpn_shared/pipewrench.cpp \
	   wpn_shared/penguin.cpp \
	   monsters/otis.cpp \
	   monsters/zombie_barney.cpp \
	   monsters/zombie_soldier.cpp \
	   monsters/fast_zombie.cpp \
	   monsters/black_headcrab.cpp \
	   monsters/hl2headcrab.cpp \
	   monsters/hl2_zombie.cpp \
	   monsters/gonome.cpp \
	   monsters/strooper.cpp \
	   monsters/massn.cpp \
	   monsters/voltigore.cpp \
	   sporegrenade.cpp \
	   monsters/pink_panther.cpp \
	   monsters/shrek.cpp \
	   wpn_shared/sniperrifle.cpp \
	   wpn_shared/sporelauncher.cpp \
	   spore_ammo.cpp \
	   wpn_shared/nukelauncher.cpp \
	   monsters/blkop_osprey.cpp \
	   monsters/cleansuit_scientist.cpp \
	   monsters/fgrunt_medic.cpp \
	   monsters/fgrunt_torch.cpp \
	   wpn_shared/chaingun.cpp \
	   rcallymonster.cpp \
	   monsters/fgrunt.cpp \
	   monsters/wolf.cpp \
	   monsters/Snake.cpp \
	   monsters/Cow.cpp \
	   monsters/Chicken.cpp \
	   monsters/Trex.cpp \
	   monsters/Spider.cpp \
	   wpn_shared/uzi.cpp \
	   wpn_shared/usp.cpp \
	   wpn_shared/hammer.cpp \
	   monsters/bonewheel.cpp \
	   monsters/bigsmoke.cpp \
	   monsters/mariozombie.cpp \
	   monsters/skrillex.cpp \
	   monsters/zombozo.cpp \
	   wpn_shared/ak47.cpp \
	   wpn_shared/xm1014.cpp \
	   monsters/skeleton.cpp \
	   barrel_explosive.cpp \
	   wpn_shared/molotov.cpp \
	   monsters/monster_molotov.cpp \
	   monsters/evilsci.cpp \
	   monsters/superchav.cpp \
	   monsters/blackscary.cpp \
	   wpn_shared/physgun.cpp \
	   wpn_shared/flamethrower.cpp \
	   flame.cpp \
	   wpn_shared/grapple.cpp
#	   ../game_shared/voice_gamemgr.cpp

LOCAL_LDLIBS := -llog

include $(BUILD_SHARED_LIBRARY)
