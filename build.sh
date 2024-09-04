# check if build directory exists, if no exit

if [ ! -d "build" ]; then
  echo "build directory does not exist"
  exit 1
fi

cd build
cmake ..

# if cmake fails, exit the script
if [ $? -ne 0 ]; then
  echo "cmake failed"
  exit 1
fi

make -j$(nproc)

# if make fails, exit the script
if [ $? -ne 0 ]; then
  echo "make failed"
  exit 1
fi