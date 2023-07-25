#!/usr/bin/env bash


DOCKER_IMAGE=''
DOCKER_CONTAINER_NAME=''

ARCH=$(uname -m)
SOURCE_DIR=$(cd $(dirname ${BASH_SOURCE:-$0}) && pwd)
PROJECT_DIR=$(cd ${SOURCE_DIR}/.. && pwd)

# The purpose of using Docker container is to emulate the target OS and CPU architecture.
# So if the local machine has the target feature, we don't need to support it to emulate its environment itself.
# Thus, we'll choose opposite OS/CPU architecture in correspoding condition.
#
# example) if your local CPU architecture is "x86_64", then choose "arm64"
if [[ "${ARCH}" =~ ^arm.*$ ]]; then
    DOCKER_IMAGE='x86_64:latest'
    DOCKER_CONTAINER_NAME='x86_64_container'
    cd ${SOURCE_DIR}/x86_64
elif [[ "${ARCH}" =~ x86_64 ]] ; then
    DOCKER_IMAGE='arm64:latest'
    DOCKER_CONTAINER_NAME='arm64_container'
    cd ${SOURCE_DIR}/arm64
else
    echo "CPU architecrure: ${ARCH} is not suppored."
    exit 1
fi

function rmc(){
    docker container rm -f ${DOCKER_CONTAINER_NAME}
}

function run(){
    docker container run \
        -itd \
        -v "${PROJECT_DIR}:/home" \
        --name ${DOCKER_CONTAINER_NAME} \
        ${DOCKER_IMAGE}
}

case "$1" in
    "build")docker image build -t ${DOCKER_IMAGE} .;;
    "login")
        rmc
        run
        docker container exec \
            -it ${DOCKER_CONTAINER_NAME} \
            /bin/bash;;
    "rmc")rmc;;
    "rmi")docker image rm -f ${DOCKER_IMAGE};;
    "run")run;;
    *)echo "Bad args: $1";;
esac
