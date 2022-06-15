#!/bin/bash
cmake -Bbuild . -DENABLE_TESTS=ON
make -Cbuild
if test -f ./build/FeatureSteps ; then
  ./build/FeatureSteps 2>/dev/null &
  cucumber
fi

echo "===="
echo "real execution:"
./build/calcexe
