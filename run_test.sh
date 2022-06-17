#!/bin/bash
cmake -Bbuild . -DENABLE_TESTS=ON
make -Cbuild
if test -f ./build/FeatureSteps ; then

  echo "Starting steps"
  ./build/FeatureSteps 2>/dev/null &
  echo "waiting until port is open"

  while ! netstat -tna | grep 'LISTEN\>' | grep -q ':3902\>'; do
    sleep 1 # time in seconds, tune it as needed
  done


  cucumber
fi

echo "===="
echo "real execution:"
./build/calcexe
