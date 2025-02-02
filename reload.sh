#!/usr/bin/env bash
set -xe

cmake --workflow --preset=linux-fast-debug-workflow 

./releases/_CPack_Packages/Linux/ZIP/Template-0.0.1-Linux/bin/app2