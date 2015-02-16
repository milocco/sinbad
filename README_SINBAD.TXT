INSTRUCTIONS TO RUN SINBAD :
(tested on linux64 with clang compiler only)


- uncompress the archive (tar -xzf on linux)
- create directory 'lib' (fix)
- run './getMk -s -gcc=clang -g++=clang++'
- copy test/Makefile.new to test/Makefile or edit test/Makefile by setting 'BCOMPL=clang -std=c++11' and 'CCOMPL=clang++ -std=c++11' (fix)
- run 'make'
- binary 'sinbad' should appear
- run ./sinbad and read the options

For any problem write to: 

alberto.milocco@mib.infn.it
