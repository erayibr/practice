SHELL := /bin/bash
CC = gcc
CFLAGS = -Wall -Wextra

SRCS = $(wildcard *.c)
BINS = $(SRCS:.c=)

RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[0;33m
RESET=\033[0m

all: $(BINS)

%: %.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(BINS)

demo: all
	@echo -e "${RED}"
	@echo "-----------------------------------"
	@echo "------------ dns query ------------"
	@echo "-----------------------------------"
	./dns_query google.com
	@echo -e "${YELLOW}"
	@echo "-----------------------------------"
	@echo "----------- listen 5555 -----------"
	@echo "-----------------------------------"
	./listen_sock 5555 &
	sleep 1
	echo "Echoing this msg to test listen_sock" > /dev/tcp/localhost/5555
	@echo ""

