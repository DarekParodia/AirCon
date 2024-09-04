# check if build directory exists, if yes, remove it
# then create a new build directory

if [ -d "build" ]; then
  rm -rf build
fi

mkdir build
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