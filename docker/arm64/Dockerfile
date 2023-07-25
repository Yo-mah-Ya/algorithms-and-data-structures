FROM arm64v8/ubuntu:22.04

RUN apt update -y && apt install build-essential -y
# Other useful libraries
RUN apt install -y \
    clang-tidy \
    clang-format \
    file \
    info \
    gcc \
    g++ \
    gdb \
    sudo
WORKDIR /home
