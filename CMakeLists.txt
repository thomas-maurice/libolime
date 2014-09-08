CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

PROJECT(libolime)

INCLUDE_DIRECTORIES("include")
LINK_DIRECTORIES()

FILE(
	GLOB_RECURSE
	sources
	src/*.c
	src/*.cpp
	include/*.h
	include/*.hpp
)

ADD_LIBRARY(
	olime
	SHARED
	${sources}
)
