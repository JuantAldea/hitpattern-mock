all:
	genreflex classes.h -s classes_def.xml --gccxmlpath=/afs/cern.ch/cms/sw/ReleaseCandidates/vol0/slc6_amd64_gcc481/external/gccxml/0.9.0-20140124-0/bin/
	g++ classes_rflx.cpp -o libMock.so `root-config --cflags --libs --ldflags` -lReflex -lCintex -shared -fPIC -g3

clean:
	rm -rf *.d
	rm -rf *.so
	rm -rf *rflx.cpp
