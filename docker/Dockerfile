FROM       debian:11.5-slim

ARG        VERSION
ENV        VERSION=${VERSION}

ARG        DIR=/app

WORKDIR    $DIR
ADD        . $DIR

RUN        apt update -y
RUN        apt install -y cmake g++ gcc-arm-none-eabi libnewlib-arm-none-eabi
RUN        apt install -y git python3

RUN        mkdir -p build
RUN        cd build; cmake .. && make
