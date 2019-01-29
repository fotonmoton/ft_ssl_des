#!/usr/bin/env sh
while true; do
	find src t inc Makefile | entr -cd make check -j8
done
