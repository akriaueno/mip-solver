#!/bin/bash

set -eu
project_root=$(cd $(dirname $0); pwd)
pushd ${project_root}/build
cmake .. -GNinja && ninja
popd
