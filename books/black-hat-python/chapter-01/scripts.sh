#!/usr/bin/env bash

NETWORK=blackhat-python
ATCKR_IMG=dali:v0.4

KALI_WORKDIR=/kali-workdir
DBN_WORKDIR=/dbn-workdir

function start_victim() {
    echo "Starting victim container"
    docker run --rm --network=$NETWORK -h victim -it \
        --name metasploitable2 \
    	tleemcjr/metasploitable2
}


# TODO: --privileged is needed to fix nmap. Find a better way to fix this
function start_kali() {
    echo "Starting kali container"
    set -x
    docker run --rm --network=$NETWORK -h kali -it --privileged \
        --name kalibox -v "$(pwd):${KALI_WORKDIR}" -w "${KALI_WORKDIR}" \
    	kl:v1
}

function start_dbn() {
    echo "Starting dbn container"
    docker run --rm --network=$NETWORK -h dbn -it \
        --name debianbox -v "$(pwd):${DBN_WORKDIR}" -w "${DBN_WORKDIR}" \
    	dbn:v1
}

function start_attacker() {
    echo "Starting attacker container"
    docker run --rm --network=$NETWORK -h attacker -it \
	--name kalibox \
    	"${ATCKR_IMG}"
}
