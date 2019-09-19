CC=gcc
CFLAGS=-g -Wall -O1
OBJECTS=elfdata demo

all: elfdata demo

test: all
	./demo
	./elfdata -k demo PRODUCT_NAME
	./elfdata -k demo PRODUCT_VERSION
	printf "alternate name\0" > PRODUCT_NAME
	printf "1.0.0\0" > PRODUCT_VERSION
	objcopy -v --update-section PRODUCT_NAME=PRODUCT_NAME --update-section PRODUCT_VERSION=PRODUCT_VERSION demo
	./demo
	./elfdata -k demo PRODUCT_NAME
	./elfdata -k demo PRODUCT_VERSION

clean:
	git clean -dxf

.PHONY: clean
