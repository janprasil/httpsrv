CXX=g++
LD=g++
CFLAGS=-Wall -pedantic -Wno-long-long -O0 -ggdb
IN=src/

all: httpsrv doc
compile: httpsrv
main.o: $(IN)main.cpp
	$(CXX) $(CFLAGS) -c -o $@ $<
CBadAddressException.o: $(IN)CBadAddressException.cpp $(IN)CBadAddressException.h
	$(CXX) $(CFLAGS) -c -o $@ $<
CConfig.o: $(IN)CConfig.cpp $(IN)CConfig.h
	$(CXX) $(CFLAGS) -c -o $@ $<
CConfigException.o: $(IN)CConfigException.cpp $(IN)CConfigException.h
	$(CXX) $(CFLAGS) -c -o $@ $<
CConnection.o: $(IN)CConnection.cpp $(IN)CConnection.h
	$(CXX) $(CFLAGS) -c -o $@ $<
CDynamic.o: $(IN)CDynamic.cpp $(IN)CDynamic.h
	$(CXX) $(CFLAGS) -c -o $@ $<
CFolder.o: $(IN)CFolder.cpp $(IN)CFolder.h
	$(CXX) $(CFLAGS) -c -o $@ $<
CListenException.o: $(IN)CListenException.cpp $(IN)CListenException.h
	$(CXX) $(CFLAGS) -c -o $@ $<
CLog.o: $(IN)CLog.cpp $(IN)CLog.h
	$(CXX) $(CFLAGS) -c -o $@ $<
CPath.o: $(IN)CPath.cpp $(IN)CPath.h
	$(CXX) $(CFLAGS) -c -o $@ $<
CPortException.o: $(IN)CPortException.cpp $(IN)CPortException.h
	$(CXX) $(CFLAGS) -c -o $@ $<
CRequest.o: $(IN)CRequest.cpp $(IN)CRequest.h
	$(CXX) $(CFLAGS) -c -o $@ $<
CServer.o: $(IN)CServer.cpp $(IN)CServer.h
	$(CXX) $(CFLAGS) -c -o $@ $<
CSocketException.o: $(IN)CSocketException.cpp $(IN)CSocketException.h
	$(CXX) $(CFLAGS) -c -o $@ $<
CStatic.o: $(IN)CStatic.cpp $(IN)CStatic.h
	$(CXX) $(CFLAGS) -c -o $@ $<

doc:
	doxygen Doxyfile
httpsrv: CBadAddressException.o CConfig.o CConfigException.o CConnection.o CDynamic.o CFolder.o CListenException.o CLog.o CPath.o CPortException.o CRequest.o CServer.o CSocketException.o CStatic.o main.o
	$(LD) -o httpsrv *.o

clean:
	rm -fr *.o httpsrv doc
run:
	./httpsrv
