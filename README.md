# sinbad
CombLayer build of the SINBAD/ASPIS experiments


commands to regenerate the binary sinbad:

rm CMakeCache.txt
./CMake.pl -s -gcc=clang -g++=clang++  %%%%(clang compilers assumed)
cmake ./
make

then run ./sinbad

a set of options will appear (use always also flag -r)

The interested user is also invited to look at the following link for the aspis gui:


https://onedrive.live.com/redir?resid=3D65198DEFEF9606!1934&authkey=!AErzBZiwv11QVrk&ithint=folder%2creadme
 


