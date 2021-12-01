# Makefile 4.0
obj-m := demo.o#编译文件
CURRENT_PATH := $(shell pwd)

#LINUX_KERNEL := $(shell uname -r)
#LINUX_KERNEL_PATH := /usr/src/linux-headers-$(LINUX_KERNEL)
LINUX_KERNEL_PATH := []#内核绝对路径

EXTRA_CFLAGS += -Wfatal-errors  # 遇到错误停止编译

export CROSS_COMPILE = []#交叉编译工具链 
export ARCH = []#交叉编译架构


all:
	make -C $(LINUX_KERNEL_PATH) M=$(CURRENT_PATH) modules

help:
	make -C $(LINUX_KERNEL_PATH) M=$(CURRENT_PATH) help

clean:
	make -C $(LINUX_KERNEL_PATH) M=$(CURRENT_PATH) clean

