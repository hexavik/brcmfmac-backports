# SPDX-License-Identifier: GPL-2.0
obj-$(CPTCFG_WCN36XX) := wcn36xx.o
wcn36xx-y +=   main.o \
               dxe.o \
               txrx.o \
               smd.o \
               pmc.o \
               debug.o

wcn36xx-$(CPTCFG_NL80211_TESTMODE) += testmode.o
