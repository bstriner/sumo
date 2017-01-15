# libsumo
Branch of https://github.com/planetsumo/sumo the official mirror of the SUMO sources

I modified the SUMO build to produce a library named libsumo that allows direct access to the SUMO API in C++.
This allows for a significant performance improvement over traci.

libsumo provides a library for traffic simulation that can be used from C++. 
The build outputs are a shared library and a static library named libsumo.so and libsumo.a.
`make install` will copy the library to the system library directory. 
Make sure to run `ldconfig` after installing if you want to be able to use the library in your own code.

```
git clone https://github.com/bstriner/sumo.git
cd sumo/sumo
aclocal
autoconf
automake
./configure --enable-libsumo=yes
make
make -C src/libsumo install
```
